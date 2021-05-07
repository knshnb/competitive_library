---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/TreeDiameter.hpp\"\n// \u6728\u306E\u76F4\u5F84\u304C\
    diameter\u306B\u683C\u7D0D\u3055\u308C\u308B\nsigned main() {\n    int n;\n  \
    \  cin >> n;\n    vector<vector<int>> g(n);\n    REP(i, n - 1) {\n        int\
    \ u, v;\n        cin >> u >> v;\n        u--;\n        v--;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    int diameter = 0;\n    function<int(int,\
    \ int)> dfs = [&](int v, int p) {\n        int ma = 0;\n        for (int s : g[v])\n\
    \            if (s != p) {\n                int tmp = dfs(s, v) + 1;\n       \
    \         diameter = max(diameter, ma + tmp);\n                ma = max(ma, tmp);\n\
    \            }\n        return ma;\n    };\n    dfs(0, -1);\n}\n"
  code: "// \u6728\u306E\u76F4\u5F84\u304Cdiameter\u306B\u683C\u7D0D\u3055\u308C\u308B\
    \nsigned main() {\n    int n;\n    cin >> n;\n    vector<vector<int>> g(n);\n\
    \    REP(i, n - 1) {\n        int u, v;\n        cin >> u >> v;\n        u--;\n\
    \        v--;\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\
    \    int diameter = 0;\n    function<int(int, int)> dfs = [&](int v, int p) {\n\
    \        int ma = 0;\n        for (int s : g[v])\n            if (s != p) {\n\
    \                int tmp = dfs(s, v) + 1;\n                diameter = max(diameter,\
    \ ma + tmp);\n                ma = max(ma, tmp);\n            }\n        return\
    \ ma;\n    };\n    dfs(0, -1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/TreeDiameter.hpp
  requiredBy: []
  timestamp: '2020-06-13 20:39:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/TreeDiameter.hpp
layout: document
redirect_from:
- /library/src/old/TreeDiameter.hpp
- /library/src/old/TreeDiameter.hpp.html
title: src/old/TreeDiameter.hpp
---
