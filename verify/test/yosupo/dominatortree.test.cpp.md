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


# :heavy_check_mark: test/yosupo/dominatortree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/dominatortree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-01 16:38:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/dominatortree">https://judge.yosupo.jp/problem/dominatortree</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/DominatorTree.hpp.html">src/Graph/DominatorTree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Aug  1 15:46:59 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/DominatorTree.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        Int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    std::vector<int> dtree = construct_domnator_tree(g, s);
    for (int x : dtree) std::cout << x << " ";
    std::cout << std::endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/dominatortree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Aug  1 15:46:59 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Graph/DominatorTree.hpp"
/// @docs src/Graph/DominatorTree.md
// 根付き森と、根から各頂点までのaggregationを管理
template <class T, class F> struct DirectedUnionFind {
    std::vector<int> par;
    std::vector<T> val;
    F op;
    DirectedUnionFind(F op_) : op(op_) {}
    void set_by_vector(const std::vector<T>& val_) {
        par.resize(val_.size()), std::iota(par.begin(), par.end(), 0);
        val = val_;
    }
    void set_by_value(int n, T a) {
        par.resize(n), std::iota(par.begin(), par.end(), 0);
        val.resize(n, a);
    }
    int compress(int v) {
        if (par[v] == v) return v;
        int root = compress(par[v]);
        val[v] = op(val[par[v]], val[v]);
        return par[v] = root;
    }
    int eval(int v) {
        compress(v);
        return val[v];
    }
    // rootをtoにつなげる
    void link(int to, int root) {
        assert(par[root] == root);
        par[root] = to;
    }
};
template <class T, class F> DirectedUnionFind<T, F> make_directed_unionfind(F op_) {
    return DirectedUnionFind<T, F>(op_);
}

// 親をさすvectorを返す。rootの親はroot、rootから到達できない頂点の親は-1
std::vector<int> construct_domnator_tree(const std::vector<std::vector<int>>& edge, int root) {
    int n = edge.size();
    std::vector<std::vector<int>> redge(n);
    for (int u = 0; u < n; u++)
        for (int v : edge[u]) redge[v].push_back(u);
    // dfs木を作る
    std::vector<int> par(n, -1), to_vertex, to_ord(n, -1);
    auto dfs = [&](auto&& self, int v) -> void {
        to_ord[v] = to_vertex.size();
        to_vertex.push_back(v);
        for (int u : edge[v]) {
            if (to_ord[u] != -1) continue;
            self(self, u);
            par[to_ord[u]] = to_ord[v];
        }
    };
    dfs(dfs, root);
    int m = to_vertex.size();  // rootから到達可能な頂点数
    // dfs逆順
    std::vector<int> sdom(m), U(m, -1);
    for (int i = 1; i < m; i++) sdom[i] = i;  // Theorem 4の左側をカバーできるように、iで初期化しておく
    auto uf = make_directed_unionfind<int>([&](int i, int j) { return sdom[i] < sdom[j] ? i : j; });
    uf.set_by_value(m, 0);
    for (int i = 0; i < m; i++) uf.val[i] = i;
    std::vector<std::vector<int>> bucket(n);
    for (int i = m - 1; i >= 1; i--) {
        // dfs逆順にsemidominatorを求める(Theorem 4)
        for (int v : redge[to_vertex[i]]) {
            int j = to_ord[v];
            if (j == -1) continue;  // rootから到達できない頂点
            sdom[i] = std::min(sdom[i], sdom[uf.eval(j)]);
        }
        // Corollary 1
        bucket[sdom[i]].push_back(i);
        for (int j : bucket[par[i]]) U[j] = uf.eval(j);
        uf.link(par[i], i);
    }
    // dfs順にimmediate dominatorを求める
    std::vector<int> idom(m, -1);
    for (int i = 1; i < m; i++) {
        int u = U[i];
        idom[i] = sdom[i] == sdom[u] ? sdom[i] : idom[u];
    }
    // dfs順序からもとの頂点番号で表示したものに直す
    std::vector<int> ret(n, -1);
    for (int i = 1; i < m; i++) {
        ret[to_vertex[i]] = to_vertex[idom[i]];
    }
    ret[root] = root;
    return ret;
}
#line 19 "test/yosupo/dominatortree.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        Int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    std::vector<int> dtree = construct_domnator_tree(g, s);
    for (int x : dtree) std::cout << x << " ";
    std::cout << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

