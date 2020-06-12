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


# :heavy_check_mark: test/yosupo/unionfind_dynamic.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/unionfind_dynamic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 19:44:07+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/DynamicUnionFind.hpp.html">src/DataStructure/DynamicUnionFind.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

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
 *    created: Sun Mar 29 05:04:23 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/DynamicUnionFind.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    DynamicUnionFind uf;
    REP(q, Q) {
        Int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            std::cout << uf.is_same(u, v) << "\n";
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/unionfind_dynamic.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

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
 *    created: Sun Mar 29 05:04:23 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/DataStructure/DynamicUnionFind.hpp"
struct DynamicUnionFind {
    int cnt = 0;
    std::unordered_map<int, int> number;

    int root(int x) {
        if (!number.count(x)) number[x] = -1, cnt++;
        return number[x] < 0 ? x : number[x] = root(number[x]);
    }
    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (number[y] < number[x]) std::swap(x, y);
        // yをxにマージ
        number[x] += number[y];
        number[y] = x;
        cnt--;
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
};
#line 19 "test/yosupo/unionfind_dynamic.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    DynamicUnionFind uf;
    REP(q, Q) {
        Int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            std::cout << uf.is_same(u, v) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

