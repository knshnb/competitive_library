---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/WarshallFloyd.hpp
    title: src/Graph/WarshallFloyd.hpp
  - icon: ':heavy_check_mark:'
    path: src/Helper/MakeVec.hpp
    title: src/Helper/MakeVec.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun May  3 17:28:08 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Helper/MakeVec.hpp\"\ntemplate <class T, class S> T make_vec(S x)\
    \ { return x; }\ntemplate <class T, class... Ts> auto make_vec(size_t n, Ts...\
    \ ts) {\n    return std::vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));\n\
    }\n#line 1 \"src/Graph/WarshallFloyd.hpp\"\n/// @docs src/Graph/WarshallFloyd.md\n\
    template <class T> void warshall_floyd(std::vector<std::vector<T>> &d, const T\
    \ INF) {\n    int n = d.size();\n    for (int i = 0; i < n; i++) assert(d[i][i]\
    \ == 0);\n    for (int k = 0; k < n; k++) {\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < n; j++) {\n                if (d[i][k] ==\
    \ INF || d[k][j] == INF) continue;\n                d[i][j] = std::min(d[i][j],\
    \ d[i][k] + d[k][j]);\n            }\n        }\n    }\n}\n#line 20 \"test/aoj/GRL_1_C.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nconst Int INF = 1e18;\nsigned main() {\n    Int n,\
    \ m;\n    std::cin >> n >> m;\n    auto adj = make_vec<Int>(n, n, INF);\n    REP(i,\
    \ n) adj[i][i] = 0;\n    REP(_, m) {\n        Int u, v, d;\n        std::cin >>\
    \ u >> v >> d;\n        adj[u][v] = d;\n    }\n    warshall_floyd(adj, INF);\n\
    \    REP(i, n) {\n        if (adj[i][i] < 0) {\n            std::cout << \"NEGATIVE\
    \ CYCLE\" << std::endl;\n            return 0;\n        }\n    }\n    REP(i, n)\
    \ {\n        REP(j, n) {\n            if (adj[i][j] == INF) {\n              \
    \  std::cout << \"INF\";\n            } else {\n                std::cout << adj[i][j];\n\
    \            }\n            if (j != n - 1) std::cout << \" \";\n        }\n \
    \       std::cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sun May  3 17:28:08 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Helper/MakeVec.hpp\"\n#include \"../../src/Graph/WarshallFloyd.hpp\"\
    \n#undef CALL_FROM_TEST\n\nconst Int INF = 1e18;\nsigned main() {\n    Int n,\
    \ m;\n    std::cin >> n >> m;\n    auto adj = make_vec<Int>(n, n, INF);\n    REP(i,\
    \ n) adj[i][i] = 0;\n    REP(_, m) {\n        Int u, v, d;\n        std::cin >>\
    \ u >> v >> d;\n        adj[u][v] = d;\n    }\n    warshall_floyd(adj, INF);\n\
    \    REP(i, n) {\n        if (adj[i][i] < 0) {\n            std::cout << \"NEGATIVE\
    \ CYCLE\" << std::endl;\n            return 0;\n        }\n    }\n    REP(i, n)\
    \ {\n        REP(j, n) {\n            if (adj[i][j] == INF) {\n              \
    \  std::cout << \"INF\";\n            } else {\n                std::cout << adj[i][j];\n\
    \            }\n            if (j != n - 1) std::cout << \" \";\n        }\n \
    \       std::cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/Helper/MakeVec.hpp
  - src/Graph/WarshallFloyd.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2020-05-03 20:57:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: test/aoj/GRL_1_C.test.cpp
---
