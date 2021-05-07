---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: src/DataStructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Mar 29 05:04:23 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/DataStructure/UnionFind.hpp\"\nstruct UnionFind {\n    int cnt;\
    \                  // \u96C6\u5408\u306E\u6570\n    std::vector<int> number; \
    \ // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306Eindex, \u8CA0\u306E\u3068\u304D\
    \u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    UnionFind(int n) : cnt(n), number(n,\
    \ -1) {}\n    int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]);\
    \ }\n    void unite(int x, int y) {\n        x = root(x), y = root(y);\n     \
    \   if (x == y) return;\n        if (number[y] < number[x]) std::swap(x, y);\n\
    \        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        number[x] += number[y];\n\
    \        number[y] = x;\n        cnt--;\n    }\n    bool is_same(int x, int y)\
    \ { return root(x) == root(y); }\n    int size(int x) { return -number[root(x)];\
    \ }\n};\n#line 19 \"test/yosupo/unionfind.test.cpp\"\n#undef CALL_FROM_TEST\n\n\
    signed main() {\n    Int n, Q;\n    std::cin >> n >> Q;\n    UnionFind uf(n);\n\
    \    REP(q, Q) {\n        Int t, u, v;\n        std::cin >> t >> u >> v;\n   \
    \     if (t == 0) {\n            uf.unite(u, v);\n        } else {\n         \
    \   std::cout << uf.is_same(u, v) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define REP_(i,\
    \ a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define\
    \ REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO\
    \ { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout\
    \ << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n#define\
    \ dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n *    created:\
    \ Sun Mar 29 05:04:23 JST 2020\n **/\n\n#define CALL_FROM_TEST\n#include \"../../src/DataStructure/UnionFind.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, Q;\n    std::cin >> n >>\
    \ Q;\n    UnionFind uf(n);\n    REP(q, Q) {\n        Int t, u, v;\n        std::cin\
    \ >> t >> u >> v;\n        if (t == 0) {\n            uf.unite(u, v);\n      \
    \  } else {\n            std::cout << uf.is_same(u, v) << \"\\n\";\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-04-01 18:40:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind.test.cpp
- /verify/test/yosupo/unionfind.test.cpp.html
title: test/yosupo/unionfind.test.cpp
---
