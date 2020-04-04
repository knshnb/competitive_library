#define PROBLEM "https://judge.yosupo.jp/problem/scc"

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
 *    created: Fri Apr  3 13:28:22 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/StronglyConnectedComponents.hpp"
#undef CALL_FROM_TEST

signed main() {
    int n, m;
    std::cin >> n >> m;
    StronglyConnectedComponents scc(n);
    REP(i, m) {
        int u, v;
        std::cin >> u >> v;
        scc.add_edge(u, v);
    }
    scc.build();
    std::vector<std::vector<int>> groups(scc.size);
    REP(i, n) { groups[scc.belong_to[i]].push_back(i); }
    std::cout << scc.size << std::endl;
    for (auto& group : groups) {
        std::cout << group.size() << " ";
        for (int v : group) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
}
