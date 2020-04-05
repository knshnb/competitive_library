#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

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
 *    created: Sun Apr  5 20:03:46 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/String/RollingHash.hpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    Int n = s.size();
    MultiRollingHash rh(s);
    REP(i, n) {
        auto check = [&](Int mid) -> bool {
            return rh.get(0, mid) == rh.get(i, i + mid);
        };
        Int ok = 0, ng = n - i + 1;
        while (std::abs(ok - ng) > 1) {
            Int mid = (ok + ng) / 2;
            (check(mid) ? ok : ng) = mid;
        }
        std::cout << ok << " ";
    }
    std::cout << std::endl;
}
