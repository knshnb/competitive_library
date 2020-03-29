#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

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
 *    created: Sat Mar 21 19:52:09 JST 2020
 **/

#include "../src/DataStructure/LazySegmentTree.hpp"

const Int INF = 1e9;
signed main() {
    int n, Q;
    std::cin >> n >> Q;
    auto seg = make_lazy_segment_tree<Int, Int>(
        [](Int x, Int y) { return std::min(x, y); }, INF, [](Int x, Int y) { return x + y; }, 0,
        [](Int x, Int y) { return x == INF ? x : x + y; }, [](Int x, int len) { return x; });
    seg.set_by_vector(std::vector<Int>(n));
    REP(q, Q) {
        int c, s, t;
        std::cin >> c >> s >> t;
        t++;
        if (c == 0) {
            Int x;
            std::cin >> x;
            seg.update(s, t, x);
        } else {
            std::cout << seg.query(s, t) << std::endl;
        }
    }
}
