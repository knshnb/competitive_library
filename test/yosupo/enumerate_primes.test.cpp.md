---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/Eratosthenes.hpp
    title: src/Math/Eratosthenes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo/enumerate_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef _MY_DEBUG\n#define dump(...)\n#endif  // clang-format\
    \ on\n\n/**\n *    author:  knshnb\n *    created: Sun Apr  5 19:29:53 JST 2020\n\
    \ **/\n\n#define CALL_FROM_TEST\n#line 1 \"src/Math/Eratosthenes.hpp\"\n/// @docs\
    \ src/Math/Eratosthenes.md\nstruct Eratosthenes {\n    std::vector<bool> is_prime;\n\
    \    std::vector<int> primes;\n    Eratosthenes(int n) {\n        is_prime.assign(n,\
    \ true);\n        is_prime[0] = is_prime[1] = false;\n        for (int i = 2;\
    \ i < n; i++) {\n            if (!is_prime[i]) continue;\n            for (int\
    \ j = i * 2; j < n; j += i) {\n                is_prime[j] = false;\n        \
    \    }\n        }\n        for (int i = 2; i < n; i++) {\n            if (is_prime[i])\
    \ primes.push_back(i);\n        }\n    }\n};\n#line 19 \"test/yosupo/enumerate_primes.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, A, B;\n    std::cin >>\
    \ n >> A >> B;\n    Eratosthenes er(n + 1);\n    Int num = ((Int)er.primes.size()\
    \ - B + A - 1) / A;\n    std::cout << er.primes.size() << \" \" << num << std::endl;\n\
    \    REP(i, num) {\n        std::cout << er.primes[A * i + B] << \" \";\n    }\n\
    \    std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Apr  5 19:29:53 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Math/Eratosthenes.hpp\"\n#undef CALL_FROM_TEST\n\nsigned\
    \ main() {\n    Int n, A, B;\n    std::cin >> n >> A >> B;\n    Eratosthenes er(n\
    \ + 1);\n    Int num = ((Int)er.primes.size() - B + A - 1) / A;\n    std::cout\
    \ << er.primes.size() << \" \" << num << std::endl;\n    REP(i, num) {\n     \
    \   std::cout << er.primes[A * i + B] << \" \";\n    }\n    std::cout << std::endl;\n\
    }\n"
  dependsOn:
  - src/Math/Eratosthenes.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2020-04-05 19:54:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_primes.test.cpp
- /verify/test/yosupo/enumerate_primes.test.cpp.html
title: test/yosupo/enumerate_primes.test.cpp
---
