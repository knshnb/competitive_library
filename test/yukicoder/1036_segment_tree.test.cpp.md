---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree.hpp
    title: src/DataStructure/SegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1036
    links:
    - https://yukicoder.me/problems/no/1036
  bundledCode: "#line 1 \"test/yukicoder/1036_segment_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1036\"\n\n#include <bits/stdc++.h>  // clang-format\
    \ off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b, ...) for (Int i =\
    \ (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i, __VA_ARGS__,\
    \ __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef _MY_DEBUG\n#define dump(...)\n#endif  // clang-format\
    \ on\n\n/**\n *    author:  knshnb\n *    created: Sat Apr 25 22:22:21 JST 2020\n\
    \ **/\n\n#define CALL_FROM_TEST\n#line 1 \"src/DataStructure/SegmentTree.hpp\"\
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
    \ SegmentTree<T, F>(op, e); }\n#line 19 \"test/yukicoder/1036_segment_tree.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n;\n    std::cin >> n;\n \
    \   std::vector<Int> a(n);\n    REP(i, n) std::cin >> a[i];\n    auto seg = make_segment_tree<Int>([](Int\
    \ x, Int y) { return std::gcd(x, y); }, 0);\n    seg.set_by_vector(a);\n    Int\
    \ ans = 0, j = 0;\n    REP(i, n) {\n        j = std::max(i, j);\n        Int acc\
    \ = seg.query(i, j);\n        while (j < n && (acc = std::gcd(acc, a[j])) != 1)\
    \ {\n            j++;\n        }\n        ans += n - j;\n    }\n    std::cout\
    \ << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1036\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef _MY_DEBUG\n#define dump(...)\n#endif  // clang-format\
    \ on\n\n/**\n *    author:  knshnb\n *    created: Sat Apr 25 22:22:21 JST 2020\n\
    \ **/\n\n#define CALL_FROM_TEST\n#include \"../../src/DataStructure/SegmentTree.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n;\n    std::cin >> n;\n \
    \   std::vector<Int> a(n);\n    REP(i, n) std::cin >> a[i];\n    auto seg = make_segment_tree<Int>([](Int\
    \ x, Int y) { return std::gcd(x, y); }, 0);\n    seg.set_by_vector(a);\n    Int\
    \ ans = 0, j = 0;\n    REP(i, n) {\n        j = std::max(i, j);\n        Int acc\
    \ = seg.query(i, j);\n        while (j < n && (acc = std::gcd(acc, a[j])) != 1)\
    \ {\n            j++;\n        }\n        ans += n - j;\n    }\n    std::cout\
    \ << ans << std::endl;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: test/yukicoder/1036_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-04-27 22:57:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/1036_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1036_segment_tree.test.cpp
- /verify/test/yukicoder/1036_segment_tree.test.cpp.html
title: test/yukicoder/1036_segment_tree.test.cpp
---