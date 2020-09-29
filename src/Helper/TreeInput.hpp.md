---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/TreeInput.hpp\"\nint n;\nstd::cin >> n;\nstd::vector<std::vector<int>>\
    \ g(n);\nfor (int i = 0; i < n - 1; i++) {\n    int u, v;\n    std::cin >> u >>\
    \ v;\n    u--, v--;\n    g[u].push_back(v);\n    g[v].push_back(u);\n}\n"
  code: "int n;\nstd::cin >> n;\nstd::vector<std::vector<int>> g(n);\nfor (int i =\
    \ 0; i < n - 1; i++) {\n    int u, v;\n    std::cin >> u >> v;\n    u--, v--;\n\
    \    g[u].push_back(v);\n    g[v].push_back(u);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/TreeInput.hpp
  requiredBy: []
  timestamp: '2020-03-29 16:30:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/TreeInput.hpp
layout: document
redirect_from:
- /library/src/Helper/TreeInput.hpp
- /library/src/Helper/TreeInput.hpp.html
title: src/Helper/TreeInput.hpp
---
