---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SparseTable.hpp
    title: src/DataStructure/SparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/staticrmq_sparse_table.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>  //\
    \ clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b, ...)\
    \ for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Mon Jul 13 00:06:28 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#line 1 \"src/DataStructure/SparseTable.hpp\"\n/// @docs\
    \ src/DataStructure/SparseTable.md\ntemplate <class T, class F> struct SparseTable\
    \ {\n    const F op;\n    std::vector<std::vector<T>> t;\n    SparseTable(F op_,\
    \ const std::vector<T>& a) : op(op_), t({a}) {\n        for (int k = 1; 1 << k\
    \ < a.size() + 1; k++) {\n            t.emplace_back(a.size() - (1 << k) + 1);\n\
    \            for (int i = 0; i < a.size() - (1 << k) + 1; i++) {\n           \
    \     t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);\n            }\n\
    \        }\n    }\n    T query(int l, int r) const {\n        assert(0 <= l &&\
    \ l < r && r <= t[0].size());\n        int k = std::__lg(r - l);\n        return\
    \ op(t[k][l], t[k][r - (1 << k)]);\n    }\n};\ntemplate <class T, class F> auto\
    \ make_sparse_table(F op, const std::vector<T>& a) { return SparseTable<T, F>(op,\
    \ a); }\n#line 19 \"test/yosupo/staticrmq_sparse_table.test.cpp\"\n#undef CALL_FROM_TEST\n\
    \nsigned main() {\n    Int n, Q;\n    std::cin >> n >> Q;\n    std::vector<Int>\
    \ a(n);\n    REP(i, n) std::cin >> a[i];\n    auto st = make_sparse_table<Int>([](Int\
    \ x, Int y) { return std::min(x, y); }, a);\n    REP(q, Q) {\n        Int l, r;\n\
    \        std::cin >> l >> r;\n        std::cout << st.query(l, r) << \"\\n\";\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define REP_(i,\
    \ a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define\
    \ REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO\
    \ { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout\
    \ << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n#define\
    \ dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n *    created:\
    \ Mon Jul 13 00:06:28 JST 2020\n **/\n\n#define CALL_FROM_TEST\n#include \"../../src/DataStructure/SparseTable.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, Q;\n    std::cin >> n >>\
    \ Q;\n    std::vector<Int> a(n);\n    REP(i, n) std::cin >> a[i];\n    auto st\
    \ = make_sparse_table<Int>([](Int x, Int y) { return std::min(x, y); }, a);\n\
    \    REP(q, Q) {\n        Int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << st.query(l, r) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/DataStructure/SparseTable.hpp
  isVerificationFile: true
  path: test/yosupo/staticrmq_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2020-07-13 00:16:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/staticrmq_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/staticrmq_sparse_table.test.cpp
- /verify/test/yosupo/staticrmq_sparse_table.test.cpp.html
title: test/yosupo/staticrmq_sparse_table.test.cpp
---
