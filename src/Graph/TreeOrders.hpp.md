---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: src/Graph/TreeOrders.md
    links: []
  bundledCode: "#line 1 \"src/Graph/TreeOrders.hpp\"\n/// @docs src/Graph/TreeOrders.md\n\
    std::vector<int> pre_order(const std::vector<std::vector<int>>& g, int s = 0)\
    \ {\n    std::vector<int> ord;\n    ord.reserve(g.size());\n    auto dfs = [&g,\
    \ &ord](auto&& self, int v, int prv) -> void {\n        ord.push_back(v);\n  \
    \      for (int s : g[v]) {\n            if (s == prv) continue;\n           \
    \ self(self, s, v);\n        }\n    };\n    dfs(dfs, s, -1);\n    return ord;\n\
    }\nstd::vector<int> post_order(const std::vector<std::vector<int>>& g, int s =\
    \ 0) {\n    std::vector<int> ord;\n    ord.reserve(g.size());\n    auto dfs =\
    \ [&g, &ord](auto&& self, int v, int prv) -> void {\n        for (int s : g[v])\
    \ {\n            if (s == prv) continue;\n            self(self, s, v);\n    \
    \    }\n        ord.push_back(v);\n    };\n    dfs(dfs, s, -1);\n    return ord;\n\
    }\n"
  code: "/// @docs src/Graph/TreeOrders.md\nstd::vector<int> pre_order(const std::vector<std::vector<int>>&\
    \ g, int s = 0) {\n    std::vector<int> ord;\n    ord.reserve(g.size());\n   \
    \ auto dfs = [&g, &ord](auto&& self, int v, int prv) -> void {\n        ord.push_back(v);\n\
    \        for (int s : g[v]) {\n            if (s == prv) continue;\n         \
    \   self(self, s, v);\n        }\n    };\n    dfs(dfs, s, -1);\n    return ord;\n\
    }\nstd::vector<int> post_order(const std::vector<std::vector<int>>& g, int s =\
    \ 0) {\n    std::vector<int> ord;\n    ord.reserve(g.size());\n    auto dfs =\
    \ [&g, &ord](auto&& self, int v, int prv) -> void {\n        for (int s : g[v])\
    \ {\n            if (s == prv) continue;\n            self(self, s, v);\n    \
    \    }\n        ord.push_back(v);\n    };\n    dfs(dfs, s, -1);\n    return ord;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/TreeOrders.hpp
  requiredBy: []
  timestamp: '2020-07-12 16:30:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/TreeOrders.hpp
layout: document
redirect_from:
- /library/src/Graph/TreeOrders.hpp
- /library/src/Graph/TreeOrders.hpp.html
title: src/Graph/TreeOrders.hpp
---
## 概要
木を受け取り、dfs順を返す。
pre_order: トップダウン。dfsで訪れた順。
post_order: ボトムアップ。木dpとかで使う。
