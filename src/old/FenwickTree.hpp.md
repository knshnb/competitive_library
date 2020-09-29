---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/FenwickTree.hpp\"\n// 0-indexed\ntemplate <class\
    \ T> struct FenwickTree {\n    const T e;\n    FenwickTree(T e_ = 0) : e(e_) {}\n\
    \    int n;\n    vector<T> t;\n    void set_by_identity(int n_) {\n        n =\
    \ n_;\n        t.clear(), t.resize(n, e);\n    }\n    void set_by_vector(const\
    \ vector<T>& a) {\n        n = a.size();\n        t.clear(), t = a;\n        for\
    \ (int i = 0; i < n - 1; i++) {\n            if ((i | (i + 1)) < n) t[i | (i +\
    \ 1)] = op(t[i | (i + 1)], t[i]);\n        }\n    }\n    // a\u756A\u76EE\u306B\
    x\u3092\u52A0\u7B97\n    void add(int a, T x) {\n        for (int i = a; i < n;\
    \ i |= i + 1) {\n            t[i] += x;\n        }\n    }\n\n    // [0, a)\u3001\
    a == 0\u306E\u3068\u304D\u306F0\u3092\u8FD4\u3059\n    T query(int a) const {\n\
    \        T ret = 0;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\
    \ {\n            ret += t[i];\n        }\n        return ret;\n    }\n    // [a,\
    \ b)\n    T query(int a, int b) const {\n        assert(a <= b);\n        return\
    \ query(b) - query(a);\n    }\n    T operator[](int a) const { return query(a,\
    \ a + 1); }\n    // k\u756A\u76EE\u3092x\u306B\n    void update(int a, T x) {\
    \ add(a, x - operator[](a)); }\n\n    // \u6CE8: \u4E2D\u8EAB\u304C\u5168\u3066\
    \u6B63\u306E\u3068\u304D\u3057\u304B\u52D5\u304B\u306A\u3044\n    // query[0,\
    \ i] >= x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int lower_bound(T\
    \ x) const {\n        int i = -1;\n        for (int w = 1 << __lg(n); w > 0; w\
    \ >>= 1) {\n            if (i + w < n && t[i + w] < x) {\n                x -=\
    \ t[i + w];\n                i += w;\n            }\n        }\n        return\
    \ i + 1;\n    }\n    // query[begin, i + 1) >= x\u3068\u306A\u308B\u3088\u3046\
    \u306A\u6700\u5C0F\u306Ei\n    int lower_bound(int begin, T x) const {\n     \
    \   int lb = lower_bound(x + query(begin));\n        return max(begin, lb);\n\
    \    }\n    // query(i + 1) > x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\
    \u306Ei\n    int upper_bound(T x) const {\n        int i = -1;\n        for (int\
    \ w = 1 << __lg(n); w > 0; w /= 2) {\n            if (i + w < n && t[i + w] <=\
    \ x) {\n                x -= t[i + w];\n                i += w;\n            }\n\
    \        }\n        return i + 1;\n    }\n    // query[begin, i + 1) > x\u3068\
    \u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int upper_bound(int begin,\
    \ T x) const {\n        int ub = upper_bound(x + query(begin));\n        return\
    \ max(begin, ub);\n    }\n    friend string to_string(const FenwickTree<T>& ft)\
    \ {\n        vector<T> ret(ft.n);\n        for (int i = 0; i < ft.n; i++) ret[i]\
    \ = ft.operator[](i);\n        return to_string(ret);\n    }\n};\n"
  code: "// 0-indexed\ntemplate <class T> struct FenwickTree {\n    const T e;\n \
    \   FenwickTree(T e_ = 0) : e(e_) {}\n    int n;\n    vector<T> t;\n    void set_by_identity(int\
    \ n_) {\n        n = n_;\n        t.clear(), t.resize(n, e);\n    }\n    void\
    \ set_by_vector(const vector<T>& a) {\n        n = a.size();\n        t.clear(),\
    \ t = a;\n        for (int i = 0; i < n - 1; i++) {\n            if ((i | (i +\
    \ 1)) < n) t[i | (i + 1)] = op(t[i | (i + 1)], t[i]);\n        }\n    }\n    //\
    \ a\u756A\u76EE\u306Bx\u3092\u52A0\u7B97\n    void add(int a, T x) {\n       \
    \ for (int i = a; i < n; i |= i + 1) {\n            t[i] += x;\n        }\n  \
    \  }\n\n    // [0, a)\u3001a == 0\u306E\u3068\u304D\u306F0\u3092\u8FD4\u3059\n\
    \    T query(int a) const {\n        T ret = 0;\n        for (int i = a - 1; i\
    \ >= 0; i = (i & (i + 1)) - 1) {\n            ret += t[i];\n        }\n      \
    \  return ret;\n    }\n    // [a, b)\n    T query(int a, int b) const {\n    \
    \    assert(a <= b);\n        return query(b) - query(a);\n    }\n    T operator[](int\
    \ a) const { return query(a, a + 1); }\n    // k\u756A\u76EE\u3092x\u306B\n  \
    \  void update(int a, T x) { add(a, x - operator[](a)); }\n\n    // \u6CE8: \u4E2D\
    \u8EAB\u304C\u5168\u3066\u6B63\u306E\u3068\u304D\u3057\u304B\u52D5\u304B\u306A\
    \u3044\n    // query[0, i] >= x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\
    \u306Ei\n    int lower_bound(T x) const {\n        int i = -1;\n        for (int\
    \ w = 1 << __lg(n); w > 0; w >>= 1) {\n            if (i + w < n && t[i + w] <\
    \ x) {\n                x -= t[i + w];\n                i += w;\n            }\n\
    \        }\n        return i + 1;\n    }\n    // query[begin, i + 1) >= x\u3068\
    \u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int lower_bound(int begin,\
    \ T x) const {\n        int lb = lower_bound(x + query(begin));\n        return\
    \ max(begin, lb);\n    }\n    // query(i + 1) > x\u3068\u306A\u308B\u3088\u3046\
    \u306A\u6700\u5C0F\u306Ei\n    int upper_bound(T x) const {\n        int i = -1;\n\
    \        for (int w = 1 << __lg(n); w > 0; w /= 2) {\n            if (i + w <\
    \ n && t[i + w] <= x) {\n                x -= t[i + w];\n                i +=\
    \ w;\n            }\n        }\n        return i + 1;\n    }\n    // query[begin,\
    \ i + 1) > x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int upper_bound(int\
    \ begin, T x) const {\n        int ub = upper_bound(x + query(begin));\n     \
    \   return max(begin, ub);\n    }\n    friend string to_string(const FenwickTree<T>&\
    \ ft) {\n        vector<T> ret(ft.n);\n        for (int i = 0; i < ft.n; i++)\
    \ ret[i] = ft.operator[](i);\n        return to_string(ret);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/FenwickTree.hpp
  requiredBy: []
  timestamp: '2020-04-28 00:07:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/FenwickTree.hpp
layout: document
redirect_from:
- /library/src/old/FenwickTree.hpp
- /library/src/old/FenwickTree.hpp.html
title: src/old/FenwickTree.hpp
---
