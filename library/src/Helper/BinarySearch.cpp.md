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


# :warning: src/Helper/BinarySearch.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1b49b634354b8edb1dc8ef8a73014950">src/Helper</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Helper/BinarySearch.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 10:21:51-08:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
auto check = [&](Int mid) -> bool {};
Int ok = 0, ng = 1e18;
while (abs(ok - ng) > 1) {
    Int mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Helper/BinarySearch.cpp"
auto check = [&](Int mid) -> bool {};
Int ok = 0, ng = 1e18;
while (abs(ok - ng) > 1) {
    Int mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

