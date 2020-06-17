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


# :warning: src/Math/PascalTriangle.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/PascalTriangle.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-18 02:53:07+09:00




## 概要
パスカルの三角形によるコンビネーションテーブルの作成。
O(n^2)。
<br/>
素数でないModで逆元計算ができないときや、整数の範囲で階乗がオーバーフローしてしまうときに使える。



## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/Math/PascalTriangle.md
template <class T = long long> struct PascalTriangle {
    std::vector<std::vector<T>> binom;
    PascalTriangle(int n) : binom(n + 1, std::vector<T>(n + 1)) {
        for (int i = 0; i < n + 1; i++) {
            binom[i][0] = 1;
            for (int j = 1; j < i + 1; j++) {
                binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
            }
        }
    }
    // nCr
    T operator()(int n, int r) {
        assert(0 <= n && 0 <= r && r <= n && n <= binom.size());
        return binom[n][r];
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/PascalTriangle.hpp"
/// @docs src/Math/PascalTriangle.md
template <class T = long long> struct PascalTriangle {
    std::vector<std::vector<T>> binom;
    PascalTriangle(int n) : binom(n + 1, std::vector<T>(n + 1)) {
        for (int i = 0; i < n + 1; i++) {
            binom[i][0] = 1;
            for (int j = 1; j < i + 1; j++) {
                binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
            }
        }
    }
    // nCr
    T operator()(int n, int r) {
        assert(0 <= n && 0 <= r && r <= n && n <= binom.size());
        return binom[n][r];
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

