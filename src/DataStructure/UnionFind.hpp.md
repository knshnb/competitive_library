---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/UnionFind.hpp\"\nstruct UnionFind {\n\
    \    int cnt;                  // \u96C6\u5408\u306E\u6570\n    std::vector<int>\
    \ number;  // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306Eindex, \u8CA0\u306E\u3068\
    \u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    UnionFind(int n) : cnt(n), number(n,\
    \ -1) {}\n    int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]);\
    \ }\n    void unite(int x, int y) {\n        x = root(x), y = root(y);\n     \
    \   if (x == y) return;\n        if (number[y] < number[x]) std::swap(x, y);\n\
    \        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        number[x] += number[y];\n\
    \        number[y] = x;\n        cnt--;\n    }\n    bool is_same(int x, int y)\
    \ { return root(x) == root(y); }\n    int size(int x) { return -number[root(x)];\
    \ }\n};\n"
  code: "struct UnionFind {\n    int cnt;                  // \u96C6\u5408\u306E\u6570\
    \n    std::vector<int> number;  // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306E\
    index, \u8CA0\u306E\u3068\u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    UnionFind(int\
    \ n) : cnt(n), number(n, -1) {}\n    int root(int x) { return number[x] < 0 ?\
    \ x : number[x] = root(number[x]); }\n    void unite(int x, int y) {\n       \
    \ x = root(x), y = root(y);\n        if (x == y) return;\n        if (number[y]\
    \ < number[x]) std::swap(x, y);\n        // y\u3092x\u306B\u30DE\u30FC\u30B8\n\
    \        number[x] += number[y];\n        number[y] = x;\n        cnt--;\n   \
    \ }\n    bool is_same(int x, int y) { return root(x) == root(y); }\n    int size(int\
    \ x) { return -number[root(x)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2020-03-29 16:30:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
documentation_of: src/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind.hpp
- /library/src/DataStructure/UnionFind.hpp.html
title: src/DataStructure/UnionFind.hpp
---
