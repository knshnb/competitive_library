---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/ReversedBinaryIndexedTree.hpp\"\n// 0-indexed\n\
    class BinaryIndexedTree {\n    int max_pow;  // N\u4EE5\u4E0B\u306E\u6700\u5927\
    \u306E2\u3079\u304D\npublic:\n    vector<int> bit;\n    int N;\n    BinaryIndexedTree(int\
    \ n, int x = 0) : N(n), bit(n, x) {\n        for (max_pow = 1; max_pow <= N /\
    \ 2; max_pow *= 2)\n            ;\n    }\n    BinaryIndexedTree(const vector<int>&\
    \ a) : N(a.size()), bit(a) {\n        for (max_pow = 1; max_pow <= N / 2; max_pow\
    \ *= 2)\n            ;\n        REP(i, N - 1) if ((i | (i + 1)) < N) { bit[i |\
    \ (i + 1)] += bit[i]; }\n    }\n    // k\u756A\u76EE\u306Bx\u3092\u52A0\u7B97\n\
    \    void add(int k, int x) {\n        for (int i = k; i < N; i |= i + 1) {\n\
    \            bit[i] += x;\n        }\n    }\n\n    // [0, k)\u3001k == 0\u306E\
    \u3068\u304D\u306F0\u3092\u8FD4\u3059\n    int sum(int k) {\n        int ret =\
    \ 0;\n        for (int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) {\n         \
    \   ret += bit[i];\n        }\n        return ret;\n    }\n    int sum() { return\
    \ sum(N); }\n\n    // [a, b)\n    int query(int a, int b) {\n        assert(a\
    \ <= b);\n        return sum(b) - sum(a);\n    }\n    int operator[](int k) {\
    \ return query(k, k + 1); }\n\n    // k\u756A\u76EE\u3092x\u306B\n    void update(int\
    \ k, int x) { add(k, x - operator[](k)); }\n\n    // \u6CE8: \u4E2D\u8EAB\u304C\
    \u5168\u3066\u6B63\u306E\u3068\u304D\u3057\u304B\u52D5\u304B\u306A\u3044\n   \
    \ // sum(i + 1) >= x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ei\n\
    \    int lower_bound(int x) {\n        int i = -1;\n        for (int w = max_pow;\
    \ w > 0; w /= 2) {\n            if (i + w < N && bit[i + w] < x) {\n         \
    \       x -= bit[i + w];\n                i += w;\n            }\n        }\n\
    \        return i + 1;\n    }\n    // query[begin, i + 1) >= x\u3068\u306A\u308B\
    \u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int lower_bound(int begin, int x) {\n\
    \        int lb = lower_bound(x + sum(begin));\n        return max(begin, lb);\n\
    \    }\n    // sum(i + 1) > x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306E\
    i\n    int upper_bound(int x) {\n        int i = -1;\n        for (int w = max_pow;\
    \ w > 0; w /= 2) {\n            if (i + w < N && bit[i + w] <= x) {\n        \
    \        x -= bit[i + w];\n                i += w;\n            }\n        }\n\
    \        return i + 1;\n    }\n    // query[begin, i + 1) > x\u3068\u306A\u308B\
    \u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int upper_bound(int begin, int x) {\n\
    \        int ub = upper_bound(x + sum(begin));\n        return max(begin, ub);\n\
    \    }\n};\n\n// \u5927\u304D\u3044\u65B9\u304B\u3089lower_bound\u306A\u3069\u3092\
    \u3057\u305F\u3044\u3068\u304D\u306Ewrapper\n// \u653F\u5E9C\u9006\u8EE2\u3055\
    \u305B\u3066(-N, 0]\u306B\u3057\u3066\u3001\u5E73\u884C\u79FB\u52D5\u3057\u3066\
    [0, N)\u306B\u3057\u3066\u3044\u308B\nclass ReversedBinaryIndexedTree : public\
    \ BinaryIndexedTree {\npublic:\n    using BinaryIndexedTree::BinaryIndexedTree;\n\
    \    int rev(int k) { return N - 1 - k; }\n    void add(int k, int x) { BinaryIndexedTree::add(rev(k),\
    \ x); }\n    // (k, N-1]\n    int sum(int k) { return BinaryIndexedTree::sum(rev(k));\
    \ }\n    // query(i - 1, N-1] >= x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\
    n\u306Ei\n    int lower_bound(int x) { return rev(BinaryIndexedTree::lower_bound(x));\
    \ }\n    // query(i - 1, N-1] > x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\
    n\u306Ei\n    int upper_bound(int x) { return rev(BinaryIndexedTree::upper_bound(x));\
    \ }\n};\n"
  code: "// 0-indexed\nclass BinaryIndexedTree {\n    int max_pow;  // N\u4EE5\u4E0B\
    \u306E\u6700\u5927\u306E2\u3079\u304D\npublic:\n    vector<int> bit;\n    int\
    \ N;\n    BinaryIndexedTree(int n, int x = 0) : N(n), bit(n, x) {\n        for\
    \ (max_pow = 1; max_pow <= N / 2; max_pow *= 2)\n            ;\n    }\n    BinaryIndexedTree(const\
    \ vector<int>& a) : N(a.size()), bit(a) {\n        for (max_pow = 1; max_pow <=\
    \ N / 2; max_pow *= 2)\n            ;\n        REP(i, N - 1) if ((i | (i + 1))\
    \ < N) { bit[i | (i + 1)] += bit[i]; }\n    }\n    // k\u756A\u76EE\u306Bx\u3092\
    \u52A0\u7B97\n    void add(int k, int x) {\n        for (int i = k; i < N; i |=\
    \ i + 1) {\n            bit[i] += x;\n        }\n    }\n\n    // [0, k)\u3001\
    k == 0\u306E\u3068\u304D\u306F0\u3092\u8FD4\u3059\n    int sum(int k) {\n    \
    \    int ret = 0;\n        for (int i = k - 1; i >= 0; i = (i & (i + 1)) - 1)\
    \ {\n            ret += bit[i];\n        }\n        return ret;\n    }\n    int\
    \ sum() { return sum(N); }\n\n    // [a, b)\n    int query(int a, int b) {\n \
    \       assert(a <= b);\n        return sum(b) - sum(a);\n    }\n    int operator[](int\
    \ k) { return query(k, k + 1); }\n\n    // k\u756A\u76EE\u3092x\u306B\n    void\
    \ update(int k, int x) { add(k, x - operator[](k)); }\n\n    // \u6CE8: \u4E2D\
    \u8EAB\u304C\u5168\u3066\u6B63\u306E\u3068\u304D\u3057\u304B\u52D5\u304B\u306A\
    \u3044\n    // sum(i + 1) >= x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\
    \u306Ei\n    int lower_bound(int x) {\n        int i = -1;\n        for (int w\
    \ = max_pow; w > 0; w /= 2) {\n            if (i + w < N && bit[i + w] < x) {\n\
    \                x -= bit[i + w];\n                i += w;\n            }\n  \
    \      }\n        return i + 1;\n    }\n    // query[begin, i + 1) >= x\u3068\u306A\
    \u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int lower_bound(int begin, int\
    \ x) {\n        int lb = lower_bound(x + sum(begin));\n        return max(begin,\
    \ lb);\n    }\n    // sum(i + 1) > x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\
    \u5C0F\u306Ei\n    int upper_bound(int x) {\n        int i = -1;\n        for\
    \ (int w = max_pow; w > 0; w /= 2) {\n            if (i + w < N && bit[i + w]\
    \ <= x) {\n                x -= bit[i + w];\n                i += w;\n       \
    \     }\n        }\n        return i + 1;\n    }\n    // query[begin, i + 1) >\
    \ x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ei\n    int upper_bound(int\
    \ begin, int x) {\n        int ub = upper_bound(x + sum(begin));\n        return\
    \ max(begin, ub);\n    }\n};\n\n// \u5927\u304D\u3044\u65B9\u304B\u3089lower_bound\u306A\
    \u3069\u3092\u3057\u305F\u3044\u3068\u304D\u306Ewrapper\n// \u653F\u5E9C\u9006\
    \u8EE2\u3055\u305B\u3066(-N, 0]\u306B\u3057\u3066\u3001\u5E73\u884C\u79FB\u52D5\
    \u3057\u3066[0, N)\u306B\u3057\u3066\u3044\u308B\nclass ReversedBinaryIndexedTree\
    \ : public BinaryIndexedTree {\npublic:\n    using BinaryIndexedTree::BinaryIndexedTree;\n\
    \    int rev(int k) { return N - 1 - k; }\n    void add(int k, int x) { BinaryIndexedTree::add(rev(k),\
    \ x); }\n    // (k, N-1]\n    int sum(int k) { return BinaryIndexedTree::sum(rev(k));\
    \ }\n    // query(i - 1, N-1] >= x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\
    n\u306Ei\n    int lower_bound(int x) { return rev(BinaryIndexedTree::lower_bound(x));\
    \ }\n    // query(i - 1, N-1] > x\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\
    n\u306Ei\n    int upper_bound(int x) { return rev(BinaryIndexedTree::upper_bound(x));\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/ReversedBinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2020-04-28 00:07:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/ReversedBinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/src/old/ReversedBinaryIndexedTree.hpp
- /library/src/old/ReversedBinaryIndexedTree.hpp.html
title: src/old/ReversedBinaryIndexedTree.hpp
---
