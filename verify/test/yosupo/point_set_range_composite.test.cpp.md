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


# :heavy_check_mark: test/yosupo/point_set_range_composite.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_set_range_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-12 16:47:15+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/SegmentTree.hpp.html">src/DataStructure/SegmentTree.hpp</a>
* :question: <a href="../../../library/src/Math/ModInt.hpp.html">src/Math/ModInt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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
 *    created: Sun Mar 29 16:52:02 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/ModInt.hpp"
#include "../../src/DataStructure/SegmentTree.hpp"
#undef CALL_FROM_TEST

using mint = ModInt<998244353>;
using pmm = std::pair<mint, mint>;
signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<pmm> a(n);
    REP(i, n) std::cin >> a[i].first >> a[i].second;
    auto seg = make_segment_tree<pmm>(
        [](pmm x, pmm y) {
            return pmm{x.first * y.first, y.first * x.second + y.second};
        },
        {1, 0});
    seg.set_by_vector(a);
    REP(q, Q) {
        Int c, x, y, z;
        std::cin >> c >> x >> y >> z;
        if (c == 0) {
            seg.update(x, {y, z});
        } else {
            pmm tmp = seg.query(x, y);
            std::cout << tmp.first * z + tmp.second << "\n";
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_set_range_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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
 *    created: Sun Mar 29 16:52:02 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Math/ModInt.hpp"
template <class T> T pow(T x, int n, const T UNION = 1) {
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
    static int runtime_mod;
    static std::unordered_map<int, int> to_inv;
    // テンプレート引数が負のときは実行時ModInt
    static int mod() { return Mod < 0 ? runtime_mod : Mod; }
    static void set_runtime_mod(int mod) {
        static_assert(Mod < 0, "template parameter Mod must be negative for runtime ModInt");
        runtime_mod = mod;
        to_inv.clear();
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
        x = (unsigned long long)x * rhs.inv().x % mod();
        return *this;
    }
    ModInt operator-() const { return -x < 0 ? mod() - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    ModInt inv() const { return to_inv.count(this->x) ? to_inv[this->x] : (to_inv[this->x] = pow(*this, mod() - 2).x); }

    friend std::ostream& operator<<(std::ostream& s, ModInt<Mod> a) {
        s << a.x;
        return s;
    }
    friend std::istream& operator>>(std::istream& s, ModInt<Mod>& a) {
        long long tmp;
        s >> tmp;
        a = ModInt<Mod>(tmp);
        return s;
    }
    friend std::string to_string(ModInt<Mod> a) { return std::to_string(a.x); }
};
template <int Mod> std::unordered_map<int, int> ModInt<Mod>::to_inv;
template <int Mod> int ModInt<Mod>::runtime_mod;

#ifndef CALL_FROM_TEST
using mint = ModInt<1000000007>;
#endif
#line 1 "src/DataStructure/SegmentTree.hpp"
/// @docs src/DataStructure/SegmentTree.md
template <class T, class F> struct SegmentTree {
    const F op;
    const T e;
    SegmentTree(F op_, T e_) : op(op_), e(e_) {}
    int n;
    std::vector<T> t;
    void set_by_identity(int n_) {
        n = n_;
        t.clear(), t.resize(2 * n, e);
    }
    void set_by_vector(const std::vector<T>& a) {
        n = a.size();
        t.clear(), t.resize(2 * n, e);
        for (int i = 0; i < n; i++) t[i + n] = a[i];
        build();
    }
    void build() {
        for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    T& operator[](int i) { return t[i + n]; }
    // [l, r)
    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        T resl = e, resr = e;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = op(resl, t[l++]);
            if (r & 1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
    // i番目をxに変更
    void update(int i, const T& x) {
        assert(0 <= i && i < n);
        t[i += n] = x;
        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    // i番目にxを作用 (a[i] = op(a[i], x))
    void operate(int i, const T& x) {
        assert(0 <= i && i < n);
        i += n;
        t[i] = op(t[i], x);
        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    friend std::string to_string(const SegmentTree<T, F>& seg) {
        return to_string(std::vector<T>(seg.t.begin() + seg.n, seg.t.end()));
    }
};
template <class T, class F> auto make_segment_tree(F op, T e) { return SegmentTree<T, F>(op, e); }
#line 20 "test/yosupo/point_set_range_composite.test.cpp"
#undef CALL_FROM_TEST

using mint = ModInt<998244353>;
using pmm = std::pair<mint, mint>;
signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<pmm> a(n);
    REP(i, n) std::cin >> a[i].first >> a[i].second;
    auto seg = make_segment_tree<pmm>(
        [](pmm x, pmm y) {
            return pmm{x.first * y.first, y.first * x.second + y.second};
        },
        {1, 0});
    seg.set_by_vector(a);
    REP(q, Q) {
        Int c, x, y, z;
        std::cin >> c >> x >> y >> z;
        if (c == 0) {
            seg.update(x, {y, z});
        } else {
            pmm tmp = seg.query(x, y);
            std::cout << tmp.first * z + tmp.second << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

