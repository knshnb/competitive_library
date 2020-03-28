#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

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
 *    created: Sat Mar 28 22:38:45 JST 2020
 **/

#include "../src/DataStructure/SegmentTree.cpp"

const Int INF = 1e18;
signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    auto seg = make_segment_tree<Int>([](Int a, Int b) { return std::min(a, b); }, INF);
    seg.set_by_vector(std::vector<Int>(n, (1LL << 31) - 1));
    REP(q, Q) {
        Int c, x, y;
        std::cin >> c >> x >> y;
        if (c == 0) {
            seg.update(x, y);
        } else {
            std::cout << seg.query(x, y + 1) << "\n";
        }
    }
}
