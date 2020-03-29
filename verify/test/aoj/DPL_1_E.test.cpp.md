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


# :heavy_check_mark: test/aoj/DPL_1_E.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_E.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:50:34+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Helper/ChminChmax.hpp.html">src/Helper/ChminChmax.hpp</a>
* :heavy_check_mark: <a href="../../../library/src/Helper/MakeVec.hpp.html">src/Helper/MakeVec.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Thu Mar 26 18:48:49 JST 2020
 **/

#include "../../src/Helper/ChminChmax.hpp"
#include "../../src/Helper/MakeVec.hpp"

signed main() {
    std::string s, t;
    std::cin >> s >> t;
    Int n = s.size(), m = t.size();
    auto dp = make_vec<Int>(n + 1, m + 1, 1e9);
    dp[0][0] = 0;
    REP(i, n + 1) {
        REP(j, m + 1) {
            if (i - 1 >= 0) chmin(dp[i][j], dp[i - 1][j] + 1);
            if (j - 1 >= 0) chmin(dp[i][j], dp[i][j - 1] + 1);
            if (i - 1 >= 0 && j - 1 >= 0) chmin(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
        }
    }
    std::cout << dp[n][m] << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_E.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Thu Mar 26 18:48:49 JST 2020
 **/

#line 1 "src/Helper/ChminChmax.hpp"
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
#line 1 "src/Helper/MakeVec.hpp"
template <class T, class S> T make_vec(S x) { return x; }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return std::vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}
#line 19 "test/aoj/DPL_1_E.test.cpp"

signed main() {
    std::string s, t;
    std::cin >> s >> t;
    Int n = s.size(), m = t.size();
    auto dp = make_vec<Int>(n + 1, m + 1, 1e9);
    dp[0][0] = 0;
    REP(i, n + 1) {
        REP(j, m + 1) {
            if (i - 1 >= 0) chmin(dp[i][j], dp[i - 1][j] + 1);
            if (j - 1 >= 0) chmin(dp[i][j], dp[i][j - 1] + 1);
            if (i - 1 >= 0 && j - 1 >= 0) chmin(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
        }
    }
    std::cout << dp[n][m] << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

