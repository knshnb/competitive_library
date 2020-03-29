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


# :warning: src/Math/Eratosthenes.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/Eratosthenes.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Eratosthenes {
    vector<bool> is_prime;
    vector<int> primes;
    Eratosthenes(int n) {
        is_prime = vector<bool>(n, true);
        is_prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (!is_prime[i]) continue;
            for (int j = i * 2; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/Eratosthenes.hpp"
struct Eratosthenes {
    vector<bool> is_prime;
    vector<int> primes;
    Eratosthenes(int n) {
        is_prime = vector<bool>(n, true);
        is_prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (!is_prime[i]) continue;
            for (int j = i * 2; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

