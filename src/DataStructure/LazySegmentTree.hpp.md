---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/DataStructure/LazySegmentTree.md
    links: []
  bundledCode: "#line 1 \"src/DataStructure/LazySegmentTree.hpp\"\n/// @docs src/DataStructure/LazySegmentTree.md\n\
    template <class T0, class T1, class F0, class F1, class G, class P> class LazySegmentTree\
    \ {\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306B\u306Elazy\u3092\u4F1D\u642C\
    \n    void eval(int k, int len) {\n        // \u5B9A\u6570\u500D\u9AD8\u901F\u5316\
    \n        if (lazy[k] == u1) return;\n        // len\u500B\u5206\u306Elazy[k]\u3092\
    \u8A55\u4FA1\n        node[k] = g(node[k], p(lazy[k], len));\n        if (k <\
    \ N - 1) {\n            // \u6700\u4E0B\u6BB5\u3067\u306A\u3051\u308C\u3070\u4E0B\
    \u306Elazy\u306B\u4F1D\u642C\n            lazy[2 * k + 1] = f1(lazy[2 * k + 1],\
    \ lazy[k]);\n            lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);\n   \
    \     }\n        lazy[k] = u1;\n    }\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\
    [l, r)\u306B\u3064\u3044\u3066\u3001[a, b)\u306E\u7BC4\u56F2\u5185\u306Bx\u3092\
    \u4F5C\u7528\n    void update(int a, int b, T1 x, int k, int l, int r) {\n   \
    \     eval(k, r - l);\n        if (b <= l || r <= a) return;\n        if (a <=\
    \ l && r <= b) {\n            lazy[k] = f1(lazy[k], x);\n            eval(k, r\
    \ - l);\n        } else {\n            update(a, b, x, 2 * k + 1, l, (l + r) /\
    \ 2);\n            update(a, b, x, 2 * k + 2, (l + r) / 2, r);\n            node[k]\
    \ = f0(node[2 * k + 1], node[2 * k + 2]);\n        }\n    }\n    // k\u756A\u76EE\
    \u306E\u30CE\u30FC\u30C9[l, r)\u306B\u3064\u3044\u3066\u3001[a, b)\u306E\u30AF\
    \u30A8\u30EA\u3092\u6C42\u3081\u308B\n    T0 query(int a, int b, int k, int l,\
    \ int r) {\n        if (r <= a || b <= l) return u0;\n        eval(k, r - l);\n\
    \        if (a <= l && r <= b) return node[k];\n        T0 vl = query(a, b, 2\
    \ * k + 1, l, (l + r) / 2);\n        T0 vr = query(a, b, 2 * k + 2, (l + r) /\
    \ 2, r);\n        return f0(vl, vr);\n    }\n\npublic:\n    int sz;  // \u5143\
    \u306E\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    int N;\n    std::vector<T0> node;\n\
    \    std::vector<T1> lazy;\n    // T0\u4E0A\u306E\u6F14\u7B97\u3001\u5358\u4F4D\
    \u5143\n    const F0 f0;\n    const T0 u0;\n    // T1\u4E0A\u306E\u6F14\u7B97\u3001\
    \u5358\u4F4D\u5143\n    const F1 f1;\n    const T1 u1;\n    // T0\u306B\u5BFE\u3059\
    \u308BT1\u306E\u4F5C\u7528\n    const G g;\n    // \u591A\u6570\u306Et1(T1)\u306B\
    \u5BFE\u3059\u308Bf1\u306E\u5408\u6210\n    const P p;\n\n    LazySegmentTree(F0\
    \ f0_, T0 u0_, F1 f1_, T1 u1_, G g_, P p_) : f0(f0_), u0(u0_), f1(f1_), u1(u1_),\
    \ g(g_), p(p_) {}\n    void set_by_vector(const std::vector<T0>& a) {\n      \
    \  sz = a.size();\n        for (N = 1; N < sz; N *= 2)\n            ;\n      \
    \  node.resize(2 * N - 1, u0);\n        lazy.resize(2 * N - 1, u1);\n        for\
    \ (int i = 0; i < sz; i++) node[N - 1 + i] = a[i];\n        for (int i = N - 2;\
    \ i >= 0; i--) node[i] = f0(node[2 * i + 1], node[2 * i + 2]);\n    }\n    void\
    \ set_by_unit(int n) {\n        sz = n;\n        for (N = 1; N < sz; N *= 2)\n\
    \            ;\n        node.resize(2 * N - 1, u0);\n        lazy.resize(2 * N\
    \ - 1, u1);\n    }\n    // [a, b)\u306Bx\u3092\u4F5C\u7528\n    void update(int\
    \ a, int b, T1 x) {\n        assert(0 <= a && a < b && b <= sz);\n        update(a,\
    \ b, x, 0, 0, N);\n    }\n    void update(int a, T1 x) { update(a, a + 1, x);\
    \ }\n    // [a, b)\n    T0 query(int a, int b) { return query(a, b, 0, 0, N);\
    \ }\n    T0 query(int a) { return query(a, a + 1); }\n    friend std::string to_string(LazySegmentTree<T0,\
    \ T1, F0, F1, G, P>& seg) {\n        for (int i = 0; i < seg.sz; i++) seg.query(i);\n\
    \        return to_string(std::vector<T0>(seg.node.begin() + (seg.N - 1), seg.node.begin()\
    \ + (seg.N - 1 + seg.sz)));\n    }\n};\ntemplate <class T0, class T1, class F0,\
    \ class F1, class G, class P>\nauto make_lazy_segment_tree(F0 f0, T0 u0, F1 f1,\
    \ T1 u1, G g, P p) {\n    return LazySegmentTree<T0, T1, F0, F1, G, P>(f0, u0,\
    \ f1, u1, g, p);\n}\n"
  code: "/// @docs src/DataStructure/LazySegmentTree.md\ntemplate <class T0, class\
    \ T1, class F0, class F1, class G, class P> class LazySegmentTree {\n    // k\u756A\
    \u76EE\u306E\u30CE\u30FC\u30C9\u306B\u306Elazy\u3092\u4F1D\u642C\n    void eval(int\
    \ k, int len) {\n        // \u5B9A\u6570\u500D\u9AD8\u901F\u5316\n        if (lazy[k]\
    \ == u1) return;\n        // len\u500B\u5206\u306Elazy[k]\u3092\u8A55\u4FA1\n\
    \        node[k] = g(node[k], p(lazy[k], len));\n        if (k < N - 1) {\n  \
    \          // \u6700\u4E0B\u6BB5\u3067\u306A\u3051\u308C\u3070\u4E0B\u306Elazy\u306B\
    \u4F1D\u642C\n            lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);\n  \
    \          lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);\n        }\n      \
    \  lazy[k] = u1;\n    }\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9[l, r)\u306B\
    \u3064\u3044\u3066\u3001[a, b)\u306E\u7BC4\u56F2\u5185\u306Bx\u3092\u4F5C\u7528\
    \n    void update(int a, int b, T1 x, int k, int l, int r) {\n        eval(k,\
    \ r - l);\n        if (b <= l || r <= a) return;\n        if (a <= l && r <= b)\
    \ {\n            lazy[k] = f1(lazy[k], x);\n            eval(k, r - l);\n    \
    \    } else {\n            update(a, b, x, 2 * k + 1, l, (l + r) / 2);\n     \
    \       update(a, b, x, 2 * k + 2, (l + r) / 2, r);\n            node[k] = f0(node[2\
    \ * k + 1], node[2 * k + 2]);\n        }\n    }\n    // k\u756A\u76EE\u306E\u30CE\
    \u30FC\u30C9[l, r)\u306B\u3064\u3044\u3066\u3001[a, b)\u306E\u30AF\u30A8\u30EA\
    \u3092\u6C42\u3081\u308B\n    T0 query(int a, int b, int k, int l, int r) {\n\
    \        if (r <= a || b <= l) return u0;\n        eval(k, r - l);\n        if\
    \ (a <= l && r <= b) return node[k];\n        T0 vl = query(a, b, 2 * k + 1, l,\
    \ (l + r) / 2);\n        T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n   \
    \     return f0(vl, vr);\n    }\n\npublic:\n    int sz;  // \u5143\u306E\u914D\
    \u5217\u306E\u30B5\u30A4\u30BA\n    int N;\n    std::vector<T0> node;\n    std::vector<T1>\
    \ lazy;\n    // T0\u4E0A\u306E\u6F14\u7B97\u3001\u5358\u4F4D\u5143\n    const\
    \ F0 f0;\n    const T0 u0;\n    // T1\u4E0A\u306E\u6F14\u7B97\u3001\u5358\u4F4D\
    \u5143\n    const F1 f1;\n    const T1 u1;\n    // T0\u306B\u5BFE\u3059\u308B\
    T1\u306E\u4F5C\u7528\n    const G g;\n    // \u591A\u6570\u306Et1(T1)\u306B\u5BFE\
    \u3059\u308Bf1\u306E\u5408\u6210\n    const P p;\n\n    LazySegmentTree(F0 f0_,\
    \ T0 u0_, F1 f1_, T1 u1_, G g_, P p_) : f0(f0_), u0(u0_), f1(f1_), u1(u1_), g(g_),\
    \ p(p_) {}\n    void set_by_vector(const std::vector<T0>& a) {\n        sz = a.size();\n\
    \        for (N = 1; N < sz; N *= 2)\n            ;\n        node.resize(2 * N\
    \ - 1, u0);\n        lazy.resize(2 * N - 1, u1);\n        for (int i = 0; i <\
    \ sz; i++) node[N - 1 + i] = a[i];\n        for (int i = N - 2; i >= 0; i--) node[i]\
    \ = f0(node[2 * i + 1], node[2 * i + 2]);\n    }\n    void set_by_unit(int n)\
    \ {\n        sz = n;\n        for (N = 1; N < sz; N *= 2)\n            ;\n   \
    \     node.resize(2 * N - 1, u0);\n        lazy.resize(2 * N - 1, u1);\n    }\n\
    \    // [a, b)\u306Bx\u3092\u4F5C\u7528\n    void update(int a, int b, T1 x) {\n\
    \        assert(0 <= a && a < b && b <= sz);\n        update(a, b, x, 0, 0, N);\n\
    \    }\n    void update(int a, T1 x) { update(a, a + 1, x); }\n    // [a, b)\n\
    \    T0 query(int a, int b) { return query(a, b, 0, 0, N); }\n    T0 query(int\
    \ a) { return query(a, a + 1); }\n    friend std::string to_string(LazySegmentTree<T0,\
    \ T1, F0, F1, G, P>& seg) {\n        for (int i = 0; i < seg.sz; i++) seg.query(i);\n\
    \        return to_string(std::vector<T0>(seg.node.begin() + (seg.N - 1), seg.node.begin()\
    \ + (seg.N - 1 + seg.sz)));\n    }\n};\ntemplate <class T0, class T1, class F0,\
    \ class F1, class G, class P>\nauto make_lazy_segment_tree(F0 f0, T0 u0, F1 f1,\
    \ T1 u1, G g, P p) {\n    return LazySegmentTree<T0, T1, F0, F1, G, P>(f0, u0,\
    \ f1, u1, g, p);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2020-04-03 22:30:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_H.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: src/DataStructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/LazySegmentTree.hpp
