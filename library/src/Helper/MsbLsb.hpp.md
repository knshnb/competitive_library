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


# :warning: src/Helper/MsbLsb.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1b49b634354b8edb1dc8ef8a73014950">src/Helper</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Helper/MsbLsb.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int get_msb(long long x) {
    assert(x != 0);
    return 63 - __builtin_clzll(x);
}
int get_lsb(long long x) {
    assert(x != 0);
    return __builtin_ctzll(x);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Helper/MsbLsb.hpp"
int get_msb(long long x) {
    assert(x != 0);
    return 63 - __builtin_clzll(x);
}
int get_lsb(long long x) {
    assert(x != 0);
    return __builtin_ctzll(x);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

