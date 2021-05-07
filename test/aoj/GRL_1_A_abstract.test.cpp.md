---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/AbstractDijkstra.hpp
    title: src/Graph/AbstractDijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
  bundledCode: "#line 1 \"test/aoj/GRL_1_A_abstract.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\n#define ALL(v) std::begin(v), std::end(v)\n\
    struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun Aug 16 15:46:30 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Graph/AbstractDijkstra.hpp\"\n/// @docs src/Graph/AbstractDijkstra.md\n\
    template <class Dist, class Key, class Delta>  // Delta: Key from, (Key to, Dist\
    \ d -> void) update -> void\nstd::map<Key, Dist> dijkstra(Key s, Delta delta)\
    \ {\n    std::map<Key, Dist> dist;\n    using P = std::pair<Dist, Key>;\n    auto\
    \ cmp_first = [](const P& a, const P& b) { return a.first > b.first; };\n    std::priority_queue<P,\
    \ std::vector<P>, decltype(cmp_first)> q{cmp_first};\n    q.push({dist[s] = Dist(),\
    \ s});\n    while (!q.empty()) {\n        std::pair<Dist, Key> p = q.top();\n\
    \        q.pop();\n        if (dist[p.second] < p.first) continue;\n        delta(p.second,\
    \ [&](Key to, Dist d) -> void {\n            if (dist.count(to) && dist[to] <=\
    \ p.first + d) return;\n            q.push({dist[to] = p.first + d, to});\n  \
    \      });\n    }\n    return dist;\n}\n#line 20 \"test/aoj/GRL_1_A_abstract.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, m, r;\n    std::cin >>\
    \ n >> m >> r;\n    struct Edge {\n        Int to, cost;\n    };\n    std::vector<std::vector<Edge>>\
    \ g(n);\n    REP(i, m) {\n        Int s, t, d;\n        std::cin >> s >> t >>\
    \ d;\n        g[s].push_back({t, d});\n    }\n    auto delta = [&](Int from, auto\
    \ update) -> void {\n        for (Edge& edge : g[from]) {\n            update(edge.to,\
    \ edge.cost);\n        }\n    };\n    auto dist = dijkstra<Int>(r, delta);\n \
    \   REP(i, n) {\n        if (dist.count(i)) {\n            std::cout << dist[i]\
    \ << \"\\n\";\n        } else {\n            std::cout << \"INF\\n\";\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n\n\
    #include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\n#define\
    \ ALL(v) std::begin(v), std::end(v)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Sun Aug 16 15:46:30 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#include \"../../src/Graph/AbstractDijkstra.hpp\"\n\
    #undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, m, r;\n    std::cin >> n\
    \ >> m >> r;\n    struct Edge {\n        Int to, cost;\n    };\n    std::vector<std::vector<Edge>>\
    \ g(n);\n    REP(i, m) {\n        Int s, t, d;\n        std::cin >> s >> t >>\
    \ d;\n        g[s].push_back({t, d});\n    }\n    auto delta = [&](Int from, auto\
    \ update) -> void {\n        for (Edge& edge : g[from]) {\n            update(edge.to,\
    \ edge.cost);\n        }\n    };\n    auto dist = dijkstra<Int>(r, delta);\n \
    \   REP(i, n) {\n        if (dist.count(i)) {\n            std::cout << dist[i]\
    \ << \"\\n\";\n        } else {\n            std::cout << \"INF\\n\";\n      \
    \  }\n    }\n}\n"
  dependsOn:
  - src/Graph/AbstractDijkstra.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A_abstract.test.cpp
  requiredBy: []
  timestamp: '2020-08-26 17:58:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A_abstract.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A_abstract.test.cpp
- /verify/test/aoj/GRL_1_A_abstract.test.cpp.html
title: test/aoj/GRL_1_A_abstract.test.cpp
---
