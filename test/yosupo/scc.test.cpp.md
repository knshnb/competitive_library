---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: src/Graph/StronglyConnectedComponents.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Fri Apr  3 13:28:22 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #line 1 \"src/Graph/StronglyConnectedComponents.hpp\"\n/// @docs src/Graph/StronglyConnectedComponents.md\n\
    struct StronglyConnectedComponents {\n    int n, size;  // size\u306Fbuild()\u5F8C\
    \u306B\u5F37\u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u683C\u7D0D\n    std::vector<std::vector<int>>\
    \ edge, redge;\n    std::vector<int> belong_to;\n    StronglyConnectedComponents(int\
    \ n_) : n(n_), edge(n_), redge(n_) {}\n    void add_edge(int u, int v) {\n   \
    \     assert(0 <= u && u < n && 0 <= v && v < n);\n        edge[u].push_back(v);\n\
    \        redge[v].push_back(u);\n    }\n    void build() {\n        std::vector<int>\
    \ ord;  // post-order\n        // \u6B63\u65B9\u5411\u306E\u8FBA\u3067dfs\u3001\
    post-order\u3092\u3075\u308B\n        std::vector<bool> visited(n, false);\n \
    \       auto dfs1 = [&](auto f, int v) -> void {\n            if (visited[v])\
    \ return;\n            visited[v] = true;\n            for (int s : edge[v]) {\n\
    \                f(f, s);\n            }\n            ord.push_back(v);\n    \
    \    };\n        for (int i = 0; i < n; i++) dfs1(dfs1, i);\n\n        // post-order\u9006\
    \u9806\u306Bdfs\u3001\u5230\u9054\u53EF\u80FD\u306A\u540C\u5024\u985E\u306B\u5206\
    \u3051\u308B\n        belong_to.assign(n, -1);\n        int cur_group = 0;\n \
    \       auto dfs2 = [&](auto f, int v) -> void {\n            if (belong_to[v]\
    \ != -1) return;\n            belong_to[v] = cur_group;\n            for (int\
    \ s : redge[v]) {\n                f(f, s);\n            }\n        };\n     \
    \   std::reverse(ord.begin(), ord.end());\n        for (int i : ord) {\n     \
    \       if (belong_to[i] == -1) {\n                dfs2(dfs2, i);\n          \
    \      cur_group++;\n            }\n        }\n        size = cur_group;\n   \
    \ }\n    bool has_loop() {\n        build();\n        return size < n;\n    }\n\
    };\n#line 19 \"test/yosupo/scc.test.cpp\"\n#undef CALL_FROM_TEST\n\nsigned main()\
    \ {\n    int n, m;\n    std::cin >> n >> m;\n    StronglyConnectedComponents scc(n);\n\
    \    REP(i, m) {\n        int u, v;\n        std::cin >> u >> v;\n        scc.add_edge(u,\
    \ v);\n    }\n    scc.build();\n    std::vector<std::vector<int>> groups(scc.size);\n\
    \    REP(i, n) { groups[scc.belong_to[i]].push_back(i); }\n    std::cout << scc.size\
    \ << std::endl;\n    for (auto& group : groups) {\n        std::cout << group.size()\
    \ << \" \";\n        for (int v : group) {\n            std::cout << v << \" \"\
    ;\n        }\n        std::cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef _MY_DEBUG\n#define dump(...)\n#endif  // clang-format\
    \ on\n\n/**\n *    author:  knshnb\n *    created: Fri Apr  3 13:28:22 JST 2020\n\
    \ **/\n\n#define CALL_FROM_TEST\n#include \"../../src/Graph/StronglyConnectedComponents.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    int n, m;\n    std::cin >> n >>\
    \ m;\n    StronglyConnectedComponents scc(n);\n    REP(i, m) {\n        int u,\
    \ v;\n        std::cin >> u >> v;\n        scc.add_edge(u, v);\n    }\n    scc.build();\n\
    \    std::vector<std::vector<int>> groups(scc.size);\n    REP(i, n) { groups[scc.belong_to[i]].push_back(i);\
    \ }\n    std::cout << scc.size << std::endl;\n    for (auto& group : groups) {\n\
    \        std::cout << group.size() << \" \";\n        for (int v : group) {\n\
    \            std::cout << v << \" \";\n        }\n        std::cout << \"\\n\"\
    ;\n    }\n}\n"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2020-04-04 18:54:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
