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


# :warning: src/DataStructure/Imos2D.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/Imos2D.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 02:16:10+09:00




## 概要
H*Wの二次元データで長方形部分に区間加算するクエリをimos法によって行う。
各クエリO(1)、構築にO(HW)。

imos法: https://imoz.jp/algorithms/imos_method.html
<br/>
多次元の累積和についてはこれがわかりやすい: https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/DataStructure/Imos2D.md
// 0-indexed
// t.add(i0, j0, i1, j1) -> t.run() -> t[i][j]
template <class T> struct Imos2D {
    int n, m;
    std::vector<std::vector<T>> t;  // 0-indexed!!, -x分のために配列の外側を1大きめに
    Imos2D(int n_, int m_) : n(n_), m(m_), t(n_ + 1, std::vector<T>(m_ + 1)) {}
    // i0 <= i < i1, j0 < j < j1の範囲に+x
    void add(int i0, int j0, int i1, int j1, T x) {
        t[i0][j0] += x, t[i1][j1] += x;
        t[i1][j0] -= x, t[i0][j1] -= x;
    }
    // 2方向に累積和をとる
    void build() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) t[i + 1][j] += t[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) t[i][j + 1] += t[i][j];
    }
    std::vector<T>& operator[](int i) { return t[i]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/Imos2D.hpp"
/// @docs src/DataStructure/Imos2D.md
// 0-indexed
// t.add(i0, j0, i1, j1) -> t.run() -> t[i][j]
template <class T> struct Imos2D {
    int n, m;
    std::vector<std::vector<T>> t;  // 0-indexed!!, -x分のために配列の外側を1大きめに
    Imos2D(int n_, int m_) : n(n_), m(m_), t(n_ + 1, std::vector<T>(m_ + 1)) {}
    // i0 <= i < i1, j0 < j < j1の範囲に+x
    void add(int i0, int j0, int i1, int j1, T x) {
        t[i0][j0] += x, t[i1][j1] += x;
        t[i1][j0] -= x, t[i0][j1] -= x;
    }
    // 2方向に累積和をとる
    void build() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) t[i + 1][j] += t[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) t[i][j + 1] += t[i][j];
    }
    std::vector<T>& operator[](int i) { return t[i]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

