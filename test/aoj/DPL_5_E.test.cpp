#define PROBLEM ""

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
 *    created: Sun Apr 12 17:52:03 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/Combination.hpp"
#include "../../src/Math/ModInt.hpp"
#undef CALL_FROM_TEST

using mint = ModInt<1000000007>;
signed main() {
    Int n, k;
    std::cin >> n >> k;
    Combination<mint> comb(n + k - 1);
    std::cout << (n > k ? 0 : comb(k, n)) << std::endl;
}
