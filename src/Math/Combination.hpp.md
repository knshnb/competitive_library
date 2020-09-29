---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D_runtime.test.cpp
    title: test/aoj/DPL_5_D_runtime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Math/Combination.hpp\"\ntemplate <class T> struct Combination\
    \ {\n    std::vector<T> fact, fact_inv;\n    Combination(int n = 1000003) : fact(n\
    \ + 1, 1), fact_inv(n + 1) {\n        for (int i = 0; i < n; i++) fact[i + 1]\
    \ = fact[i] * (i + 1);\n        fact_inv[n] = (T)1 / fact[n];\n        for (int\
    \ i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);\n        //\
    \ for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);\n    }\n\
    \    T operator()(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n -\
    \ r]; }\n};\n"
  code: "template <class T> struct Combination {\n    std::vector<T> fact, fact_inv;\n\
    \    Combination(int n = 1000003) : fact(n + 1, 1), fact_inv(n + 1) {\n      \
    \  for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);\n        fact_inv[n]\
    \ = (T)1 / fact[n];\n        for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i\
    \ + 1] * (i + 1);\n        // for (int i = 0; i < n + 1; i++) assert(fact[i] *\
    \ fact_inv[i] == 1);\n    }\n    T operator()(int n, int r) { return fact[n] *\
    \ fact_inv[r] * fact_inv[n - r]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combination.hpp
  requiredBy: []
  timestamp: '2020-04-01 18:54:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_D_runtime.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_F.test.cpp
documentation_of: src/Math/Combination.hpp
layout: document
redirect_from:
- /library/src/Math/Combination.hpp
- /library/src/Math/Combination.hpp.html
title: src/Math/Combination.hpp
---
