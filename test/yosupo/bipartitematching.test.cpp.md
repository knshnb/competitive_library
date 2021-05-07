---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Flow/Dinic.hpp
    title: src/Flow/Dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#include <bits/stdc++.h>\
    \  // clang-format off\nusing Int = long long;\n#define REP_(i, a_, b_, a, b,\
    \ ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n#define REP(i, ...) REP_(i,\
    \ __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef _MY_DEBUG\n#define dump(...)\n#endif  // clang-format\
    \ on\n\n/**\n *    author:  knshnb\n *    created: Fri Apr 24 16:25:41 JST 2020\n\
    \ **/\n\n#define CALL_FROM_TEST\n#line 1 \"src/Flow/Dinic.hpp\"\n/// @docs src/Flow/Dinic.md\n\
    template <class T = long long> struct Dinic {\n    struct Edge {\n        int\
    \ to, rev_idx;  // \u9006\u8FBA\u306Fg[to][rev_idx]\n        T cap;\n        bool\
    \ is_rev;\n    };\n    std::vector<std::vector<Edge>> g;\n    Dinic(int n) : g(n)\
    \ {}\n\n    void add_edge(int from, int to, T cap) {\n        g[from].push_back({to,\
    \ (int)g[to].size(), cap, false});\n        g[to].push_back({from, (int)g[from].size()\
    \ - 1, 0, true});\n    }\n    T max_flow(int s, int t) {\n        std::vector<int>\
    \ level(g.size());\n        auto bfs = [this, &level, &s, &t]() -> bool {\n  \
    \          std::fill(level.begin(), level.end(), -1);\n            std::queue<int>\
    \ q;\n            level[s] = 0, q.push(s);\n            while (!q.empty()) {\n\
    \                int v = q.front();\n                q.pop();\n              \
    \  for (Edge& e : g[v]) {\n                    if (e.cap == 0 || level[e.to] !=\
    \ -1) continue;\n                    level[e.to] = level[v] + 1;\n           \
    \         q.push(e.to);\n                }\n            }\n            return\
    \ level[t] != -1;  // \u7D42\u4E86\u3057\u3066\u3044\u306A\u3051\u308C\u3070true\u3092\
    \u8FD4\u3059\n        };\n        std::vector<int> iter(g.size());\n        auto\
    \ dfs = [this, &level, &iter, &t](auto f, int v, T min_acc) -> T {\n         \
    \   if (v == t) return min_acc;\n            for (int& i = iter[v]; i < g[v].size();\
    \ i++) {\n                Edge& e = g[v][i];\n                if (e.cap == 0 ||\
    \ level[e.to] <= level[v]) continue;\n                T dif = f(f, e.to, std::min(min_acc,\
    \ e.cap));\n                if (dif == 0) continue;\n                e.cap -=\
    \ dif, g[e.to][e.rev_idx].cap += dif;\n                return dif;\n         \
    \   }\n            return 0;\n        };\n\n        T flow = 0;\n        while\
    \ (bfs()) {\n            std::fill(iter.begin(), iter.end(), 0);\n           \
    \ while (1) {\n                T f = dfs(dfs, s, std::numeric_limits<T>::max()\
    \ / 2);\n                if (f == 0) break;\n                flow += f;\n    \
    \        }\n        }\n        return flow;\n    }\n    // max_flow()\u306E\u5F8C\
    \u306B\u547C\u3076\u3068\u3001{u, v, \u6D41\u3057\u305F\u6D41\u91CF}\u306Evector\u3092\
    \u8FD4\u3059\n    std::vector<std::tuple<int, int, T>> construct() {\n       \
    \ std::vector<std::tuple<int, int, T>> ret;\n        for (int i = 0; i < g.size();\
    \ i++) {\n            for (Edge& e : g[i]) {\n                if (e.is_rev) continue;\n\
    \                T f = g[e.to][e.rev_idx].cap;\n                if (f == 0) continue;\n\
    \                ret.push_back({i, e.to, f});\n            }\n        }\n    \
    \    return ret;\n    }\n};\n#line 19 \"test/yosupo/bipartitematching.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    int L, R, M;\n    std::cin >>\
    \ L >> R >> M;\n    Dinic ff(L + R + 2);\n    int s = L + R, t = L + R + 1;\n\
    \    REP(i, L) { ff.add_edge(s, (int)i, 1); }\n    REP(i, R) { ff.add_edge((int)L\
    \ + i, t, 1); }\n    REP(_, M) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        ff.add_edge(a, L + b, 1);\n    }\n    std::cout << ff.max_flow(s,\
    \ t) << std::endl;\n    for (auto& [u, v, f] : ff.construct()) {\n        if (u\
    \ < L && L <= v && v < L + R) {\n            std::cout << u << \" \" << v - L\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\nstruct\
    \ SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false),\
    \ std::cout << std::fixed << std::setprecision(13); } } setup_io;\n#ifndef _MY_DEBUG\n\
    #define dump(...)\n#endif  // clang-format on\n\n/**\n *    author:  knshnb\n\
    \ *    created: Fri Apr 24 16:25:41 JST 2020\n **/\n\n#define CALL_FROM_TEST\n\
    #include \"../../src/Flow/Dinic.hpp\"\n#undef CALL_FROM_TEST\n\nsigned main()\
    \ {\n    int L, R, M;\n    std::cin >> L >> R >> M;\n    Dinic ff(L + R + 2);\n\
    \    int s = L + R, t = L + R + 1;\n    REP(i, L) { ff.add_edge(s, (int)i, 1);\
    \ }\n    REP(i, R) { ff.add_edge((int)L + i, t, 1); }\n    REP(_, M) {\n     \
    \   int a, b;\n        std::cin >> a >> b;\n        ff.add_edge(a, L + b, 1);\n\
    \    }\n    std::cout << ff.max_flow(s, t) << std::endl;\n    for (auto& [u, v,\
    \ f] : ff.construct()) {\n        if (u < L && L <= v && v < L + R) {\n      \
    \      std::cout << u << \" \" << v - L << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - src/Flow/Dinic.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2020-04-24 21:15:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
