---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: src/Graph/TwoEdgeConnectedComponents.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/TwoEdgeConnectedComponents.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 03:56:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/two_edge_connected_components.test.cpp.html">test/yosupo/two_edge_connected_components.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 木上のimos法による二重辺連結成分分解、O(E + V)
struct TwoEdgeConnectedComponents {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<std::pair<int, int>> bridges;  // 列挙された橋
    std::vector<int> belong_to;                // 各頂点の属する二重辺連結成分のindex
    int size = -1;                             // 二重辺連結成分の個数

    TwoEdgeConnectedComponents(int n_) : n(n_), g(n_) {}
    TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& g_) : n(g_.size()), g(g_) {}
    void build() {
        // dfs木を作り、各辺が後退辺にはさまれているかどうかをimos法で判定
        std::vector<int> imos(n);  // imos[i] == 0なら(i, par)が橋になるように更新
        std::vector<int> flag(n);  // 0: unvisited, 1: ancestor of current v, 2: done(後退辺になりえない)
        auto dfs1 = [&](auto f, int v, int prv) -> void {
            flag[v] = 1;
            bool skipped_parent = false;
            for (int s : g[v]) {
                if (s == prv && !skipped_parent) {  // 多重辺に対応
                    skipped_parent = true;
                    continue;
                }
                if (flag[s] == 0) {
                    f(f, s, v);
                    if (imos[s] == 0) bridges.push_back({v, s});
                    imos[v] += imos[s];
                } else if (flag[s] == 1) {  // 後退辺
                    imos[v]++;
                    imos[s]--;
                }
            }
            flag[v] = 2;
        };
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0) dfs1(dfs1, i, -1);
        }

        // 橋(imos[i] == 0となるような(i, par))で区切って二重編連結成分に分ける
        int cur_group = 0;
        belong_to.assign(n, -1);
        auto dfs2 = [&](auto f, int v) -> void {
            for (int s : g[v]) {
                if (belong_to[s] != -1) continue;
                belong_to[s] = imos[s] == 0 ? cur_group++ : belong_to[v];
                f(f, s);
            }
        };
        for (int i = 0; i < n; i++) {
            if (belong_to[i] == -1) {
                belong_to[i] = cur_group++;
                dfs2(dfs2, i);
            }
        }
        size = cur_group;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/TwoEdgeConnectedComponents.hpp"
// 木上のimos法による二重辺連結成分分解、O(E + V)
struct TwoEdgeConnectedComponents {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<std::pair<int, int>> bridges;  // 列挙された橋
    std::vector<int> belong_to;                // 各頂点の属する二重辺連結成分のindex
    int size = -1;                             // 二重辺連結成分の個数

    TwoEdgeConnectedComponents(int n_) : n(n_), g(n_) {}
    TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& g_) : n(g_.size()), g(g_) {}
    void build() {
        // dfs木を作り、各辺が後退辺にはさまれているかどうかをimos法で判定
        std::vector<int> imos(n);  // imos[i] == 0なら(i, par)が橋になるように更新
        std::vector<int> flag(n);  // 0: unvisited, 1: ancestor of current v, 2: done(後退辺になりえない)
        auto dfs1 = [&](auto f, int v, int prv) -> void {
            flag[v] = 1;
            bool skipped_parent = false;
            for (int s : g[v]) {
                if (s == prv && !skipped_parent) {  // 多重辺に対応
                    skipped_parent = true;
                    continue;
                }
                if (flag[s] == 0) {
                    f(f, s, v);
                    if (imos[s] == 0) bridges.push_back({v, s});
                    imos[v] += imos[s];
                } else if (flag[s] == 1) {  // 後退辺
                    imos[v]++;
                    imos[s]--;
                }
            }
            flag[v] = 2;
        };
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0) dfs1(dfs1, i, -1);
        }

        // 橋(imos[i] == 0となるような(i, par))で区切って二重編連結成分に分ける
        int cur_group = 0;
        belong_to.assign(n, -1);
        auto dfs2 = [&](auto f, int v) -> void {
            for (int s : g[v]) {
                if (belong_to[s] != -1) continue;
                belong_to[s] = imos[s] == 0 ? cur_group++ : belong_to[v];
                f(f, s);
            }
        };
        for (int i = 0; i < n; i++) {
            if (belong_to[i] == -1) {
                belong_to[i] = cur_group++;
                dfs2(dfs2, i);
            }
        }
        size = cur_group;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