- /library/src/DataStructure/LazySegmentTree.hpp.html
title: src/DataStructure/LazySegmentTree.hpp
---
## 概要
区間更新区間取得セグメント木。

参考
- http://tsutaj.hatenablog.com/entry/2017/03/30/224339
- https://beet-aizu.hatenablog.com/entry/2017/12/01/225955

## 使い方
### 変数
- `f0(T0, T0) -> T0`: 取得クエリのモノイド
- `f1(T1, T1) -> T1`: 作用素同士のモノイド
- `g(T0, T1) -> T0`: $\mathrm{T0}$に対する$\mathrm{T1}$の作用(更新クエリ)
- `p(T1 x, int len) -> T1`: 長さ$\mathrm{len}$の区間に$x$を作用させたとき、$\mathrm{f0}$による区間合成がどう変わるか

### メソッド
- `query(int l, int r) -> T`: $\[l, r)$の範囲のモノイドの合成を返す
- `update(int l, int t, T1 x)`: $\[l, r)$の範囲に$x$を作用

## 初期化例
- `Int`に対するAdd & Sum
```cpp
auto seg = make_lazy_segment_tree<Int, Int>(std::plus<Int>(), 0, std::plus<Int>(), 0, std::plus<Int>(),
                                            [](Int x, int len) { return x * len; });
```

- `Int`に対するAdd & Max
```cpp
constexpr Int INF = 1e18;
auto seg = make_lazy_segment_tree<Int, Int>(
    [](Int x, Int y) { return std::max(x, y); }, -INF, [](Int x, Int y) { return x + y; }, 0,
    [](Int x, Int y) { return x == -INF ? x : x + y; }, [](Int x, int len) { return x; });
```

- `Int`に対するAdd & Min
```cpp
constexpr Int INF = 1e18;
auto seg = make_lazy_segment_tree<Int, Int>(
    [](Int x, Int y) { return std::min(x, y); }, INF, [](Int x, Int y) { return x + y; }, 0,
    [](Int x, Int y) { return x == INF ? x : x + y; }, [](Int x, int len) { return x; });
```

- `mint`に対するAffine & Sum
```cpp
auto seg = make_lazy_segment_tree<mint, pmm>(
    std::plus<mint>(), 0,
    [](pmm x, pmm y) -> pmm {
        return {x.first * y.first, x.second * y.first + y.second};
    },
    {1, 0}, [](mint x, pmm y) { return y.first * x + y.second; },
    [](pmm x, int len) -> pmm {
        return {x.first, x.second * len};
    });
```
