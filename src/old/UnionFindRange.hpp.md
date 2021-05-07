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
  bundledCode: "#line 1 \"src/old/UnionFindRange.hpp\"\n// 1\u6B21\u5143\u4E0A\u306E\
    \u8981\u7D20\u306E\u30DE\u30FC\u30B8\u3092\u3057\u3066\u3044\u304F\u3068\u304D\
    \u306B\u3001\u5404\u9023\u7D50\u6210\u5206\u306E[left, right)\u3092\u66F4\u65B0\
    \nstruct UnionFind {\n    int cnt;                      // \u96C6\u5408\u306E\u6570\
    \n    vector<int> number;           // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306E\
    index, \u8CA0\u306E\u3068\u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    vector<pair<int,\
    \ int>> data;  // [left, right)\n    UnionFind(int n) : cnt(n), number(n, -1),\
    \ data(n) {\n        for (int i = 0; i < n; i++) data[i] = {i, i + 1};\n    }\n\
    \    int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]);\
    \ }\n    void unite(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return;\n        if (number[y] < number[x]) swap(x, y);\n\
    \        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        number[x] += number[y];\n\
    \        number[y] = x;\n        // data\u306E\u30DE\u30FC\u30B8\u65B9\u6CD5\u306B\
    \u5408\u308F\u305B\u3066\u5909\u3048\u308B\n        data[x] = {min(data[x].first,\
    \ data[y].first), max(data[x].second, data[y].second)};\n        cnt--;\n    }\n\
    \    bool is_same(int x, int y) { return root(x) == root(y); }\n    int size(int\
    \ x) { return -number[root(x)]; }\n    int& left(int x) { return data[root(x)].first;\
    \ }\n    int& right(int x) { return data[root(x)].second; }\n    pair<int, int>&\
    \ ref(int x) { return data[root(x)]; }\n};\n"
  code: "// 1\u6B21\u5143\u4E0A\u306E\u8981\u7D20\u306E\u30DE\u30FC\u30B8\u3092\u3057\
    \u3066\u3044\u304F\u3068\u304D\u306B\u3001\u5404\u9023\u7D50\u6210\u5206\u306E\
    [left, right)\u3092\u66F4\u65B0\nstruct UnionFind {\n    int cnt;            \
    \          // \u96C6\u5408\u306E\u6570\n    vector<int> number;           // 0\u4EE5\
    \u4E0A\u306E\u3068\u304D\u89AA\u306Eindex, \u8CA0\u306E\u3068\u304D\u306F\u96C6\
    \u5408\u30B5\u30A4\u30BA\n    vector<pair<int, int>> data;  // [left, right)\n\
    \    UnionFind(int n) : cnt(n), number(n, -1), data(n) {\n        for (int i =\
    \ 0; i < n; i++) data[i] = {i, i + 1};\n    }\n    int root(int x) { return number[x]\
    \ < 0 ? x : number[x] = root(number[x]); }\n    void unite(int x, int y) {\n \
    \       x = root(x);\n        y = root(y);\n        if (x == y) return;\n    \
    \    if (number[y] < number[x]) swap(x, y);\n        // y\u3092x\u306B\u30DE\u30FC\
    \u30B8\n        number[x] += number[y];\n        number[y] = x;\n        // data\u306E\
    \u30DE\u30FC\u30B8\u65B9\u6CD5\u306B\u5408\u308F\u305B\u3066\u5909\u3048\u308B\
    \n        data[x] = {min(data[x].first, data[y].first), max(data[x].second, data[y].second)};\n\
    \        cnt--;\n    }\n    bool is_same(int x, int y) { return root(x) == root(y);\
    \ }\n    int size(int x) { return -number[root(x)]; }\n    int& left(int x) {\
    \ return data[root(x)].first; }\n    int& right(int x) { return data[root(x)].second;\
    \ }\n    pair<int, int>& ref(int x) { return data[root(x)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/UnionFindRange.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/UnionFindRange.hpp
layout: document
redirect_from:
- /library/src/old/UnionFindRange.hpp
- /library/src/old/UnionFindRange.hpp.html
title: src/old/UnionFindRange.hpp
---
