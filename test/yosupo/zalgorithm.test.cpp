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
 *    created: Mon Apr  6 23:56:02 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/String/ZAlgorithm.hpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    std::vector<int> a = Z_algorithm(s);
    for (int x : a) std::cout << x << " ";
    std::cout << std::endl;
}
