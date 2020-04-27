#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0646"

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
 *    created: Tue Apr 28 00:52:55 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Helper/BinarySearch.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, K, L;
    std::cin >> n >> K >> L;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    std::vector<Int> acc(n + 1);
    Int ans = binary_search(0, n + 1, [&](Int mid) {
        // mid以下がL個未満かどうか
        REP(i, n) { acc[i + 1] = acc[i] + (a[i] <= mid); }
        Int cnt = 0;
        REP(i, n) { cnt += acc.end() - std::lower_bound(acc.begin(), acc.end(), acc[i] + K); }
        return cnt < L;
    }) + 1;
    std::cout << ans << std::endl;
}
