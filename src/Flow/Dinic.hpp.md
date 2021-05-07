---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Flow/Dinic.md
    links: []
  bundledCode: "#line 1 \"src/Flow/Dinic.hpp\"\n/// @docs src/Flow/Dinic.md\ntemplate\
    \ <class T = long long> struct Dinic {\n    struct Edge {\n        int to, rev_idx;\
    \  // \u9006\u8FBA\u306Fg[to][rev_idx]\n        T cap;\n        bool is_rev;\n\
    \    };\n    std::vector<std::vector<Edge>> g;\n    Dinic(int n) : g(n) {}\n\n\
    \    void add_edge(int from, int to, T cap) {\n        g[from].push_back({to,\
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
    \    return ret;\n    }\n};\n"
  code: "/// @docs src/Flow/Dinic.md\ntemplate <class T = long long> struct Dinic\
    \ {\n    struct Edge {\n        int to, rev_idx;  // \u9006\u8FBA\u306Fg[to][rev_idx]\n\
    \        T cap;\n        bool is_rev;\n    };\n    std::vector<std::vector<Edge>>\
    \ g;\n    Dinic(int n) : g(n) {}\n\n    void add_edge(int from, int to, T cap)\
    \ {\n        g[from].push_back({to, (int)g[to].size(), cap, false});\n       \
    \ g[to].push_back({from, (int)g[from].size() - 1, 0, true});\n    }\n    T max_flow(int\
    \ s, int t) {\n        std::vector<int> level(g.size());\n        auto bfs = [this,\
    \ &level, &s, &t]() -> bool {\n            std::fill(level.begin(), level.end(),\
    \ -1);\n            std::queue<int> q;\n            level[s] = 0, q.push(s);\n\
    \            while (!q.empty()) {\n                int v = q.front();\n      \
    \          q.pop();\n                for (Edge& e : g[v]) {\n                \
    \    if (e.cap == 0 || level[e.to] != -1) continue;\n                    level[e.to]\
    \ = level[v] + 1;\n                    q.push(e.to);\n                }\n    \
    \        }\n            return level[t] != -1;  // \u7D42\u4E86\u3057\u3066\u3044\
    \u306A\u3051\u308C\u3070true\u3092\u8FD4\u3059\n        };\n        std::vector<int>\
    \ iter(g.size());\n        auto dfs = [this, &level, &iter, &t](auto f, int v,\
    \ T min_acc) -> T {\n            if (v == t) return min_acc;\n            for\
    \ (int& i = iter[v]; i < g[v].size(); i++) {\n                Edge& e = g[v][i];\n\
    \                if (e.cap == 0 || level[e.to] <= level[v]) continue;\n      \
    \          T dif = f(f, e.to, std::min(min_acc, e.cap));\n                if (dif\
    \ == 0) continue;\n                e.cap -= dif, g[e.to][e.rev_idx].cap += dif;\n\
    \                return dif;\n            }\n            return 0;\n        };\n\
    \n        T flow = 0;\n        while (bfs()) {\n            std::fill(iter.begin(),\
    \ iter.end(), 0);\n            while (1) {\n                T f = dfs(dfs, s,\
    \ std::numeric_limits<T>::max() / 2);\n                if (f == 0) break;\n  \
    \              flow += f;\n            }\n        }\n        return flow;\n  \
    \  }\n    // max_flow()\u306E\u5F8C\u306B\u547C\u3076\u3068\u3001{u, v, \u6D41\
    \u3057\u305F\u6D41\u91CF}\u306Evector\u3092\u8FD4\u3059\n    std::vector<std::tuple<int,\
    \ int, T>> construct() {\n        std::vector<std::tuple<int, int, T>> ret;\n\
    \        for (int i = 0; i < g.size(); i++) {\n            for (Edge& e : g[i])\
    \ {\n                if (e.is_rev) continue;\n                T f = g[e.to][e.rev_idx].cap;\n\
    \                if (f == 0) continue;\n                ret.push_back({i, e.to,\
    \ f});\n            }\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Flow/Dinic.hpp
  requiredBy: []
  timestamp: '2020-04-24 21:15:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bipartitematching.test.cpp
documentation_of: src/Flow/Dinic.hpp
layout: document
redirect_from:
- /library/src/Flow/Dinic.hpp
- /library/src/Flow/Dinic.hpp.html
title: src/Flow/Dinic.hpp
---
## 概要
グラフの最大フローを求めるアルゴリズム。計算量はO(|E||V|^2)。
実用上はこれよりかなり早く動くことが多い。
<br/>
また、二部グラフの最大マッチングを求めるときはO(E sqrt(V))になる。

## アルゴリズム
最短の増加路にフローを流していく。
<br/>
参考: https://ta1sa.hatenablog.com/entry/2020/04/13/123802