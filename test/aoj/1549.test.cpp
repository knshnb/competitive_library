#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1549"

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
 *    created: Sun Aug  9 03:20:07 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/WaveletMatrix.hpp"
#include "../../src/Helper/ChminChmax.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n;
    std::cin >> n;
    std::vector<int> a(n);
    REP(i, n) std::cin >> a[i];
    WaveletMatrix<int, 20> wm(a);
    Int Q;
    std::cin >> Q;
    REP(q, Q) {
        Int l, r, d;
        std::cin >> l >> r >> d, r++;
        Int cnt = wm.rank_3way(l, r, d)[0];
        Int ans = 1e9;
        if (cnt > 0) chmin(ans, std::abs(d - wm.quantile(l, r, cnt - 1)));
        if (cnt < r - l) chmin(ans, std::abs(d - wm.quantile(l, r, cnt)));
        std::cout << ans << "\n";
    }
}
