---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: src/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
  bundledCode: "#line 1 \"test/aoj/DPL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Apr 12 16:26:37 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Math/ModInt.hpp\"\ntemplate <class T> T pow(T x, long long n, const\
    \ T UNION = 1) {\n    T ret = UNION;\n    while (n) {\n        if (n & 1) ret\
    \ *= x;\n        x *= x;\n        n >>= 1;\n    }\n    return ret;\n}\n\n/// @docs\
    \ src/Math/ModInt.md\ntemplate <int Mod> struct ModInt {\n    int x;\n    static\
    \ int& runtime_mod() {\n        static int runtime_mod_;\n        return runtime_mod_;\n\
    \    }\n    // \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u304C\u8CA0\u306E\
    \u3068\u304D\u306F\u5B9F\u884C\u6642ModInt\n    static constexpr int mod() { return\
    \ Mod < 0 ? runtime_mod() : Mod; }\n    static std::unordered_map<int, int>& to_inv()\
    \ {\n        static std::unordered_map<int, int> to_inv_;\n        return to_inv_;\n\
    \    }\n    static void set_runtime_mod(int mod) {\n        static_assert(Mod\
    \ < 0, \"template parameter Mod must be negative for runtime ModInt\");\n    \
    \    runtime_mod() = mod, to_inv().clear();\n    }\n    ModInt() : x(0) {}\n \
    \   ModInt(long long x_) {\n        if ((x = x_ % mod() + mod()) >= mod()) x -=\
    \ mod();\n    }\n\n    ModInt& operator+=(ModInt rhs) {\n        if ((x += rhs.x)\
    \ >= mod()) x -= mod();\n        return *this;\n    }\n    ModInt& operator*=(ModInt\
    \ rhs) {\n        x = (unsigned long long)x * rhs.x % mod();\n        return *this;\n\
    \    }\n    ModInt& operator-=(ModInt rhs) {\n        if ((x -= rhs.x) < 0) x\
    \ += mod();\n        return *this;\n    }\n    ModInt& operator/=(ModInt rhs)\
    \ {\n        ModInt inv = to_inv().count(rhs.x) ? to_inv()[rhs.x] : (to_inv()[rhs.x]\
    \ = pow(rhs, mod() - 2).x);\n        return *this *= inv;\n    }\n    ModInt operator-()\
    \ const { return -x < 0 ? mod() - x : -x; }\n    ModInt operator+(ModInt rhs)\
    \ const { return ModInt(*this) += rhs; }\n    ModInt operator*(ModInt rhs) const\
    \ { return ModInt(*this) *= rhs; }\n    ModInt operator-(ModInt rhs) const { return\
    \ ModInt(*this) -= rhs; }\n    ModInt operator/(ModInt rhs) const { return ModInt(*this)\
    \ /= rhs; }\n    bool operator==(ModInt rhs) const { return x == rhs.x; }\n  \
    \  bool operator!=(ModInt rhs) const { return x != rhs.x; }\n\n    // \u8A08\u7B97\
    \u7D50\u679C\u3092map\u306B\u4FDD\u5B58\u3059\u308B\u3079\u304D\u4E57\n    ModInt\
    \ save_pow(int n) const {\n        static std::map<std::pair<int, int>, int> tbl_pow;\n\
    \        if (tbl_pow.count({x, n})) return tbl_pow[{x, n}];\n        if (n ==\
    \ 0) return 1;\n        if (n % 2) return tbl_pow[{x, n}] = (*this * save_pow(n\
    \ - 1)).x;\n        return tbl_pow[{x, n}] = (save_pow(n / 2) * save_pow(n / 2)).x;\n\
    \    }\n    // 1 + r + r^2 + ... + r^(n-1)\u3092\u9006\u5143\u304C\u306A\u3044\
    \uFF08mod\u304C\u7D20\u6570\u3067\u306A\u3044\uFF09\u5834\u5408\u306B\u8A08\u7B97\
    \n    static ModInt geometric_progression(ModInt r, int n) {\n        if (n ==\
    \ 0) return 0;\n        if (n % 2) return geometric_progression(r, n - 1) + r.save_pow(n\
    \ - 1);\n        return geometric_progression(r, n / 2) * (r.save_pow(n / 2) +\
    \ 1);\n    }\n    // a + r * (a - d) + r^2 * (a - 2d) + ... + r^(n-1) * (a - (n\
    \ - 1)d)\n    static ModInt linear_sum(ModInt r, ModInt a, ModInt d, int n) {\n\
    \        if (n == 0) return 0;\n        if (n % 2) return linear_sum(r, a, d,\
    \ n - 1) + r.save_pow(n - 1) * (a - d * (n - 1));\n        return linear_sum(r,\
    \ a, d, n / 2) * (r.save_pow(n / 2) + 1) -\n               d * (n / 2) * r.save_pow(n\
    \ / 2) * geometric_progression(r, n / 2);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ s, ModInt<Mod> a) { return s << a.x; }\n    friend std::istream& operator>>(std::istream&\
    \ s, ModInt<Mod>& a) {\n        long long tmp;\n        s >> tmp;\n        a =\
    \ ModInt<Mod>(tmp);\n        return s;\n    }\n    friend std::string to_string(ModInt<Mod>\
    \ a) { return std::to_string(a.x); }\n};\n\n#ifndef CALL_FROM_TEST\nusing mint\
    \ = ModInt<1000000007>;\n#endif\n#line 19 \"test/aoj/DPL_5_A.test.cpp\"\n#undef\
    \ CALL_FROM_TEST\n\nusing mint = ModInt<1000000007>;\nsigned main() {\n    Int\
    \ n, k;\n    std::cin >> n >> k;\n    std::cout << pow(mint(k), n) << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Apr 12 16:26:37 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Math/ModInt.hpp\"\n#undef CALL_FROM_TEST\n\nusing mint =\
    \ ModInt<1000000007>;\nsigned main() {\n    Int n, k;\n    std::cin >> n >> k;\n\
    \    std::cout << pow(mint(k), n) << std::endl;\n}\n"
  dependsOn:
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_A.test.cpp
  requiredBy: []
  timestamp: '2021-03-05 23:09:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_A.test.cpp
- /verify/test/aoj/DPL_5_A.test.cpp.html
title: test/aoj/DPL_5_A.test.cpp
---
