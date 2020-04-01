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

#include "../../src/Graph/LowestCommonAncestor.hpp"

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
