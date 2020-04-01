#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

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
 *    created: Mon Mar 30 21:14:19 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/ModInt.hpp"
#include "../../src/DataStructure/LazySegmentTree.hpp"
#undef CALL_FROM_TEST

using mint = ModInt<998244353>;
using pmm = std::pair<mint, mint>;
signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<mint> a(n);
    REP(i, n) std::cin >> a[i];
    auto seg = make_lazy_segment_tree<mint, pmm>(
        std::plus<mint>(), 0,
        [](pmm x, pmm y) -> pmm {
            return {x.first * y.first, x.second * y.first + y.second};
        },
        {1, 0}, [](mint x, pmm y) { return y.first * x + y.second; },
        [](pmm x, int len) -> pmm {
            return {x.first, x.second * len};
        });
    seg.set_by_vector(a);
    REP(q, Q) {
        Int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 0) {
            Int b, c;
            std::cin >> b >> c;
            seg.update(l, r, {b, c});
        } else {
            std::cout << seg.query(l, r) << "\n";
        }
    }
}
