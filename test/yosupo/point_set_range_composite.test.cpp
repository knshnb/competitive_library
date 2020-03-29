#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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
 *    created: Sun Mar 29 16:52:02 JST 2020
 **/

#include "../../src/Math/ModInt.hpp"
using mint = ModInt<998244353>;
#include "../../src/DataStructure/SegmentTree.hpp"

using pmm = std::pair<mint, mint>;
signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<pmm> a(n);
    REP(i, n) std::cin >> a[i].first >> a[i].second;
    auto seg = make_segment_tree<pmm>(
        [](pmm x, pmm y) {
            return pmm{x.first * y.first, y.first * x.second + y.second};
        },
        {1, 0});
    seg.set_by_vector(a);
    REP(q, Q) {
        Int c, x, y, z;
        std::cin >> c >> x >> y >> z;
        if (c == 0) {
            seg.update(x, {y, z});
        } else {
            pmm tmp = seg.query(x, y);
            std::cout << tmp.first * z + tmp.second << "\n";
        }
    }
}
