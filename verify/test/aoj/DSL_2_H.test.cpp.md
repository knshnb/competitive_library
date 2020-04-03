---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/DSL_2_H.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_H.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 22:30:09+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/LazySegmentTree.hpp.html">src/DataStructure/LazySegmentTree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Mar 21 19:52:09 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/LazySegmentTree.hpp"
#undef CALL_FROM_TEST

const Int INF = 1e9;
signed main() {
    int n, Q;
    std::cin >> n >> Q;
    auto seg = make_lazy_segment_tree<Int, Int>(
        [](Int x, Int y) { return std::min(x, y); }, INF, [](Int x, Int y) { return x + y; }, 0,
        [](Int x, Int y) { return x == INF ? x : x + y; }, [](Int x, int len) { return x; });
    seg.set_by_vector(std::vector<Int>(n));
    REP(q, Q) {
        int c, s, t;
        std::cin >> c >> s >> t;
        t++;
        if (c == 0) {
            Int x;
            std::cin >> x;
            seg.update(s, t, x);
        } else {
            std::cout << seg.query(s, t) << std::endl;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_H.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Mar 21 19:52:09 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/DataStructure/LazySegmentTree.hpp"
/// @docs src/DataStructure/LazySegmentTree.md
template <class T0, class T1, class F0, class F1, class G, class P> class LazySegmentTree {
    // k番目のノードにのlazyを伝搬
    void eval(int k, int len) {
        // 定数倍高速化
        if (lazy[k] == u1) return;
        // len個分のlazy[k]を評価
        node[k] = g(node[k], p(lazy[k], len));
        if (k < N - 1) {
            // 最下段でなければ下のlazyに伝搬
            lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);
        }
        lazy[k] = u1;
    }
    // k番目のノード[l, r)について、[a, b)の範囲内にxを作用
    void update(int a, int b, T1 x, int k, int l, int r) {
        eval(k, r - l);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = f1(lazy[k], x);
            eval(k, r - l);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = f0(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    // k番目のノード[l, r)について、[a, b)のクエリを求める
    T0 query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return u0;
        eval(k, r - l);
        if (a <= l && r <= b) return node[k];
        T0 vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f0(vl, vr);
    }

public:
    int sz;  // 元の配列のサイズ
    int N;
    std::vector<T0> node;
    std::vector<T1> lazy;
    // T0上の演算、単位元
    const F0 f0;
    const T0 u0;
    // T1上の演算、単位元
    const F1 f1;
    const T1 u1;
    // T0に対するT1の作用
    const G g;
    // 多数のt1(T1)に対するf1の合成
    const P p;

    LazySegmentTree(F0 f0_, T0 u0_, F1 f1_, T1 u1_, G g_, P p_) : f0(f0_), u0(u0_), f1(f1_), u1(u1_), g(g_), p(p_) {}
    void set_by_vector(const std::vector<T0>& a) {
        sz = a.size();
        for (N = 1; N < sz; N *= 2)
            ;
        node.resize(2 * N - 1, u0);
        lazy.resize(2 * N - 1, u1);
        for (int i = 0; i < sz; i++) node[N - 1 + i] = a[i];
        for (int i = N - 2; i >= 0; i--) node[i] = f0(node[2 * i + 1], node[2 * i + 2]);
    }
    void set_by_unit(int n) {
        sz = n;
        for (N = 1; N < sz; N *= 2)
            ;
        node.resize(2 * N - 1, u0);
        lazy.resize(2 * N - 1, u1);
    }
    // [a, b)にxを作用
    void update(int a, int b, T1 x) {
        assert(0 <= a && a < b && b <= sz);
        update(a, b, x, 0, 0, N);
    }
    void update(int a, T1 x) { update(a, a + 1, x); }
    // [a, b)
    T0 query(int a, int b) { return query(a, b, 0, 0, N); }
    T0 query(int a) { return query(a, a + 1); }
    friend std::string to_string(LazySegmentTree<T0, T1, F0, F1, G, P>& seg) {
        for (int i = 0; i < seg.sz; i++) seg.query(i);
        return to_string(std::vector<T0>(seg.node.begin() + (seg.N - 1), seg.node.begin() + (seg.N - 1 + seg.sz)));
    }
};
template <class T0, class T1, class F0, class F1, class G, class P>
auto make_lazy_segment_tree(F0 f0, T0 u0, F1 f1, T1 u1, G g, P p) {
    return LazySegmentTree<T0, T1, F0, F1, G, P>(f0, u0, f1, u1, g, p);
}
#line 19 "test/aoj/DSL_2_H.test.cpp"
#undef CALL_FROM_TEST

const Int INF = 1e9;
signed main() {
    int n, Q;
    std::cin >> n >> Q;
    auto seg = make_lazy_segment_tree<Int, Int>(
        [](Int x, Int y) { return std::min(x, y); }, INF, [](Int x, Int y) { return x + y; }, 0,
        [](Int x, Int y) { return x == INF ? x : x + y; }, [](Int x, int len) { return x; });
    seg.set_by_vector(std::vector<Int>(n));
    REP(q, Q) {
        int c, s, t;
        std::cin >> c >> s >> t;
        t++;
        if (c == 0) {
            Int x;
            std::cin >> x;
            seg.update(s, t, x);
        } else {
            std::cout << seg.query(s, t) << std::endl;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

