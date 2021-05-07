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
  bundledCode: "#line 1 \"src/old/MultisetHash.hpp\"\nusing ull = unsigned long long;\n\
    random_device rnd;\nmt19937 mt(rnd());\nmt19937_64 mt64(rnd());\nint mod_pow(int\
    \ x, int n, int mod) {\n    if (n <= 0) return 1;\n    int tmp = mod_pow(x, n\
    \ / 2, mod);\n    return tmp * tmp % mod * (n % 2 ? x : 1) % mod;\n}\n// Miller-Rabin\n\
    bool is_prime(int n, int times = 50) {\n    if (n == 2) return true;\n    if (n\
    \ % 2 == 0 || n < 2) return false;\n    int d = n - 1;\n    while (d % 2 == 0)\
    \ d /= 2;\n    while (times--) {\n        int a = rnd() % (n - 2) + 1;\n     \
    \   int t = d;\n        int y = mod_pow(a, t, n);\n        while (t != n - 1 &&\
    \ y != 1 && y != n - 1) {\n            y = y * y % n;\n            t *= 2;\n \
    \       }\n        if (y != n - 1 && t % 2 == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\nint gen_prime() {\n    int cnt = 0;\n\
    \    while (1) {\n        int n = mt();\n        n != 1;\n        if (is_prime(n))\
    \ return n;\n    }\n}\nclass MultisetHash {\npublic:\n    vector<ull> hash, pows;\n\
    \    ull mod;\n    int to_int(char c) { return c - 'a'; }\n    MultisetHash()\
    \ {}\n    MultisetHash(const string& S, int k = 26, ull base = gen_prime(), ull\
    \ m = gen_prime())\n        : hash(S.size() + 1), pows(k), mod(m) {\n        pows[0]\
    \ = 1;\n        for (int i = 0; i < k - 1; i++) {\n            pows[i + 1] = pows[i]\
    \ * base % mod;\n        }\n        for (int i = 0; i < S.size(); i++) {\n   \
    \         hash[i + 1] = hash[i] + pows[to_int(S[i])];\n        }\n    }\n    //\
    \ [l, r)\n    ull get(int l, int r) {\n        int ret = hash[r] + mod - hash[l];\n\
    \        if (ret >= mod) ret -= mod;\n        return ret;\n    }\n};\n"
  code: "using ull = unsigned long long;\nrandom_device rnd;\nmt19937 mt(rnd());\n\
    mt19937_64 mt64(rnd());\nint mod_pow(int x, int n, int mod) {\n    if (n <= 0)\
    \ return 1;\n    int tmp = mod_pow(x, n / 2, mod);\n    return tmp * tmp % mod\
    \ * (n % 2 ? x : 1) % mod;\n}\n// Miller-Rabin\nbool is_prime(int n, int times\
    \ = 50) {\n    if (n == 2) return true;\n    if (n % 2 == 0 || n < 2) return false;\n\
    \    int d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    while (times--) {\n \
    \       int a = rnd() % (n - 2) + 1;\n        int t = d;\n        int y = mod_pow(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t *= 2;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    int gen_prime() {\n    int cnt = 0;\n    while (1) {\n        int n = mt();\n\
    \        n != 1;\n        if (is_prime(n)) return n;\n    }\n}\nclass MultisetHash\
    \ {\npublic:\n    vector<ull> hash, pows;\n    ull mod;\n    int to_int(char c)\
    \ { return c - 'a'; }\n    MultisetHash() {}\n    MultisetHash(const string& S,\
    \ int k = 26, ull base = gen_prime(), ull m = gen_prime())\n        : hash(S.size()\
    \ + 1), pows(k), mod(m) {\n        pows[0] = 1;\n        for (int i = 0; i < k\
    \ - 1; i++) {\n            pows[i + 1] = pows[i] * base % mod;\n        }\n  \
    \      for (int i = 0; i < S.size(); i++) {\n            hash[i + 1] = hash[i]\
    \ + pows[to_int(S[i])];\n        }\n    }\n    // [l, r)\n    ull get(int l, int\
    \ r) {\n        int ret = hash[r] + mod - hash[l];\n        if (ret >= mod) ret\
    \ -= mod;\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/MultisetHash.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/MultisetHash.hpp
layout: document
redirect_from:
- /library/src/old/MultisetHash.hpp
- /library/src/old/MultisetHash.hpp.html
title: src/old/MultisetHash.hpp
---
