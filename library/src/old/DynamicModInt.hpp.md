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


# :warning: src/old/DynamicModInt.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/DynamicModInt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 18:01:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> T pow(T x, int n, const T UNION = 1) {
    T ret = UNION;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

// ModInt::set_mod(m)してから使う
struct ModInt {
    static int MD;
    static map<pair<int, int>, int> tbl_pow;
    static void set_mod(int mod) {
        MD = mod;
        tbl_pow.clear();
    }
    int x;
    ModInt() : x(0) {}
    ModInt(int x_) {
        if ((x = x_ % MD + MD) >= MD) x -= MD;
    }

    ModInt& operator+=(ModInt that) {
        if ((x += that.x) >= MD) x -= MD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        if ((x -= that.x) < 0) x += MD;
        return *this;
    }
    ModInt& operator/=(ModInt that) {
        x = (unsigned long long)x * that.inv().x % MD;
        return *this;
    }

    ModInt operator-() const { return -x < 0 ? MD - x : -x; }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt inv() const { return pow(*this, MD - 2); }
    friend ostream& operator<<(ostream& s, ModInt a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt& a) {
        s >> a.x;
        return s;
    }

    // 計算結果をmapに保存するべき乗
    ModInt save_pow(int n) const {
        if (tbl_pow.count({x, n})) return tbl_pow[{x, n}];
        if (n == 0) return 1;
        if (n % 2) return tbl_pow[{x, n}] = (*this * save_pow(n - 1)).x;
        return tbl_pow[{x, n}] = (save_pow(n / 2) * save_pow(n / 2)).x;
    }
    // 1 + r + r^2 + ... + r^(n-1)
    static ModInt geometric_progression(ModInt r, int n) {
        if (n == 0) return 0;
        if (n % 2) return geometric_progression(r, n - 1) + r.save_pow(n - 1);
        return geometric_progression(r, n / 2) * (r.save_pow(n / 2) + 1);
    }
    // a + r * (a - d) + r^2 * (a - 2d) + ... + r^(n-1) * (a - (n - 1)d)
    static ModInt linear_sum(ModInt r, ModInt a, ModInt d, int n) {
        if (n == 0) return 0;
        if (n % 2) return linear_sum(r, a, d, n - 1) + r.save_pow(n - 1) * (a - d * (n - 1));
        return linear_sum(r, a, d, n / 2) * (r.save_pow(n / 2) + 1) -
               d * (n / 2) * r.save_pow(n / 2) * geometric_progression(r, n / 2);
    }
};
int ModInt::MD = 1000000007;
using mint = ModInt;
map<pair<int, int>, int> mint::tbl_pow;

vector<mint> fact, fact_inv;
void init_factorial(int n) {
    fact = vector<mint>(n + 1, 1);
    fact_inv = vector<mint>(n + 1);
    for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
    fact_inv[n] = mint(1) / fact[n];
    for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
    // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
}
mint comb(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n - r]; }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/DynamicModInt.hpp"
template <class T> T pow(T x, int n, const T UNION = 1) {
    T ret = UNION;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

// ModInt::set_mod(m)してから使う
struct ModInt {
    static int MD;
    static map<pair<int, int>, int> tbl_pow;
    static void set_mod(int mod) {
        MD = mod;
        tbl_pow.clear();
    }
    int x;
    ModInt() : x(0) {}
    ModInt(int x_) {
        if ((x = x_ % MD + MD) >= MD) x -= MD;
    }

    ModInt& operator+=(ModInt that) {
        if ((x += that.x) >= MD) x -= MD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        if ((x -= that.x) < 0) x += MD;
        return *this;
    }
    ModInt& operator/=(ModInt that) {
        x = (unsigned long long)x * that.inv().x % MD;
        return *this;
    }

    ModInt operator-() const { return -x < 0 ? MD - x : -x; }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt inv() const { return pow(*this, MD - 2); }
    friend ostream& operator<<(ostream& s, ModInt a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt& a) {
        s >> a.x;
        return s;
    }

    // 計算結果をmapに保存するべき乗
    ModInt save_pow(int n) const {
        if (tbl_pow.count({x, n})) return tbl_pow[{x, n}];
        if (n == 0) return 1;
        if (n % 2) return tbl_pow[{x, n}] = (*this * save_pow(n - 1)).x;
        return tbl_pow[{x, n}] = (save_pow(n / 2) * save_pow(n / 2)).x;
    }
    // 1 + r + r^2 + ... + r^(n-1)
    static ModInt geometric_progression(ModInt r, int n) {
        if (n == 0) return 0;
        if (n % 2) return geometric_progression(r, n - 1) + r.save_pow(n - 1);
        return geometric_progression(r, n / 2) * (r.save_pow(n / 2) + 1);
    }
    // a + r * (a - d) + r^2 * (a - 2d) + ... + r^(n-1) * (a - (n - 1)d)
    static ModInt linear_sum(ModInt r, ModInt a, ModInt d, int n) {
        if (n == 0) return 0;
        if (n % 2) return linear_sum(r, a, d, n - 1) + r.save_pow(n - 1) * (a - d * (n - 1));
        return linear_sum(r, a, d, n / 2) * (r.save_pow(n / 2) + 1) -
               d * (n / 2) * r.save_pow(n / 2) * geometric_progression(r, n / 2);
    }
};
int ModInt::MD = 1000000007;
using mint = ModInt;
map<pair<int, int>, int> mint::tbl_pow;

vector<mint> fact, fact_inv;
void init_factorial(int n) {
    fact = vector<mint>(n + 1, 1);
    fact_inv = vector<mint>(n + 1);
    for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
    fact_inv[n] = mint(1) / fact[n];
    for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
    // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
}
mint comb(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n - r]; }

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

