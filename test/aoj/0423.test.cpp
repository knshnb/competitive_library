#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0423"

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
 *    created: Mon Apr 27 01:47:13 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/Dijkstra.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, R;
    std::cin >> n >> R;
    Dijkstra<Int> dj(n + 1);
    std::vector<Int> e(n);
    REP(i, n) {
        Int t;
        std::cin >> t >> e[i];
        dj.add_edge(n, i, t);
    }
    REP(_, R) {
        Int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        dj.add_edge(b, a, c - 1);
    }
    auto dist = dj.run(n);
    Int ans = 0;
    REP(i, n) ans += dist[i] * e[i];
    std::cout << ans << std::endl;
}
