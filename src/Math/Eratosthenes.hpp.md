---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_primes.test.cpp
    title: test/yosupo/enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Math/Eratosthenes.md
    links: []
  bundledCode: "#line 1 \"src/Math/Eratosthenes.hpp\"\n/// @docs src/Math/Eratosthenes.md\n\
    struct Eratosthenes {\n    std::vector<bool> is_prime;\n    std::vector<int> primes;\n\
    \    Eratosthenes(int n) {\n        is_prime.assign(n, true);\n        is_prime[0]\
    \ = is_prime[1] = false;\n        for (int i = 2; i < n; i++) {\n            if\
    \ (!is_prime[i]) continue;\n            for (int j = i * 2; j < n; j += i) {\n\
    \                is_prime[j] = false;\n            }\n        }\n        for (int\
    \ i = 2; i < n; i++) {\n            if (is_prime[i]) primes.push_back(i);\n  \
    \      }\n    }\n};\n"
  code: "/// @docs src/Math/Eratosthenes.md\nstruct Eratosthenes {\n    std::vector<bool>\
    \ is_prime;\n    std::vector<int> primes;\n    Eratosthenes(int n) {\n       \
    \ is_prime.assign(n, true);\n        is_prime[0] = is_prime[1] = false;\n    \
    \    for (int i = 2; i < n; i++) {\n            if (!is_prime[i]) continue;\n\
    \            for (int j = i * 2; j < n; j += i) {\n                is_prime[j]\
    \ = false;\n            }\n        }\n        for (int i = 2; i < n; i++) {\n\
    \            if (is_prime[i]) primes.push_back(i);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Eratosthenes.hpp
  requiredBy: []
  timestamp: '2020-04-05 19:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_primes.test.cpp
documentation_of: src/Math/Eratosthenes.hpp
layout: document
redirect_from:
- /library/src/Math/Eratosthenes.hpp
- /library/src/Math/Eratosthenes.hpp.html
title: src/Math/Eratosthenes.hpp
---
## 概要
エラトステネスの篩による素数列挙。
計算量は、n以下の素数の逆数和がO(loglog n)であることから、O(n loglog n)である(参考: https://mathtrain.jp/eratosthenes)。

定数倍高速化を頑張るともっとかなり早くなる(参考: https://qiita.com/peria/items/a4ff4ddb3336f7b81d50)
