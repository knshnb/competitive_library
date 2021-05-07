---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq_sparse_table.test.cpp
    title: test/yosupo/staticrmq_sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/DataStructure/SparseTable.md
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SparseTable.hpp\"\n/// @docs src/DataStructure/SparseTable.md\n\
    template <class T, class F> struct SparseTable {\n    const F op;\n    std::vector<std::vector<T>>\
    \ t;\n    SparseTable(F op_, const std::vector<T>& a) : op(op_), t({a}) {\n  \
    \      for (int k = 1; 1 << k < a.size() + 1; k++) {\n            t.emplace_back(a.size()\
    \ - (1 << k) + 1);\n            for (int i = 0; i < a.size() - (1 << k) + 1; i++)\
    \ {\n                t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);\n\
    \            }\n        }\n    }\n    T query(int l, int r) const {\n        assert(0\
    \ <= l && l < r && r <= t[0].size());\n        int k = std::__lg(r - l);\n   \
    \     return op(t[k][l], t[k][r - (1 << k)]);\n    }\n};\ntemplate <class T, class\
    \ F> auto make_sparse_table(F op, const std::vector<T>& a) { return SparseTable<T,\
    \ F>(op, a); }\n"
  code: "/// @docs src/DataStructure/SparseTable.md\ntemplate <class T, class F> struct\
    \ SparseTable {\n    const F op;\n    std::vector<std::vector<T>> t;\n    SparseTable(F\
    \ op_, const std::vector<T>& a) : op(op_), t({a}) {\n        for (int k = 1; 1\
    \ << k < a.size() + 1; k++) {\n            t.emplace_back(a.size() - (1 << k)\
    \ + 1);\n            for (int i = 0; i < a.size() - (1 << k) + 1; i++) {\n   \
    \             t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);\n     \
    \       }\n        }\n    }\n    T query(int l, int r) const {\n        assert(0\
    \ <= l && l < r && r <= t[0].size());\n        int k = std::__lg(r - l);\n   \
    \     return op(t[k][l], t[k][r - (1 << k)]);\n    }\n};\ntemplate <class T, class\
    \ F> auto make_sparse_table(F op, const std::vector<T>& a) { return SparseTable<T,\
    \ F>(op, a); }"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2020-07-13 00:16:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq_sparse_table.test.cpp
documentation_of: src/DataStructure/SparseTable.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SparseTable.hpp
- /library/src/DataStructure/SparseTable.hpp.html
title: src/DataStructure/SparseTable.hpp
---
## 概要
冪等性を持つモノイドについて、区間畳み込みを高速に計算する。
構築O(n log n), クエリO(1)

## アルゴリズム
構築時には各点から始まるダブリングを計算。
クエリ時には、始点と終点からそれぞれ最も長い計算済みの区間を持ってきて(これはMSBから求まる)、2つの合成を求める。
2つの区間にはかぶりが生じるが、冪等性を仮定していることから正しい答えが求まることが保証される。
