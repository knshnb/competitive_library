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
  bundledCode: "#line 1 \"src/DataStructure/UnionFindWithData.hpp\"\nstruct UnionFind\
    \ {\n    int cnt;                  // \u96C6\u5408\u306E\u6570\n    std::vector<int>\
    \ number;  // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306Eindex, \u8CA0\u306E\u3068\
    \u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    UnionFind(int n) : cnt(n), number(n,\
    \ -1) {}\n    int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]);\
    \ }\n    template <class F> void unite(int x, int y, F merge) {  // merge(x, y):\
    \ y\u3092x\u306B\u30DE\u30FC\u30B8\n        x = root(x), y = root(y);\n      \
    \  if (x == y) return;\n        if (number[y] < number[x]) std::swap(x, y);\n\
    \        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        number[x] += number[y];\n\
    \        number[y] = x;\n        cnt--;\n        merge(x, y);\n    }\n    bool\
    \ is_same(int x, int y) { return root(x) == root(y); }\n    int size(int x) {\
    \ return -number[root(x)]; }\n};\n"
  code: "struct UnionFind {\n    int cnt;                  // \u96C6\u5408\u306E\u6570\
    \n    std::vector<int> number;  // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306E\
    index, \u8CA0\u306E\u3068\u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    UnionFind(int\
    \ n) : cnt(n), number(n, -1) {}\n    int root(int x) { return number[x] < 0 ?\
    \ x : number[x] = root(number[x]); }\n    template <class F> void unite(int x,\
    \ int y, F merge) {  // merge(x, y): y\u3092x\u306B\u30DE\u30FC\u30B8\n      \
    \  x = root(x), y = root(y);\n        if (x == y) return;\n        if (number[y]\
    \ < number[x]) std::swap(x, y);\n        // y\u3092x\u306B\u30DE\u30FC\u30B8\n\
    \        number[x] += number[y];\n        number[y] = x;\n        cnt--;\n   \
    \     merge(x, y);\n    }\n    bool is_same(int x, int y) { return root(x) ==\
    \ root(y); }\n    int size(int x) { return -number[root(x)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFindWithData.hpp
  requiredBy: []
  timestamp: '2020-11-15 22:26:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/UnionFindWithData.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFindWithData.hpp
- /library/src/DataStructure/UnionFindWithData.hpp.html
title: src/DataStructure/UnionFindWithData.hpp
---
