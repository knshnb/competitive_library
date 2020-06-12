#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

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
 *    created: Sat Jun 13 03:04:06 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/TwoSat.hpp"
#undef CALL_FROM_TEST

signed main() {
    std::string _;
    Int n, m;
    std::cin >> _ >> _ >> n >> m;
    TwoSat sat(n);
    REP(i, m) {
        Int a, b;
        std::cin >> a >> b >> _;
        sat.add_condition(std::abs(a) - 1, a < 0, std::abs(b) - 1, b < 0);
    }
    if (!sat.run()) {
        std::cout << "s UNSATISFIABLE" << std::endl;
    } else {
        std::cout << "s SATISFIABLE" << std::endl << "v ";
        REP(i, n) std::cout << (sat.is_true(i) ? (i + 1) : -(i + 1)) << " ";
        std::cout << 0 << std::endl;
    }
}
