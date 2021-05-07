---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D_runtime.test.cpp
    title: test/aoj/DPL_5_D_runtime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1073.test.cpp
    title: test/yukicoder/1073.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1073_matrix_static.test.cpp
    title: test/yukicoder/1073_matrix_static.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Math/ModInt.md
    links: []
  bundledCode: "#line 1 \"src/Math/ModInt.hpp\"\ntemplate <class T> T pow(T x, long\
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
    \ rhs) const { return x != rhs.x; }\n\n    // \u8A08\u7B97\u7D50\u679C\u3092map\u306B\
    \u4FDD\u5B58\u3059\u308B\u3079\u304D\u4E57\n    ModInt save_pow(int n) const {\n\
    \        static std::map<std::pair<int, int>, int> tbl_pow;\n        if (tbl_pow.count({x,\
    \ n})) return tbl_pow[{x, n}];\n        if (n == 0) return 1;\n        if (n %\
    \ 2) return tbl_pow[{x, n}] = (*this * save_pow(n - 1)).x;\n        return tbl_pow[{x,\
    \ n}] = (save_pow(n / 2) * save_pow(n / 2)).x;\n    }\n    // 1 + r + r^2 + ...\
    \ + r^(n-1)\u3092\u9006\u5143\u304C\u306A\u3044\uFF08mod\u304C\u7D20\u6570\u3067\
    \u306A\u3044\uFF09\u5834\u5408\u306B\u8A08\u7B97\n    static ModInt geometric_progression(ModInt\
    \ r, int n) {\n        if (n == 0) return 0;\n        if (n % 2) return geometric_progression(r,\
    \ n - 1) + r.save_pow(n - 1);\n        return geometric_progression(r, n / 2)\
    \ * (r.save_pow(n / 2) + 1);\n    }\n    // a + r * (a - d) + r^2 * (a - 2d) +\
    \ ... + r^(n-1) * (a - (n - 1)d)\n    static ModInt linear_sum(ModInt r, ModInt\
    \ a, ModInt d, int n) {\n        if (n == 0) return 0;\n        if (n % 2) return\
    \ linear_sum(r, a, d, n - 1) + r.save_pow(n - 1) * (a - d * (n - 1));\n      \
    \  return linear_sum(r, a, d, n / 2) * (r.save_pow(n / 2) + 1) -\n           \
    \    d * (n / 2) * r.save_pow(n / 2) * geometric_progression(r, n / 2);\n    }\n\
    \n    friend std::ostream& operator<<(std::ostream& s, ModInt<Mod> a) { return\
    \ s << a.x; }\n    friend std::istream& operator>>(std::istream& s, ModInt<Mod>&\
    \ a) {\n        long long tmp;\n        s >> tmp;\n        a = ModInt<Mod>(tmp);\n\
    \        return s;\n    }\n    friend std::string to_string(ModInt<Mod> a) { return\
    \ std::to_string(a.x); }\n};\n\n#ifndef CALL_FROM_TEST\nusing mint = ModInt<1000000007>;\n\
    #endif\n"
  code: "template <class T> T pow(T x, long long n, const T UNION = 1) {\n    T ret\
    \ = UNION;\n    while (n) {\n        if (n & 1) ret *= x;\n        x *= x;\n \
    \       n >>= 1;\n    }\n    return ret;\n}\n\n/// @docs src/Math/ModInt.md\n\
    template <int Mod> struct ModInt {\n    int x;\n    static int& runtime_mod()\
    \ {\n        static int runtime_mod_;\n        return runtime_mod_;\n    }\n \
    \   // \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u304C\u8CA0\u306E\u3068\
    \u304D\u306F\u5B9F\u884C\u6642ModInt\n    static constexpr int mod() { return\
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
    \ = ModInt<1000000007>;\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModInt.hpp
  requiredBy: []
  timestamp: '2021-03-05 23:09:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_A.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_D_runtime.test.cpp
  - test/yukicoder/1073_matrix_static.test.cpp
  - test/yukicoder/1073.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
documentation_of: src/Math/ModInt.hpp
layout: document
redirect_from:
- /library/src/Math/ModInt.hpp
- /library/src/Math/ModInt.hpp.html
title: src/Math/ModInt.hpp
---
## 概要
modにおける四則演算クラス。
テンプレート引数`Mod`が負のとき、modは実行時に指定したものになる。

加算O(1)、減算O(1)、乗算O(1)、除算O(log mod)。
除算はフェルマーの小定理を用いているので、modが素数でないときは使えないことに注意(そもそも逆元が存在しない)。
