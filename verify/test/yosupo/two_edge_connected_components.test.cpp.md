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


# :heavy_check_mark: test/yosupo/two_edge_connected_components.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/two_edge_connected_components.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 03:56:08+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_edge_connected_components">https://judge.yosupo.jp/problem/two_edge_connected_components</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/TwoEdgeConnectedComponents.hpp.html">src/Graph/TwoEdgeConnectedComponents.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

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
 *    created: Wed Apr  1 19:23:42 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/TwoEdgeConnectedComponents.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m;
    std::cin >> n >> m;
    TwoEdgeConnectedComponents t(n);
    REP(i, m) {
        int u, v;
        std::cin >> u >> v;
        t.g[u].push_back(v);
        t.g[v].push_back(u);
    }
    t.build();

    std::vector<std::vector<int>> groups(t.size);
    REP(i, n) { groups[t.belong_to[i]].push_back(i); }
    std::cout << groups.size() << std::endl;
    for (auto& vs : groups) {
        std::cout << vs.size() << " ";
        for (auto v : vs) std::cout << v << " ";
        std::cout << "\n";
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/two_edge_connected_components.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

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
 *    created: Wed Apr  1 19:23:42 JST 2020
 **/

#define CALL_FROM_TEST
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
#line 19 "test/yosupo/two_edge_connected_components.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m;
    std::cin >> n >> m;
    TwoEdgeConnectedComponents t(n);
    REP(i, m) {
        int u, v;
        std::cin >> u >> v;
        t.g[u].push_back(v);
        t.g[v].push_back(u);
    }
    t.build();

    std::vector<std::vector<int>> groups(t.size);
    REP(i, n) { groups[t.belong_to[i]].push_back(i); }
    std::cout << groups.size() << std::endl;
    for (auto& vs : groups) {
        std::cout << vs.size() << " ";
        for (auto v : vs) std::cout << v << " ";
        std::cout << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

