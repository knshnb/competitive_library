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
    - Last commit date: 2020-03-29 17:29:15+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/range_affine_range_sum.test.cpp.html">test/yosupo/range_affine_range_sum.test.cpp</a>


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

template <int MD> struct ModInt {
    int x;
    static std::unordered_map<int, int> to_inv;
    ModInt() : x(0) {}
    ModInt(long long x_) {
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
    ModInt inv() const { return to_inv.count(this->x) ? to_inv[this->x] : (to_inv[this->x] = pow(*this, MD - 2).x); }

    friend std::ostream& operator<<(std::ostream& s, ModInt<MD> a) {
        s << a.x;
        return s;
    }
    friend std::istream& operator>>(std::istream& s, ModInt<MD>& a) {
        long long tmp;
        s >> tmp;
        a = ModInt<MD>(tmp);
        return s;
    }
    friend std::string to_string(ModInt<MD> a) { return std::to_string(a.x); }
};
template <int MD> std::unordered_map<int, int> ModInt<MD>::to_inv;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

template <int MD> struct ModInt {
    int x;
    static std::unordered_map<int, int> to_inv;
    ModInt() : x(0) {}
    ModInt(long long x_) {
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
    ModInt inv() const { return to_inv.count(this->x) ? to_inv[this->x] : (to_inv[this->x] = pow(*this, MD - 2).x); }

    friend std::ostream& operator<<(std::ostream& s, ModInt<MD> a) {
        s << a.x;
        return s;
    }
    friend std::istream& operator>>(std::istream& s, ModInt<MD>& a) {
        long long tmp;
        s >> tmp;
        a = ModInt<MD>(tmp);
        return s;
    }
    friend std::string to_string(ModInt<MD> a) { return std::to_string(a.x); }
};
template <int MD> std::unordered_map<int, int> ModInt<MD>::to_inv;

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

