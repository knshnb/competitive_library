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


# :heavy_check_mark: src/Math/Combination.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/Combination.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 18:54:36+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_B.test.cpp.html">test/aoj/DPL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_D_runtime.test.cpp.html">test/aoj/DPL_5_D_runtime.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

