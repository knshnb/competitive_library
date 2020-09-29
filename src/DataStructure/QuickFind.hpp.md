---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind_quick_find.test.cpp
    title: test/yosupo/unionfind_quick_find.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/DataStructure/QuickFind.md
    links: []
  bundledCode: "#line 1 \"src/DataStructure/QuickFind.hpp\"\n/// @docs src/DataStructure/QuickFind.md\n\
    struct QuickFind {\n    std::vector<int> belong_to;\n    std::vector<std::vector<int>>\
    \ groups;\n    QuickFind(int n) : belong_to(n), groups(n, std::vector<int>(1))\
    \ {\n        std::iota(belong_to.begin(), belong_to.end(), 0);\n        for (int\
    \ i = 0; i < n; i++) groups[i][0] = i;\n    }\n    void unite(int x, int y) {\n\
    \        x = belong_to[x], y = belong_to[y];\n        if (x == y) return;\n  \
    \      if (groups[x].size() < groups[y].size()) std::swap(x, y);\n        // y\u3092\
    x\u306B\u30DE\u30FC\u30B8\n        for (int v : groups[y]) belong_to[v] = x;\n\
    \        groups[x].insert(groups[x].end(), groups[y].begin(), groups[y].end());\n\
    \        groups[y].clear();\n    }\n    bool is_same(int x, int y) { return belong_to[x]\
    \ == belong_to[y]; }\n};\n"
  code: "/// @docs src/DataStructure/QuickFind.md\nstruct QuickFind {\n    std::vector<int>\
    \ belong_to;\n    std::vector<std::vector<int>> groups;\n    QuickFind(int n)\
    \ : belong_to(n), groups(n, std::vector<int>(1)) {\n        std::iota(belong_to.begin(),\
    \ belong_to.end(), 0);\n        for (int i = 0; i < n; i++) groups[i][0] = i;\n\
    \    }\n    void unite(int x, int y) {\n        x = belong_to[x], y = belong_to[y];\n\
    \        if (x == y) return;\n        if (groups[x].size() < groups[y].size())\
    \ std::swap(x, y);\n        // y\u3092x\u306B\u30DE\u30FC\u30B8\n        for (int\
    \ v : groups[y]) belong_to[v] = x;\n        groups[x].insert(groups[x].end(),\
    \ groups[y].begin(), groups[y].end());\n        groups[y].clear();\n    }\n  \
    \  bool is_same(int x, int y) { return belong_to[x] == belong_to[y]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/QuickFind.hpp
  requiredBy: []
  timestamp: '2020-04-27 23:52:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind_quick_find.test.cpp
documentation_of: src/DataStructure/QuickFind.hpp
layout: document
redirect_from:
- /library/src/DataStructure/QuickFind.hpp
- /library/src/DataStructure/QuickFind.hpp.html
title: src/DataStructure/QuickFind.hpp
---
## 概要
素集合データ構造のマージを高速化するテクニック。
n要素の集合のマージを何度も行う際に、サイズの小さい方を大きい方にマージすることでのべ移動回数がO(n log n)回で抑えられる。
これは、各要素に注目すると、別の集合に移動されるたびに属する集合のサイズが2倍以上になるのでO(log n)回しか移動されないことからわかる。

データをマージする一般的なテク(通称、マージテク)とも呼ばれる。
名前はiwiwiさんのブログに由来するが、消えてしまった…。
アカデミア用語はWeighted-Union Heuristic。
