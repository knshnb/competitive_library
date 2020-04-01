#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Thu Mar 26 18:48:49 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Helper/ChminChmax.hpp"
#include "../../src/Helper/MakeVec.hpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s, t;
    std::cin >> s >> t;
    Int n = s.size(), m = t.size();
    auto dp = make_vec<Int>(n + 1, m + 1, 1e9);
    dp[0][0] = 0;
    REP(i, n + 1) {
        REP(j, m + 1) {
            if (i - 1 >= 0) chmin(dp[i][j], dp[i - 1][j] + 1);
            if (j - 1 >= 0) chmin(dp[i][j], dp[i][j - 1] + 1);
            if (i - 1 >= 0 && j - 1 >= 0) chmin(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
        }
    }
    std::cout << dp[n][m] << std::endl;
}
