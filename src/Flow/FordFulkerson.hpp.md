---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: src/Flow/FordFulkerson.md
    links: []
  bundledCode: "#line 1 \"src/Flow/FordFulkerson.hpp\"\n/// @docs src/Flow/FordFulkerson.md\n\
    template <class T = long long> struct FordFulkerson {\n    struct Edge {\n   \
    \     int to, rev_idx;  // \u9006\u8FBA\u306Fg[to][rev_idx]\n        T cap;\n\
    \        bool is_rev;\n    };\n    std::vector<std::vector<Edge>> g;\n    FordFulkerson(int\
    \ n) : g(n) {}\n\n    void add_edge(int from, int to, T cap) {\n        g[from].push_back({to,\
    \ (int)g[to].size(), cap, false});\n        g[to].push_back({from, (int)g[from].size()\
    \ - 1, 0, true});\n    }\n    T max_flow(int s, int t) {\n        std::vector<bool>\
    \ used(g.size());\n        auto dfs = [this, &used, &t](auto f, int v, T min_acc)\
    \ -> T {\n            if (v == t) return min_acc;\n            if (used[v]) return\
    \ 0;\n            used[v] = true;\n            for (Edge& e : g[v]) {\n      \
    \          if (e.cap == 0) continue;\n                T dif = f(f, e.to, std::min(min_acc,\
    \ e.cap));\n                if (dif == 0) continue;\n                e.cap -=\
    \ dif, g[e.to][e.rev_idx].cap += dif;\n                return dif;\n         \
    \   }\n            return 0;\n        };\n\n        T flow = 0;\n        while\
    \ (1) {\n            std::fill(used.begin(), used.end(), false);\n           \
    \ T f = dfs(dfs, s, std::numeric_limits<T>::max() / 2);\n            if (f ==\
    \ 0) return flow;\n            flow += f;\n        }\n    }\n    // max_flow()\u306E\
    \u5F8C\u306B\u547C\u3076\u3068\u3001{u, v, \u6D41\u3057\u305F\u6D41\u91CF}\u306E\
    vector\u3092\u8FD4\u3059\n    std::vector<std::tuple<int, int, T>> construct()\
    \ {\n        std::vector<std::tuple<int, int, T>> ret;\n        for (int i = 0;\
    \ i < g.size(); i++) {\n            for (Edge& e : g[i]) {\n                if\
    \ (e.is_rev) continue;\n                T f = g[e.to][e.rev_idx].cap;\n      \
    \          if (f == 0) continue;\n                ret.push_back({i, e.to, f});\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  code: "/// @docs src/Flow/FordFulkerson.md\ntemplate <class T = long long> struct\
    \ FordFulkerson {\n    struct Edge {\n        int to, rev_idx;  // \u9006\u8FBA\
    \u306Fg[to][rev_idx]\n        T cap;\n        bool is_rev;\n    };\n    std::vector<std::vector<Edge>>\
    \ g;\n    FordFulkerson(int n) : g(n) {}\n\n    void add_edge(int from, int to,\
    \ T cap) {\n        g[from].push_back({to, (int)g[to].size(), cap, false});\n\
    \        g[to].push_back({from, (int)g[from].size() - 1, 0, true});\n    }\n \
    \   T max_flow(int s, int t) {\n        std::vector<bool> used(g.size());\n  \
    \      auto dfs = [this, &used, &t](auto f, int v, T min_acc) -> T {\n       \
    \     if (v == t) return min_acc;\n            if (used[v]) return 0;\n      \
    \      used[v] = true;\n            for (Edge& e : g[v]) {\n                if\
    \ (e.cap == 0) continue;\n                T dif = f(f, e.to, std::min(min_acc,\
    \ e.cap));\n                if (dif == 0) continue;\n                e.cap -=\
    \ dif, g[e.to][e.rev_idx].cap += dif;\n                return dif;\n         \
    \   }\n            return 0;\n        };\n\n        T flow = 0;\n        while\
    \ (1) {\n            std::fill(used.begin(), used.end(), false);\n           \
    \ T f = dfs(dfs, s, std::numeric_limits<T>::max() / 2);\n            if (f ==\
    \ 0) return flow;\n            flow += f;\n        }\n    }\n    // max_flow()\u306E\
    \u5F8C\u306B\u547C\u3076\u3068\u3001{u, v, \u6D41\u3057\u305F\u6D41\u91CF}\u306E\
    vector\u3092\u8FD4\u3059\n    std::vector<std::tuple<int, int, T>> construct()\
    \ {\n        std::vector<std::tuple<int, int, T>> ret;\n        for (int i = 0;\
    \ i < g.size(); i++) {\n            for (Edge& e : g[i]) {\n                if\
    \ (e.is_rev) continue;\n                T f = g[e.to][e.rev_idx].cap;\n      \
    \          if (f == 0) continue;\n                ret.push_back({i, e.to, f});\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Flow/FordFulkerson.hpp
  requiredBy: []
  timestamp: '2020-04-24 20:42:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Flow/FordFulkerson.hpp
layout: document
redirect_from:
- /library/src/Flow/FordFulkerson.hpp
- /library/src/Flow/FordFulkerson.hpp.html
title: src/Flow/FordFulkerson.hpp
---

## 概要
グラフの最大フローを求めるアルゴリズム。
最大流の流量をFとして、O(F|E|)。

## アルゴリズム
増加パス(容量以内の正辺と、今までに流した流量を逆に押し戻す逆辺のみからなるパス)を1つ見つけて目一杯流すことを繰り返す。
dfsで増加パスを見つけるのがO(|E|)、これが最大O(F)回行われる可能性がある(実用上はこれよりかなり早く動作することが多い)。