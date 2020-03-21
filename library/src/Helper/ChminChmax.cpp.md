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


# :warning: src/Helper/ChminChmax.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1b49b634354b8edb1dc8ef8a73014950">src/Helper</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Helper/ChminChmax.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-07 01:53:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> inline bool chmin(T& a, const T& b) {
    if (a <= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmax(T& a, const T& b) {
    if (a >= b) return false;
    a = b;
    return true;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Helper/ChminChmax.cpp"
template <class T> inline bool chmin(T& a, const T& b) {
    if (a <= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmax(T& a, const T& b) {
    if (a >= b) return false;
    a = b;
    return true;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

