---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: src/Graph/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: src/Graph/TwoSat.hpp
    title: src/Graph/TwoSat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef dump\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Sat Jun 13 03:04:06 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
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
    };\n#line 2 \"src/Graph/TwoSat.hpp\"\n\nstruct TwoSat {\n    int n;\n    StronglyConnectedComponents\
    \ scc;  // [0, n): x, [n, 2n): not x\n    TwoSat(int n_) : n(n_), scc(2 * n_)\
    \ {}\n    // x\u306E\u5426\u5B9A\u3092\u8868\u3059index\n    int rev(int x) {\
    \ return x < n ? x + n : x - n; }\n    // (x \\vee y)\u306E\u6761\u4EF6\u3092\u8FFD\
    \u52A0\n    void add_condition(int x, bool not_x, int y, bool not_y) {\n     \
    \   if (not_x) x = rev(x);\n        if (not_y) y = rev(y);\n        scc.add_edge(rev(x),\
    \ y);\n        scc.add_edge(rev(y), x);\n    }\n    bool run() {\n        scc.build();\n\
    \        for (int x = 0; x < n; x++) {\n            if (scc.belong_to[x] == scc.belong_to[rev(x)])\
    \ return false;\n        }\n        return true;\n    }\n    bool is_true(int\
    \ x) {\n        assert(0 <= x && x < n);\n        return scc.belong_to[x] > scc.belong_to[rev(x)];\n\
    \    }\n};\n#line 19 \"test/yosupo/two_sat.test.cpp\"\n#undef CALL_FROM_TEST\n\
    \nsigned main() {\n    std::string _;\n    Int n, m;\n    std::cin >> _ >> _ >>\
    \ n >> m;\n    TwoSat sat(n);\n    REP(i, m) {\n        Int a, b;\n        std::cin\
    \ >> a >> b >> _;\n        sat.add_condition(std::abs(a) - 1, a < 0, std::abs(b)\
    \ - 1, b < 0);\n    }\n    if (!sat.run()) {\n        std::cout << \"s UNSATISFIABLE\"\
    \ << std::endl;\n    } else {\n        std::cout << \"s SATISFIABLE\" << std::endl\
    \ << \"v \";\n        REP(i, n) std::cout << (sat.is_true(i) ? (i + 1) : -(i +\
    \ 1)) << \" \";\n        std::cout << 0 << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Sat Jun 13 03:04:06 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#include \"../../src/Graph/TwoSat.hpp\"\n#undef CALL_FROM_TEST\n\
    \nsigned main() {\n    std::string _;\n    Int n, m;\n    std::cin >> _ >> _ >>\
    \ n >> m;\n    TwoSat sat(n);\n    REP(i, m) {\n        Int a, b;\n        std::cin\
    \ >> a >> b >> _;\n        sat.add_condition(std::abs(a) - 1, a < 0, std::abs(b)\
    \ - 1, b < 0);\n    }\n    if (!sat.run()) {\n        std::cout << \"s UNSATISFIABLE\"\
    \ << std::endl;\n    } else {\n        std::cout << \"s SATISFIABLE\" << std::endl\
    \ << \"v \";\n        REP(i, n) std::cout << (sat.is_true(i) ? (i + 1) : -(i +\
    \ 1)) << \" \";\n        std::cout << 0 << std::endl;\n    }\n}\n"
  dependsOn:
  - src/Graph/TwoSat.hpp
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-06-13 03:26:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
