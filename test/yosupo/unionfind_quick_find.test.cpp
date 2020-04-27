#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

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
 *    created: Mon Apr 27 23:29:45 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/QuickFind.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    QuickFind qf(n);
    REP(q, Q) {
        Int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            qf.unite(u, v);
        } else {
            std::cout << qf.is_same(u, v) << "\n";
        }
    }
}
