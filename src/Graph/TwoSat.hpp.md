---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: src/Graph/StronglyConnectedComponents.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/StronglyConnectedComponents.hpp\"\n/// @docs src/Graph/StronglyConnectedComponents.md\n\
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
    \    }\n};\n"
  code: "#include \"StronglyConnectedComponents.hpp\"\n\nstruct TwoSat {\n    int\
    \ n;\n    StronglyConnectedComponents scc;  // [0, n): x, [n, 2n): not x\n   \
    \ TwoSat(int n_) : n(n_), scc(2 * n_) {}\n    // x\u306E\u5426\u5B9A\u3092\u8868\
    \u3059index\n    int rev(int x) { return x < n ? x + n : x - n; }\n    // (x \\\
    vee y)\u306E\u6761\u4EF6\u3092\u8FFD\u52A0\n    void add_condition(int x, bool\
    \ not_x, int y, bool not_y) {\n        if (not_x) x = rev(x);\n        if (not_y)\
    \ y = rev(y);\n        scc.add_edge(rev(x), y);\n        scc.add_edge(rev(y),\
    \ x);\n    }\n    bool run() {\n        scc.build();\n        for (int x = 0;\
    \ x < n; x++) {\n            if (scc.belong_to[x] == scc.belong_to[rev(x)]) return\
    \ false;\n        }\n        return true;\n    }\n    bool is_true(int x) {\n\
    \        assert(0 <= x && x < n);\n        return scc.belong_to[x] > scc.belong_to[rev(x)];\n\
    \    }\n};\n"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: src/Graph/TwoSat.hpp
  requiredBy: []
  timestamp: '2020-06-13 03:26:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: src/Graph/TwoSat.hpp
layout: document
redirect_from:
- /library/src/Graph/TwoSat.hpp
- /library/src/Graph/TwoSat.hpp.html
title: src/Graph/TwoSat.hpp
---
