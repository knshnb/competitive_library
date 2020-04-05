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


# :heavy_check_mark: src/Math/Eratosthenes.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/Eratosthenes.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 19:54:10+09:00




## 概要
エラトステネスの篩による素数列挙。
計算量は、n以下の素数の逆数和がO(loglog n)であることから、O(n loglog n)である(参考: https://mathtrain.jp/eratosthenes)。

定数倍高速化を頑張るともっとかなり早くなる(参考: https://qiita.com/peria/items/a4ff4ddb3336f7b81d50)


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/enumerate_primes.test.cpp.html">test/yosupo/enumerate_primes.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/Math/Eratosthenes.md
struct Eratosthenes {
    std::vector<bool> is_prime;
    std::vector<int> primes;
    Eratosthenes(int n) {
        is_prime.assign(n, true);
        is_prime[0] = is_prime[1] = false;
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
/// @docs src/Math/Eratosthenes.md
struct Eratosthenes {
    std::vector<bool> is_prime;
    std::vector<int> primes;
    Eratosthenes(int n) {
        is_prime.assign(n, true);
        is_prime[0] = is_prime[1] = false;
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

