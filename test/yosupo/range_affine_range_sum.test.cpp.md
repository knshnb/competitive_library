---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/LazySegmentTree.hpp
    title: src/DataStructure/LazySegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: src/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef _MY_DEBUG\n#define dump(...)\n#endif  // clang-format\
    \ on\n\n/**\n *    author:  knshnb\n *    created: Mon Mar 30 21:14:19 JST 2020\n\
    \ **/\n\n#define CALL_FROM_TEST\n#line 1 \"src/Math/ModInt.hpp\"\ntemplate <class\
    \ T> T pow(T x, long long n, const T UNION = 1) {\n    T ret = UNION;\n    while\
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
    \ = ModInt<1000000007>;\n#endif\n#line 1 \"src/DataStructure/LazySegmentTree.hpp\"\
    \n/// @docs src/DataStructure/LazySegmentTree.md\ntemplate <class T0, class T1,\
    \ class F0, class F1, class G, class P> class LazySegmentTree {\n    // k\u756A\
    \u76EE\u306E\u30CE\u30FC\u30C9\u306B\u306Elazy\u3092\u4F1D\u642C\n    void eval(int\
    \ k, int len) {\n        // \u5B9A\u6570\u500D\u9AD8\u901F\u5316\n        if (lazy[k]\
    \ == u1) return;\n        // len\u500B\u5206\u306Elazy[k]\u3092\u8A55\u4FA1\n\
    \        node[k] = g(node[k], p(lazy[k], len));\n        if (k < N - 1) {\n  \
    \          // \u6700\u4E0B\u6BB5\u3067\u306A\u3051\u308C\u3070\u4E0B\u306Elazy\u306B\
    \u4F1D\u642C\n            lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);\n  \
    \          lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);\n        }\n      \
    \  lazy[k] = u1;\n    }\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9[l, r)\u306B\
    \u3064\u3044\u3066\u3001[a, b)\u306E\u7BC4\u56F2\u5185\u306Bx\u3092\u4F5C\u7528\
    \n    void update(int a, int b, T1 x, int k, int l, int r) {\n        eval(k,\
    \ r - l);\n        if (b <= l || r <= a) return;\n        if (a <= l && r <= b)\
    \ {\n            lazy[k] = f1(lazy[k], x);\n            eval(k, r - l);\n    \
    \    } else {\n            update(a, b, x, 2 * k + 1, l, (l + r) / 2);\n     \
    \       update(a, b, x, 2 * k + 2, (l + r) / 2, r);\n            node[k] = f0(node[2\
    \ * k + 1], node[2 * k + 2]);\n        }\n    }\n    // k\u756A\u76EE\u306E\u30CE\
    \u30FC\u30C9[l, r)\u306B\u3064\u3044\u3066\u3001[a, b)\u306E\u30AF\u30A8\u30EA\
    \u3092\u6C42\u3081\u308B\n    T0 query(int a, int b, int k, int l, int r) {\n\
    \        if (r <= a || b <= l) return u0;\n        eval(k, r - l);\n        if\
    \ (a <= l && r <= b) return node[k];\n        T0 vl = query(a, b, 2 * k + 1, l,\
    \ (l + r) / 2);\n        T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n   \
    \     return f0(vl, vr);\n    }\n\npublic:\n    int sz;  // \u5143\u306E\u914D\
    \u5217\u306E\u30B5\u30A4\u30BA\n    int N;\n    std::vector<T0> node;\n    std::vector<T1>\
    \ lazy;\n    // T0\u4E0A\u306E\u6F14\u7B97\u3001\u5358\u4F4D\u5143\n    const\
    \ F0 f0;\n    const T0 u0;\n    // T1\u4E0A\u306E\u6F14\u7B97\u3001\u5358\u4F4D\
    \u5143\n    const F1 f1;\n    const T1 u1;\n    // T0\u306B\u5BFE\u3059\u308B\
    T1\u306E\u4F5C\u7528\n    const G g;\n    // \u591A\u6570\u306Et1(T1)\u306B\u5BFE\
    \u3059\u308Bf1\u306E\u5408\u6210\n    const P p;\n\n    LazySegmentTree(F0 f0_,\
    \ T0 u0_, F1 f1_, T1 u1_, G g_, P p_) : f0(f0_), u0(u0_), f1(f1_), u1(u1_), g(g_),\
    \ p(p_) {}\n    void set_by_vector(const std::vector<T0>& a) {\n        sz = a.size();\n\
    \        for (N = 1; N < sz; N *= 2)\n            ;\n        node.resize(2 * N\
    \ - 1, u0);\n        lazy.resize(2 * N - 1, u1);\n        for (int i = 0; i <\
    \ sz; i++) node[N - 1 + i] = a[i];\n        for (int i = N - 2; i >= 0; i--) node[i]\
    \ = f0(node[2 * i + 1], node[2 * i + 2]);\n    }\n    void set_by_unit(int n)\
    \ {\n        sz = n;\n        for (N = 1; N < sz; N *= 2)\n            ;\n   \
    \     node.resize(2 * N - 1, u0);\n        lazy.resize(2 * N - 1, u1);\n    }\n\
    \    // [a, b)\u306Bx\u3092\u4F5C\u7528\n    void update(int a, int b, T1 x) {\n\
    \        assert(0 <= a && a < b && b <= sz);\n        update(a, b, x, 0, 0, N);\n\
    \    }\n    void update(int a, T1 x) { update(a, a + 1, x); }\n    // [a, b)\n\
    \    T0 query(int a, int b) { return query(a, b, 0, 0, N); }\n    T0 query(int\
    \ a) { return query(a, a + 1); }\n    friend std::string to_string(LazySegmentTree<T0,\
    \ T1, F0, F1, G, P>& seg) {\n        for (int i = 0; i < seg.sz; i++) seg.query(i);\n\
    \        return to_string(std::vector<T0>(seg.node.begin() + (seg.N - 1), seg.node.begin()\
    \ + (seg.N - 1 + seg.sz)));\n    }\n};\ntemplate <class T0, class T1, class F0,\
    \ class F1, class G, class P>\nauto make_lazy_segment_tree(F0 f0, T0 u0, F1 f1,\
    \ T1 u1, G g, P p) {\n    return LazySegmentTree<T0, T1, F0, F1, G, P>(f0, u0,\
    \ f1, u1, g, p);\n}\n#line 20 \"test/yosupo/range_affine_range_sum.test.cpp\"\n\
    #undef CALL_FROM_TEST\n\nusing mint = ModInt<998244353>;\nusing pmm = std::pair<mint,\
    \ mint>;\nsigned main() {\n    Int n, Q;\n    std::cin >> n >> Q;\n    std::vector<mint>\
    \ a(n);\n    REP(i, n) std::cin >> a[i];\n    auto seg = make_lazy_segment_tree<mint,\
    \ pmm>(\n        std::plus<mint>(), 0,\n        [](pmm x, pmm y) -> pmm {\n  \
    \          return {x.first * y.first, x.second * y.first + y.second};\n      \
    \  },\n        {1, 0}, [](mint x, pmm y) { return y.first * x + y.second; },\n\
    \        [](pmm x, int len) -> pmm {\n            return {x.first, x.second *\
    \ len};\n        });\n    seg.set_by_vector(a);\n    REP(q, Q) {\n        Int\
    \ t, l, r;\n        std::cin >> t >> l >> r;\n        if (t == 0) {\n        \
    \    Int b, c;\n            std::cin >> b >> c;\n            seg.update(l, r,\
    \ {b, c});\n        } else {\n            std::cout << seg.query(l, r) << \"\\\
    n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Mon Mar 30 21:14:19 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Math/ModInt.hpp\"\n#include \"../../src/DataStructure/LazySegmentTree.hpp\"\
    \n#undef CALL_FROM_TEST\n\nusing mint = ModInt<998244353>;\nusing pmm = std::pair<mint,\
    \ mint>;\nsigned main() {\n    Int n, Q;\n    std::cin >> n >> Q;\n    std::vector<mint>\
    \ a(n);\n    REP(i, n) std::cin >> a[i];\n    auto seg = make_lazy_segment_tree<mint,\
    \ pmm>(\n        std::plus<mint>(), 0,\n        [](pmm x, pmm y) -> pmm {\n  \
    \          return {x.first * y.first, x.second * y.first + y.second};\n      \
    \  },\n        {1, 0}, [](mint x, pmm y) { return y.first * x + y.second; },\n\
    \        [](pmm x, int len) -> pmm {\n            return {x.first, x.second *\
    \ len};\n        });\n    seg.set_by_vector(a);\n    REP(q, Q) {\n        Int\
    \ t, l, r;\n        std::cin >> t >> l >> r;\n        if (t == 0) {\n        \
    \    Int b, c;\n            std::cin >> b >> c;\n            seg.update(l, r,\
    \ {b, c});\n        } else {\n            std::cout << seg.query(l, r) << \"\\\
    n\";\n        }\n    }\n}\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/DataStructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-08-29 04:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
