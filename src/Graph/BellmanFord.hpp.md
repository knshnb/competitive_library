---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/BellmanFord.hpp\"\n// O(EV)\u3001\u8CA0\u306E\u30B5\
    \u30A4\u30AF\u30EB\u3092\u901A\u3063\u305F\u5F8C\u306B\u5230\u9054\u3067\u304D\
    \u308B\u70B9\u306B\u3064\u3044\u3066\u306F-INF, \u5230\u9054\u4E0D\u53EF\u80FD\
    \u306A\u70B9\u306B\u3064\u3044\u3066\u306FINF\u3092\u8FD4\u3059\ntemplate <class\
    \ T> struct BellmanFord {\n    struct Edge {\n        int from, to;\n        T\
    \ cost;\n    };\n    const T INF = std::numeric_limits<T>::max() / 2;\n    int\
    \ n;\n    std::vector<Edge> edges;\n\n    BellmanFord(int n_) : n(n_) {}\n   \
    \ void add_edge(int u, int v, T cost) { edges.push_back({u, v, cost}); }\n   \
    \ std::vector<T> run(int s) {\n        std::vector<T> dist(n, INF);\n        dist[s]\
    \ = 0;\n        for (int i = 0; i < n - 1; i++) {\n            for (Edge& e :\
    \ edges) {\n                if (dist[e.from] == INF) continue;\n             \
    \   dist[e.to] = std::min(dist[e.to], dist[e.from] + e.cost);\n            }\n\
    \        }\n        for (Edge& e : edges) {\n            // s\u304B\u3089\u5230\
    \u9054\u3067\u304D\u308B\u8CA0\u306E\u30B5\u30A4\u30AF\u30EB\u691C\u51FA\n   \
    \         if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to]) {\n    \
    \            dist[e.from] = -INF;\n                dist[e.to] = -INF;\n      \
    \      }\n        }\n        for (int i = 0; i < n - 1; i++) {\n            for\
    \ (Edge& e : edges) {\n                if (dist[e.from] == -INF) dist[e.to] =\
    \ -INF;\n            }\n        }\n        return dist;\n    }\n};\n"
  code: "// O(EV)\u3001\u8CA0\u306E\u30B5\u30A4\u30AF\u30EB\u3092\u901A\u3063\u305F\
    \u5F8C\u306B\u5230\u9054\u3067\u304D\u308B\u70B9\u306B\u3064\u3044\u3066\u306F\
    -INF, \u5230\u9054\u4E0D\u53EF\u80FD\u306A\u70B9\u306B\u3064\u3044\u3066\u306F\
    INF\u3092\u8FD4\u3059\ntemplate <class T> struct BellmanFord {\n    struct Edge\
    \ {\n        int from, to;\n        T cost;\n    };\n    const T INF = std::numeric_limits<T>::max()\
    \ / 2;\n    int n;\n    std::vector<Edge> edges;\n\n    BellmanFord(int n_) :\
    \ n(n_) {}\n    void add_edge(int u, int v, T cost) { edges.push_back({u, v, cost});\
    \ }\n    std::vector<T> run(int s) {\n        std::vector<T> dist(n, INF);\n \
    \       dist[s] = 0;\n        for (int i = 0; i < n - 1; i++) {\n            for\
    \ (Edge& e : edges) {\n                if (dist[e.from] == INF) continue;\n  \
    \              dist[e.to] = std::min(dist[e.to], dist[e.from] + e.cost);\n   \
    \         }\n        }\n        for (Edge& e : edges) {\n            // s\u304B\
    \u3089\u5230\u9054\u3067\u304D\u308B\u8CA0\u306E\u30B5\u30A4\u30AF\u30EB\u691C\
    \u51FA\n            if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to])\
    \ {\n                dist[e.from] = -INF;\n                dist[e.to] = -INF;\n\
    \            }\n        }\n        for (int i = 0; i < n - 1; i++) {\n       \
    \     for (Edge& e : edges) {\n                if (dist[e.from] == -INF) dist[e.to]\
    \ = -INF;\n            }\n        }\n        return dist;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/BellmanFord.hpp
  requiredBy: []
  timestamp: '2020-04-28 00:31:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
documentation_of: src/Graph/BellmanFord.hpp
layout: document
redirect_from:
- /library/src/Graph/BellmanFord.hpp
- /library/src/Graph/BellmanFord.hpp.html
title: src/Graph/BellmanFord.hpp
---
