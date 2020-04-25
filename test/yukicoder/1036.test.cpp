#define PROBLEM "https://yukicoder.me/problems/no/1036"

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
 *    created: Sat Apr 25 17:19:30 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/SlidingWindowAggregation.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n;
    std::cin >> n;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    a.push_back(1);
    auto swag = make_swag<Int>([](Int x, Int y) { return std::gcd(x, y); }, 0);
    Int ans = 0, j = -1;
    REP(i, n) {
        while (swag.fold_all() != 1) {
            swag.push(a[++j]);
        }
        ans += n - j;
        swag.pop();
    }
    std::cout << ans << std::endl;
}
