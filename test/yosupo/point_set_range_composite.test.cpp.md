---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree.hpp
    title: src/DataStructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: src/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#include\
    \ <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define REP_(i,\
    \ a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define\
    \ REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO\
    \ { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout\
    \ << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n#define\
    \ dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n *    created:\
    \ Sun Mar 29 16:52:02 JST 2020\n **/\n\n#define CALL_FROM_TEST\n#line 1 \"src/Math/ModInt.hpp\"\
    \ntemplate <class T> T pow(T x, long long n, const T UNION = 1) {\n    T ret =\
    \ UNION;\n    while (n) {\n        if (n & 1) ret *= x;\n        x *= x;\n   \
    \     n >>= 1;\n    }\n    return ret;\n}\n\n/// @docs src/Math/ModInt.md\ntemplate\
    \ <int Mod> struct ModInt {\n    int x;\n    static int& runtime_mod() {\n   \
    \     static int runtime_mod_;\n        return runtime_mod_;\n    }\n    // \u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u304C\u8CA0\u306E\u3068\u304D\u306F\
    \u5B9F\u884C\u6642ModInt\n    static constexpr int mod() { return Mod < 0 ? runtime_mod()\
    \ : Mod; }\n    static std::unordered_map<int, int>& to_inv() {\n        static\
    \ std::unordered_map<int, int> to_inv_;\n        return to_inv_;\n    }\n    static\
    \ void set_runtime_mod(int mod) {\n        static_assert(Mod < 0, \"template parameter\
    \ Mod must be negative for runtime ModInt\");\n        runtime_mod() = mod, to_inv().clear();\n\
    \    }\n    ModInt() : x(0) {}\n    ModInt(long long x_) {\n        if ((x = x_\
    \ % mod() + mod()) >= mod()) x -= mod();\n    }\n\n    ModInt& operator+=(ModInt\
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
    \ = ModInt<1000000007>;\n#endif\n#line 1 \"src/DataStructure/SegmentTree.hpp\"\
    \n/// @docs src/DataStructure/SegmentTree.md\ntemplate <class T, class F> struct\
    \ SegmentTree {\n    const F op;\n    const T e;\n    SegmentTree(F op_, T e_)\
    \ : op(op_), e(e_) {}\n    int n;\n    std::vector<T> t;\n    void set_by_identity(int\
    \ n_) {\n        n = n_;\n        t.clear(), t.resize(2 * n, e);\n    }\n    void\
    \ set_by_vector(const std::vector<T>& a) {\n        n = a.size();\n        t.clear(),\
    \ t.resize(2 * n, e);\n        for (int i = 0; i < n; i++) t[i + n] = a[i];\n\
    \        build();\n    }\n    void build() {\n        for (int i = n - 1; i; --i)\
    \ t[i] = op(t[2 * i], t[2 * i + 1]);\n    }\n    T& operator[](int i) { return\
    \ t[i + n]; }\n    // [l, r)\n    T query(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        T resl = e, resr = e;\n        for (l +=\
    \ n, r += n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) resl = op(resl,\
    \ t[l++]);\n            if (r & 1) resr = op(t[--r], resr);\n        }\n     \
    \   return op(resl, resr);\n    }\n    // i\u756A\u76EE\u3092x\u306B\u5909\u66F4\
    \n    void update(int i, const T& x) {\n        assert(0 <= i && i < n);\n   \
    \     t[i += n] = x;\n        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);\n\
    \    }\n    // i\u756A\u76EE\u306Bx\u3092\u4F5C\u7528 (a[i] = op(a[i], x))\n \
    \   void operate(int i, const T& x) {\n        assert(0 <= i && i < n);\n    \
    \    i += n;\n        t[i] = op(t[i], x);\n        while (i >>= 1) t[i] = op(t[2\
    \ * i], t[2 * i + 1]);\n    }\n    friend std::string to_string(const SegmentTree<T,\
    \ F>& seg) {\n        return to_string(std::vector<T>(seg.t.begin() + seg.n, seg.t.end()));\n\
    \    }\n};\ntemplate <class T, class F> auto make_segment_tree(F op, T e) { return\
    \ SegmentTree<T, F>(op, e); }\n#line 20 \"test/yosupo/point_set_range_composite.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nusing mint = ModInt<998244353>;\nusing pmm = std::pair<mint,\
    \ mint>;\nsigned main() {\n    Int n, Q;\n    std::cin >> n >> Q;\n    std::vector<pmm>\
    \ a(n);\n    REP(i, n) std::cin >> a[i].first >> a[i].second;\n    auto seg =\
    \ make_segment_tree<pmm>(\n        [](pmm x, pmm y) {\n            return pmm{x.first\
    \ * y.first, y.first * x.second + y.second};\n        },\n        {1, 0});\n \
    \   seg.set_by_vector(a);\n    REP(q, Q) {\n        Int c, x, y, z;\n        std::cin\
    \ >> c >> x >> y >> z;\n        if (c == 0) {\n            seg.update(x, {y, z});\n\
    \        } else {\n            pmm tmp = seg.query(x, y);\n            std::cout\
    \ << tmp.first * z + tmp.second << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Mar 29 16:52:02 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Math/ModInt.hpp\"\n#include \"../../src/DataStructure/SegmentTree.hpp\"\
    \n#undef CALL_FROM_TEST\n\nusing mint = ModInt<998244353>;\nusing pmm = std::pair<mint,\
    \ mint>;\nsigned main() {\n    Int n, Q;\n    std::cin >> n >> Q;\n    std::vector<pmm>\
    \ a(n);\n    REP(i, n) std::cin >> a[i].first >> a[i].second;\n    auto seg =\
    \ make_segment_tree<pmm>(\n        [](pmm x, pmm y) {\n            return pmm{x.first\
    \ * y.first, y.first * x.second + y.second};\n        },\n        {1, 0});\n \
    \   seg.set_by_vector(a);\n    REP(q, Q) {\n        Int c, x, y, z;\n        std::cin\
    \ >> c >> x >> y >> z;\n        if (c == 0) {\n            seg.update(x, {y, z});\n\
    \        } else {\n            pmm tmp = seg.query(x, y);\n            std::cout\
    \ << tmp.first * z + tmp.second << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2020-08-29 04:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
