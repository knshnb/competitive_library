#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"

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
 *    created: Sun Aug 16 15:46:30 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/AbstractDijkstra.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m, r;
    std::cin >> n >> m >> r;
    struct Edge {
        Int to, cost;
    };
    std::vector<std::vector<Edge>> g(n);
    REP(i, m) {
        Int s, t, d;
        std::cin >> s >> t >> d;
        g[s].push_back({t, d});
    }
    auto delta = [&](Int from, auto update) -> void {
        for (Edge& edge : g[from]) {
            update(edge.to, edge.cost);
        }
    };
    auto dist = dijkstra<Int>(r, delta);
    REP(i, n) {
        if (dist.count(i)) {
            std::cout << dist[i] << "\n";
        } else {
            std::cout << "INF\n";
        }
    }
}
