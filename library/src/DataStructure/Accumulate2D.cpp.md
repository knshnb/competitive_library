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


# :warning: src/DataStructure/Accumulate2D.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/Accumulate2D.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-26 00:05:16+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// インターフェイスは0-indexed
// update(i, j, x) -> run() -> query(i0, j0, i1, j1)
template <class T> struct Accumulate2D {
    int n, m;
    vector<vector<T>> t;  // 1-indexed!!
    Accumulate2D(int n_, int m_) : n(n_), m(m_), t(n_ + 1, vector<T>(m_ + 1)) {}
    void update(int i, int j, T x) { t[i + 1][j + 1] = x; }
    // 累積和を取る
    void run() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i + 1][j + 1] += t[i][j + 1] + t[i + 1][j] - t[i][j];
            }
        }
    }
    // i0 <= i < i1, j0 < j < j1の範囲のsum
    T query(int i0, int j0, int i1, int j1) { return t[i1][j1] - t[i1][j0] - t[i0][j1] + t[i0][j0]; }
    // もともとの値
    T query(int i, int j) { return query(i, j, i + 1, j + 1); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/Accumulate2D.cpp"
// インターフェイスは0-indexed
// update(i, j, x) -> run() -> query(i0, j0, i1, j1)
template <class T> struct Accumulate2D {
    int n, m;
    vector<vector<T>> t;  // 1-indexed!!
    Accumulate2D(int n_, int m_) : n(n_), m(m_), t(n_ + 1, vector<T>(m_ + 1)) {}
    void update(int i, int j, T x) { t[i + 1][j + 1] = x; }
    // 累積和を取る
    void run() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i + 1][j + 1] += t[i][j + 1] + t[i + 1][j] - t[i][j];
            }
        }
    }
    // i0 <= i < i1, j0 < j < j1の範囲のsum
    T query(int i0, int j0, int i1, int j1) { return t[i1][j1] - t[i1][j0] - t[i0][j1] + t[i0][j0]; }
    // もともとの値
    T query(int i, int j) { return query(i, j, i + 1, j + 1); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

