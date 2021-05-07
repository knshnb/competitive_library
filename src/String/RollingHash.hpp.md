---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm_rolling_hash.test.cpp
    title: test/yosupo/zalgorithm_rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/String/RollingHash.md
    links: []
  bundledCode: "#line 1 \"src/String/RollingHash.hpp\"\n/// @docs src/String/RollingHash.md\n\
    template <class T> struct RollingHash {\n    std::vector<int> hash, pows;\n  \
    \  int base, mod;\n    RollingHash(const T &a, int base_, int mod_ = 1000000009)\n\
    \        : hash(a.size() + 1), pows(a.size() + 1, 1), base(base_), mod(mod_) {\n\
    \        for (int i = 0; i < a.size(); i++) {\n            pows[i + 1] = (long\
    \ long)pows[i] * base % mod;\n            hash[i + 1] = ((long long)hash[i] *\
    \ base % mod + a[i]) % mod;\n            if (hash[i + 1] < 0) hash[i + 1] += mod;\n\
    \        }\n    }\n    // \u73FE\u5728\u306E\u6587\u5B57\u5217\u306E\u30B5\u30A4\
    \u30BA\n    int size() { return hash.size() - 1; }\n    // [l, r)\n    int get(int\
    \ l, int r) {\n        assert(l <= r);\n        int ret = hash[r] + mod - (long\
    \ long)hash[l] * pows[r - l] % mod;\n        if (ret >= mod) ret -= mod;\n   \
    \     return ret;\n    }\n    void concat(const T &b) {\n        int n = hash.size()\
    \ - 1, m = b.size();\n        pows.resize(n + m + 1);\n        hash.resize(n +\
    \ m + 1);\n        for (int i = 0; i < m; i++) {\n            pows[n + i + 1]\
    \ = (long long)pows[n + i] * base % mod;\n            hash[n + i + 1] = (long\
    \ long)hash[n + i] * base % mod + b[i];\n            if (hash[n + i + 1] >= mod)\
    \ hash[n + i + 1] -= mod;\n        }\n    }\n    void pop_back() {\n        hash.pop_back();\n\
    \        pows.pop_back();\n    }\n};\n\ntemplate <int HashNum> std::array<int,\
    \ HashNum> make_rand_array() {\n    std::array<int, HashNum> res;\n    std::mt19937\
    \ rnd(std::chrono::steady_clock::now().time_since_epoch().count());\n    for (int\
    \ i = 0; i < HashNum; i++) res[i] = rnd() % 1000000;\n    return res;\n}\ntemplate\
    \ <class T, int HashNum = 4> struct MultiRollingHash {\n    using multihash_t\
    \ = std::array<int, HashNum>;\n    static std::array<int, HashNum> bases;\n  \
    \  std::vector<RollingHash<T>> rhs;\n    MultiRollingHash(const T &a) {\n    \
    \    for (int i = 0; i < HashNum; i++) {\n            rhs.push_back(RollingHash<T>(a,\
    \ bases[i]));\n        }\n    }\n    multihash_t get(int l, int r) {\n       \
    \ multihash_t ret;\n        for (int i = 0; i < HashNum; i++) ret[i] = rhs[i].get(l,\
    \ r);\n        return ret;\n    }\n    int size() { return rhs[0].size(); }\n\
    \    void concat(const T &b) {\n        for (auto &rh : rhs) rh.concat(b);\n \
    \   }\n    void pop_back() {\n        for (auto &rh : rhs) rh.pop_back();\n  \
    \  }\n};\ntemplate <class T, int HashNum>\nstd::array<int, HashNum> MultiRollingHash<T,\
    \ HashNum>::bases = make_rand_array<HashNum>();\n"
  code: "/// @docs src/String/RollingHash.md\ntemplate <class T> struct RollingHash\
    \ {\n    std::vector<int> hash, pows;\n    int base, mod;\n    RollingHash(const\
    \ T &a, int base_, int mod_ = 1000000009)\n        : hash(a.size() + 1), pows(a.size()\
    \ + 1, 1), base(base_), mod(mod_) {\n        for (int i = 0; i < a.size(); i++)\
    \ {\n            pows[i + 1] = (long long)pows[i] * base % mod;\n            hash[i\
    \ + 1] = ((long long)hash[i] * base % mod + a[i]) % mod;\n            if (hash[i\
    \ + 1] < 0) hash[i + 1] += mod;\n        }\n    }\n    // \u73FE\u5728\u306E\u6587\
    \u5B57\u5217\u306E\u30B5\u30A4\u30BA\n    int size() { return hash.size() - 1;\
    \ }\n    // [l, r)\n    int get(int l, int r) {\n        assert(l <= r);\n   \
    \     int ret = hash[r] + mod - (long long)hash[l] * pows[r - l] % mod;\n    \
    \    if (ret >= mod) ret -= mod;\n        return ret;\n    }\n    void concat(const\
    \ T &b) {\n        int n = hash.size() - 1, m = b.size();\n        pows.resize(n\
    \ + m + 1);\n        hash.resize(n + m + 1);\n        for (int i = 0; i < m; i++)\
    \ {\n            pows[n + i + 1] = (long long)pows[n + i] * base % mod;\n    \
    \        hash[n + i + 1] = (long long)hash[n + i] * base % mod + b[i];\n     \
    \       if (hash[n + i + 1] >= mod) hash[n + i + 1] -= mod;\n        }\n    }\n\
    \    void pop_back() {\n        hash.pop_back();\n        pows.pop_back();\n \
    \   }\n};\n\ntemplate <int HashNum> std::array<int, HashNum> make_rand_array()\
    \ {\n    std::array<int, HashNum> res;\n    std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \    for (int i = 0; i < HashNum; i++) res[i] = rnd() % 1000000;\n    return res;\n\
    }\ntemplate <class T, int HashNum = 4> struct MultiRollingHash {\n    using multihash_t\
    \ = std::array<int, HashNum>;\n    static std::array<int, HashNum> bases;\n  \
    \  std::vector<RollingHash<T>> rhs;\n    MultiRollingHash(const T &a) {\n    \
    \    for (int i = 0; i < HashNum; i++) {\n            rhs.push_back(RollingHash<T>(a,\
    \ bases[i]));\n        }\n    }\n    multihash_t get(int l, int r) {\n       \
    \ multihash_t ret;\n        for (int i = 0; i < HashNum; i++) ret[i] = rhs[i].get(l,\
    \ r);\n        return ret;\n    }\n    int size() { return rhs[0].size(); }\n\
    \    void concat(const T &b) {\n        for (auto &rh : rhs) rh.concat(b);\n \
    \   }\n    void pop_back() {\n        for (auto &rh : rhs) rh.pop_back();\n  \
    \  }\n};\ntemplate <class T, int HashNum>\nstd::array<int, HashNum> MultiRollingHash<T,\
    \ HashNum>::bases = make_rand_array<HashNum>();\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/RollingHash.hpp
  requiredBy: []
  timestamp: '2020-04-06 03:23:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/zalgorithm_rolling_hash.test.cpp
documentation_of: src/String/RollingHash.hpp
layout: document
redirect_from:
- /library/src/String/RollingHash.hpp
- /library/src/String/RollingHash.hpp.html
title: src/String/RollingHash.hpp
---
## 概要
文字列を多項式と捉えて、適当なmod,baseでhash化。
Sを与えて事前計算しておけば、S[l, r)のhashがO(1)で取得できる。
具体的には、各iについて
`hash[0, i) = S[0] * base^(i-1) + S[1] * base^(i-2) + ... + S[i-1] * base^0`
を計算しておくと、
`hash[l, r) = hash[0, r) - hash[0, l) * base^(r-1)`
となる。

衝突率を下げるため、modを素数に固定しbaseをいくつか乱択し、全てが一致するか確認している。
文字列の中で先頭の0の個数のみがちがうもの(00032と032など)は区別できないので注意！適当な定数を足す必要あり。

参考: Rolling Hashの衝突確率について(https://maspypy.com/rolling-hash%e3%81%ab%e3%81%a4%e3%81%84%e3%81%a6%ef%bc%88survey-%e7%a0%94%e7%a9%b6%ef%bc%89)
