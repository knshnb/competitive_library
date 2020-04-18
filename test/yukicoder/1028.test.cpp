#define PROBLEM "https://yukicoder.me/problems/no/1028"

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
 *    created: Sat Apr 18 15:55:11 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Helper/TernarySearch.hpp"
#undef CALL_FROM_TEST

using pii = std::pair<Int, Int>;
signed main() {
    Int n;
    std::cin >> n;
    std::vector<std::vector<pii>> ps(n);
    REP(i, n) REP(j, n) {
        Int x;
        std::cin >> x;
        ps[x - 1].push_back({i, j});
    }
    Int ans = 0;
    REP(idx, n) {
        auto f = [&](Int mid) {
            Int ret = 0;
            for (pii& p : ps[idx]) {
                ret += std::max(std::abs(mid - p.first), p.second);
            }
            return ret;
        };

        Int mi_idx = ternary_search(0LL, n, f, false);
        ans += f(mi_idx);
    }
    std::cout << ans << std::endl;
}
