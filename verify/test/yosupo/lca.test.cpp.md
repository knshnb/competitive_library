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


# :heavy_check_mark: test/yosupo/lca.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 18:40:05+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/LowestCommonAncestor.hpp.html">src/Graph/LowestCommonAncestor.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Tue Mar 31 17:04:00 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/LowestCommonAncestor.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    TreeDoubling td(n);
    REP(i, n - 1) {
        int p;
        std::cin >> p;
        td.g[p].push_back({(int)i + 1, 1});
        td.g[i + 1].push_back({p, 1});
    }
    td.build();
    REP(q, Q) {
        Int u, v;
        std::cin >> u >> v;
        std::cout << td.lca(u, v) << "\n";
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/lca.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Tue Mar 31 17:04:00 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Graph/LowestCommonAncestor.hpp"
// edgeを貼ったあとにbuild()を忘れない！
struct TreeDoubling {
    struct Edge {
        int to, len;
    };  // 場合に応じて書き換える、toは必須
    std::vector<std::vector<Edge>> g;
    int n, size;  // MSB + 1
    int root;
    std::vector<int> depth;
    std::vector<std::vector<int>> parent;  // ダミー頂点n(親もn)
    TreeDoubling(int n_) : g(n_), n(n_), size(64 - __builtin_clzll(n_) + 1), depth(n_) {
        parent.resize(size, std::vector<int>(n + 1, n));
    }
    void build(int root_ = 0) {
        auto dfs = [&](auto f, int v, int prv) -> void {
            for (Edge& e : g[v]) {
                if (e.to == prv) continue;
                depth[e.to] = depth[v] + e.len;
                parent[0][e.to] = v;
                f(f, e.to, v);
            }
        };
        root = root_;
        depth[root] = 0;
        dfs(dfs, root, -1);
        for (int k = 0; k < size - 1; k++) {
            for (int i = 0; i < n; i++) {
                parent[k + 1][i] = parent[k][parent[k][i]];
            }
        }
    }

    // vからd個分親にさかのぼった頂点、rootよりも上はnを返す
    int query(int v, int d) {
        int ret = v;
        for (int j = 0; j < size; j++) {
            if (d >> j & 1) ret = parent[j][ret];
        }
        return ret;
    }
    int lca(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        v = query(v, depth[v] - depth[u]);
        if (u == v) return u;

        for (int j = size - 1; j >= 0; j--) {
            if (parent[j][u] == parent[j][v]) continue;
            u = parent[j][u];
            v = parent[j][v];
        }
        assert(parent[0][u] == parent[0][v]);
        return parent[0][u];
    }
    int dist(int u, int v) { return depth[u] + depth[v] - depth[lca(u, v)] * 2; }
};
#line 19 "test/yosupo/lca.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    TreeDoubling td(n);
    REP(i, n - 1) {
        int p;
        std::cin >> p;
        td.g[p].push_back({(int)i + 1, 1});
        td.g[i + 1].push_back({p, 1});
    }
    td.build();
    REP(q, Q) {
        Int u, v;
        std::cin >> u >> v;
        std::cout << td.lca(u, v) << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

