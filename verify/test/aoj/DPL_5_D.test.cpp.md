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


# :heavy_check_mark: test/aoj/DPL_5_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_5_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 17:42:46+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Math/Combination.hpp.html">src/Math/Combination.hpp</a>
* :heavy_check_mark: <a href="../../../library/src/Math/ModInt.hpp.html">src/Math/ModInt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

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
 *    created: Wed Apr  1 18:41:55 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/ModInt.hpp"
#include "../../src/Math/Combination.hpp"
#undef CALL_FROM_TEST

using mint = ModInt<1000000007>;
signed main() {
    Int n, k;
    std::cin >> n >> k;
    Combination<mint> comb(n + k - 1);
    std::cout << comb(n + k - 1, n) << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_5_D.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

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
 *    created: Wed Apr  1 18:41:55 JST 2020
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
        static_assert(Mod < 0);
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
#line 1 "src/Math/Combination.hpp"
template <class T> struct Combination {
    std::vector<T> fact, fact_inv;
    Combination(int n = 1000003) : fact(n + 1, 1), fact_inv(n + 1) {
        for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
        fact_inv[n] = (T)1 / fact[n];
        for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
        // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
    }
    T operator()(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n - r]; }
};
#line 20 "test/aoj/DPL_5_D.test.cpp"
#undef CALL_FROM_TEST

using mint = ModInt<1000000007>;
signed main() {
    Int n, k;
    std::cin >> n >> k;
    Combination<mint> comb(n + k - 1);
    std::cout << comb(n + k - 1, n) << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
