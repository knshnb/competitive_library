---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A_abstract.test.cpp
    title: test/aoj/GRL_1_A_abstract.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Graph/AbstractDijkstra.md
    links: []
  bundledCode: "#line 1 \"src/Graph/AbstractDijkstra.hpp\"\n/// @docs src/Graph/AbstractDijkstra.md\n\
    template <class Dist, class Key, class Delta>  // Delta: Key from, (Key to, Dist\
    \ d -> void) update -> void\nstd::map<Key, Dist> dijkstra(Key s, Delta delta)\
    \ {\n    std::map<Key, Dist> dist;\n    using P = std::pair<Dist, Key>;\n    auto\
    \ cmp_first = [](const P& a, const P& b) { return a.first > b.first; };\n    std::priority_queue<P,\
    \ std::vector<P>, decltype(cmp_first)> q{cmp_first};\n    q.push({dist[s] = Dist(),\
    \ s});\n    while (!q.empty()) {\n        std::pair<Dist, Key> p = q.top();\n\
    \        q.pop();\n        if (dist[p.second] < p.first) continue;\n        delta(p.second,\
    \ [&](Key to, Dist d) -> void {\n            if (dist.count(to) && dist[to] <=\
    \ p.first + d) return;\n            q.push({dist[to] = p.first + d, to});\n  \
    \      });\n    }\n    return dist;\n}\n"
  code: "/// @docs src/Graph/AbstractDijkstra.md\ntemplate <class Dist, class Key,\
    \ class Delta>  // Delta: Key from, (Key to, Dist d -> void) update -> void\n\
    std::map<Key, Dist> dijkstra(Key s, Delta delta) {\n    std::map<Key, Dist> dist;\n\
    \    using P = std::pair<Dist, Key>;\n    auto cmp_first = [](const P& a, const\
    \ P& b) { return a.first > b.first; };\n    std::priority_queue<P, std::vector<P>,\
    \ decltype(cmp_first)> q{cmp_first};\n    q.push({dist[s] = Dist(), s});\n   \
    \ while (!q.empty()) {\n        std::pair<Dist, Key> p = q.top();\n        q.pop();\n\
    \        if (dist[p.second] < p.first) continue;\n        delta(p.second, [&](Key\
    \ to, Dist d) -> void {\n            if (dist.count(to) && dist[to] <= p.first\
    \ + d) return;\n            q.push({dist[to] = p.first + d, to});\n        });\n\
    \    }\n    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/AbstractDijkstra.hpp
  requiredBy: []
  timestamp: '2020-08-26 17:58:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_A_abstract.test.cpp
documentation_of: src/Graph/AbstractDijkstra.hpp
layout: document
redirect_from:
- /library/src/Graph/AbstractDijkstra.hpp
- /library/src/Graph/AbstractDijkstra.hpp.html
title: src/Graph/AbstractDijkstra.hpp
---
## 概要
抽象化dijkstra。
記事: https://blog.knshnb.com/posts/abstract-dijkstra/

## 参考
https://niuez.github.io/posts/impl_abstract_dijkstra/
