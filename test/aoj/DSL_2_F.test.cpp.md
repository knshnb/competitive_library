---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/LazySegmentTreeACL.hpp
    title: src/DataStructure/LazySegmentTreeACL.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\n#define\
    \ ALL(v) std::begin(v), std::end(v)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Wed Sep 30 01:42:47 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#line 2 \"src/DataStructure/LazySegmentTreeACL.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n)\
    \ {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index, n);\n\
    \    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace\
    \ internal\n\n}  // namespace atcoder\n\n#line 38 \"src/DataStructure/LazySegmentTreeACL.hpp\"\
    \nnamespace atcoder {\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F,\
    \ S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\nstruct lazy_segtree\
    \ {\npublic:\n    lazy_segtree() : lazy_segtree(0) {}\n    lazy_segtree(int n)\
    \ : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n        size\
    \ = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push(r >> i);\n        }\n\n        S sml\
    \ = e(), smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n  \
    \  S all_prod() { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n    \
    \    assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n   \
    \     l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int\
    \ l2 = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ f);\n                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l\
    \ >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\nprivate:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n}  // namespace atcoder\n\nnamespace min_update {\nusing T = Int;\n\
    \nusing S = T;\nS op(S x, S y) { return std::min<S>(x, y); }\nS e() { return std::numeric_limits<S>::max();\
    \ }\nusing F = T;\nconstexpr F dummy = std::numeric_limits<F>::min();\nS mapping(F\
    \ f, S x) { return f == dummy ? x : f; }\nF composition(F f, F g) { return f ==\
    \ dummy ? g : f; }\nF id() { return dummy; }\nusing segtree = atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n};  // namespace min_update\n\nnamespace\
    \ sum_add {\nusing T = Int;\n\nstruct S {\n    T sum;\n    int len;\n};\nS op(S\
    \ x, S y) { return {x.sum + y.sum, x.len + y.len}; }\nS e() { return {0, 0}; }\n\
    using F = T;\nS mapping(F f, S x) { return {x.sum + f * x.len, x.len}; }\nF composition(F\
    \ f, F g) { return f + g; }\nF id() { return 0; }\nusing segtree = atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n}  // namespace sum_add\n\nnamespace min_add\
    \ {\nusing T = Int;\n\nusing S = T;\nS op(S x, S y) { return std::min(x, y); }\n\
    S e() { return std::numeric_limits<S>::max() / 2; }\nusing F = T;\nS mapping(F\
    \ f, S x) { return x + f; }\nF composition(F f, F g) { return f + g; }\nF id()\
    \ { return 0; }\nusing segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n}  // namespace min_add\n\nnamespace sum_update {\nusing T = Int;\n\n\
    struct S {\n    T sum;\n    int len;\n};\nS op(S x, S y) { return {x.sum + y.sum,\
    \ x.len + y.len}; }\nS e() { return {0, 0}; }\nusing F = T;\nconstexpr F dummy\
    \ = std::numeric_limits<F>::min();\nS mapping(F f, S x) { return f == dummy ?\
    \ x : S{f * x.len, x.len}; }\nF composition(F f, F g) { return f == dummy ? g\
    \ : f; }\nF id() { return dummy; }\nusing segtree = atcoder::lazy_segtree<S, op,\
    \ e, F, mapping, composition, id>;\n}  // namespace sum_update\n#line 20 \"test/aoj/DSL_2_F.test.cpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, Q;\n    std::cin >> n >>\
    \ Q;\n    min_update::segtree seg(std::vector<Int>(n, (1LL << 31) - 1));\n   \
    \ REP(q, Q) {\n        Int t, l, r;\n        std::cin >> t >> l >> r, r++;\n \
    \       if (t == 0) {\n            Int x;\n            std::cin >> x;\n      \
    \      seg.apply(l, r, x);\n        } else {\n            std::cout << seg.prod(l,\
    \ r) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n\n#include <bits/stdc++.h>  // clang-format off\nusing Int = long long;\n#define\
    \ REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)\n\
    #define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)\n#define\
    \ ALL(v) std::begin(v), std::end(v)\nstruct SetupIO { SetupIO() { std::cin.tie(nullptr),\
    \ std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13);\
    \ } } setup_io;\n#ifndef dump\n#define dump(...)\n#endif  // clang-format on\n\
    \n/**\n *    author:  knshnb\n *    created: Wed Sep 30 01:42:47 JST 2020\n **/\n\
    \n#define CALL_FROM_TEST\n#include \"../../src/DataStructure/LazySegmentTreeACL.hpp\"\
    \n#undef CALL_FROM_TEST\n\nsigned main() {\n    Int n, Q;\n    std::cin >> n >>\
    \ Q;\n    min_update::segtree seg(std::vector<Int>(n, (1LL << 31) - 1));\n   \
    \ REP(q, Q) {\n        Int t, l, r;\n        std::cin >> t >> l >> r, r++;\n \
    \       if (t == 0) {\n            Int x;\n            std::cin >> x;\n      \
    \      seg.apply(l, r, x);\n        } else {\n            std::cout << seg.prod(l,\
    \ r) << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - src/DataStructure/LazySegmentTreeACL.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2020-09-30 02:17:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.test.cpp
- /verify/test/aoj/DSL_2_F.test.cpp.html
title: test/aoj/DSL_2_F.test.cpp
---