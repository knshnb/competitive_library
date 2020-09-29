---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/Accumulate2D.hpp\"\n// \u30A4\u30F3\u30BF\
    \u30FC\u30D5\u30A7\u30A4\u30B9\u306F0-indexed\n// update(i, j, x) -> run() ->\
    \ query(i0, j0, i1, j1)\ntemplate <class T> struct Accumulate2D {\n    int n,\
    \ m;\n    std::vector<std::vector<T>> t;  // 1-indexed!!\n    Accumulate2D(int\
    \ n_, int m_) : n(n_), m(m_), t(n_ + 1, std::vector<T>(m_ + 1)) {}\n    void update(int\
    \ i, int j, T x) { t[i + 1][j + 1] = x; }\n    // \u7D2F\u7A4D\u548C\u3092\u53D6\
    \u308B\n    void run() {\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = 0; j < m; j++) {\n                t[i + 1][j + 1] += t[i][j + 1] +\
    \ t[i + 1][j] - t[i][j];\n            }\n        }\n    }\n    // i0 <= i < i1,\
    \ j0 < j < j1\u306E\u7BC4\u56F2\u306Esum\n    T query(int i0, int j0, int i1,\
    \ int j1) { return t[i1][j1] - t[i1][j0] - t[i0][j1] + t[i0][j0]; }\n    // \u3082\
    \u3068\u3082\u3068\u306E\u5024\n    T query(int i, int j) { return query(i, j,\
    \ i + 1, j + 1); }\n};\n"
  code: "// \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30A4\u30B9\u306F0-indexed\n// update(i,\
    \ j, x) -> run() -> query(i0, j0, i1, j1)\ntemplate <class T> struct Accumulate2D\
    \ {\n    int n, m;\n    std::vector<std::vector<T>> t;  // 1-indexed!!\n    Accumulate2D(int\
    \ n_, int m_) : n(n_), m(m_), t(n_ + 1, std::vector<T>(m_ + 1)) {}\n    void update(int\
    \ i, int j, T x) { t[i + 1][j + 1] = x; }\n    // \u7D2F\u7A4D\u548C\u3092\u53D6\
    \u308B\n    void run() {\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = 0; j < m; j++) {\n                t[i + 1][j + 1] += t[i][j + 1] +\
    \ t[i + 1][j] - t[i][j];\n            }\n        }\n    }\n    // i0 <= i < i1,\
    \ j0 < j < j1\u306E\u7BC4\u56F2\u306Esum\n    T query(int i0, int j0, int i1,\
    \ int j1) { return t[i1][j1] - t[i1][j0] - t[i0][j1] + t[i0][j0]; }\n    // \u3082\
    \u3068\u3082\u3068\u306E\u5024\n    T query(int i, int j) { return query(i, j,\
    \ i + 1, j + 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/Accumulate2D.hpp
  requiredBy: []
  timestamp: '2020-05-19 02:16:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/Accumulate2D.hpp
layout: document
redirect_from:
- /library/src/DataStructure/Accumulate2D.hpp
- /library/src/DataStructure/Accumulate2D.hpp.html
title: src/DataStructure/Accumulate2D.hpp
---
