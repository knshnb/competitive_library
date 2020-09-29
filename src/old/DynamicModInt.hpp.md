---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/DynamicModInt.hpp\"\ntemplate <class T> T pow(T\
    \ x, int n, const T UNION = 1) {\n    T ret = UNION;\n    while (n) {\n      \
    \  if (n & 1) ret *= x;\n        x *= x;\n        n >>= 1;\n    }\n    return\
    \ ret;\n}\n\n// ModInt::set_mod(m)\u3057\u3066\u304B\u3089\u4F7F\u3046\nstruct\
    \ ModInt {\n    static int MD;\n    static map<pair<int, int>, int> tbl_pow;\n\
    \    static void set_mod(int mod) {\n        MD = mod;\n        tbl_pow.clear();\n\
    \    }\n    int x;\n    ModInt() : x(0) {}\n    ModInt(int x_) {\n        if ((x\
    \ = x_ % MD + MD) >= MD) x -= MD;\n    }\n\n    ModInt& operator+=(ModInt that)\
    \ {\n        if ((x += that.x) >= MD) x -= MD;\n        return *this;\n    }\n\
    \    ModInt& operator*=(ModInt that) {\n        x = (unsigned long long)x * that.x\
    \ % MD;\n        return *this;\n    }\n    ModInt& operator-=(ModInt that) {\n\
    \        if ((x -= that.x) < 0) x += MD;\n        return *this;\n    }\n    ModInt&\
    \ operator/=(ModInt that) {\n        x = (unsigned long long)x * that.inv().x\
    \ % MD;\n        return *this;\n    }\n\n    ModInt operator-() const { return\
    \ -x < 0 ? MD - x : -x; }\n    ModInt operator+(ModInt that) const { return ModInt(*this)\
    \ += that; }\n    ModInt operator*(ModInt that) const { return ModInt(*this) *=\
    \ that; }\n    ModInt operator-(ModInt that) const { return ModInt(*this) -= that;\
    \ }\n    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }\n\
    \    bool operator==(ModInt that) const { return x == that.x; }\n    bool operator!=(ModInt\
    \ that) const { return x != that.x; }\n    ModInt inv() const { return pow(*this,\
    \ MD - 2); }\n    friend ostream& operator<<(ostream& s, ModInt a) {\n       \
    \ s << a.x;\n        return s;\n    }\n    friend istream& operator>>(istream&\
    \ s, ModInt& a) {\n        s >> a.x;\n        return s;\n    }\n\n    // \u8A08\
    \u7B97\u7D50\u679C\u3092map\u306B\u4FDD\u5B58\u3059\u308B\u3079\u304D\u4E57\n\
    \    ModInt save_pow(int n) const {\n        if (tbl_pow.count({x, n})) return\
    \ tbl_pow[{x, n}];\n        if (n == 0) return 1;\n        if (n % 2) return tbl_pow[{x,\
    \ n}] = (*this * save_pow(n - 1)).x;\n        return tbl_pow[{x, n}] = (save_pow(n\
    \ / 2) * save_pow(n / 2)).x;\n    }\n    // 1 + r + r^2 + ... + r^(n-1)\n    static\
    \ ModInt geometric_progression(ModInt r, int n) {\n        if (n == 0) return\
    \ 0;\n        if (n % 2) return geometric_progression(r, n - 1) + r.save_pow(n\
    \ - 1);\n        return geometric_progression(r, n / 2) * (r.save_pow(n / 2) +\
    \ 1);\n    }\n    // a + r * (a - d) + r^2 * (a - 2d) + ... + r^(n-1) * (a - (n\
    \ - 1)d)\n    static ModInt linear_sum(ModInt r, ModInt a, ModInt d, int n) {\n\
    \        if (n == 0) return 0;\n        if (n % 2) return linear_sum(r, a, d,\
    \ n - 1) + r.save_pow(n - 1) * (a - d * (n - 1));\n        return linear_sum(r,\
    \ a, d, n / 2) * (r.save_pow(n / 2) + 1) -\n               d * (n / 2) * r.save_pow(n\
    \ / 2) * geometric_progression(r, n / 2);\n    }\n};\nint ModInt::MD = 1000000007;\n\
    using mint = ModInt;\nmap<pair<int, int>, int> mint::tbl_pow;\n\nvector<mint>\
    \ fact, fact_inv;\nvoid init_factorial(int n) {\n    fact = vector<mint>(n + 1,\
    \ 1);\n    fact_inv = vector<mint>(n + 1);\n    for (int i = 0; i < n; i++) fact[i\
    \ + 1] = fact[i] * (i + 1);\n    fact_inv[n] = mint(1) / fact[n];\n    for (int\
    \ i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);\n    // for\
    \ (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);\n}\nmint comb(int\
    \ n, int r) { return fact[n] * fact_inv[r] * fact_inv[n - r]; }\n"
  code: "template <class T> T pow(T x, int n, const T UNION = 1) {\n    T ret = UNION;\n\
    \    while (n) {\n        if (n & 1) ret *= x;\n        x *= x;\n        n >>=\
    \ 1;\n    }\n    return ret;\n}\n\n// ModInt::set_mod(m)\u3057\u3066\u304B\u3089\
    \u4F7F\u3046\nstruct ModInt {\n    static int MD;\n    static map<pair<int, int>,\
    \ int> tbl_pow;\n    static void set_mod(int mod) {\n        MD = mod;\n     \
    \   tbl_pow.clear();\n    }\n    int x;\n    ModInt() : x(0) {}\n    ModInt(int\
    \ x_) {\n        if ((x = x_ % MD + MD) >= MD) x -= MD;\n    }\n\n    ModInt&\
    \ operator+=(ModInt that) {\n        if ((x += that.x) >= MD) x -= MD;\n     \
    \   return *this;\n    }\n    ModInt& operator*=(ModInt that) {\n        x = (unsigned\
    \ long long)x * that.x % MD;\n        return *this;\n    }\n    ModInt& operator-=(ModInt\
    \ that) {\n        if ((x -= that.x) < 0) x += MD;\n        return *this;\n  \
    \  }\n    ModInt& operator/=(ModInt that) {\n        x = (unsigned long long)x\
    \ * that.inv().x % MD;\n        return *this;\n    }\n\n    ModInt operator-()\
    \ const { return -x < 0 ? MD - x : -x; }\n    ModInt operator+(ModInt that) const\
    \ { return ModInt(*this) += that; }\n    ModInt operator*(ModInt that) const {\
    \ return ModInt(*this) *= that; }\n    ModInt operator-(ModInt that) const { return\
    \ ModInt(*this) -= that; }\n    ModInt operator/(ModInt that) const { return ModInt(*this)\
    \ /= that; }\n    bool operator==(ModInt that) const { return x == that.x; }\n\
    \    bool operator!=(ModInt that) const { return x != that.x; }\n    ModInt inv()\
    \ const { return pow(*this, MD - 2); }\n    friend ostream& operator<<(ostream&\
    \ s, ModInt a) {\n        s << a.x;\n        return s;\n    }\n    friend istream&\
    \ operator>>(istream& s, ModInt& a) {\n        s >> a.x;\n        return s;\n\
    \    }\n\n    // \u8A08\u7B97\u7D50\u679C\u3092map\u306B\u4FDD\u5B58\u3059\u308B\
    \u3079\u304D\u4E57\n    ModInt save_pow(int n) const {\n        if (tbl_pow.count({x,\
    \ n})) return tbl_pow[{x, n}];\n        if (n == 0) return 1;\n        if (n %\
    \ 2) return tbl_pow[{x, n}] = (*this * save_pow(n - 1)).x;\n        return tbl_pow[{x,\
    \ n}] = (save_pow(n / 2) * save_pow(n / 2)).x;\n    }\n    // 1 + r + r^2 + ...\
    \ + r^(n-1)\n    static ModInt geometric_progression(ModInt r, int n) {\n    \
    \    if (n == 0) return 0;\n        if (n % 2) return geometric_progression(r,\
    \ n - 1) + r.save_pow(n - 1);\n        return geometric_progression(r, n / 2)\
    \ * (r.save_pow(n / 2) + 1);\n    }\n    // a + r * (a - d) + r^2 * (a - 2d) +\
    \ ... + r^(n-1) * (a - (n - 1)d)\n    static ModInt linear_sum(ModInt r, ModInt\
    \ a, ModInt d, int n) {\n        if (n == 0) return 0;\n        if (n % 2) return\
    \ linear_sum(r, a, d, n - 1) + r.save_pow(n - 1) * (a - d * (n - 1));\n      \
    \  return linear_sum(r, a, d, n / 2) * (r.save_pow(n / 2) + 1) -\n           \
    \    d * (n / 2) * r.save_pow(n / 2) * geometric_progression(r, n / 2);\n    }\n\
    };\nint ModInt::MD = 1000000007;\nusing mint = ModInt;\nmap<pair<int, int>, int>\
    \ mint::tbl_pow;\n\nvector<mint> fact, fact_inv;\nvoid init_factorial(int n) {\n\
    \    fact = vector<mint>(n + 1, 1);\n    fact_inv = vector<mint>(n + 1);\n   \
    \ for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);\n    fact_inv[n]\
    \ = mint(1) / fact[n];\n    for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i\
    \ + 1] * (i + 1);\n    // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i]\
    \ == 1);\n}\nmint comb(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n\
    \ - r]; }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/DynamicModInt.hpp
  requiredBy: []
  timestamp: '2020-04-05 18:01:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/DynamicModInt.hpp
layout: document
redirect_from:
- /library/src/old/DynamicModInt.hpp
- /library/src/old/DynamicModInt.hpp.html
title: src/old/DynamicModInt.hpp
---
