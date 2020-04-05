#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

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
 *    created: Sun Apr  5 19:29:53 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/Eratosthenes.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, A, B;
    std::cin >> n >> A >> B;
    Eratosthenes er(n + 1);
    Int num = ((Int)er.primes.size() - B + A - 1) / A;
    std::cout << er.primes.size() << " " << num << std::endl;
    REP(i, num) {
        std::cout << er.primes[A * i + B] << " ";
    }
    std::cout << std::endl;
}
