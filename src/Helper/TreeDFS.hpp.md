---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/TreeDFS.hpp\"\nauto dfs = [&](auto&& self, int\
    \ v, int prv) -> void {\n    for (int s : g[v]) {\n        if (s == prv) continue;\n\
    \        self(self, s, v);\n    }\n};\ndfs(dfs, 0, -1);\n"
  code: "auto dfs = [&](auto&& self, int v, int prv) -> void {\n    for (int s : g[v])\
    \ {\n        if (s == prv) continue;\n        self(self, s, v);\n    }\n};\ndfs(dfs,\
    \ 0, -1);\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/TreeDFS.hpp
  requiredBy: []
  timestamp: '2020-06-18 02:53:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/TreeDFS.hpp
layout: document
redirect_from:
- /library/src/Helper/TreeDFS.hpp
- /library/src/Helper/TreeDFS.hpp.html
title: src/Helper/TreeDFS.hpp
---
