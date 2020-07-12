#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Mon Jul 13 00:06:28 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/SparseTable.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    auto st = make_sparse_table<Int>([](Int x, Int y) { return std::min(x, y); }, a);
    REP(q, Q) {
        Int l, r;
        std::cin >> l >> r;
        std::cout << st.query(l, r) << "\n";
    }
}
