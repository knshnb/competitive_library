---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1242/submission/64467604
  bundledCode: "#line 1 \"src/old/Boruvka.hpp\"\n// F(\u73FE\u5728\u306E\u6728\u306E\
    \u500B\u6570, vector<\u9802\u70B9->\u96C6\u5408\u306Eindex>) -> vector<\u96C6\u5408\
    \u306Eindex->(cost, to)>\n// \u4F7F\u3044\u65B9: https://codeforces.com/contest/1242/submission/64467604\n\
    template <class T, class F> T boruvka(int n, const F& f) {\n    struct UnionFind\
    \ {\n        vector<int> number;  // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306E\
    index, \u8CA0\u306E\u3068\u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n        UnionFind(int\
    \ n) : number(n, -1) {}\n        int root(int x) { return number[x] < 0 ? x :\
    \ number[x] = root(number[x]); }\n        bool unite(int x, int y) {\n       \
    \     x = root(x), y = root(y);\n            if (x == y) return false;\n     \
    \       if (number[y] < number[x]) swap(x, y);\n            number[x] += number[y];\n\
    \            number[y] = x;\n            return true;\n        }\n    };\n\n \
    \   UnionFind uf(n);\n    T res(0);\n    bool update = true;\n    vector<int>\
    \ belongs(n), rev(n);\n    while (update) {\n        update = false;\n       \
    \ int ptr = 0;\n        for (int i = 0; i < n; i++) {\n            if (i == uf.root(i))\
    \ rev[ptr] = i, belongs[i] = ptr++;\n        }\n        for (int i = 0; i < n;\
    \ i++) belongs[i] = belongs[uf.root(i)];\n        vector<pair<T, int>> v = f(ptr,\
    \ belongs);\n        for (int i = 0; i < ptr; i++) {\n            if (v[i].second\
    \ >= 0 && uf.unite(rev[i], rev[v[i].second])) res += v[i].first, update = true;\n\
    \        }\n        if (!update) break;\n    }\n    return res;\n}\n"
  code: "// F(\u73FE\u5728\u306E\u6728\u306E\u500B\u6570, vector<\u9802\u70B9->\u96C6\
    \u5408\u306Eindex>) -> vector<\u96C6\u5408\u306Eindex->(cost, to)>\n// \u4F7F\u3044\
    \u65B9: https://codeforces.com/contest/1242/submission/64467604\ntemplate <class\
    \ T, class F> T boruvka(int n, const F& f) {\n    struct UnionFind {\n       \
    \ vector<int> number;  // 0\u4EE5\u4E0A\u306E\u3068\u304D\u89AA\u306Eindex, \u8CA0\
    \u306E\u3068\u304D\u306F\u96C6\u5408\u30B5\u30A4\u30BA\n        UnionFind(int\
    \ n) : number(n, -1) {}\n        int root(int x) { return number[x] < 0 ? x :\
    \ number[x] = root(number[x]); }\n        bool unite(int x, int y) {\n       \
    \     x = root(x), y = root(y);\n            if (x == y) return false;\n     \
    \       if (number[y] < number[x]) swap(x, y);\n            number[x] += number[y];\n\
    \            number[y] = x;\n            return true;\n        }\n    };\n\n \
    \   UnionFind uf(n);\n    T res(0);\n    bool update = true;\n    vector<int>\
    \ belongs(n), rev(n);\n    while (update) {\n        update = false;\n       \
    \ int ptr = 0;\n        for (int i = 0; i < n; i++) {\n            if (i == uf.root(i))\
    \ rev[ptr] = i, belongs[i] = ptr++;\n        }\n        for (int i = 0; i < n;\
    \ i++) belongs[i] = belongs[uf.root(i)];\n        vector<pair<T, int>> v = f(ptr,\
    \ belongs);\n        for (int i = 0; i < ptr; i++) {\n            if (v[i].second\
    \ >= 0 && uf.unite(rev[i], rev[v[i].second])) res += v[i].first, update = true;\n\
    \        }\n        if (!update) break;\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/Boruvka.hpp
  requiredBy: []
  timestamp: '2020-06-13 20:39:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/Boruvka.hpp
layout: document
redirect_from:
- /library/src/old/Boruvka.hpp
- /library/src/old/Boruvka.hpp.html
title: src/old/Boruvka.hpp
---
