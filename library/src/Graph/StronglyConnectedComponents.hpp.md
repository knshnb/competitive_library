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


# :heavy_check_mark: src/Graph/StronglyConnectedComponents.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/StronglyConnectedComponents.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 18:03:13+09:00




## 概要
Kosaraju' algorithm(https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm)による強連結成分分解。O(E + V)。

2回dfsを行う。
1回目のdfsでpost-orderを記録。
2回目はそれの逆順に始点を変えてdfsを行い、到達可能な頂点集合は同じ強連結に属することがわかる。


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/Graph/StronglyConnectedComponents.md
struct StronglyConnectedComponents {
    int n, size;  // sizeはbuild()後に強連結成分の数を格納
    std::vector<std::vector<int>> edge, redge;
    std::vector<int> belong_to;
    StronglyConnectedComponents(int n_) : n(n_), edge(n_), redge(n_) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        edge[u].push_back(v);
        redge[v].push_back(u);
    }
    void build() {
        std::vector<int> ord;  // post-order
        // 正方向の辺でdfs、post-orderをふる
        std::vector<bool> visited(n, false);
        auto dfs1 = [&](auto f, int v) -> void {
            if (visited[v]) return;
            visited[v] = true;
            for (int s : edge[v]) {
                f(f, s);
            }
            ord.push_back(v);
        };
        for (int i = 0; i < n; i++) dfs1(dfs1, i);

        // post-order逆順にdfs、到達可能な同値類に分ける
        belong_to.assign(n, -1);
        int cur_group = 0;
        auto dfs2 = [&](auto f, int v) -> void {
            if (belong_to[v] != -1) return;
            belong_to[v] = cur_group;
            for (int s : redge[v]) {
                f(f, s);
            }
        };
        std::reverse(ord.begin(), ord.end());
        for (int i : ord) {
            if (belong_to[i] == -1) {
                dfs2(dfs2, i);
                cur_group++;
            }
        }
        size = cur_group;
    }
    bool has_loop() {
        build();
        return size < n;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/StronglyConnectedComponents.hpp"
/// @docs src/Graph/StronglyConnectedComponents.md
struct StronglyConnectedComponents {
    int n, size;  // sizeはbuild()後に強連結成分の数を格納
    std::vector<std::vector<int>> edge, redge;
    std::vector<int> belong_to;
    StronglyConnectedComponents(int n_) : n(n_), edge(n_), redge(n_) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        edge[u].push_back(v);
        redge[v].push_back(u);
    }
    void build() {
        std::vector<int> ord;  // post-order
        // 正方向の辺でdfs、post-orderをふる
        std::vector<bool> visited(n, false);
        auto dfs1 = [&](auto f, int v) -> void {
            if (visited[v]) return;
            visited[v] = true;
            for (int s : edge[v]) {
                f(f, s);
            }
            ord.push_back(v);
        };
        for (int i = 0; i < n; i++) dfs1(dfs1, i);

        // post-order逆順にdfs、到達可能な同値類に分ける
        belong_to.assign(n, -1);
        int cur_group = 0;
        auto dfs2 = [&](auto f, int v) -> void {
            if (belong_to[v] != -1) return;
            belong_to[v] = cur_group;
            for (int s : redge[v]) {
                f(f, s);
            }
        };
        std::reverse(ord.begin(), ord.end());
        for (int i : ord) {
            if (belong_to[i] == -1) {
                dfs2(dfs2, i);
                cur_group++;
            }
        }
        size = cur_group;
    }
    bool has_loop() {
        build();
        return size < n;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

