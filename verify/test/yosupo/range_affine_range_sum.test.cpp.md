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


# :heavy_check_mark: test/yosupo/range_affine_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-29 04:09:47+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/LazySegmentTree.hpp.html">src/DataStructure/LazySegmentTree.hpp</a>
* :heavy_check_mark: <a href="../../../library/src/Math/ModInt.hpp.html">src/Math/ModInt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Mon Mar 30 21:14:19 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/ModInt.hpp"
#include "../../src/DataStructure/LazySegmentTree.hpp"
#undef CALL_FROM_TEST

using mint = ModInt<998244353>;
using pmm = std::pair<mint, mint>;
signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<mint> a(n);
    REP(i, n) std::cin >> a[i];
    auto seg = make_lazy_segment_tree<mint, pmm>(
        std::plus<mint>(), 0,
        [](pmm x, pmm y) -> pmm {
            return {x.first * y.first, x.second * y.first + y.second};
        },
        {1, 0}, [](mint x, pmm y) { return y.first * x + y.second; },
        [](pmm x, int len) -> pmm {
            return {x.first, x.second * len};
        });
    seg.set_by_vector(a);
    REP(q, Q) {
        Int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 0) {
            Int b, c;
            std::cin >> b >> c;
            seg.update(l, r, {b, c});
        } else {
            std::cout << seg.query(l, r) << "\n";
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_affine_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Mon Mar 30 21:14:19 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Math/ModInt.hpp"
template <class T> T pow(T x, long long n, const T UNION = 1) {
    T ret = UNION;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

/// @docs src/Math/ModInt.md
template <int Mod> struct ModInt {
    int x;
    static int& runtime_mod() {
        static int runtime_mod_;
        return runtime_mod_;
    }
    // テンプレート引数が負のときは実行時ModInt
    static constexpr int mod() { return Mod < 0 ? runtime_mod() : Mod; }
    static std::unordered_map<int, int>& to_inv() {
        static std::unordered_map<int, int> to_inv_;
        return to_inv_;
    }
    static void set_runtime_mod(int mod) {
        static_assert(Mod < 0, "template parameter Mod must be negative for runtime ModInt");
        runtime_mod() = mod, to_inv().clear();
    }
    ModInt() : x(0) {}
    ModInt(long long x_) {
        if ((x = x_ % mod() + mod()) >= mod()) x -= mod();
    }

    ModInt& operator+=(ModInt rhs) {
        if ((x += rhs.x) >= mod()) x -= mod();
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (unsigned long long)x * rhs.x % mod();
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        if ((x -= rhs.x) < 0) x += mod();
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        ModInt inv = to_inv().count(rhs.x) ? to_inv()[rhs.x] : (to_inv()[rhs.x] = pow(rhs, mod() - 2).x);
        return *this *= inv;
    }
    ModInt operator-() const { return -x < 0 ? mod() - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }

    friend std::ostream& operator<<(std::ostream& s, ModInt<Mod> a) { return s << a.x; }
    friend std::istream& operator>>(std::istream& s, ModInt<Mod>& a) {
        long long tmp;
        s >> tmp;
        a = ModInt<Mod>(tmp);
        return s;
    }
    friend std::string to_string(ModInt<Mod> a) { return std::to_string(a.x); }
};

#ifndef CALL_FROM_TEST
using mint = ModInt<1000000007>;
#endif
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
#line 20 "test/yosupo/range_affine_range_sum.test.cpp"
#undef CALL_FROM_TEST

using mint = ModInt<998244353>;
using pmm = std::pair<mint, mint>;
signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<mint> a(n);
    REP(i, n) std::cin >> a[i];
    auto seg = make_lazy_segment_tree<mint, pmm>(
        std::plus<mint>(), 0,
        [](pmm x, pmm y) -> pmm {
            return {x.first * y.first, x.second * y.first + y.second};
        },
        {1, 0}, [](mint x, pmm y) { return y.first * x + y.second; },
        [](pmm x, int len) -> pmm {
            return {x.first, x.second * len};
        });
    seg.set_by_vector(a);
    REP(q, Q) {
        Int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 0) {
            Int b, c;
            std::cin >> b >> c;
            seg.update(l, r, {b, c});
        } else {
            std::cout << seg.query(l, r) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

