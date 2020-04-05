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


# :heavy_check_mark: test/yosupo/enumerate_primes.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/enumerate_primes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 19:54:10+09:00


* see: <a href="https://judge.yosupo.jp/problem/enumerate_primes">https://judge.yosupo.jp/problem/enumerate_primes</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Math/Eratosthenes.hpp.html">src/Math/Eratosthenes.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Apr  5 19:29:53 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Math/Eratosthenes.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, A, B;
    std::cin >> n >> A >> B;
    Eratosthenes er(n + 1);
    Int num = ((Int)er.primes.size() - B + A - 1) / A;
    std::cout << er.primes.size() << " " << num << std::endl;
    REP(i, num) {
        std::cout << er.primes[A * i + B] << " ";
    }
    std::cout << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/enumerate_primes.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Apr  5 19:29:53 JST 2020
 **/

#define CALL_FROM_TEST
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
#line 19 "test/yosupo/enumerate_primes.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, A, B;
    std::cin >> n >> A >> B;
    Eratosthenes er(n + 1);
    Int num = ((Int)er.primes.size() - B + A - 1) / A;
    std::cout << er.primes.size() << " " << num << std::endl;
    REP(i, num) {
        std::cout << er.primes[A * i + B] << " ";
    }
    std::cout << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

