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


# :heavy_check_mark: src/Math/MatrixStatic.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/MatrixStatic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 02:12:27+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1073_matrix_static.test.cpp.html">test/yukicoder/1073_matrix_static.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

