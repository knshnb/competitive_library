---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/QuickFind.hpp
    title: src/DataStructure/QuickFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind_quick_find.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>  //\
    \ clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b, ...)\
    \ for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Mon Apr 27 23:29:45 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#line 1 \"src/DataStructure/QuickFind.hpp\"\n/// @docs\
    \ src/DataStructure/QuickFind.md\nstruct QuickFind {\n    std::vector<int> belong_to;\n\
    \    std::vector<std::vector<int>> groups;\n    QuickFind(int n) : belong_to(n),\
    \ groups(n, std::vector<int>(1)) {\n        std::iota(belong_to.begin(), belong_to.end(),\
    \ 0);\n        for (int i = 0; i < n; i++) groups[i][0] = i;\n    }\n    void\
    \ unite(int x, int y) {\n        x = belong_to[x], y = belong_to[y];\n       \
    \ if (x == y) return;\n        if (groups[x].size() < groups[y].size()) std::swap(x,\
    \ y);\n        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        for (int v : groups[y])\
    \ belong_to[v] = x;\n        groups[x].insert(groups[x].end(), groups[y].begin(),\
    \ groups[y].end());\n        groups[y].clear();\n    }\n    bool is_same(int x,\
    \ int y) { return belong_to[x] == belong_to[y]; }\n};\n#line 19 \"test/yosupo/unionfind_quick_find.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, Q;\n    std::cin >> n >>\
    \ Q;\n    QuickFind qf(n);\n    REP(q, Q) {\n        Int t, u, v;\n        std::cin\
    \ >> t >> u >> v;\n        if (t == 0) {\n            qf.unite(u, v);\n      \
    \  } else {\n            std::cout << qf.is_same(u, v) << \"\\n\";\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define REP_(i,\
    \ a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define\
    \ REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO\
    \ { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout\
    \ << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n#define\
    \ dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n *    created:\
    \ Mon Apr 27 23:29:45 JST 2020\n **/\n\n#define CALL_FROM_TEST\n#include \"../../src/DataStructure/QuickFind.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, Q;\n    std::cin >> n >>\
    \ Q;\n    QuickFind qf(n);\n    REP(q, Q) {\n        Int t, u, v;\n        std::cin\
    \ >> t >> u >> v;\n        if (t == 0) {\n            qf.unite(u, v);\n      \
    \  } else {\n            std::cout << qf.is_same(u, v) << \"\\n\";\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/DataStructure/QuickFind.hpp
  isVerificationFile: true
  path: test/yosupo/unionfind_quick_find.test.cpp
  requiredBy: []
  timestamp: '2020-04-27 23:52:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/unionfind_quick_find.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind_quick_find.test.cpp
- /verify/test/yosupo/unionfind_quick_find.test.cpp.html
title: test/yosupo/unionfind_quick_find.test.cpp
---
