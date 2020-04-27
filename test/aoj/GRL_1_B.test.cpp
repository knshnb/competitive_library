#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

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
 *    created: Tue Apr 28 00:15:10 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/BellmanFord.hpp"
#undef CALL_FROM_TEST

signed main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    BellmanFord<Int> bf(n);
    REP(_, m) {
        Int u, v, c;
        std::cin >> u >> v >> c;
        bf.add_edge(u, v, c);
    }
    auto dist = bf.run(s);
    if (std::find(dist.begin(), dist.end(), -bf.INF) != dist.end()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
        for (Int d : dist) {
            if (d == bf.INF) {
                std::cout << "INF" << "\n";
            } else {
                std::cout << d << "\n";
            }
        }
    }
}
