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
  bundledCode: "#line 1 \"src/old/Kruskal.hpp\"\nclass UnionFind {\npublic:\n    VI\
    \ par, rank;\n    UnionFind(int n) {\n        par = VI(n);\n        iota(par.begin(),\
    \ par.end(), 0);\n        rank = VI(n, 0);\n    }\n    int root(int x) {\n   \
    \     if (par[x] == x) {\n            return x;\n        } else {\n          \
    \  return par[x] = root(par[x]);\n        }\n    }\n    void unite(int x, int\
    \ y) {\n        x = root(x);\n        y = root(y);\n        if (x == y) {\n  \
    \          return;\n        }\n        if (rank[x] < rank[y]) {\n            par[x]\
    \ = y;\n        } else {\n            par[y] = x;\n            if (rank[x] ==\
    \ rank[y]) {\n                rank[x]++;\n            }\n        }\n    }\n  \
    \  bool same(int x, int y) { return root(x) == root(y); }\n};\n\nstruct edge {\n\
    \    int u, v, cost;\n};\nbool comp(const edge& e1, const edge& e2) { return e1.cost\
    \ < e2.cost; }\nint kruskal(int V, vector<edge>& es) {\n    sort(es.begin(), es.end(),\
    \ comp);\n    UnionFind uf(V);\n    int ans = 0;\n    for (edge e : es) {\n  \
    \      if (uf.same(e.u, e.v)) {\n            continue;\n        }\n        uf.unite(e.u,\
    \ e.v);\n        ans += e.cost;\n    }\n    return ans;\n}\nsigned main() {\n\
    \    int V, E;\n    cin >> V >> E;\n    vector<edge> es(E);\n    REP(i, E) { cin\
    \ >> es[i].u >> es[i].v >> es[i].cost; }\n    cout << kruskal(V, es) << endl;\n\
    }\n"
  code: "class UnionFind {\npublic:\n    VI par, rank;\n    UnionFind(int n) {\n \
    \       par = VI(n);\n        iota(par.begin(), par.end(), 0);\n        rank =\
    \ VI(n, 0);\n    }\n    int root(int x) {\n        if (par[x] == x) {\n      \
    \      return x;\n        } else {\n            return par[x] = root(par[x]);\n\
    \        }\n    }\n    void unite(int x, int y) {\n        x = root(x);\n    \
    \    y = root(y);\n        if (x == y) {\n            return;\n        }\n   \
    \     if (rank[x] < rank[y]) {\n            par[x] = y;\n        } else {\n  \
    \          par[y] = x;\n            if (rank[x] == rank[y]) {\n              \
    \  rank[x]++;\n            }\n        }\n    }\n    bool same(int x, int y) {\
    \ return root(x) == root(y); }\n};\n\nstruct edge {\n    int u, v, cost;\n};\n\
    bool comp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }\nint kruskal(int\
    \ V, vector<edge>& es) {\n    sort(es.begin(), es.end(), comp);\n    UnionFind\
    \ uf(V);\n    int ans = 0;\n    for (edge e : es) {\n        if (uf.same(e.u,\
    \ e.v)) {\n            continue;\n        }\n        uf.unite(e.u, e.v);\n   \
    \     ans += e.cost;\n    }\n    return ans;\n}\nsigned main() {\n    int V, E;\n\
    \    cin >> V >> E;\n    vector<edge> es(E);\n    REP(i, E) { cin >> es[i].u >>\
    \ es[i].v >> es[i].cost; }\n    cout << kruskal(V, es) << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/Kruskal.hpp
  requiredBy: []
  timestamp: '2020-06-13 20:39:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/Kruskal.hpp
layout: document
redirect_from:
- /library/src/old/Kruskal.hpp
- /library/src/old/Kruskal.hpp.html
title: src/old/Kruskal.hpp
---
