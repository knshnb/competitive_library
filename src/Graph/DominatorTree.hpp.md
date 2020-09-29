---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0294.test.cpp
    title: test/aoj/0294.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dominatortree.test.cpp
    title: test/yosupo/dominatortree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Graph/DominatorTree.md
    links: []
  bundledCode: "#line 1 \"src/Graph/DominatorTree.hpp\"\n/// @docs src/Graph/DominatorTree.md\n\
    // \u6839\u4ED8\u304D\u68EE\u3068\u3001\u6839\u304B\u3089\u5404\u9802\u70B9\u307E\
    \u3067\u306Eaggregation\u3092\u7BA1\u7406\ntemplate <class T, class F> struct\
    \ DirectedUnionFind {\n    std::vector<int> par;\n    std::vector<T> val;\n  \
    \  F op;\n    DirectedUnionFind(F op_) : op(op_) {}\n    void set_by_vector(const\
    \ std::vector<T>& val_) {\n        par.resize(val_.size()), std::iota(par.begin(),\
    \ par.end(), 0);\n        val = val_;\n    }\n    void set_by_value(int n, T a)\
    \ {\n        par.resize(n), std::iota(par.begin(), par.end(), 0);\n        val.resize(n,\
    \ a);\n    }\n    int compress(int v) {\n        if (par[v] == v) return v;\n\
    \        int root = compress(par[v]);\n        val[v] = op(val[par[v]], val[v]);\n\
    \        return par[v] = root;\n    }\n    int eval(int v) {\n        compress(v);\n\
    \        return val[v];\n    }\n    // root\u3092to\u306B\u3064\u306A\u3052\u308B\
    \n    void link(int to, int root) {\n        assert(par[root] == root);\n    \
    \    par[root] = to;\n    }\n};\ntemplate <class T, class F> DirectedUnionFind<T,\
    \ F> make_directed_unionfind(F op_) {\n    return DirectedUnionFind<T, F>(op_);\n\
    }\n\n// \u89AA\u3092\u3055\u3059vector\u3092\u8FD4\u3059\u3002root\u306E\u89AA\
    \u306Froot\u3001root\u304B\u3089\u5230\u9054\u3067\u304D\u306A\u3044\u9802\u70B9\
    \u306E\u89AA\u306F-1\nstd::vector<int> construct_domnator_tree(const std::vector<std::vector<int>>&\
    \ edge, int root) {\n    int n = edge.size();\n    std::vector<std::vector<int>>\
    \ redge(n);\n    for (int u = 0; u < n; u++)\n        for (int v : edge[u]) redge[v].push_back(u);\n\
    \    // step1: dfs\u6728\u3092\u4F5C\u308B\n    std::vector<int> par(n, -1), to_vertex,\
    \ to_ord(n, -1);\n    auto dfs = [&](auto&& self, int v) -> void {\n        to_ord[v]\
    \ = to_vertex.size();\n        to_vertex.push_back(v);\n        for (int u : edge[v])\
    \ {\n            if (to_ord[u] != -1) continue;\n            self(self, u);\n\
    \            par[to_ord[u]] = to_ord[v];\n        }\n    };\n    dfs(dfs, root);\n\
    \    int m = to_vertex.size();  // root\u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\
    \u9802\u70B9\u6570\n    // dfs\u9006\u9806\n    std::vector<int> sdom(m), U(m,\
    \ -1);\n    for (int i = 1; i < m; i++) sdom[i] = i;  // Theorem 4\u306E\u5DE6\
    \u5074\u3092\u30AB\u30D0\u30FC\u3067\u304D\u308B\u3088\u3046\u306B\u3001i\u3067\
    \u521D\u671F\u5316\u3057\u3066\u304A\u304F\n    auto uf = make_directed_unionfind<int>([&](int\
    \ i, int j) { return sdom[i] < sdom[j] ? i : j; });\n    uf.set_by_value(m, 0);\n\
    \    for (int i = 0; i < m; i++) uf.val[i] = i;\n    std::vector<std::vector<int>>\
    \ bucket(n);\n    for (int i = m - 1; i >= 1; i--) {\n        // step2: dfs\u9006\
    \u9806\u306Bsemidominator\u3092\u6C42\u3081\u308B(Theorem 4)\n        for (int\
    \ v : redge[to_vertex[i]]) {\n            int j = to_ord[v];\n            if (j\
    \ == -1) continue;  // root\u304B\u3089\u5230\u9054\u3067\u304D\u306A\u3044\u9802\
    \u70B9\n            sdom[i] = std::min(sdom[i], sdom[uf.eval(j)]);\n        }\n\
    \        uf.link(par[i], i);\n        // step3: Corollary 1\n        bucket[sdom[i]].push_back(i);\n\
    \        for (int j : bucket[par[i]]) U[j] = uf.eval(j);\n    }\n    // dfs\u9806\
    \u306Bimmediate dominator\u3092\u6C42\u3081\u308B\n    std::vector<int> idom(n,\
    \ -1);  // dfs\u9806\u5E8F\u3067\u306F\u306A\u304F\u3067\u306F\u306A\u304F\u5143\
    \u306E\u9802\u70B9\u756A\u53F7\u3067\u8868\u3057\u3066\u3044\u308B\u3053\u3068\
    \u306B\u6CE8\u610F\uFF01\n    for (int i = 1; i < m; i++) {\n        int u = U[i];\n\
    \        idom[to_vertex[i]] = sdom[i] == sdom[u] ? to_vertex[sdom[i]] : idom[to_vertex[u]];\n\
    \    }\n    idom[root] = root;\n    return idom;\n}\n"
  code: "/// @docs src/Graph/DominatorTree.md\n// \u6839\u4ED8\u304D\u68EE\u3068\u3001\
    \u6839\u304B\u3089\u5404\u9802\u70B9\u307E\u3067\u306Eaggregation\u3092\u7BA1\u7406\
    \ntemplate <class T, class F> struct DirectedUnionFind {\n    std::vector<int>\
    \ par;\n    std::vector<T> val;\n    F op;\n    DirectedUnionFind(F op_) : op(op_)\
    \ {}\n    void set_by_vector(const std::vector<T>& val_) {\n        par.resize(val_.size()),\
    \ std::iota(par.begin(), par.end(), 0);\n        val = val_;\n    }\n    void\
    \ set_by_value(int n, T a) {\n        par.resize(n), std::iota(par.begin(), par.end(),\
    \ 0);\n        val.resize(n, a);\n    }\n    int compress(int v) {\n        if\
    \ (par[v] == v) return v;\n        int root = compress(par[v]);\n        val[v]\
    \ = op(val[par[v]], val[v]);\n        return par[v] = root;\n    }\n    int eval(int\
    \ v) {\n        compress(v);\n        return val[v];\n    }\n    // root\u3092\
    to\u306B\u3064\u306A\u3052\u308B\n    void link(int to, int root) {\n        assert(par[root]\
    \ == root);\n        par[root] = to;\n    }\n};\ntemplate <class T, class F> DirectedUnionFind<T,\
    \ F> make_directed_unionfind(F op_) {\n    return DirectedUnionFind<T, F>(op_);\n\
    }\n\n// \u89AA\u3092\u3055\u3059vector\u3092\u8FD4\u3059\u3002root\u306E\u89AA\
    \u306Froot\u3001root\u304B\u3089\u5230\u9054\u3067\u304D\u306A\u3044\u9802\u70B9\
    \u306E\u89AA\u306F-1\nstd::vector<int> construct_domnator_tree(const std::vector<std::vector<int>>&\
    \ edge, int root) {\n    int n = edge.size();\n    std::vector<std::vector<int>>\
    \ redge(n);\n    for (int u = 0; u < n; u++)\n        for (int v : edge[u]) redge[v].push_back(u);\n\
    \    // step1: dfs\u6728\u3092\u4F5C\u308B\n    std::vector<int> par(n, -1), to_vertex,\
    \ to_ord(n, -1);\n    auto dfs = [&](auto&& self, int v) -> void {\n        to_ord[v]\
    \ = to_vertex.size();\n        to_vertex.push_back(v);\n        for (int u : edge[v])\
    \ {\n            if (to_ord[u] != -1) continue;\n            self(self, u);\n\
    \            par[to_ord[u]] = to_ord[v];\n        }\n    };\n    dfs(dfs, root);\n\
    \    int m = to_vertex.size();  // root\u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\
    \u9802\u70B9\u6570\n    // dfs\u9006\u9806\n    std::vector<int> sdom(m), U(m,\
    \ -1);\n    for (int i = 1; i < m; i++) sdom[i] = i;  // Theorem 4\u306E\u5DE6\
    \u5074\u3092\u30AB\u30D0\u30FC\u3067\u304D\u308B\u3088\u3046\u306B\u3001i\u3067\
    \u521D\u671F\u5316\u3057\u3066\u304A\u304F\n    auto uf = make_directed_unionfind<int>([&](int\
    \ i, int j) { return sdom[i] < sdom[j] ? i : j; });\n    uf.set_by_value(m, 0);\n\
    \    for (int i = 0; i < m; i++) uf.val[i] = i;\n    std::vector<std::vector<int>>\
    \ bucket(n);\n    for (int i = m - 1; i >= 1; i--) {\n        // step2: dfs\u9006\
    \u9806\u306Bsemidominator\u3092\u6C42\u3081\u308B(Theorem 4)\n        for (int\
    \ v : redge[to_vertex[i]]) {\n            int j = to_ord[v];\n            if (j\
    \ == -1) continue;  // root\u304B\u3089\u5230\u9054\u3067\u304D\u306A\u3044\u9802\
    \u70B9\n            sdom[i] = std::min(sdom[i], sdom[uf.eval(j)]);\n        }\n\
    \        uf.link(par[i], i);\n        // step3: Corollary 1\n        bucket[sdom[i]].push_back(i);\n\
    \        for (int j : bucket[par[i]]) U[j] = uf.eval(j);\n    }\n    // dfs\u9806\
    \u306Bimmediate dominator\u3092\u6C42\u3081\u308B\n    std::vector<int> idom(n,\
    \ -1);  // dfs\u9806\u5E8F\u3067\u306F\u306A\u304F\u3067\u306F\u306A\u304F\u5143\
    \u306E\u9802\u70B9\u756A\u53F7\u3067\u8868\u3057\u3066\u3044\u308B\u3053\u3068\
    \u306B\u6CE8\u610F\uFF01\n    for (int i = 1; i < m; i++) {\n        int u = U[i];\n\
    \        idom[to_vertex[i]] = sdom[i] == sdom[u] ? to_vertex[sdom[i]] : idom[to_vertex[u]];\n\
    \    }\n    idom[root] = root;\n    return idom;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/DominatorTree.hpp
  requiredBy: []
  timestamp: '2020-08-03 01:19:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0294.test.cpp
  - test/yosupo/dominatortree.test.cpp
documentation_of: src/Graph/DominatorTree.hpp
layout: document
redirect_from:
- /library/src/Graph/DominatorTree.hpp
- /library/src/Graph/DominatorTree.hpp.html
title: src/Graph/DominatorTree.hpp
---
## 概要
有向グラフのDominator Treeを返す。
計算量はO(m log(n))

## アルゴリズム
大変だった…

## 参考
元論文: https://www.cs.princeton.edu/courses/archive/spr03/cs423/download/dominators.pdf
sigmaさんのブログ: http://sigma425.hatenablog.com/entry/2015/12/25/224053
