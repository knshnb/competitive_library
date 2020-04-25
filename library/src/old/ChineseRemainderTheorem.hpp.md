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


# :warning: src/old/ChineseRemainderTheorem.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/ChineseRemainderTheorem.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 17:53:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// ax + by = gcd(a, b) を満たす(x, y)
pair<int, int> ext_gcd(int a, int b) {
    if (b == 0) return {1, 0};
    pair<int, int> xy = ext_gcd(b, a % b);  // b(qx + y) + rx = ...
    swap(xy.fi, xy.se);
    xy.se -= (a / b) * xy.fi;
    return xy;
}
const pair<int, int> DUM = {0, -1};
// r = b[i] (mod m[i])
// r: 剰余, M: mod
pair<int, int> chinese_rem(const VI& b, const VI& m) {
    int r = 0, M = 1;
    for (int i = 0; i < b.size(); i++) {
        pair<int, int> xy = ext_gcd(M, m[i]);
        int d = __gcd(M, m[i]);
        if ((b[i] - r) % d != 0) return DUM;
        int tmp = ((b[i] - r) / d) * xy.fi % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    ((r %= M) += M) %= M;
    return {r, M};
}

signed main() {}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/ChineseRemainderTheorem.hpp"
// ax + by = gcd(a, b) を満たす(x, y)
pair<int, int> ext_gcd(int a, int b) {
    if (b == 0) return {1, 0};
    pair<int, int> xy = ext_gcd(b, a % b);  // b(qx + y) + rx = ...
    swap(xy.fi, xy.se);
    xy.se -= (a / b) * xy.fi;
    return xy;
}
const pair<int, int> DUM = {0, -1};
// r = b[i] (mod m[i])
// r: 剰余, M: mod
pair<int, int> chinese_rem(const VI& b, const VI& m) {
    int r = 0, M = 1;
    for (int i = 0; i < b.size(); i++) {
        pair<int, int> xy = ext_gcd(M, m[i]);
        int d = __gcd(M, m[i]);
        if ((b[i] - r) % d != 0) return DUM;
        int tmp = ((b[i] - r) / d) * xy.fi % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    ((r %= M) += M) %= M;
    return {r, M};
}

signed main() {}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

