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


# :heavy_check_mark: src/Graph/TwoSat.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/TwoSat.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 03:26:44+09:00




## Depends on

* :heavy_check_mark: <a href="StronglyConnectedComponents.hpp.html">src/Graph/StronglyConnectedComponents.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "StronglyConnectedComponents.hpp"

struct TwoSat {
    int n;
    StronglyConnectedComponents scc;  // [0, n): x, [n, 2n): not x
    TwoSat(int n_) : n(n_), scc(2 * n_) {}
    // xの否定を表すindex
    int rev(int x) { return x < n ? x + n : x - n; }
    // (x \vee y)の条件を追加
    void add_condition(int x, bool not_x, int y, bool not_y) {
        if (not_x) x = rev(x);
        if (not_y) y = rev(y);
        scc.add_edge(rev(x), y);
        scc.add_edge(rev(y), x);
    }
    bool run() {
        scc.build();
        for (int x = 0; x < n; x++) {
            if (scc.belong_to[x] == scc.belong_to[rev(x)]) return false;
        }
        return true;
    }
    bool is_true(int x) {
        assert(0 <= x && x < n);
        return scc.belong_to[x] > scc.belong_to[rev(x)];
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
#line 2 "src/Graph/TwoSat.hpp"

struct TwoSat {
    int n;
    StronglyConnectedComponents scc;  // [0, n): x, [n, 2n): not x
    TwoSat(int n_) : n(n_), scc(2 * n_) {}
    // xの否定を表すindex
    int rev(int x) { return x < n ? x + n : x - n; }
    // (x \vee y)の条件を追加
    void add_condition(int x, bool not_x, int y, bool not_y) {
        if (not_x) x = rev(x);
        if (not_y) y = rev(y);
        scc.add_edge(rev(x), y);
        scc.add_edge(rev(y), x);
    }
    bool run() {
        scc.build();
        for (int x = 0; x < n; x++) {
            if (scc.belong_to[x] == scc.belong_to[rev(x)]) return false;
        }
        return true;
    }
    bool is_true(int x) {
        assert(0 <= x && x < n);
        return scc.belong_to[x] > scc.belong_to[rev(x)];
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

