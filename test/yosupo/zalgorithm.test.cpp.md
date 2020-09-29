---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/String/ZAlgorithm.hpp
    title: src/String/ZAlgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Mon Apr  6 23:56:02 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/String/ZAlgorithm.hpp\"\n/// @docs src/String/ZAlgorithm.md\ntemplate\
    \ <class T> std::vector<int> Z_algorithm(const T& s) {\n    std::vector<int> a(s.size());\n\
    \    for (int i = 1, rm_idx = 0; i < s.size(); i++) {\n        if (a[i - rm_idx]\
    \ < a[rm_idx] - (i - rm_idx)) {\n            a[i] = a[i - rm_idx];\n        }\
    \ else {\n            a[i] = std::max(0, a[rm_idx] - (i - rm_idx));\n        \
    \    while (i + a[i] < s.size() && s[a[i]] == s[i + a[i]]) a[i]++;\n         \
    \   rm_idx = i;\n        }\n    }\n    a[0] = s.size();\n    return a;\n}\n#line\
    \ 19 \"test/yosupo/zalgorithm.test.cpp\"\n#undef CALL_FROM_TEST\n\nsigned main()\
    \ {\n    std::string s;\n    std::cin >> s;\n    std::vector<int> a = Z_algorithm(s);\n\
    \    for (int x : a) std::cout << x << \" \";\n    std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define REP_(i,\
    \ a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define\
    \ REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO\
    \ { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout\
    \ << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n#define\
    \ dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n *    created:\
    \ Mon Apr  6 23:56:02 JST 2020\n **/\n\n#define CALL_FROM_TEST\n#include \"../../src/String/ZAlgorithm.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    std::string s;\n    std::cin >>\
    \ s;\n    std::vector<int> a = Z_algorithm(s);\n    for (int x : a) std::cout\
    \ << x << \" \";\n    std::cout << std::endl;\n}\n"
  dependsOn:
  - src/String/ZAlgorithm.hpp
  isVerificationFile: true
  path: test/yosupo/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2020-04-07 02:27:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/zalgorithm.test.cpp
- /verify/test/yosupo/zalgorithm.test.cpp.html
title: test/yosupo/zalgorithm.test.cpp
---
