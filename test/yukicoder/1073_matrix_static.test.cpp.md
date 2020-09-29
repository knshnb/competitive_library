---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/MatrixStatic.hpp
    title: src/Math/MatrixStatic.hpp
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: src/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1073
    links:
    - https://yukicoder.me/problems/no/1073
  bundledCode: "#line 1 \"test/yukicoder/1073_matrix_static.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1073\"\n\n#include <bits/stdc++.h>  // clang-format\
    \ off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b, ...) for (Int i =\
    \ (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i, __VA_ARGS__,\
    \ __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Sat Jun  6 01:52:00 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#line 1 \"src/Math/MatrixStatic.hpp\"\ntemplate <class\
    \ T, int size> struct Matrix {\n    std::array<std::array<T, size>, size> A;\n\
    \    Matrix() {}\n    Matrix(const std::array<std::array<T, size>, size> &A_)\
    \ : A(A_) {}\n    static Matrix eye() {\n        Matrix mat{};\n        for (int\
    \ i = 0; i < size; i++) mat[i][i] = 1;\n        return mat;\n    }\n    std::array<T,\
    \ size> &operator[](int k) { return A[k]; }\n    const std::array<T, size> &operator[](int\
    \ k) const { return (A[k]); }\n    Matrix &operator+=(const Matrix &B) {\n   \
    \     for (int i = 0; i < A.size(); i++)\n            for (int j = 0; j < A[0].size();\
    \ j++) A[i][j] += B[i][j];\n        return *this;\n    }\n    Matrix &operator-=(const\
    \ Matrix &B) {\n        for (int i = 0; i < A.size(); i++)\n            for (int\
    \ j = 0; j < A[0].size(); j++) A[i][j] -= B[i][j];\n        return *this;\n  \
    \  }\n    Matrix &operator*=(const Matrix &B) {\n        std::array<std::array<T,\
    \ size>, size> C{};\n        for (int i = 0; i < size; i++)\n            for (int\
    \ j = 0; j < size; j++)\n                for (int k = 0; k < size; k++) C[i][j]\
    \ += A[i][k] * B[k][j];\n        std::swap(A, C);\n        return *this;\n   \
    \ }\n    Matrix operator+(const Matrix &B) const { return Matrix(*this) += B;\
    \ }\n    Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B;\
    \ }\n    Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B;\
    \ }\n    std::array<T, size> operator*(const std::array<T, size> &x) const {\n\
    \        std::array<T, size> ret{};\n        for (int i = 0; i < size; i++)\n\
    \            for (int j = 0; j < size; j++) ret[i] += A[i][j] * x[j];\n      \
    \  return ret;\n    }\n};\n#line 1 \"src/Math/ModInt.hpp\"\ntemplate <class T>\
    \ T pow(T x, long long n, const T UNION = 1) {\n    T ret = UNION;\n    while\
    \ (n) {\n        if (n & 1) ret *= x;\n        x *= x;\n        n >>= 1;\n   \
    \ }\n    return ret;\n}\n\n/// @docs src/Math/ModInt.md\ntemplate <int Mod> struct\
    \ ModInt {\n    int x;\n    static int& runtime_mod() {\n        static int runtime_mod_;\n\
    \        return runtime_mod_;\n    }\n    // \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \u5F15\u6570\u304C\u8CA0\u306E\u3068\u304D\u306F\u5B9F\u884C\u6642ModInt\n   \
    \ static constexpr int mod() { return Mod < 0 ? runtime_mod() : Mod; }\n    static\
    \ std::unordered_map<int, int>& to_inv() {\n        static std::unordered_map<int,\
    \ int> to_inv_;\n        return to_inv_;\n    }\n    static void set_runtime_mod(int\
    \ mod) {\n        static_assert(Mod < 0, \"template parameter Mod must be negative\
    \ for runtime ModInt\");\n        runtime_mod() = mod, to_inv().clear();\n   \
    \ }\n    ModInt() : x(0) {}\n    ModInt(long long x_) {\n        if ((x = x_ %\
    \ mod() + mod()) >= mod()) x -= mod();\n    }\n\n    ModInt& operator+=(ModInt\
    \ rhs) {\n        if ((x += rhs.x) >= mod()) x -= mod();\n        return *this;\n\
    \    }\n    ModInt& operator*=(ModInt rhs) {\n        x = (unsigned long long)x\
    \ * rhs.x % mod();\n        return *this;\n    }\n    ModInt& operator-=(ModInt\
    \ rhs) {\n        if ((x -= rhs.x) < 0) x += mod();\n        return *this;\n \
    \   }\n    ModInt& operator/=(ModInt rhs) {\n        ModInt inv = to_inv().count(rhs.x)\
    \ ? to_inv()[rhs.x] : (to_inv()[rhs.x] = pow(rhs, mod() - 2).x);\n        return\
    \ *this *= inv;\n    }\n    ModInt operator-() const { return -x < 0 ? mod() -\
    \ x : -x; }\n    ModInt operator+(ModInt rhs) const { return ModInt(*this) +=\
    \ rhs; }\n    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs;\
    \ }\n    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }\n\
    \    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }\n   \
    \ bool operator==(ModInt rhs) const { return x == rhs.x; }\n    bool operator!=(ModInt\
    \ rhs) const { return x != rhs.x; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ s, ModInt<Mod> a) { return s << a.x; }\n    friend std::istream& operator>>(std::istream&\
    \ s, ModInt<Mod>& a) {\n        long long tmp;\n        s >> tmp;\n        a =\
    \ ModInt<Mod>(tmp);\n        return s;\n    }\n    friend std::string to_string(ModInt<Mod>\
    \ a) { return std::to_string(a.x); }\n};\n\n#ifndef CALL_FROM_TEST\nusing mint\
    \ = ModInt<1000000007>;\n#endif\n#line 20 \"test/yukicoder/1073_matrix_static.test.cpp\"\
    \n#undef CALL_FROM_TEST\nusing mint = ModInt<1000000007>;\n\nsigned main() {\n\
    \    Int n;\n    std::cin >> n;\n    std::array<mint, 6> x{};\n    x[0] = 1;\n\
    \    Matrix<mint, 6> A{};\n    REP(j, 6) A[0][j] = mint(1) / 6;\n    REP(i, 1,\
    \ 6) A[i][i - 1] = 1;\n    auto ret = pow(A, n, Matrix<mint, 6>::eye()) * x;\n\
    \    std::cout << ret[0] << std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1073\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Sat Jun  6 01:52:00 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#include \"../../src/Math/MatrixStatic.hpp\"\n#include\
    \ \"../../src/Math/ModInt.hpp\"\n#undef CALL_FROM_TEST\nusing mint = ModInt<1000000007>;\n\
    \nsigned main() {\n    Int n;\n    std::cin >> n;\n    std::array<mint, 6> x{};\n\
    \    x[0] = 1;\n    Matrix<mint, 6> A{};\n    REP(j, 6) A[0][j] = mint(1) / 6;\n\
    \    REP(i, 1, 6) A[i][i - 1] = 1;\n    auto ret = pow(A, n, Matrix<mint, 6>::eye())\
    \ * x;\n    std::cout << ret[0] << std::endl;\n}\n"
  dependsOn:
  - src/Math/MatrixStatic.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yukicoder/1073_matrix_static.test.cpp
  requiredBy: []
  timestamp: '2020-08-29 04:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/1073_matrix_static.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1073_matrix_static.test.cpp
- /verify/test/yukicoder/1073_matrix_static.test.cpp.html
title: test/yukicoder/1073_matrix_static.test.cpp
---
