#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

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
 *    created: Fri Apr 24 16:25:41 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Flow/Dinic.hpp"
#undef CALL_FROM_TEST

signed main() {
    int L, R, M;
    std::cin >> L >> R >> M;
    Dinic ff(L + R + 2);
    int s = L + R, t = L + R + 1;
    REP(i, L) { ff.add_edge(s, (int)i, 1); }
    REP(i, R) { ff.add_edge((int)L + i, t, 1); }
    REP(_, M) {
        int a, b;
        std::cin >> a >> b;
        ff.add_edge(a, L + b, 1);
    }
    std::cout << ff.max_flow(s, t) << std::endl;
    for (auto& [u, v, f] : ff.construct()) {
        if (u < L && L <= v && v < L + R) {
            std::cout << u << " " << v - L << "\n";
        }
    }
}
