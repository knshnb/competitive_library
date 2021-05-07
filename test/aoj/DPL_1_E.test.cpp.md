---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Helper/ChminChmax.hpp
    title: src/Helper/ChminChmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/Helper/MakeVec.hpp
    title: src/Helper/MakeVec.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E
  bundledCode: "#line 1 \"test/aoj/DPL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Thu Mar 26 18:48:49 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Helper/ChminChmax.hpp\"\ntemplate <class T> bool chmin(T& a, const\
    \ T& b) { return a > b ? a = b, true : false; }\ntemplate <class T> bool chmax(T&\
    \ a, const T& b) { return a < b ? a = b, true : false; }\n#line 1 \"src/Helper/MakeVec.hpp\"\
    \ntemplate <class T, class S> T make_vec(S x) { return x; }\ntemplate <class T,\
    \ class... Ts> auto make_vec(size_t n, Ts... ts) {\n    return std::vector<decltype(make_vec<T>(ts...))>(n,\
    \ make_vec<T>(ts...));\n}\n#line 20 \"test/aoj/DPL_1_E.test.cpp\"\n#undef CALL_FROM_TEST\n\
    \nsigned main() {\n    std::string s, t;\n    std::cin >> s >> t;\n    Int n =\
    \ s.size(), m = t.size();\n    auto dp = make_vec<Int>(n + 1, m + 1, 1e9);\n \
    \   dp[0][0] = 0;\n    REP(i, n + 1) {\n        REP(j, m + 1) {\n            if\
    \ (i - 1 >= 0) chmin(dp[i][j], dp[i - 1][j] + 1);\n            if (j - 1 >= 0)\
    \ chmin(dp[i][j], dp[i][j - 1] + 1);\n            if (i - 1 >= 0 && j - 1 >= 0)\
    \ chmin(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));\n        }\n   \
    \ }\n    std::cout << dp[n][m] << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Thu Mar 26 18:48:49 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Helper/ChminChmax.hpp\"\n#include \"../../src/Helper/MakeVec.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    std::string s, t;\n    std::cin\
    \ >> s >> t;\n    Int n = s.size(), m = t.size();\n    auto dp = make_vec<Int>(n\
    \ + 1, m + 1, 1e9);\n    dp[0][0] = 0;\n    REP(i, n + 1) {\n        REP(j, m\
    \ + 1) {\n            if (i - 1 >= 0) chmin(dp[i][j], dp[i - 1][j] + 1);\n   \
    \         if (j - 1 >= 0) chmin(dp[i][j], dp[i][j - 1] + 1);\n            if (i\
    \ - 1 >= 0 && j - 1 >= 0) chmin(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j\
    \ - 1]));\n        }\n    }\n    std::cout << dp[n][m] << std::endl;\n}\n"
  dependsOn:
  - src/Helper/ChminChmax.hpp
  - src/Helper/MakeVec.hpp
  isVerificationFile: true
  path: test/aoj/DPL_1_E.test.cpp
  requiredBy: []
  timestamp: '2020-05-24 02:38:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_E.test.cpp
- /verify/test/aoj/DPL_1_E.test.cpp.html
title: test/aoj/DPL_1_E.test.cpp
---
