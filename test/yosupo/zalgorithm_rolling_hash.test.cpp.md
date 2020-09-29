---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/String/RollingHash.hpp
    title: src/String/RollingHash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/zalgorithm_rolling_hash.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef _MY_DEBUG\n#define dump(...)\n#endif  // clang-format\
    \ on\n\n/**\n *    author:  knshnb\n *    created: Sun Apr  5 20:03:46 JST 2020\n\
    \ **/\n\n#define CALL_FROM_TEST\n#line 1 \"src/String/RollingHash.hpp\"\n/// @docs\
    \ src/String/RollingHash.md\ntemplate <class T> struct RollingHash {\n    std::vector<int>\
    \ hash, pows;\n    int base, mod;\n    RollingHash(const T &a, int base_, int\
    \ mod_ = 1000000009)\n        : hash(a.size() + 1), pows(a.size() + 1, 1), base(base_),\
    \ mod(mod_) {\n        for (int i = 0; i < a.size(); i++) {\n            pows[i\
    \ + 1] = (long long)pows[i] * base % mod;\n            hash[i + 1] = ((long long)hash[i]\
    \ * base % mod + a[i]) % mod;\n            if (hash[i + 1] < 0) hash[i + 1] +=\
    \ mod;\n        }\n    }\n    // \u73FE\u5728\u306E\u6587\u5B57\u5217\u306E\u30B5\
    \u30A4\u30BA\n    int size() { return hash.size() - 1; }\n    // [l, r)\n    int\
    \ get(int l, int r) {\n        assert(l <= r);\n        int ret = hash[r] + mod\
    \ - (long long)hash[l] * pows[r - l] % mod;\n        if (ret >= mod) ret -= mod;\n\
    \        return ret;\n    }\n    void concat(const T &b) {\n        int n = hash.size()\
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
    \ HashNum>::bases = make_rand_array<HashNum>();\n#line 19 \"test/yosupo/zalgorithm_rolling_hash.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    std::string s;\n    std::cin >>\
    \ s;\n    Int n = s.size();\n    MultiRollingHash rh(s);\n    REP(i, n) {\n  \
    \      auto check = [&](Int mid) -> bool {\n            return rh.get(0, mid)\
    \ == rh.get(i, i + mid);\n        };\n        Int ok = 0, ng = n - i + 1;\n  \
    \      while (std::abs(ok - ng) > 1) {\n            Int mid = (ok + ng) / 2;\n\
    \            (check(mid) ? ok : ng) = mid;\n        }\n        std::cout << ok\
    \ << \" \";\n    }\n    std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define REP_(i,\
    \ a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define\
    \ REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO\
    \ { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout\
    \ << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n#define\
    \ dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n *    created:\
    \ Sun Apr  5 20:03:46 JST 2020\n **/\n\n#define CALL_FROM_TEST\n#include \"../../src/String/RollingHash.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    std::string s;\n    std::cin >>\
    \ s;\n    Int n = s.size();\n    MultiRollingHash rh(s);\n    REP(i, n) {\n  \
    \      auto check = [&](Int mid) -> bool {\n            return rh.get(0, mid)\
    \ == rh.get(i, i + mid);\n        };\n        Int ok = 0, ng = n - i + 1;\n  \
    \      while (std::abs(ok - ng) > 1) {\n            Int mid = (ok + ng) / 2;\n\
    \            (check(mid) ? ok : ng) = mid;\n        }\n        std::cout << ok\
    \ << \" \";\n    }\n    std::cout << std::endl;\n}\n"
  dependsOn:
  - src/String/RollingHash.hpp
  isVerificationFile: true
  path: test/yosupo/zalgorithm_rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2020-04-06 03:23:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/zalgorithm_rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/zalgorithm_rolling_hash.test.cpp
- /verify/test/yosupo/zalgorithm_rolling_hash.test.cpp.html
title: test/yosupo/zalgorithm_rolling_hash.test.cpp
---
