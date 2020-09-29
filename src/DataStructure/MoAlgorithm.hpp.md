---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: src/DataStructure/MoAlgorithm.md
    links: []
  bundledCode: "#line 1 \"src/DataStructure/MoAlgorithm.hpp\"\n/// @docs src/DataStructure/MoAlgorithm.md\n\
    struct Mo {\n    struct Query {\n        int l, r, idx;  // \u914D\u5217\u306B\
    \u5BFE\u3059\u308B[l, r)\u306E\u30AF\u30A8\u30EA, idx\u306F\u30AF\u30A8\u30EA\u306E\
    \u756A\u53F7\n        Query(int l_, int r_, int idx_) : l(l_), r(r_), idx(idx_)\
    \ {}\n    };\n    int width;\n    std::vector<Query> query;\n    std::vector<bool>\
    \ v;\n\n    // width\u306F\u6307\u5B9A\u3057\u306A\u3044\u3068\u81EA\u52D5\u3067\
    sqrt(n)\u306B\u3059\u308B\n    Mo(int n, int width_ = -1) : width(width_ == -1\
    \ ? (int)sqrt(n) : width_), v(n) {}\n    void add(int l, int r) {\n        int\
    \ idx = query.size();\n        query.emplace_back(l, r, idx);\n    }\n    template\
    \ <class F, class G, class H> void run(const F& add, const G& del, const H& rem)\
    \ {\n        std::sort(query.begin(), query.end(), [&](const Query& a, const Query&\
    \ b) {\n            int ablock = a.l / width, bblock = b.l / width;\n        \
    \    if (ablock != bblock) return ablock < bblock;\n            if (ablock & 1)\
    \ return a.r < b.r;\n            return a.r > b.r;\n        });\n        int nl\
    \ = 0, nr = 0;\n        auto push = [&](int idx) {\n            v[idx].flip();\n\
    \            if (v[idx])\n                add(idx);\n            else\n      \
    \          del(idx);\n        };\n        for (Query& q : query) {\n         \
    \   while (nl > q.l) push(--nl);\n            while (nr < q.r) push(nr++);\n \
    \           while (nl < q.l) push(nl++);\n            while (nr > q.r) push(--nr);\n\
    \            rem(q.idx);\n            while (nl > q.l) push(--nl);\n        }\n\
    \    }\n};\n"
  code: "/// @docs src/DataStructure/MoAlgorithm.md\nstruct Mo {\n    struct Query\
    \ {\n        int l, r, idx;  // \u914D\u5217\u306B\u5BFE\u3059\u308B[l, r)\u306E\
    \u30AF\u30A8\u30EA, idx\u306F\u30AF\u30A8\u30EA\u306E\u756A\u53F7\n        Query(int\
    \ l_, int r_, int idx_) : l(l_), r(r_), idx(idx_) {}\n    };\n    int width;\n\
    \    std::vector<Query> query;\n    std::vector<bool> v;\n\n    // width\u306F\
    \u6307\u5B9A\u3057\u306A\u3044\u3068\u81EA\u52D5\u3067sqrt(n)\u306B\u3059\u308B\
    \n    Mo(int n, int width_ = -1) : width(width_ == -1 ? (int)sqrt(n) : width_),\
    \ v(n) {}\n    void add(int l, int r) {\n        int idx = query.size();\n   \
    \     query.emplace_back(l, r, idx);\n    }\n    template <class F, class G, class\
    \ H> void run(const F& add, const G& del, const H& rem) {\n        std::sort(query.begin(),\
    \ query.end(), [&](const Query& a, const Query& b) {\n            int ablock =\
    \ a.l / width, bblock = b.l / width;\n            if (ablock != bblock) return\
    \ ablock < bblock;\n            if (ablock & 1) return a.r < b.r;\n          \
    \  return a.r > b.r;\n        });\n        int nl = 0, nr = 0;\n        auto push\
    \ = [&](int idx) {\n            v[idx].flip();\n            if (v[idx])\n    \
    \            add(idx);\n            else\n                del(idx);\n        };\n\
    \        for (Query& q : query) {\n            while (nl > q.l) push(--nl);\n\
    \            while (nr < q.r) push(nr++);\n            while (nl < q.l) push(nl++);\n\
    \            while (nr > q.r) push(--nr);\n            rem(q.idx);\n         \
    \   while (nl > q.l) push(--nl);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/MoAlgorithm.hpp
  requiredBy: []
  timestamp: '2020-08-09 02:48:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/MoAlgorithm.hpp
layout: document
redirect_from:
- /library/src/DataStructure/MoAlgorithm.hpp
- /library/src/DataStructure/MoAlgorithm.hpp.html
title: src/DataStructure/MoAlgorithm.hpp
---
## 概要
配列に対するオフライン区間クエリを扱うテクニック。
計算量O((N + Q) sqrt(N))。

## 参考
https://ei1333.hateblo.jp/entry/2017/09/11/211011
