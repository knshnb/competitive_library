---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0423.test.cpp
    title: test/aoj/0423.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/Dijkstra.hpp\"\ntemplate <class T, bool directed\
    \ = true> struct Dijkstra {\n    struct Edge {\n        int to;\n        T cost;\n\
    \    };\n    std::vector<std::vector<Edge>> g;\n    Dijkstra(int n) : g(n) {}\n\
    \    void add_edge(int u, int v, T cost) {\n        g[u].push_back({v, cost});\n\
    \        if (!directed) g[v].push_back({u, cost});\n    }\n    std::vector<T>\
    \ run(int s) {\n        std::vector<T> dist(g.size(), std::numeric_limits<T>::max()\
    \ / 2);\n        // {d, v}\n        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T,\
    \ int>>, std::greater<std::pair<T, int>>> q;\n        q.push({0, s});\n      \
    \  while (!q.empty()) {\n            std::pair<T, int> p = q.top();\n        \
    \    q.pop();\n            int v = p.second;\n            if (dist[v] <= p.first)\
    \ continue;\n            dist[v] = p.first;\n            for (const Edge& e :\
    \ g[v]) {\n                if (dist[e.to] <= p.first + e.cost) continue;  // \u5B9A\
    \u6570\u500D\u679D\u5208\u308A\n                q.emplace(p.first + e.cost, e.to);\n\
    \            }\n        }\n        return dist;\n    }\n};\n"
  code: "template <class T, bool directed = true> struct Dijkstra {\n    struct Edge\
    \ {\n        int to;\n        T cost;\n    };\n    std::vector<std::vector<Edge>>\
    \ g;\n    Dijkstra(int n) : g(n) {}\n    void add_edge(int u, int v, T cost) {\n\
    \        g[u].push_back({v, cost});\n        if (!directed) g[v].push_back({u,\
    \ cost});\n    }\n    std::vector<T> run(int s) {\n        std::vector<T> dist(g.size(),\
    \ std::numeric_limits<T>::max() / 2);\n        // {d, v}\n        std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> q;\n\
    \        q.push({0, s});\n        while (!q.empty()) {\n            std::pair<T,\
    \ int> p = q.top();\n            q.pop();\n            int v = p.second;\n   \
    \         if (dist[v] <= p.first) continue;\n            dist[v] = p.first;\n\
    \            for (const Edge& e : g[v]) {\n                if (dist[e.to] <= p.first\
    \ + e.cost) continue;  // \u5B9A\u6570\u500D\u679D\u5208\u308A\n             \
    \   q.emplace(p.first + e.cost, e.to);\n            }\n        }\n        return\
    \ dist;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2020-04-27 03:13:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0423.test.cpp
documentation_of: src/Graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/src/Graph/Dijkstra.hpp
- /library/src/Graph/Dijkstra.hpp.html
title: src/Graph/Dijkstra.hpp
---
