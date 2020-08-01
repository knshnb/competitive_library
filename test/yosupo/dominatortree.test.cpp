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