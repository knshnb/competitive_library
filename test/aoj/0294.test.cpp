#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0294"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Aug  1 16:21:06 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/DominatorTree.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        Int u, v;
        std::cin >> u >> v, u--, v--;
        g[u].push_back(v);
    }
    std::vector<int> dtree = construct_domnator_tree(g, 0);
    Int Q;
    std::cin >> Q;
    REP(q, Q) {
        Int r;
        std::cin >> r, r--;
        std::cout << (dtree[r] == 0 ? r : dtree[r]) + 1 << "\n";
    }
}
