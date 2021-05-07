---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/MillerRabin.hpp\"\nrandom_device rnd;\nmt19937 mt(rnd());\n\
    mt19937_64 mt64(rnd());\nint mod_pow(int x, int n, int mod) {\n    if (n <= 0)\
    \ return 1;\n    int tmp = mod_pow(x, n / 2, mod);\n    return tmp * tmp % mod\
    \ * (n % 2 ? x : 1) % mod;\n}\nint mod_inv(int x, int mod) { return mod_pow(x,\
    \ mod - 2, mod); }\n// Miller-Rabin\nbool is_prime(int n, int times = 50) {\n\
    \    if (n == 2) return true;\n    if (n % 2 == 0 || n < 2) return false;\n  \
    \  int d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    while (times--) {\n   \
    \     int a = rnd() % (n - 2) + 1;\n        int t = d;\n        int y = mod_pow(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t *= 2;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    int gen_prime() {\n    int cnt = 0;\n    while (1) {\n        int n = mt();\n\
    \        n != 1;\n        if (is_prime(n)) return n;\n    }\n}\n"
  code: "random_device rnd;\nmt19937 mt(rnd());\nmt19937_64 mt64(rnd());\nint mod_pow(int\
    \ x, int n, int mod) {\n    if (n <= 0) return 1;\n    int tmp = mod_pow(x, n\
    \ / 2, mod);\n    return tmp * tmp % mod * (n % 2 ? x : 1) % mod;\n}\nint mod_inv(int\
    \ x, int mod) { return mod_pow(x, mod - 2, mod); }\n// Miller-Rabin\nbool is_prime(int\
    \ n, int times = 50) {\n    if (n == 2) return true;\n    if (n % 2 == 0 || n\
    \ < 2) return false;\n    int d = n - 1;\n    while (d % 2 == 0) d /= 2;\n   \
    \ while (times--) {\n        int a = rnd() % (n - 2) + 1;\n        int t = d;\n\
    \        int y = mod_pow(a, t, n);\n        while (t != n - 1 && y != 1 && y !=\
    \ n - 1) {\n            y = y * y % n;\n            t *= 2;\n        }\n     \
    \   if (y != n - 1 && t % 2 == 0) {\n            return false;\n        }\n  \
    \  }\n    return true;\n}\nint gen_prime() {\n    int cnt = 0;\n    while (1)\
    \ {\n        int n = mt();\n        n != 1;\n        if (is_prime(n)) return n;\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/MillerRabin.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/MillerRabin.hpp
layout: document
redirect_from:
- /library/src/old/MillerRabin.hpp
- /library/src/old/MillerRabin.hpp.html
title: src/old/MillerRabin.hpp
---
