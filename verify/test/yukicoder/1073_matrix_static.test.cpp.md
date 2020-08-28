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


# :heavy_check_mark: test/yukicoder/1073_matrix_static.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#de60e5ba474ac43bf7562c10f5977e2d">test/yukicoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/1073_matrix_static.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-29 03:59:22+09:00


* see: <a href="https://yukicoder.me/problems/no/1073">https://yukicoder.me/problems/no/1073</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Math/MatrixStatic.hpp.html">src/Math/MatrixStatic.hpp</a>
* :heavy_check_mark: <a href="../../../library/src/Math/ModInt.hpp.html">src/Math/ModInt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1073"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Jun  6 01:52:00 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/MatrixStatic.hpp"
#include "../../src/Math/ModInt.hpp"
#undef CALL_FROM_TEST
using mint = ModInt<1000000007>;

signed main() {
    Int n;
    std::cin >> n;
    std::array<mint, 6> x{};
    x[0] = 1;
    Matrix<mint, 6> A{};
    REP(j, 6) A[0][j] = mint(1) / 6;
    REP(i, 1, 6) A[i][i - 1] = 1;
    auto ret = pow(A, n, Matrix<mint, 6>::eye()) * x;
    std::cout << ret[0] << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/1073_matrix_static.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1073"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Jun  6 01:52:00 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Math/MatrixStatic.hpp"
template <class T, int size> struct Matrix {
    std::array<std::array<T, size>, size> A;
    Matrix() {}
    Matrix(const std::array<std::array<T, size>, size> &A_) : A(A_) {}
    static Matrix eye() {
        Matrix mat{};
        for (int i = 0; i < size; i++) mat[i][i] = 1;
        return mat;
    }
    std::array<T, size> &operator[](int k) { return A[k]; }
    const std::array<T, size> &operator[](int k) const { return (A[k]); }
    Matrix &operator+=(const Matrix &B) {
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) A[i][j] += B[i][j];
        return *this;
    }
    Matrix &operator-=(const Matrix &B) {
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) A[i][j] -= B[i][j];
        return *this;
    }
    Matrix &operator*=(const Matrix &B) {
        std::array<std::array<T, size>, size> C{};
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++) C[i][j] += A[i][k] * B[k][j];
        std::swap(A, C);
        return *this;
    }
    Matrix operator+(const Matrix &B) const { return Matrix(*this) += B; }
    Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B; }
    Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }
    std::array<T, size> operator*(const std::array<T, size> &x) const {
        std::array<T, size> ret{};
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) ret[i] += A[i][j] * x[j];
        return ret;
    }
};
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
    // テンプレート引数が負のときは実行時ModInt
    static int mod() { return Mod < 0 ? runtime_mod : Mod; }
    static std::unordered_map<int, int>& to_inv() {
        static std::unordered_map<int, int> to_inv_;
        return to_inv_;
    }
    static void set_runtime_mod(int mod) {
        static_assert(Mod < 0, "template parameter Mod must be negative for runtime ModInt");
        runtime_mod = mod;
        to_inv().clear();
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
template <int Mod> int ModInt<Mod>::runtime_mod;

#ifndef CALL_FROM_TEST
using mint = ModInt<1000000007>;
#endif
#line 20 "test/yukicoder/1073_matrix_static.test.cpp"
#undef CALL_FROM_TEST
using mint = ModInt<1000000007>;

signed main() {
    Int n;
    std::cin >> n;
    std::array<mint, 6> x{};
    x[0] = 1;
    Matrix<mint, 6> A{};
    REP(j, 6) A[0][j] = mint(1) / 6;
    REP(i, 1, 6) A[i][i - 1] = 1;
    auto ret = pow(A, n, Matrix<mint, 6>::eye()) * x;
    std::cout << ret[0] << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

