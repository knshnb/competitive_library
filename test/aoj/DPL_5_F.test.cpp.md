---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/Combination.hpp
    title: src/Math/Combination.hpp
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: src/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F
  bundledCode: "#line 1 \"test/aoj/DPL_5_F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Apr 12 17:57:28 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Math/Combination.hpp\"\ntemplate <class T> struct Combination {\n\
    \    std::vector<T> fact, fact_inv;\n    Combination(int n = 1000003) : fact(n\
    \ + 1, 1), fact_inv(n + 1) {\n        for (int i = 0; i < n; i++) fact[i + 1]\
    \ = fact[i] * (i + 1);\n        fact_inv[n] = (T)1 / fact[n];\n        for (int\
    \ i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);\n        //\
    \ for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);\n    }\n\
    \    T operator()(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n -\
    \ r]; }\n};\n#line 1 \"src/Math/ModInt.hpp\"\ntemplate <class T> T pow(T x, long\
    \ long n, const T UNION = 1) {\n    T ret = UNION;\n    while (n) {\n        if\
    \ (n & 1) ret *= x;\n        x *= x;\n        n >>= 1;\n    }\n    return ret;\n\
    }\n\n/// @docs src/Math/ModInt.md\ntemplate <int Mod> struct ModInt {\n    int\
    \ x;\n    static int& runtime_mod() {\n        static int runtime_mod_;\n    \
    \    return runtime_mod_;\n    }\n    // \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\
    \u6570\u304C\u8CA0\u306E\u3068\u304D\u306F\u5B9F\u884C\u6642ModInt\n    static\
    \ constexpr int mod() { return Mod < 0 ? runtime_mod() : Mod; }\n    static std::unordered_map<int,\
    \ int>& to_inv() {\n        static std::unordered_map<int, int> to_inv_;\n   \
    \     return to_inv_;\n    }\n    static void set_runtime_mod(int mod) {\n   \
    \     static_assert(Mod < 0, \"template parameter Mod must be negative for runtime\
    \ ModInt\");\n        runtime_mod() = mod, to_inv().clear();\n    }\n    ModInt()\
    \ : x(0) {}\n    ModInt(long long x_) {\n        if ((x = x_ % mod() + mod())\
    \ >= mod()) x -= mod();\n    }\n\n    ModInt& operator+=(ModInt rhs) {\n     \
    \   if ((x += rhs.x) >= mod()) x -= mod();\n        return *this;\n    }\n   \
    \ ModInt& operator*=(ModInt rhs) {\n        x = (unsigned long long)x * rhs.x\
    \ % mod();\n        return *this;\n    }\n    ModInt& operator-=(ModInt rhs) {\n\
    \        if ((x -= rhs.x) < 0) x += mod();\n        return *this;\n    }\n   \
    \ ModInt& operator/=(ModInt rhs) {\n        ModInt inv = to_inv().count(rhs.x)\
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
    \ = ModInt<1000000007>;\n#endif\n#line 20 \"test/aoj/DPL_5_F.test.cpp\"\n#undef\
    \ CALL_FROM_TEST\n\nusing mint = ModInt<1000000007>;\nsigned main() {\n    Int\
    \ n, k;\n    std::cin >> n >> k;\n    Combination<mint> comb(n + k - 1);\n   \
    \ std::cout << (n < k ? 0 : comb(n - 1, k - 1)) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Apr 12 17:57:28 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Math/Combination.hpp\"\n#include \"../../src/Math/ModInt.hpp\"\
    \n#undef CALL_FROM_TEST\n\nusing mint = ModInt<1000000007>;\nsigned main() {\n\
    \    Int n, k;\n    std::cin >> n >> k;\n    Combination<mint> comb(n + k - 1);\n\
    \    std::cout << (n < k ? 0 : comb(n - 1, k - 1)) << std::endl;\n}\n"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_F.test.cpp
  requiredBy: []
  timestamp: '2020-08-29 04:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_F.test.cpp
- /verify/test/aoj/DPL_5_F.test.cpp.html
title: test/aoj/DPL_5_F.test.cpp
---
