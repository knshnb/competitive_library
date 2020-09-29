#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

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
 *    created: Wed Sep 30 02:13:06 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/LazySegmentTreeACL.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    sum_update::segtree seg{std::vector<sum_update::S>(n, {0, 1})};
    REP(q, Q) {
        Int t, l, r;
        std::cin >> t >> l >> r, r++;
        if (t == 0) {
            Int x;
            std::cin >> x;
            seg.apply(l, r, x);
        } else {
            std::cout << seg.prod(l, r).sum << "\n";
        }
    }
}
