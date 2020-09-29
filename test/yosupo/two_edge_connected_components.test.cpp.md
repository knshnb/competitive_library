---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/TwoEdgeConnectedComponents.hpp
    title: src/Graph/TwoEdgeConnectedComponents.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Wed Apr  1 19:23:42 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Graph/TwoEdgeConnectedComponents.hpp\"\n/// @docs src/Graph/TwoEdgeConnectedComponents.md\n\
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
    \    }\n};\n#line 19 \"test/yosupo/two_edge_connected_components.test.cpp\"\n\
    #undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, m;\n    std::cin >> n >>\
    \ m;\n    TwoEdgeConnectedComponents t(n);\n    REP(i, m) {\n        int u, v;\n\
    \        std::cin >> u >> v;\n        t.g[u].push_back(v);\n        t.g[v].push_back(u);\n\
    \    }\n    t.build();\n\n    std::vector<std::vector<int>> groups(t.size);\n\
    \    REP(i, n) { groups[t.belong_to[i]].push_back(i); }\n    std::cout << groups.size()\
    \ << std::endl;\n    for (auto& vs : groups) {\n        std::cout << vs.size()\
    \ << \" \";\n        for (auto v : vs) std::cout << v << \" \";\n        std::cout\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Wed Apr  1 19:23:42 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Graph/TwoEdgeConnectedComponents.hpp\"\n#undef CALL_FROM_TEST\n\
    \nsigned main() {\n    Int n, m;\n    std::cin >> n >> m;\n    TwoEdgeConnectedComponents\
    \ t(n);\n    REP(i, m) {\n        int u, v;\n        std::cin >> u >> v;\n   \
    \     t.g[u].push_back(v);\n        t.g[v].push_back(u);\n    }\n    t.build();\n\
    \n    std::vector<std::vector<int>> groups(t.size);\n    REP(i, n) { groups[t.belong_to[i]].push_back(i);\
    \ }\n    std::cout << groups.size() << std::endl;\n    for (auto& vs : groups)\
    \ {\n        std::cout << vs.size() << \" \";\n        for (auto v : vs) std::cout\
    \ << v << \" \";\n        std::cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/Graph/TwoEdgeConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2020-04-03 18:09:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
