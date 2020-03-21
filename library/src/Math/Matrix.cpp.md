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


# :warning: src/Math/Matrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/Matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-20 20:00:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> struct Matrix {
    vector<vector<T>> A;
    Matrix() {}
    Matrix(int n) : A(n, vector<T>(n, 0)) {}
    Matrix(const vector<vector<T>> &A) : A(A) {}
    static Matrix I(int n) {
        Matrix mat(n);
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return (mat);
    }
    int height() const { return (A.size()); }
    int width() const { return (A[0].size()); }
    vector<T> &operator[](int k) { return A[k]; }
    const vector<T> &operator[](int k) const { return (A[k]); }
    Matrix &operator+=(const Matrix &B) {
        assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) (*this)[i][j] += B[i][j];
        return (*this);
    }
    Matrix &operator-=(const Matrix &B) {
        assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) (*this)[i][j] -= B[i][j];
        return (*this);
    }
    Matrix &operator*=(const Matrix &B) {
        int n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector<vector<T>> C(n, vector<T>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < p; k++) C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return (*this);
    }
    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }
    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }
    vector<T> operator*(const vector<T> &x) const {
        int n = height(), m = width();
        assert(m == x.size());
        vector<T> ret(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ret[i] += (*this)[i][j] * x[j];
        return ret;
    }
    friend ostream &operator<<(ostream &os, Matrix &p) {
        int n = p.height(), m = p.width();
        for (int i = 0; i < n; i++) {
            os << "[";
            for (int j = 0; j < m; j++) {
                os << p[i][j] << (j + 1 == m ? "]\n" : ",");
            }
        }
        return (os);
    }
    T determinant() {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for (int i = 0; i < width(); i++) {
            int idx = -1;
            for (int j = i; j < width(); j++) {
                if (B[j][i] != 0) idx = j;
            }
            if (idx == -1) return (0);
            if (i != idx) {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < width(); j++) {
                B[i][j] /= vv;
            }
            for (int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for (int k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return (ret);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/Matrix.cpp"
template <class T> struct Matrix {
    vector<vector<T>> A;
    Matrix() {}
    Matrix(int n) : A(n, vector<T>(n, 0)) {}
    Matrix(const vector<vector<T>> &A) : A(A) {}
    static Matrix I(int n) {
        Matrix mat(n);
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return (mat);
    }
    int height() const { return (A.size()); }
    int width() const { return (A[0].size()); }
    vector<T> &operator[](int k) { return A[k]; }
    const vector<T> &operator[](int k) const { return (A[k]); }
    Matrix &operator+=(const Matrix &B) {
        assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) (*this)[i][j] += B[i][j];
        return (*this);
    }
    Matrix &operator-=(const Matrix &B) {
        assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) (*this)[i][j] -= B[i][j];
        return (*this);
    }
    Matrix &operator*=(const Matrix &B) {
        int n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector<vector<T>> C(n, vector<T>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < p; k++) C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return (*this);
    }
    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }
    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }
    vector<T> operator*(const vector<T> &x) const {
        int n = height(), m = width();
        assert(m == x.size());
        vector<T> ret(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ret[i] += (*this)[i][j] * x[j];
        return ret;
    }
    friend ostream &operator<<(ostream &os, Matrix &p) {
        int n = p.height(), m = p.width();
        for (int i = 0; i < n; i++) {
            os << "[";
            for (int j = 0; j < m; j++) {
                os << p[i][j] << (j + 1 == m ? "]\n" : ",");
            }
        }
        return (os);
    }
    T determinant() {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for (int i = 0; i < width(); i++) {
            int idx = -1;
            for (int j = i; j < width(); j++) {
                if (B[j][i] != 0) idx = j;
            }
            if (idx == -1) return (0);
            if (i != idx) {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < width(); j++) {
                B[i][j] /= vv;
            }
            for (int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for (int k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return (ret);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

