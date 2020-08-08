#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

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
 *    created: Sat Aug  8 21:10:39 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/WaveletMatrix.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<int> a(n);
    REP(i, n) std::cin >> a[i];
    WaveletMatrix wm(a);
    REP(q, Q) {
        Int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << wm.quantile(l, r, k) << "\n";
    }
}
