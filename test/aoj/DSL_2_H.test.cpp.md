---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/LazySegmentTree.hpp
    title: src/DataStructure/LazySegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"test/aoj/DSL_2_H.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sat Mar 21 19:52:09 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/DataStructure/LazySegmentTree.hpp\"\n/// @docs src/DataStructure/LazySegmentTree.md\n\
    template <class T0, class T1, class F0, class F1, class G, class P> class LazySegmentTree\
    \ {\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306B\u306Elazy\u3092\u4F1D\u642C\
    \n    void eval(int k, int len) {\n        // \u5B9A\u6570\u500D\u9AD8\u901F\u5316\
    \n        if (lazy[k] == u1) return;\n        // len\u500B\u5206\u306Elazy[k]\u3092\
    \u8A55\u4FA1\n        node[k] = g(node[k], p(lazy[k], len));\n        if (k <\
    \ N - 1) {\n            // \u6700\u4E0B\u6BB5\u3067\u306A\u3051\u308C\u3070\u4E0B\
    \u306Elazy\u306B\u4F1D\u642C\n            lazy[2 * k + 1] = f1(lazy[2 * k + 1],\
    \ lazy[k]);\n            lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);\n   \
    \     }\n        lazy[k] = u1;\n    }\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\
    [l, r)\u306B\u3064\u3044\u3066\u3001[a, b)\u306E\u7BC4\u56F2\u5185\u306Bx\u3092\
    \u4F5C\u7528\n    void update(int a, int b, T1 x, int k, int l, int r) {\n   \
    \     eval(k, r - l);\n        if (b <= l || r <= a) return;\n        if (a <=\
    \ l && r <= b) {\n            lazy[k] = f1(lazy[k], x);\n            eval(k, r\
    \ - l);\n        } else {\n            update(a, b, x, 2 * k + 1, l, (l + r) /\
    \ 2);\n            update(a, b, x, 2 * k + 2, (l + r) / 2, r);\n            node[k]\
    \ = f0(node[2 * k + 1], node[2 * k + 2]);\n        }\n    }\n    // k\u756A\u76EE\
    \u306E\u30CE\u30FC\u30C9[l, r)\u306B\u3064\u3044\u3066\u3001[a, b)\u306E\u30AF\
    \u30A8\u30EA\u3092\u6C42\u3081\u308B\n    T0 query(int a, int b, int k, int l,\
    \ int r) {\n        if (r <= a || b <= l) return u0;\n        eval(k, r - l);\n\
    \        if (a <= l && r <= b) return node[k];\n        T0 vl = query(a, b, 2\
    \ * k + 1, l, (l + r) / 2);\n        T0 vr = query(a, b, 2 * k + 2, (l + r) /\
    \ 2, r);\n        return f0(vl, vr);\n    }\n\npublic:\n    int sz;  // \u5143\
    \u306E\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    int N;\n    std::vector<T0> node;\n\
    \    std::vector<T1> lazy;\n    // T0\u4E0A\u306E\u6F14\u7B97\u3001\u5358\u4F4D\
    \u5143\n    const F0 f0;\n    const T0 u0;\n    // T1\u4E0A\u306E\u6F14\u7B97\u3001\
    \u5358\u4F4D\u5143\n    const F1 f1;\n    const T1 u1;\n    // T0\u306B\u5BFE\u3059\
    \u308BT1\u306E\u4F5C\u7528\n    const G g;\n    // \u591A\u6570\u306Et1(T1)\u306B\
    \u5BFE\u3059\u308Bf1\u306E\u5408\u6210\n    const P p;\n\n    LazySegmentTree(F0\
    \ f0_, T0 u0_, F1 f1_, T1 u1_, G g_, P p_) : f0(f0_), u0(u0_), f1(f1_), u1(u1_),\
    \ g(g_), p(p_) {}\n    void set_by_vector(const std::vector<T0>& a) {\n      \
    \  sz = a.size();\n        for (N = 1; N < sz; N *= 2)\n            ;\n      \
    \  node.resize(2 * N - 1, u0);\n        lazy.resize(2 * N - 1, u1);\n        for\
    \ (int i = 0; i < sz; i++) node[N - 1 + i] = a[i];\n        for (int i = N - 2;\
    \ i >= 0; i--) node[i] = f0(node[2 * i + 1], node[2 * i + 2]);\n    }\n    void\
    \ set_by_unit(int n) {\n        sz = n;\n        for (N = 1; N < sz; N *= 2)\n\
    \            ;\n        node.resize(2 * N - 1, u0);\n        lazy.resize(2 * N\
    \ - 1, u1);\n    }\n    // [a, b)\u306Bx\u3092\u4F5C\u7528\n    void update(int\
    \ a, int b, T1 x) {\n        assert(0 <= a && a < b && b <= sz);\n        update(a,\
    \ b, x, 0, 0, N);\n    }\n    void update(int a, T1 x) { update(a, a + 1, x);\
    \ }\n    // [a, b)\n    T0 query(int a, int b) { return query(a, b, 0, 0, N);\
    \ }\n    T0 query(int a) { return query(a, a + 1); }\n    friend std::string to_string(LazySegmentTree<T0,\
    \ T1, F0, F1, G, P>& seg) {\n        for (int i = 0; i < seg.sz; i++) seg.query(i);\n\
    \        return to_string(std::vector<T0>(seg.node.begin() + (seg.N - 1), seg.node.begin()\
    \ + (seg.N - 1 + seg.sz)));\n    }\n};\ntemplate <class T0, class T1, class F0,\
    \ class F1, class G, class P>\nauto make_lazy_segment_tree(F0 f0, T0 u0, F1 f1,\
    \ T1 u1, G g, P p) {\n    return LazySegmentTree<T0, T1, F0, F1, G, P>(f0, u0,\
    \ f1, u1, g, p);\n}\n#line 19 \"test/aoj/DSL_2_H.test.cpp\"\n#undef CALL_FROM_TEST\n\
    \nconst Int INF = 1e9;\nsigned main() {\n    int n, Q;\n    std::cin >> n >> Q;\n\
    \    auto seg = make_lazy_segment_tree<Int, Int>(\n        [](Int x, Int y) {\
    \ return std::min(x, y); }, INF, [](Int x, Int y) { return x + y; }, 0,\n    \
    \    [](Int x, Int y) { return x == INF ? x : x + y; }, [](Int x, int len) { return\
    \ x; });\n    seg.set_by_vector(std::vector<Int>(n));\n    REP(q, Q) {\n     \
    \   int c, s, t;\n        std::cin >> c >> s >> t;\n        t++;\n        if (c\
    \ == 0) {\n            Int x;\n            std::cin >> x;\n            seg.update(s,\
    \ t, x);\n        } else {\n            std::cout << seg.query(s, t) << std::endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sat Mar 21 19:52:09 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/DataStructure/LazySegmentTree.hpp\"\n#undef CALL_FROM_TEST\n\
    \nconst Int INF = 1e9;\nsigned main() {\n    int n, Q;\n    std::cin >> n >> Q;\n\
    \    auto seg = make_lazy_segment_tree<Int, Int>(\n        [](Int x, Int y) {\
    \ return std::min(x, y); }, INF, [](Int x, Int y) { return x + y; }, 0,\n    \
    \    [](Int x, Int y) { return x == INF ? x : x + y; }, [](Int x, int len) { return\
    \ x; });\n    seg.set_by_vector(std::vector<Int>(n));\n    REP(q, Q) {\n     \
    \   int c, s, t;\n        std::cin >> c >> s >> t;\n        t++;\n        if (c\
    \ == 0) {\n            Int x;\n            std::cin >> x;\n            seg.update(s,\
    \ t, x);\n        } else {\n            std::cout << seg.query(s, t) << std::endl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - src/DataStructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_H.test.cpp
  requiredBy: []
  timestamp: '2020-04-03 22:30:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_H.test.cpp
- /verify/test/aoj/DSL_2_H.test.cpp.html
title: test/aoj/DSL_2_H.test.cpp
---
