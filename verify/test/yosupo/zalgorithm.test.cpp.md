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


# :heavy_check_mark: test/yosupo/zalgorithm.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/zalgorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 02:21:00+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/String/ZAlgorithm.hpp.html">src/String/ZAlgorithm.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

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
 *    created: Mon Apr  6 23:56:02 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/String/ZAlgorithm.hpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    std::vector<int> a = Z_algorithm(s);
    for (int x : a) std::cout << x << " ";
    std::cout << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/zalgorithm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

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
 *    created: Mon Apr  6 23:56:02 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/String/ZAlgorithm.hpp"
/// @docs src/String/ZAlgorithm.md
template <class T> std::vector<int> Z_algorithm(const T& s) {
    std::vector<int> a(s.size());
    for (int i = 1, rm_idx = 0; i < s.size(); i++) {
        if (a[i - rm_idx] < a[rm_idx] - (i - rm_idx)) {
            a[i] = a[i - rm_idx];
        } else {
            a[i] = std::max(0, a[rm_idx] - (i - rm_idx));
            while (i + a[i] < s.size() && s[a[i]] == s[i + a[i]]) a[i]++;
            rm_idx = i;
        }
    }
    a[0] = s.size();
    return a;
}
#line 19 "test/yosupo/zalgorithm.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    std::vector<int> a = Z_algorithm(s);
    for (int x : a) std::cout << x << " ";
    std::cout << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

