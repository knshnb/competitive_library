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


# :warning: src/Graph/ErdosGallai.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/ErdosGallai.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Erdos-Gallai theorem: (O(n))
// https://en.wikipedia.org/wiki/Erdős–Gallai_theorem
bool is_graphic(const VI& d) {
    int n = d.size();
    if (accumulate(ALL(d), 0LL) % 2) return false;
    VI acc(n + 1);
    REP(i, n) { acc[i + 1] = acc[i] + d[i]; }
    int l = n - 1;  // d[l] >= i + 1を満たす最大のl
    REP(i, n) {
        int lhs = acc[i + 1];
        while (l >= i + 1 && d[l] < i + 1) l--;
        // [i + 1, l]: i + 1, [l + 1, n - 1]: acc
        int rhs = i * (i + 1) + (i + 1) * (l - i) + (acc[n] - acc[l + 1]);
        if (lhs > rhs) return false;
    }
    return true;
}

signed main() {
    // verify: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/3925879
    int n;
    cin >> n;
    VI d(n);
    REP(i, n) cin >> d[i];

    sort(RALL(d));
    if (is_graphic(d)) {
        cout << "YES" << endl;
    } else {
        d.back() += 1;
        sort(RALL(d));
        if (is_graphic(d)) {
            cout << "NO" << endl;
        } else {
            cout << "ABSOLUTELY NO" << endl;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/ErdosGallai.hpp"
// Erdos-Gallai theorem: (O(n))
// https://en.wikipedia.org/wiki/Erdős–Gallai_theorem
bool is_graphic(const VI& d) {
    int n = d.size();
    if (accumulate(ALL(d), 0LL) % 2) return false;
    VI acc(n + 1);
    REP(i, n) { acc[i + 1] = acc[i] + d[i]; }
    int l = n - 1;  // d[l] >= i + 1を満たす最大のl
    REP(i, n) {
        int lhs = acc[i + 1];
        while (l >= i + 1 && d[l] < i + 1) l--;
        // [i + 1, l]: i + 1, [l + 1, n - 1]: acc
        int rhs = i * (i + 1) + (i + 1) * (l - i) + (acc[n] - acc[l + 1]);
        if (lhs > rhs) return false;
    }
    return true;
}

signed main() {
    // verify: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/3925879
    int n;
    cin >> n;
    VI d(n);
    REP(i, n) cin >> d[i];

    sort(RALL(d));
    if (is_graphic(d)) {
        cout << "YES" << endl;
    } else {
        d.back() += 1;
        sort(RALL(d));
        if (is_graphic(d)) {
            cout << "NO" << endl;
        } else {
            cout << "ABSOLUTELY NO" << endl;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

