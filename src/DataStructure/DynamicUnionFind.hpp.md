---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind_dynamic.test.cpp
    title: test/yosupo/unionfind_dynamic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/DynamicUnionFind.hpp\"\nstruct DynamicUnionFind\
    \ {\n    int cnt = 0;\n    std::unordered_map<int, int> number;\n\n    int root(int\
    \ x) {\n        if (!number.count(x)) number[x] = -1, cnt++;\n        return number[x]\
    \ < 0 ? x : number[x] = root(number[x]);\n    }\n    void unite(int x, int y)\
    \ {\n        x = root(x), y = root(y);\n        if (x == y) return;\n        if\
    \ (number[y] < number[x]) std::swap(x, y);\n        // y\u3092x\u306B\u30DE\u30FC\
    \u30B8\n        number[x] += number[y];\n        number[y] = x;\n        cnt--;\n\
    \    }\n    bool is_same(int x, int y) { return root(x) == root(y); }\n    int\
    \ size(int x) { return -number[root(x)]; }\n};\n"
  code: "struct DynamicUnionFind {\n    int cnt = 0;\n    std::unordered_map<int,\
    \ int> number;\n\n    int root(int x) {\n        if (!number.count(x)) number[x]\
    \ = -1, cnt++;\n        return number[x] < 0 ? x : number[x] = root(number[x]);\n\
    \    }\n    void unite(int x, int y) {\n        x = root(x), y = root(y);\n  \
    \      if (x == y) return;\n        if (number[y] < number[x]) std::swap(x, y);\n\
    \        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        number[x] += number[y];\n\
    \        number[y] = x;\n        cnt--;\n    }\n    bool is_same(int x, int y)\
    \ { return root(x) == root(y); }\n    int size(int x) { return -number[root(x)];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/DynamicUnionFind.hpp
  requiredBy: []
  timestamp: '2020-06-12 19:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind_dynamic.test.cpp
documentation_of: src/DataStructure/DynamicUnionFind.hpp
layout: document
redirect_from:
- /library/src/DataStructure/DynamicUnionFind.hpp
- /library/src/DataStructure/DynamicUnionFind.hpp.html
title: src/DataStructure/DynamicUnionFind.hpp
---
