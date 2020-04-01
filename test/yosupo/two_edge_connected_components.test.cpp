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
