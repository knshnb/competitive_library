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
  bundledCode: "#line 1 \"src/old/UnionFindWithWeight.hpp\"\nstruct UnionFind {\n\
    \    vector<int> par, rank, diff_weight;\n    UnionFind(int n) {\n        par\
    \ = vector<int>(n);\n        iota(par.begin(), par.end(), 0);\n        rank =\
    \ vector<int>(n, 0);\n        diff_weight = vector<int>(n, 0);\n    }\n    int\
    \ root(int x) {\n        if (par[x] == x) {\n            return x;\n        }\
    \ else {\n            int r = root(par[x]);\n            diff_weight[x] += diff_weight[par[x]];\n\
    \            return par[x] = root(par[x]);\n        }\n    }\n    bool unite(int\
    \ x, int y, int w) {\n        w += weight(x);\n        w -= weight(y);\n     \
    \   x = root(x);\n        y = root(y);\n        if (x == y) {\n            return\
    \ false;\n        }\n        if (rank[x] < rank[y]) {\n            diff_weight[x]\
    \ -= w;\n            par[x] = y;\n        } else {\n            diff_weight[y]\
    \ += w;\n            par[y] = x;\n            if (rank[x] == rank[y]) {\n    \
    \            rank[x]++;\n            }\n        }\n        return true;\n    }\n\
    \    bool same(int x, int y) { return root(x) == root(y); }\n    int weight(int\
    \ x) {\n        root(x);\n        return diff_weight[x];\n    }\n    int diff(int\
    \ x, int y) {\n        assert(same(x, y));\n        return weight(y) - weight(x);\n\
    \    }\n};\n"
  code: "struct UnionFind {\n    vector<int> par, rank, diff_weight;\n    UnionFind(int\
    \ n) {\n        par = vector<int>(n);\n        iota(par.begin(), par.end(), 0);\n\
    \        rank = vector<int>(n, 0);\n        diff_weight = vector<int>(n, 0);\n\
    \    }\n    int root(int x) {\n        if (par[x] == x) {\n            return\
    \ x;\n        } else {\n            int r = root(par[x]);\n            diff_weight[x]\
    \ += diff_weight[par[x]];\n            return par[x] = root(par[x]);\n       \
    \ }\n    }\n    bool unite(int x, int y, int w) {\n        w += weight(x);\n \
    \       w -= weight(y);\n        x = root(x);\n        y = root(y);\n        if\
    \ (x == y) {\n            return false;\n        }\n        if (rank[x] < rank[y])\
    \ {\n            diff_weight[x] -= w;\n            par[x] = y;\n        } else\
    \ {\n            diff_weight[y] += w;\n            par[y] = x;\n            if\
    \ (rank[x] == rank[y]) {\n                rank[x]++;\n            }\n        }\n\
    \        return true;\n    }\n    bool same(int x, int y) { return root(x) ==\
    \ root(y); }\n    int weight(int x) {\n        root(x);\n        return diff_weight[x];\n\
    \    }\n    int diff(int x, int y) {\n        assert(same(x, y));\n        return\
    \ weight(y) - weight(x);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/UnionFindWithWeight.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/UnionFindWithWeight.hpp
layout: document
redirect_from:
- /library/src/old/UnionFindWithWeight.hpp
- /library/src/old/UnionFindWithWeight.hpp.html
title: src/old/UnionFindWithWeight.hpp
---
