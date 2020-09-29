---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/BellmanFord.hpp
    title: src/Graph/BellmanFord.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Tue Apr 28 00:15:10 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Graph/BellmanFord.hpp\"\n// O(EV)\u3001\u8CA0\u306E\u30B5\u30A4\u30AF\
    \u30EB\u3092\u901A\u3063\u305F\u5F8C\u306B\u5230\u9054\u3067\u304D\u308B\u70B9\
    \u306B\u3064\u3044\u3066\u306F-INF, \u5230\u9054\u4E0D\u53EF\u80FD\u306A\u70B9\
    \u306B\u3064\u3044\u3066\u306FINF\u3092\u8FD4\u3059\ntemplate <class T> struct\
    \ BellmanFord {\n    struct Edge {\n        int from, to;\n        T cost;\n \
    \   };\n    const T INF = std::numeric_limits<T>::max() / 2;\n    int n;\n   \
    \ std::vector<Edge> edges;\n\n    BellmanFord(int n_) : n(n_) {}\n    void add_edge(int\
    \ u, int v, T cost) { edges.push_back({u, v, cost}); }\n    std::vector<T> run(int\
    \ s) {\n        std::vector<T> dist(n, INF);\n        dist[s] = 0;\n        for\
    \ (int i = 0; i < n - 1; i++) {\n            for (Edge& e : edges) {\n       \
    \         if (dist[e.from] == INF) continue;\n                dist[e.to] = std::min(dist[e.to],\
    \ dist[e.from] + e.cost);\n            }\n        }\n        for (Edge& e : edges)\
    \ {\n            // s\u304B\u3089\u5230\u9054\u3067\u304D\u308B\u8CA0\u306E\u30B5\
    \u30A4\u30AF\u30EB\u691C\u51FA\n            if (dist[e.to] < INF && dist[e.from]\
    \ + e.cost < dist[e.to]) {\n                dist[e.from] = -INF;\n           \
    \     dist[e.to] = -INF;\n            }\n        }\n        for (int i = 0; i\
    \ < n - 1; i++) {\n            for (Edge& e : edges) {\n                if (dist[e.from]\
    \ == -INF) dist[e.to] = -INF;\n            }\n        }\n        return dist;\n\
    \    }\n};\n#line 19 \"test/aoj/GRL_1_B.test.cpp\"\n#undef CALL_FROM_TEST\n\n\
    signed main() {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n    BellmanFord<Int>\
    \ bf(n);\n    REP(_, m) {\n        Int u, v, c;\n        std::cin >> u >> v >>\
    \ c;\n        bf.add_edge(u, v, c);\n    }\n    auto dist = bf.run(s);\n    if\
    \ (std::find(dist.begin(), dist.end(), -bf.INF) != dist.end()) {\n        std::cout\
    \ << \"NEGATIVE CYCLE\" << std::endl;\n    } else {\n        for (Int d : dist)\
    \ {\n            if (d == bf.INF) {\n                std::cout << \"INF\" << \"\
    \\n\";\n            } else {\n                std::cout << d << \"\\n\";\n   \
    \         }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Tue Apr 28 00:15:10 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Graph/BellmanFord.hpp\"\n#undef CALL_FROM_TEST\n\nsigned\
    \ main() {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n    BellmanFord<Int>\
    \ bf(n);\n    REP(_, m) {\n        Int u, v, c;\n        std::cin >> u >> v >>\
    \ c;\n        bf.add_edge(u, v, c);\n    }\n    auto dist = bf.run(s);\n    if\
    \ (std::find(dist.begin(), dist.end(), -bf.INF) != dist.end()) {\n        std::cout\
    \ << \"NEGATIVE CYCLE\" << std::endl;\n    } else {\n        for (Int d : dist)\
    \ {\n            if (d == bf.INF) {\n                std::cout << \"INF\" << \"\
    \\n\";\n            } else {\n                std::cout << d << \"\\n\";\n   \
    \         }\n        }\n    }\n}\n"
  dependsOn:
  - src/Graph/BellmanFord.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-04-28 00:31:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
