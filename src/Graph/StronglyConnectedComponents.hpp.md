---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/TwoSat.hpp
    title: src/Graph/TwoSat.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Graph/StronglyConnectedComponents.md
    links: []
  bundledCode: "#line 1 \"src/Graph/StronglyConnectedComponents.hpp\"\n/// @docs src/Graph/StronglyConnectedComponents.md\n\
    struct StronglyConnectedComponents {\n    int n, size;  // size\u306Fbuild()\u5F8C\
    \u306B\u5F37\u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u683C\u7D0D\n    std::vector<std::vector<int>>\
    \ edge, redge;\n    std::vector<int> belong_to;\n    StronglyConnectedComponents(int\
    \ n_) : n(n_), edge(n_), redge(n_) {}\n    void add_edge(int u, int v) {\n   \
    \     assert(0 <= u && u < n && 0 <= v && v < n);\n        edge[u].push_back(v);\n\
    \        redge[v].push_back(u);\n    }\n    void build() {\n        std::vector<int>\
    \ ord;  // post-order\n        // \u6B63\u65B9\u5411\u306E\u8FBA\u3067dfs\u3001\
    post-order\u3092\u3075\u308B\n        std::vector<bool> visited(n, false);\n \
    \       auto dfs1 = [&](auto f, int v) -> void {\n            if (visited[v])\
    \ return;\n            visited[v] = true;\n            for (int s : edge[v]) {\n\
    \                f(f, s);\n            }\n            ord.push_back(v);\n    \
    \    };\n        for (int i = 0; i < n; i++) dfs1(dfs1, i);\n\n        // post-order\u9006\
    \u9806\u306Bdfs\u3001\u5230\u9054\u53EF\u80FD\u306A\u540C\u5024\u985E\u306B\u5206\
    \u3051\u308B\n        belong_to.assign(n, -1);\n        int cur_group = 0;\n \
    \       auto dfs2 = [&](auto f, int v) -> void {\n            if (belong_to[v]\
    \ != -1) return;\n            belong_to[v] = cur_group;\n            for (int\
    \ s : redge[v]) {\n                f(f, s);\n            }\n        };\n     \
    \   std::reverse(ord.begin(), ord.end());\n        for (int i : ord) {\n     \
    \       if (belong_to[i] == -1) {\n                dfs2(dfs2, i);\n          \
    \      cur_group++;\n            }\n        }\n        size = cur_group;\n   \
    \ }\n    bool has_loop() {\n        build();\n        return size < n;\n    }\n\
    };\n"
  code: "/// @docs src/Graph/StronglyConnectedComponents.md\nstruct StronglyConnectedComponents\
    \ {\n    int n, size;  // size\u306Fbuild()\u5F8C\u306B\u5F37\u9023\u7D50\u6210\
    \u5206\u306E\u6570\u3092\u683C\u7D0D\n    std::vector<std::vector<int>> edge,\
    \ redge;\n    std::vector<int> belong_to;\n    StronglyConnectedComponents(int\
    \ n_) : n(n_), edge(n_), redge(n_) {}\n    void add_edge(int u, int v) {\n   \
    \     assert(0 <= u && u < n && 0 <= v && v < n);\n        edge[u].push_back(v);\n\
    \        redge[v].push_back(u);\n    }\n    void build() {\n        std::vector<int>\
    \ ord;  // post-order\n        // \u6B63\u65B9\u5411\u306E\u8FBA\u3067dfs\u3001\
    post-order\u3092\u3075\u308B\n        std::vector<bool> visited(n, false);\n \
    \       auto dfs1 = [&](auto f, int v) -> void {\n            if (visited[v])\
    \ return;\n            visited[v] = true;\n            for (int s : edge[v]) {\n\
    \                f(f, s);\n            }\n            ord.push_back(v);\n    \
    \    };\n        for (int i = 0; i < n; i++) dfs1(dfs1, i);\n\n        // post-order\u9006\
    \u9806\u306Bdfs\u3001\u5230\u9054\u53EF\u80FD\u306A\u540C\u5024\u985E\u306B\u5206\
    \u3051\u308B\n        belong_to.assign(n, -1);\n        int cur_group = 0;\n \
    \       auto dfs2 = [&](auto f, int v) -> void {\n            if (belong_to[v]\
    \ != -1) return;\n            belong_to[v] = cur_group;\n            for (int\
    \ s : redge[v]) {\n                f(f, s);\n            }\n        };\n     \
    \   std::reverse(ord.begin(), ord.end());\n        for (int i : ord) {\n     \
    \       if (belong_to[i] == -1) {\n                dfs2(dfs2, i);\n          \
    \      cur_group++;\n            }\n        }\n        size = cur_group;\n   \
    \ }\n    bool has_loop() {\n        build();\n        return size < n;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/StronglyConnectedComponents.hpp
  requiredBy:
  - src/Graph/TwoSat.hpp
  timestamp: '2020-04-03 18:03:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/scc.test.cpp
  - test/yosupo/two_sat.test.cpp
documentation_of: src/Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/src/Graph/StronglyConnectedComponents.hpp
- /library/src/Graph/StronglyConnectedComponents.hpp.html
title: src/Graph/StronglyConnectedComponents.hpp
---
## 概要
Kosaraju' algorithm(https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm)による強連結成分分解。O(E + V)。

2回dfsを行う。
1回目のdfsでpost-orderを記録。
2回目はそれの逆順に始点を変えてdfsを行い、到達可能な頂点集合は同じ強連結に属することがわかる。
