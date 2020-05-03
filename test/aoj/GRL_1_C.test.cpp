#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"

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
 *    created: Sun May  3 17:28:08 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Helper/MakeVec.hpp"
#include "../../src/Graph/WarshallFloyd.hpp"
#undef CALL_FROM_TEST

const Int INF = 1e18;
signed main() {
    Int n, m;
    std::cin >> n >> m;
    auto adj = make_vec<Int>(n, n, INF);
    REP(i, n) adj[i][i] = 0;
    REP(_, m) {
        Int u, v, d;
        std::cin >> u >> v >> d;
        adj[u][v] = d;
    }
    warshall_floyd(adj, INF);
    REP(i, n) {
        if (adj[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }
    REP(i, n) {
        REP(j, n) {
            if (adj[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << adj[i][j];
            }
            if (j != n - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
}
