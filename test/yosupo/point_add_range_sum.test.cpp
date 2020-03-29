#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

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
 *    created: Sun Mar 29 16:41:21 JST 2020
 **/

#include "../../src/DataStructure/SegmentTree.hpp"

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    auto seg = make_segment_tree<Int>(std::plus<Int>(), 0);
    seg.set_by_vector(a);
    REP(q, Q) {
        Int t, x, y;
        std::cin >> t >> x >> y;
        if (t == 0) {
            seg.operate(x, y);
        } else {
            std::cout << seg.query(x, y) << "\n";
        }
    }
}
