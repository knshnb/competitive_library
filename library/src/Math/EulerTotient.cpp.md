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


# :warning: src/Math/EulerTotient.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/EulerTotient.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int euler_totient(int n) {
    vector<int> ps;
    {
        int tmp = n;
        for (int x = 2; x * x <= tmp; x++) {
            if (tmp % x) continue;
            ps.push_back(x);
            while (tmp % x == 0) tmp /= x;
        }
        if (tmp != 1) ps.push_back(tmp);
    }
    int m = ps.size();
    int ans = 0;
    for (int bit = 0; bit < 1LL << m; bit++) {
        int d = 1;
        for (int i = 0; i < m; i++) {
            if (bit >> i & 1) d *= ps[i];
        }
        int sign = __builtin_popcount(bit) % 2 ? -1 : 1;
        ans += sign * (n / d);
    }
    return ans;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/EulerTotient.cpp"
int euler_totient(int n) {
    vector<int> ps;
    {
        int tmp = n;
        for (int x = 2; x * x <= tmp; x++) {
            if (tmp % x) continue;
            ps.push_back(x);
            while (tmp % x == 0) tmp /= x;
        }
        if (tmp != 1) ps.push_back(tmp);
    }
    int m = ps.size();
    int ans = 0;
    for (int bit = 0; bit < 1LL << m; bit++) {
        int d = 1;
        for (int i = 0; i < m; i++) {
            if (bit >> i & 1) d *= ps[i];
        }
        int sign = __builtin_popcount(bit) % 2 ? -1 : 1;
        ans += sign * (n / d);
    }
    return ans;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

