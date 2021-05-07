---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036_segment_tree.test.cpp
    title: test/yukicoder/1036_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/DataStructure/SegmentTree.md
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SegmentTree.hpp\"\n/// @docs src/DataStructure/SegmentTree.md\n\
    template <class T, class F> struct SegmentTree {\n    const F op;\n    const T\
    \ e;\n    SegmentTree(F op_, T e_) : op(op_), e(e_) {}\n    int n;\n    std::vector<T>\
    \ t;\n    void set_by_identity(int n_) {\n        n = n_;\n        t.clear(),\
    \ t.resize(2 * n, e);\n    }\n    void set_by_vector(const std::vector<T>& a)\
    \ {\n        n = a.size();\n        t.clear(), t.resize(2 * n, e);\n        for\
    \ (int i = 0; i < n; i++) t[i + n] = a[i];\n        build();\n    }\n    void\
    \ build() {\n        for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i +\
    \ 1]);\n    }\n    T& operator[](int i) { return t[i + n]; }\n    // [l, r)\n\
    \    T query(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        T resl = e, resr = e;\n        for (l += n, r += n; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) resl = op(resl, t[l++]);\n            if (r\
    \ & 1) resr = op(t[--r], resr);\n        }\n        return op(resl, resr);\n \
    \   }\n    // i\u756A\u76EE\u3092x\u306B\u5909\u66F4\n    void update(int i, const\
    \ T& x) {\n        assert(0 <= i && i < n);\n        t[i += n] = x;\n        while\
    \ (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);\n    }\n    // i\u756A\u76EE\u306B\
    x\u3092\u4F5C\u7528 (a[i] = op(a[i], x))\n    void operate(int i, const T& x)\
    \ {\n        assert(0 <= i && i < n);\n        i += n;\n        t[i] = op(t[i],\
    \ x);\n        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);\n    }\n   \
    \ friend std::string to_string(const SegmentTree<T, F>& seg) {\n        return\
    \ to_string(std::vector<T>(seg.t.begin() + seg.n, seg.t.end()));\n    }\n};\n\
    template <class T, class F> auto make_segment_tree(F op, T e) { return SegmentTree<T,\
    \ F>(op, e); }\n"
  code: "/// @docs src/DataStructure/SegmentTree.md\ntemplate <class T, class F> struct\
    \ SegmentTree {\n    const F op;\n    const T e;\n    SegmentTree(F op_, T e_)\
    \ : op(op_), e(e_) {}\n    int n;\n    std::vector<T> t;\n    void set_by_identity(int\
    \ n_) {\n        n = n_;\n        t.clear(), t.resize(2 * n, e);\n    }\n    void\
    \ set_by_vector(const std::vector<T>& a) {\n        n = a.size();\n        t.clear(),\
    \ t.resize(2 * n, e);\n        for (int i = 0; i < n; i++) t[i + n] = a[i];\n\
    \        build();\n    }\n    void build() {\n        for (int i = n - 1; i; --i)\
    \ t[i] = op(t[2 * i], t[2 * i + 1]);\n    }\n    T& operator[](int i) { return\
    \ t[i + n]; }\n    // [l, r)\n    T query(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        T resl = e, resr = e;\n        for (l +=\
    \ n, r += n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) resl = op(resl,\
    \ t[l++]);\n            if (r & 1) resr = op(t[--r], resr);\n        }\n     \
    \   return op(resl, resr);\n    }\n    // i\u756A\u76EE\u3092x\u306B\u5909\u66F4\
    \n    void update(int i, const T& x) {\n        assert(0 <= i && i < n);\n   \
    \     t[i += n] = x;\n        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);\n\
    \    }\n    // i\u756A\u76EE\u306Bx\u3092\u4F5C\u7528 (a[i] = op(a[i], x))\n \
    \   void operate(int i, const T& x) {\n        assert(0 <= i && i < n);\n    \
    \    i += n;\n        t[i] = op(t[i], x);\n        while (i >>= 1) t[i] = op(t[2\
    \ * i], t[2 * i + 1]);\n    }\n    friend std::string to_string(const SegmentTree<T,\
    \ F>& seg) {\n        return to_string(std::vector<T>(seg.t.begin() + seg.n, seg.t.end()));\n\
    \    }\n};\ntemplate <class T, class F> auto make_segment_tree(F op, T e) { return\
    \ SegmentTree<T, F>(op, e); }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2020-03-31 17:02:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/yukicoder/1036_segment_tree.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/staticrmq.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
documentation_of: src/DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree.hpp
- /library/src/DataStructure/SegmentTree.hpp.html
title: src/DataStructure/SegmentTree.hpp
---
## 概要
配列の長さが$2n$($n$は扱いたい範囲の要素数)でよいセグメント木。
実装方針の参考: https://codeforces.com/blog/entry/18051

## 使い方
### 変数
- `op(T a, T b) -> T`: T上のモノイド
- `e`: モノイドの単位元

### メソッド
- `query(int l, int r) -> T`: [l, r)の範囲のモノイドの合成を返す
- `update(int i, T x)`: $i$番目の要素を$x$に変更
- `operate(int i, T x)`: $i$番目の要素に$x$を作用

## 初期化例
- `Int`に対するmin
```cpp
auto seg = make_segment_tree<Int>([](Int a, Int b) { return std::min(a, b); }, 1e18);
```

- `Int`に対するmax
```cpp
auto seg = make_segment_tree<Int>([](Int a, Int b) { return std::max(a, b); }, -1e18);
```

- `Int`に対するsum
```cpp
auto seg = make_segment_tree<Int>(std::plus<Int>(), 0);
```

- gcd
```cpp
auto seg = make_segment_tree<Int>([](Int x, Int y) { return std::gcd(x, y); }, 0);
```

- `Int`に対するAffine
```cpp
auto seg = make_segment_tree<std::pair<Int, Int>>(
    [](std::pair<Int, Int> a, std::pair<Int, Int> b) -> std::pair<Int, Int> {
        return {a.first * b.first, b.first * a.second + b.second};
    },
    {1, 0});
```