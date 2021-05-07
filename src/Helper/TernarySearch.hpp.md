---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1028.test.cpp
    title: test/yukicoder/1028.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Helper/TernarySearch.md
    links: []
  bundledCode: "#line 1 \"src/Helper/TernarySearch.hpp\"\n/// @docs src/Helper/TernarySearch.md\n\
    template <class F, class T = long long> T ternary_search(T l, T r, F f, bool is_max\
    \ = true) {\n    auto g = [&f, &is_max](T x) { return is_max ? f(x) : -f(x); };\n\
    \    while (std::abs(l - r) > 2) {\n        T m1 = (2 * l + r) / 3, m2 = (l +\
    \ 2 * r) / 3;\n        if (g(m1) < g(m2))\n            l = m1;\n        else\n\
    \            r = m2;\n    }\n    // \u6975\u5024\u306Eindex\u306F[l, r)\u306E\u7BC4\
    \u56F2\u3067\u3001abs(l - r) <= 2\u306B\u306A\u3063\u3066\u3044\u308B\n    if\
    \ (l + 1 < r && g(l + 1) > g(l)) l = l + 1;\n    return l;\n}\n"
  code: "/// @docs src/Helper/TernarySearch.md\ntemplate <class F, class T = long\
    \ long> T ternary_search(T l, T r, F f, bool is_max = true) {\n    auto g = [&f,\
    \ &is_max](T x) { return is_max ? f(x) : -f(x); };\n    while (std::abs(l - r)\
    \ > 2) {\n        T m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;\n        if (g(m1)\
    \ < g(m2))\n            l = m1;\n        else\n            r = m2;\n    }\n  \
    \  // \u6975\u5024\u306Eindex\u306F[l, r)\u306E\u7BC4\u56F2\u3067\u3001abs(l -\
    \ r) <= 2\u306B\u306A\u3063\u3066\u3044\u308B\n    if (l + 1 < r && g(l + 1) >\
    \ g(l)) l = l + 1;\n    return l;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/TernarySearch.hpp
  requiredBy: []
  timestamp: '2020-04-18 20:15:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1028.test.cpp
documentation_of: src/Helper/TernarySearch.hpp
layout: document
redirect_from:
- /library/src/Helper/TernarySearch.hpp
- /library/src/Helper/TernarySearch.hpp.html
title: src/Helper/TernarySearch.hpp
---
## 概要
三分探索で整数を引数とする凸関数の極値を求める。
fの評価回数は、O(log (r - l))。