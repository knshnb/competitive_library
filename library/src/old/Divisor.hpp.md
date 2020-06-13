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


# :warning: src/old/Divisor.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/Divisor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 20:39:55+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// ret[x]: xの約数のvector
// 構築: O(nlogn)
vector<vector<signed>> divisor(signed n) {
    vector<vector<signed>> ret(n + 1);
    for (signed i = 1; i < n + 1; i++) {
        ret[i].reserve(log(n) + 1);
    }
    for (signed i = 1; i < n + 1; i++) {
        for (signed j = i; j < n + 1; j += i) {
            ret[j].push_back(i);
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/Divisor.hpp"
// ret[x]: xの約数のvector
// 構築: O(nlogn)
vector<vector<signed>> divisor(signed n) {
    vector<vector<signed>> ret(n + 1);
    for (signed i = 1; i < n + 1; i++) {
        ret[i].reserve(log(n) + 1);
    }
    for (signed i = 1; i < n + 1; i++) {
        for (signed j = i; j < n + 1; j += i) {
            ret[j].push_back(i);
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

