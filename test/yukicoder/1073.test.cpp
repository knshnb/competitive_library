#define PROBLEM "https://yukicoder.me/problems/no/1073"

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
 *    created: Sat Jun  6 01:52:00 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/Matrix.hpp"
#include "../../src/Math/ModInt.hpp"
#undef CALL_FROM_TEST
using mint = ModInt<1000000007>;

signed main() {
    Int n;
    std::cin >> n;
    std::vector<mint> x(6);
    x[0] = 1;
    Matrix<mint> A(6);
    REP(j, 6) A[0][j] = mint(1) / 6;
    REP(i, 1, 6) A[i][i - 1] = 1;
    auto ret = pow(A, n, Matrix<mint>::eye(6)) * x;
    std::cout << ret[0] << std::endl;
}
