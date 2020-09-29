---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/LowestCommonAncestor.hpp\"\n// edge\u3092\u8CBC\
    \u3063\u305F\u3042\u3068\u306Bbuild()\u3092\u5FD8\u308C\u306A\u3044\uFF01\nstruct\
    \ TreeDoubling {\n    struct Edge {\n        int to, len;\n    };  // \u5834\u5408\
    \u306B\u5FDC\u3058\u3066\u66F8\u304D\u63DB\u3048\u308B\u3001to\u306F\u5FC5\u9808\
    \n    std::vector<std::vector<Edge>> g;\n    int n, size;  // MSB + 1\n    int\
    \ root;\n    std::vector<int> depth;\n    std::vector<std::vector<int>> parent;\
    \  // \u30C0\u30DF\u30FC\u9802\u70B9n(\u89AA\u3082n)\n    TreeDoubling(int n_)\
    \ : g(n_), n(n_), size(64 - __builtin_clzll(n_) + 1), depth(n_) {\n        parent.resize(size,\
    \ std::vector<int>(n + 1, n));\n    }\n    void build(int root_ = 0) {\n     \
    \   auto dfs = [&](auto f, int v, int prv) -> void {\n            for (Edge& e\
    \ : g[v]) {\n                if (e.to == prv) continue;\n                depth[e.to]\
    \ = depth[v] + e.len;\n                parent[0][e.to] = v;\n                f(f,\
    \ e.to, v);\n            }\n        };\n        root = root_;\n        depth[root]\
    \ = 0;\n        dfs(dfs, root, -1);\n        for (int k = 0; k < size - 1; k++)\
    \ {\n            for (int i = 0; i < n; i++) {\n                parent[k + 1][i]\
    \ = parent[k][parent[k][i]];\n            }\n        }\n    }\n\n    // v\u304B\
    \u3089d\u500B\u5206\u89AA\u306B\u3055\u304B\u306E\u307C\u3063\u305F\u9802\u70B9\
    \u3001root\u3088\u308A\u3082\u4E0A\u306Fn\u3092\u8FD4\u3059\n    int query(int\
    \ v, int d) {\n        int ret = v;\n        for (int j = 0; j < size; j++) {\n\
    \            if (d >> j & 1) ret = parent[j][ret];\n        }\n        return\
    \ ret;\n    }\n    int lca(int u, int v) {\n        if (depth[u] > depth[v]) std::swap(u,\
    \ v);\n        v = query(v, depth[v] - depth[u]);\n        if (u == v) return\
    \ u;\n\n        for (int j = size - 1; j >= 0; j--) {\n            if (parent[j][u]\
    \ == parent[j][v]) continue;\n            u = parent[j][u];\n            v = parent[j][v];\n\
    \        }\n        assert(parent[0][u] == parent[0][v]);\n        return parent[0][u];\n\
    \    }\n    int dist(int u, int v) { return depth[u] + depth[v] - depth[lca(u,\
    \ v)] * 2; }\n};\n"
  code: "// edge\u3092\u8CBC\u3063\u305F\u3042\u3068\u306Bbuild()\u3092\u5FD8\u308C\
    \u306A\u3044\uFF01\nstruct TreeDoubling {\n    struct Edge {\n        int to,\
    \ len;\n    };  // \u5834\u5408\u306B\u5FDC\u3058\u3066\u66F8\u304D\u63DB\u3048\
    \u308B\u3001to\u306F\u5FC5\u9808\n    std::vector<std::vector<Edge>> g;\n    int\
    \ n, size;  // MSB + 1\n    int root;\n    std::vector<int> depth;\n    std::vector<std::vector<int>>\
    \ parent;  // \u30C0\u30DF\u30FC\u9802\u70B9n(\u89AA\u3082n)\n    TreeDoubling(int\
    \ n_) : g(n_), n(n_), size(64 - __builtin_clzll(n_) + 1), depth(n_) {\n      \
    \  parent.resize(size, std::vector<int>(n + 1, n));\n    }\n    void build(int\
    \ root_ = 0) {\n        auto dfs = [&](auto f, int v, int prv) -> void {\n   \
    \         for (Edge& e : g[v]) {\n                if (e.to == prv) continue;\n\
    \                depth[e.to] = depth[v] + e.len;\n                parent[0][e.to]\
    \ = v;\n                f(f, e.to, v);\n            }\n        };\n        root\
    \ = root_;\n        depth[root] = 0;\n        dfs(dfs, root, -1);\n        for\
    \ (int k = 0; k < size - 1; k++) {\n            for (int i = 0; i < n; i++) {\n\
    \                parent[k + 1][i] = parent[k][parent[k][i]];\n            }\n\
    \        }\n    }\n\n    // v\u304B\u3089d\u500B\u5206\u89AA\u306B\u3055\u304B\
    \u306E\u307C\u3063\u305F\u9802\u70B9\u3001root\u3088\u308A\u3082\u4E0A\u306Fn\u3092\
    \u8FD4\u3059\n    int query(int v, int d) {\n        int ret = v;\n        for\
    \ (int j = 0; j < size; j++) {\n            if (d >> j & 1) ret = parent[j][ret];\n\
    \        }\n        return ret;\n    }\n    int lca(int u, int v) {\n        if\
    \ (depth[u] > depth[v]) std::swap(u, v);\n        v = query(v, depth[v] - depth[u]);\n\
    \        if (u == v) return u;\n\n        for (int j = size - 1; j >= 0; j--)\
    \ {\n            if (parent[j][u] == parent[j][v]) continue;\n            u =\
    \ parent[j][u];\n            v = parent[j][v];\n        }\n        assert(parent[0][u]\
    \ == parent[0][v]);\n        return parent[0][u];\n    }\n    int dist(int u,\
    \ int v) { return depth[u] + depth[v] - depth[lca(u, v)] * 2; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2020-04-01 13:39:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
documentation_of: src/Graph/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/src/Graph/LowestCommonAncestor.hpp
- /library/src/Graph/LowestCommonAncestor.hpp.html
title: src/Graph/LowestCommonAncestor.hpp
---
