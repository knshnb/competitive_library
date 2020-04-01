#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

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
 *    created: Wed Apr  1 18:41:55 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/ModInt.hpp"
#include "../../src/Math/Combination.hpp"
#undef CALL_FROM_TEST

using mint = ModInt<1000000007>;
signed main() {
    Int n, k;
    std::cin >> n >> k;
    Combination<mint> comb(n + k - 1);
    std::cout << comb(n + k - 1, n) << std::endl;
}
