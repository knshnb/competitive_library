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


# :heavy_check_mark: src/Math/ModInt.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/ModInt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 01:48:24+09:00




## 概要
modにおける四則演算クラス。
テンプレート引数`Mod`が負のとき、modは実行時に指定したものになる。

加算O(1)、減算O(1)、乗算O(1)、除算O(log mod)。
除算はフェルマーの小定理を用いているので、modが素数でないときは使えないことに注意(そもそも逆元が存在しない)。


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_A.test.cpp.html">test/aoj/DPL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_B.test.cpp.html">test/aoj/DPL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_D_runtime.test.cpp.html">test/aoj/DPL_5_D_runtime.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_E.test.cpp.html">test/aoj/DPL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_F.test.cpp.html">test/aoj/DPL_5_F.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/range_affine_range_sum.test.cpp.html">test/yosupo/range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1073.test.cpp.html">test/yukicoder/1073.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1073_matrix_static.test.cpp.html">test/yukicoder/1073_matrix_static.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

