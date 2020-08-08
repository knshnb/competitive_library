#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

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
 *    created: Fri Aug  7 22:18:24 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/WaveletMatrix.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n;
    std::cin >> n;
    std::vector<int> a(n);
    REP(i, n) std::cin >> a[i];
    WaveletMatrix<int, 32> wm(a);

    Int ans1 = 0;
    REP(i, n) { ans1 += wm.rank_3way(0, i, a[i])[2]; }
    Int ans2 = 0;
    REP(i, n) { ans2 += wm.rank_3way(i + 1, n, a[i])[0]; }
    assert(ans1 == ans2);
    std::cout << ans1 << std::endl;
}