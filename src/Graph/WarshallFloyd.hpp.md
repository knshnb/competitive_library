---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Graph/WarshallFloyd.md
    links: []
  bundledCode: "#line 1 \"src/Graph/WarshallFloyd.hpp\"\n/// @docs src/Graph/WarshallFloyd.md\n\
    template <class T> void warshall_floyd(std::vector<std::vector<T>> &d, const T\
    \ INF) {\n    int n = d.size();\n    for (int i = 0; i < n; i++) assert(d[i][i]\
    \ == 0);\n    for (int k = 0; k < n; k++) {\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < n; j++) {\n                if (d[i][k] ==\
    \ INF || d[k][j] == INF) continue;\n                d[i][j] = std::min(d[i][j],\
    \ d[i][k] + d[k][j]);\n            }\n        }\n    }\n}\n"
  code: "/// @docs src/Graph/WarshallFloyd.md\ntemplate <class T> void warshall_floyd(std::vector<std::vector<T>>\
    \ &d, const T INF) {\n    int n = d.size();\n    for (int i = 0; i < n; i++) assert(d[i][i]\
    \ == 0);\n    for (int k = 0; k < n; k++) {\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < n; j++) {\n                if (d[i][k] ==\
    \ INF || d[k][j] == INF) continue;\n                d[i][j] = std::min(d[i][j],\
    \ d[i][k] + d[k][j]);\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2020-05-03 20:57:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: src/Graph/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/src/Graph/WarshallFloyd.hpp
- /library/src/Graph/WarshallFloyd.hpp.html
title: src/Graph/WarshallFloyd.hpp
---
