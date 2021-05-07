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
  bundledCode: "#line 1 \"src/old/ConvexHullTrick.hpp\"\ntemplate <typename T, const\
    \ T id = (int)-1e18> class convex_hull_trick {\n    struct line {\n        T a,\
    \ b;\n        line(T a_ = 0, T b_ = 0) : a(a_), b(b_) {}\n        T get(T x) {\
    \ return a * x + b; }\n    };\n    struct node {\n        line l;\n        node\
    \ *lch, *rch;\n        node(line l_) : l(l_), lch(nullptr), rch(nullptr) {}\n\
    \        ~node() {\n            if (lch) delete lch;\n            if (rch) delete\
    \ rch;\n        }\n    };\n\nprivate:\n    const int n;\n    const vector<T> pos;\n\
    \    node *root;\n\npublic:\n    convex_hull_trick(const vector<T> &pos_) : n(pos_.size()),\
    \ pos(pos_), root(nullptr) {}\n    ~convex_hull_trick() {\n        if (root) delete\
    \ root;\n    }\n    // max\u3092\u6C42\u3081\u308B\u3068\u304D\n    void insert(T\
    \ a, T b) {\n        line l(a, b);\n        root = modify(root, 0, n - 1, l);\n\
    \    }\n    T get(T x) const {\n        int t = lower_bound(pos.begin(), pos.end(),\
    \ x) - pos.begin();\n        assert(t < n && pos[t] == x);\n        return sub(root,\
    \ 0, n - 1, t);\n    }\n    // min\u3092\u6C42\u3081\u308B\u3068\u304D\n    void\
    \ rev_insert(T a, T b) { insert(-a, -b); }\n    T rev_get(T x) const { return\
    \ -get(x); }\n\nprivate:\n    node *modify(node *p, int lb, int ub, line &l) {\n\
    \        if (!p) return new node(l);\n        if (p->l.get(pos[lb]) >= l.get(pos[lb])\
    \ && p->l.get(pos[ub]) >= l.get(pos[ub])) return p;\n        if (p->l.get(pos[lb])\
    \ <= l.get(pos[lb]) && p->l.get(pos[ub]) <= l.get(pos[ub])) {\n            p->l\
    \ = l;\n            return p;\n        }\n        int c = (lb + ub) / 2;\n   \
    \     if (p->l.get(pos[c]) < l.get(pos[c])) swap(p->l, l);\n        if (p->l.get(pos[lb])\
    \ <= l.get(pos[lb]))\n            p->lch = modify(p->lch, lb, c, l);\n       \
    \ else\n            p->rch = modify(p->rch, c + 1, ub, l);\n        return p;\n\
    \    }\n    T sub(node *p, int lb, int ub, int t) const {\n        if (!p) return\
    \ id;\n        if (ub - lb == 0) return p->l.get(pos[t]);\n        int c = (lb\
    \ + ub) / 2;\n        if (t <= c) return max(p->l.get(pos[t]), sub(p->lch, lb,\
    \ c, t));\n        return max(p->l.get(pos[t]), sub(p->rch, c + 1, ub, t));\n\
    \    }\n};\n"
  code: "template <typename T, const T id = (int)-1e18> class convex_hull_trick {\n\
    \    struct line {\n        T a, b;\n        line(T a_ = 0, T b_ = 0) : a(a_),\
    \ b(b_) {}\n        T get(T x) { return a * x + b; }\n    };\n    struct node\
    \ {\n        line l;\n        node *lch, *rch;\n        node(line l_) : l(l_),\
    \ lch(nullptr), rch(nullptr) {}\n        ~node() {\n            if (lch) delete\
    \ lch;\n            if (rch) delete rch;\n        }\n    };\n\nprivate:\n    const\
    \ int n;\n    const vector<T> pos;\n    node *root;\n\npublic:\n    convex_hull_trick(const\
    \ vector<T> &pos_) : n(pos_.size()), pos(pos_), root(nullptr) {}\n    ~convex_hull_trick()\
    \ {\n        if (root) delete root;\n    }\n    // max\u3092\u6C42\u3081\u308B\
    \u3068\u304D\n    void insert(T a, T b) {\n        line l(a, b);\n        root\
    \ = modify(root, 0, n - 1, l);\n    }\n    T get(T x) const {\n        int t =\
    \ lower_bound(pos.begin(), pos.end(), x) - pos.begin();\n        assert(t < n\
    \ && pos[t] == x);\n        return sub(root, 0, n - 1, t);\n    }\n    // min\u3092\
    \u6C42\u3081\u308B\u3068\u304D\n    void rev_insert(T a, T b) { insert(-a, -b);\
    \ }\n    T rev_get(T x) const { return -get(x); }\n\nprivate:\n    node *modify(node\
    \ *p, int lb, int ub, line &l) {\n        if (!p) return new node(l);\n      \
    \  if (p->l.get(pos[lb]) >= l.get(pos[lb]) && p->l.get(pos[ub]) >= l.get(pos[ub]))\
    \ return p;\n        if (p->l.get(pos[lb]) <= l.get(pos[lb]) && p->l.get(pos[ub])\
    \ <= l.get(pos[ub])) {\n            p->l = l;\n            return p;\n       \
    \ }\n        int c = (lb + ub) / 2;\n        if (p->l.get(pos[c]) < l.get(pos[c]))\
    \ swap(p->l, l);\n        if (p->l.get(pos[lb]) <= l.get(pos[lb]))\n         \
    \   p->lch = modify(p->lch, lb, c, l);\n        else\n            p->rch = modify(p->rch,\
    \ c + 1, ub, l);\n        return p;\n    }\n    T sub(node *p, int lb, int ub,\
    \ int t) const {\n        if (!p) return id;\n        if (ub - lb == 0) return\
    \ p->l.get(pos[t]);\n        int c = (lb + ub) / 2;\n        if (t <= c) return\
    \ max(p->l.get(pos[t]), sub(p->lch, lb, c, t));\n        return max(p->l.get(pos[t]),\
    \ sub(p->rch, c + 1, ub, t));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/ConvexHullTrick.hpp
  requiredBy: []
  timestamp: '2020-06-13 20:39:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/ConvexHullTrick.hpp
layout: document
redirect_from:
- /library/src/old/ConvexHullTrick.hpp
- /library/src/old/ConvexHullTrick.hpp.html
title: src/old/ConvexHullTrick.hpp
---
