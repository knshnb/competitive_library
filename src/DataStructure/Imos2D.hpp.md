---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: src/DataStructure/Imos2D.md
    links: []
  bundledCode: "#line 1 \"src/DataStructure/Imos2D.hpp\"\n/// @docs src/DataStructure/Imos2D.md\n\
    // 0-indexed\n// t.add(i0, j0, i1, j1) -> t.run() -> t[i][j]\ntemplate <class\
    \ T> struct Imos2D {\n    int n, m;\n    std::vector<std::vector<T>> t;  // 0-indexed!!,\
    \ -x\u5206\u306E\u305F\u3081\u306B\u914D\u5217\u306E\u5916\u5074\u30921\u5927\u304D\
    \u3081\u306B\n    Imos2D(int n_, int m_) : n(n_), m(m_), t(n_ + 1, std::vector<T>(m_\
    \ + 1)) {}\n    // i0 <= i < i1, j0 < j < j1\u306E\u7BC4\u56F2\u306B+x\n    void\
    \ add(int i0, int j0, int i1, int j1, T x) {\n        t[i0][j0] += x, t[i1][j1]\
    \ += x;\n        t[i1][j0] -= x, t[i0][j1] -= x;\n    }\n    // 2\u65B9\u5411\u306B\
    \u7D2F\u7A4D\u548C\u3092\u3068\u308B\n    void build() {\n        for (int i =\
    \ 0; i < n; i++)\n            for (int j = 0; j < m; j++) t[i + 1][j] += t[i][j];\n\
    \        for (int i = 0; i < n; i++)\n            for (int j = 0; j < m; j++)\
    \ t[i][j + 1] += t[i][j];\n    }\n    std::vector<T>& operator[](int i) { return\
    \ t[i]; }\n};\n"
  code: "/// @docs src/DataStructure/Imos2D.md\n// 0-indexed\n// t.add(i0, j0, i1,\
    \ j1) -> t.run() -> t[i][j]\ntemplate <class T> struct Imos2D {\n    int n, m;\n\
    \    std::vector<std::vector<T>> t;  // 0-indexed!!, -x\u5206\u306E\u305F\u3081\
    \u306B\u914D\u5217\u306E\u5916\u5074\u30921\u5927\u304D\u3081\u306B\n    Imos2D(int\
    \ n_, int m_) : n(n_), m(m_), t(n_ + 1, std::vector<T>(m_ + 1)) {}\n    // i0\
    \ <= i < i1, j0 < j < j1\u306E\u7BC4\u56F2\u306B+x\n    void add(int i0, int j0,\
    \ int i1, int j1, T x) {\n        t[i0][j0] += x, t[i1][j1] += x;\n        t[i1][j0]\
    \ -= x, t[i0][j1] -= x;\n    }\n    // 2\u65B9\u5411\u306B\u7D2F\u7A4D\u548C\u3092\
    \u3068\u308B\n    void build() {\n        for (int i = 0; i < n; i++)\n      \
    \      for (int j = 0; j < m; j++) t[i + 1][j] += t[i][j];\n        for (int i\
    \ = 0; i < n; i++)\n            for (int j = 0; j < m; j++) t[i][j + 1] += t[i][j];\n\
    \    }\n    std::vector<T>& operator[](int i) { return t[i]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/Imos2D.hpp
  requiredBy: []
  timestamp: '2020-05-19 02:16:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/Imos2D.hpp
layout: document
redirect_from:
- /library/src/DataStructure/Imos2D.hpp
- /library/src/DataStructure/Imos2D.hpp.html
title: src/DataStructure/Imos2D.hpp
---
## 概要
H*Wの二次元データで長方形部分に区間加算するクエリをimos法によって行う。
各クエリO(1)、構築にO(HW)。

imos法: https://imoz.jp/algorithms/imos_method.html
<br/>
多次元の累積和についてはこれがわかりやすい: https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
