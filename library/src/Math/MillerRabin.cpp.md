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


# :warning: src/Math/MillerRabin.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/MillerRabin.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
random_device rnd;
mt19937 mt(rnd());
mt19937_64 mt64(rnd());
int mod_pow(int x, int n, int mod) {
    if (n <= 0) return 1;
    int tmp = mod_pow(x, n / 2, mod);
    return tmp * tmp % mod * (n % 2 ? x : 1) % mod;
}
int mod_inv(int x, int mod) { return mod_pow(x, mod - 2, mod); }
// Miller-Rabin
bool is_prime(int n, int times = 50) {
    if (n == 2) return true;
    if (n % 2 == 0 || n < 2) return false;
    int d = n - 1;
    while (d % 2 == 0) d /= 2;
    while (times--) {
        int a = rnd() % (n - 2) + 1;
        int t = d;
        int y = mod_pow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t *= 2;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
int gen_prime() {
    int cnt = 0;
    while (1) {
        int n = mt();
        n != 1;
        if (is_prime(n)) return n;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/MillerRabin.cpp"
random_device rnd;
mt19937 mt(rnd());
mt19937_64 mt64(rnd());
int mod_pow(int x, int n, int mod) {
    if (n <= 0) return 1;
    int tmp = mod_pow(x, n / 2, mod);
    return tmp * tmp % mod * (n % 2 ? x : 1) % mod;
}
int mod_inv(int x, int mod) { return mod_pow(x, mod - 2, mod); }
// Miller-Rabin
bool is_prime(int n, int times = 50) {
    if (n == 2) return true;
    if (n % 2 == 0 || n < 2) return false;
    int d = n - 1;
    while (d % 2 == 0) d /= 2;
    while (times--) {
        int a = rnd() % (n - 2) + 1;
        int t = d;
        int y = mod_pow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t *= 2;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
int gen_prime() {
    int cnt = 0;
    while (1) {
        int n = mt();
        n != 1;
        if (is_prime(n)) return n;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

