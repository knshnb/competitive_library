---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Graph/TwoEdgeConnectedComponents.md
    links: []
  bundledCode: "#line 1 \"src/Graph/TwoEdgeConnectedComponents.hpp\"\n/// @docs src/Graph/TwoEdgeConnectedComponents.md\n\
    struct TwoEdgeConnectedComponents {\n    int n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<std::pair<int, int>> bridges;  // \u5217\u6319\u3055\u308C\
    \u305F\u6A4B\n    std::vector<int> belong_to;                // \u5404\u9802\u70B9\
    \u306E\u5C5E\u3059\u308B\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306Eindex\n\
    \    int size = -1;                             // \u4E8C\u91CD\u8FBA\u9023\u7D50\
    \u6210\u5206\u306E\u500B\u6570\n\n    TwoEdgeConnectedComponents(int n_) : n(n_),\
    \ g(n_) {}\n    TwoEdgeConnectedComponents(const std::vector<std::vector<int>>&\
    \ g_) : n(g_.size()), g(g_) {}\n    void build() {\n        // dfs\u6728\u3092\
    \u4F5C\u308A\u3001\u5404\u8FBA\u304C\u5F8C\u9000\u8FBA\u306B\u306F\u3055\u307E\
    \u308C\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092imos\u6CD5\u3067\u5224\u5B9A\
    \n        std::vector<int> imos(n);  // imos[i] == 0\u306A\u3089(i, par)\u304C\
    \u6A4B\u306B\u306A\u308B\u3088\u3046\u306B\u66F4\u65B0\n        std::vector<int>\
    \ flag(n);  // 0: unvisited, 1: ancestor of current v, 2: done(\u5F8C\u9000\u8FBA\
    \u306B\u306A\u308A\u3048\u306A\u3044)\n        auto dfs1 = [&](auto f, int v,\
    \ int prv) -> void {\n            flag[v] = 1;\n            bool skipped_parent\
    \ = false;\n            for (int s : g[v]) {\n                if (s == prv &&\
    \ !skipped_parent) {  // \u591A\u91CD\u8FBA\u306B\u5BFE\u5FDC\n              \
    \      skipped_parent = true;\n                    continue;\n               \
    \ }\n                if (flag[s] == 0) {\n                    f(f, s, v);\n  \
    \                  if (imos[s] == 0) bridges.push_back({v, s});\n            \
    \        imos[v] += imos[s];\n                } else if (flag[s] == 1) {  // \u5F8C\
    \u9000\u8FBA\n                    imos[v]++;\n                    imos[s]--;\n\
    \                }\n            }\n            flag[v] = 2;\n        };\n    \
    \    for (int i = 0; i < n; i++) {\n            if (flag[i] == 0) dfs1(dfs1, i,\
    \ -1);\n        }\n\n        // \u6A4B(imos[i] == 0\u3068\u306A\u308B\u3088\u3046\
    \u306A(i, par))\u3067\u533A\u5207\u3063\u3066\u4E8C\u91CD\u7DE8\u9023\u7D50\u6210\
    \u5206\u306B\u5206\u3051\u308B\n        int cur_group = 0;\n        belong_to.assign(n,\
    \ -1);\n        auto dfs2 = [&](auto f, int v) -> void {\n            for (int\
    \ s : g[v]) {\n                if (belong_to[s] != -1) continue;\n           \
    \     belong_to[s] = imos[s] == 0 ? cur_group++ : belong_to[v];\n            \
    \    f(f, s);\n            }\n        };\n        for (int i = 0; i < n; i++)\
    \ {\n            if (belong_to[i] == -1) {\n                belong_to[i] = cur_group++;\n\
    \                dfs2(dfs2, i);\n            }\n        }\n        size = cur_group;\n\
    \    }\n};\n"
  code: "/// @docs src/Graph/TwoEdgeConnectedComponents.md\nstruct TwoEdgeConnectedComponents\
    \ {\n    int n;\n    std::vector<std::vector<int>> g;\n    std::vector<std::pair<int,\
    \ int>> bridges;  // \u5217\u6319\u3055\u308C\u305F\u6A4B\n    std::vector<int>\
    \ belong_to;                // \u5404\u9802\u70B9\u306E\u5C5E\u3059\u308B\u4E8C\
    \u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306Eindex\n    int size = -1;          \
    \                   // \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\
    \n\n    TwoEdgeConnectedComponents(int n_) : n(n_), g(n_) {}\n    TwoEdgeConnectedComponents(const\
    \ std::vector<std::vector<int>>& g_) : n(g_.size()), g(g_) {}\n    void build()\
    \ {\n        // dfs\u6728\u3092\u4F5C\u308A\u3001\u5404\u8FBA\u304C\u5F8C\u9000\
    \u8FBA\u306B\u306F\u3055\u307E\u308C\u3066\u3044\u308B\u304B\u3069\u3046\u304B\
    \u3092imos\u6CD5\u3067\u5224\u5B9A\n        std::vector<int> imos(n);  // imos[i]\
    \ == 0\u306A\u3089(i, par)\u304C\u6A4B\u306B\u306A\u308B\u3088\u3046\u306B\u66F4\
    \u65B0\n        std::vector<int> flag(n);  // 0: unvisited, 1: ancestor of current\
    \ v, 2: done(\u5F8C\u9000\u8FBA\u306B\u306A\u308A\u3048\u306A\u3044)\n       \
    \ auto dfs1 = [&](auto f, int v, int prv) -> void {\n            flag[v] = 1;\n\
    \            bool skipped_parent = false;\n            for (int s : g[v]) {\n\
    \                if (s == prv && !skipped_parent) {  // \u591A\u91CD\u8FBA\u306B\
    \u5BFE\u5FDC\n                    skipped_parent = true;\n                   \
    \ continue;\n                }\n                if (flag[s] == 0) {\n        \
    \            f(f, s, v);\n                    if (imos[s] == 0) bridges.push_back({v,\
    \ s});\n                    imos[v] += imos[s];\n                } else if (flag[s]\
    \ == 1) {  // \u5F8C\u9000\u8FBA\n                    imos[v]++;\n           \
    \         imos[s]--;\n                }\n            }\n            flag[v] =\
    \ 2;\n        };\n        for (int i = 0; i < n; i++) {\n            if (flag[i]\
    \ == 0) dfs1(dfs1, i, -1);\n        }\n\n        // \u6A4B(imos[i] == 0\u3068\u306A\
    \u308B\u3088\u3046\u306A(i, par))\u3067\u533A\u5207\u3063\u3066\u4E8C\u91CD\u7DE8\
    \u9023\u7D50\u6210\u5206\u306B\u5206\u3051\u308B\n        int cur_group = 0;\n\
    \        belong_to.assign(n, -1);\n        auto dfs2 = [&](auto f, int v) -> void\
    \ {\n            for (int s : g[v]) {\n                if (belong_to[s] != -1)\
    \ continue;\n                belong_to[s] = imos[s] == 0 ? cur_group++ : belong_to[v];\n\
    \                f(f, s);\n            }\n        };\n        for (int i = 0;\
    \ i < n; i++) {\n            if (belong_to[i] == -1) {\n                belong_to[i]\
    \ = cur_group++;\n                dfs2(dfs2, i);\n            }\n        }\n \
    \       size = cur_group;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/TwoEdgeConnectedComponents.hpp
  requiredBy: []
  timestamp: '2020-04-03 18:09:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: src/Graph/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/src/Graph/TwoEdgeConnectedComponents.hpp
- /library/src/Graph/TwoEdgeConnectedComponents.hpp.html
title: src/Graph/TwoEdgeConnectedComponents.hpp
---
## 概要
木上のimos法による二重辺連結成分分解、O(E + V)。

dfs木に含まれる辺の内、後退辺によって挟まれていないものが橋となる。
imos[i] == 0と(i, par)が橋であることが同値になるようにimos法を行い、その辺で区切ることで二重辺連結成分分解している。

参考: https://www.slideshare.net/chokudai/arc039