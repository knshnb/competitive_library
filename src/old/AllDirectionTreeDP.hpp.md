---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/AllDirectionTreeDP.hpp\"\n// \u5168\u65B9\u4F4D\u6728\
    DP\n// ds[v]: v\u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u305D\u308C\u305E\
    \u308C\u306E\u8449\u307E\u3067\u306E\u8DDD\u96E2\nsigned main() {\n    struct\
    \ Edge {\n        int to, c;\n    };\n    int n;\n    cin >> n;\n    vector<vector<Edge>>\
    \ G(n);\n    REP(i, n - 1) {\n        int s, t, w;\n        cin >> s >> t >> w;\n\
    \        G[s].push_back({t, w});\n        G[t].push_back({s, w});\n    }\n   \
    \ VVII ds(n);\n    function<int(int, int)> dfs1 = [&](int v, int p) {\n      \
    \  int ma = 0;\n        for (Edge e : G[v])\n            if (e.to != p) {\n  \
    \              int tmp = dfs1(e.to, v) + e.c;\n                ds[v].push_back({tmp,\
    \ e.to});\n                ma = max(ma, tmp);\n            }\n        return ma;\n\
    \    };\n    dfs1(0, -1);\n\n    sort(RALL(ds[0]));\n    function<void(int, int)>\
    \ dfs2 = [&](int v, int p) {\n        for (Edge e : G[v])\n            if (e.to\
    \ != p) {\n                int tmp = (ds[v][0].se != e.to ? ds[v][0].fi : (ds[v].size()\
    \ == 1 ? 0 : ds[v][1].fi)) + e.c;\n                ds[e.to].push_back({tmp, v});\n\
    \                sort(RALL(ds[e.to]));\n                dfs2(e.to, v);\n     \
    \       }\n    };\n    dfs2(0, -1);\n\n    int ans = 0;\n    REP(i, n) {\n   \
    \     if (ds[i].size() == 0) continue;\n        ans = max(ans, ds[i][0].fi);\n\
    \    }\n    cout << ans << endl;\n}\n"
  code: "// \u5168\u65B9\u4F4D\u6728DP\n// ds[v]: v\u3092\u6839\u3068\u3057\u305F\u3068\
    \u304D\u306E\u305D\u308C\u305E\u308C\u306E\u8449\u307E\u3067\u306E\u8DDD\u96E2\
    \nsigned main() {\n    struct Edge {\n        int to, c;\n    };\n    int n;\n\
    \    cin >> n;\n    vector<vector<Edge>> G(n);\n    REP(i, n - 1) {\n        int\
    \ s, t, w;\n        cin >> s >> t >> w;\n        G[s].push_back({t, w});\n   \
    \     G[t].push_back({s, w});\n    }\n    VVII ds(n);\n    function<int(int, int)>\
    \ dfs1 = [&](int v, int p) {\n        int ma = 0;\n        for (Edge e : G[v])\n\
    \            if (e.to != p) {\n                int tmp = dfs1(e.to, v) + e.c;\n\
    \                ds[v].push_back({tmp, e.to});\n                ma = max(ma, tmp);\n\
    \            }\n        return ma;\n    };\n    dfs1(0, -1);\n\n    sort(RALL(ds[0]));\n\
    \    function<void(int, int)> dfs2 = [&](int v, int p) {\n        for (Edge e\
    \ : G[v])\n            if (e.to != p) {\n                int tmp = (ds[v][0].se\
    \ != e.to ? ds[v][0].fi : (ds[v].size() == 1 ? 0 : ds[v][1].fi)) + e.c;\n    \
    \            ds[e.to].push_back({tmp, v});\n                sort(RALL(ds[e.to]));\n\
    \                dfs2(e.to, v);\n            }\n    };\n    dfs2(0, -1);\n\n \
    \   int ans = 0;\n    REP(i, n) {\n        if (ds[i].size() == 0) continue;\n\
    \        ans = max(ans, ds[i][0].fi);\n    }\n    cout << ans << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/AllDirectionTreeDP.hpp
  requiredBy: []
  timestamp: '2020-04-28 00:07:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/AllDirectionTreeDP.hpp
layout: document
redirect_from:
- /library/src/old/AllDirectionTreeDP.hpp
- /library/src/old/AllDirectionTreeDP.hpp.html
title: src/old/AllDirectionTreeDP.hpp
---
