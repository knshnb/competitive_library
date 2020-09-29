---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/UnionFindWithData.hpp\"\nstruct UnionFind {\n  \
    \  int cnt;             // \u96C6\u5408\u306E\u6570\n    vector<int> number; \
    \ // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306Eindex, \u8CA0\u306E\u3068\u304D\
    \u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    struct Data {\n        Data() {}\n \
    \       void merge(Data& s) {\n            // \u81EA\u5206\u3067\u5B9A\u7FA9\n\
    \        }\n    };\n    vector<Data> data;\n\n    UnionFind(int n) : cnt(n), number(n,\
    \ -1), data(n) {}\n    int root(int x) { return number[x] < 0 ? x : number[x]\
    \ = root(number[x]); }\n    void unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return;\n        if (number[y] < number[x])\
    \ swap(x, y);\n        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        number[x]\
    \ += number[y];\n        number[y] = x;\n        // data\u306E\u30DE\u30FC\u30B8\
    \u65B9\u6CD5\u306B\u5408\u308F\u305B\u3066\u5909\u3048\u308B\n        data[x].merge(data[y]);\n\
    \n        cnt--;\n    }\n    bool is_same(int x, int y) { return root(x) == root(y);\
    \ }\n    int size(int x) { return -number[root(x)]; }\n    Data& ref(int x) {\
    \ return data[root(x)]; }\n};\n"
  code: "struct UnionFind {\n    int cnt;             // \u96C6\u5408\u306E\u6570\n\
    \    vector<int> number;  // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306Eindex,\
    \ \u8CA0\u306E\u3068\u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n    struct Data\
    \ {\n        Data() {}\n        void merge(Data& s) {\n            // \u81EA\u5206\
    \u3067\u5B9A\u7FA9\n        }\n    };\n    vector<Data> data;\n\n    UnionFind(int\
    \ n) : cnt(n), number(n, -1), data(n) {}\n    int root(int x) { return number[x]\
    \ < 0 ? x : number[x] = root(number[x]); }\n    void unite(int x, int y) {\n \
    \       x = root(x);\n        y = root(y);\n        if (x == y) return;\n    \
    \    if (number[y] < number[x]) swap(x, y);\n        // y\u3092x\u306B\u30DE\u30FC\
    \u30B8\n        number[x] += number[y];\n        number[y] = x;\n        // data\u306E\
    \u30DE\u30FC\u30B8\u65B9\u6CD5\u306B\u5408\u308F\u305B\u3066\u5909\u3048\u308B\
    \n        data[x].merge(data[y]);\n\n        cnt--;\n    }\n    bool is_same(int\
    \ x, int y) { return root(x) == root(y); }\n    int size(int x) { return -number[root(x)];\
    \ }\n    Data& ref(int x) { return data[root(x)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/UnionFindWithData.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/UnionFindWithData.hpp
layout: document
redirect_from:
- /library/src/old/UnionFindWithData.hpp
- /library/src/old/UnionFindWithData.hpp.html
title: src/old/UnionFindWithData.hpp
---
