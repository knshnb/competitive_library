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


# :heavy_check_mark: test/yosupo/staticrmq_sparse_table.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/staticrmq_sparse_table.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-13 00:16:00+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/SparseTable.hpp.html">src/DataStructure/SparseTable.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Mon Jul 13 00:06:28 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/SparseTable.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    auto st = make_sparse_table<Int>([](Int x, Int y) { return std::min(x, y); }, a);
    REP(q, Q) {
        Int l, r;
        std::cin >> l >> r;
        std::cout << st.query(l, r) << "\n";
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/staticrmq_sparse_table.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Mon Jul 13 00:06:28 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/DataStructure/SparseTable.hpp"
/// @docs src/DataStructure/SparseTable.md
template <class T, class F> struct SparseTable {
    const F op;
    std::vector<std::vector<T>> t;
    SparseTable(F op_, const std::vector<T>& a) : op(op_), t({a}) {
        for (int k = 1; 1 << k < a.size() + 1; k++) {
            t.emplace_back(a.size() - (1 << k) + 1);
            for (int i = 0; i < a.size() - (1 << k) + 1; i++) {
                t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r) const {
        assert(0 <= l && l < r && r <= t[0].size());
        int k = std::__lg(r - l);
        return op(t[k][l], t[k][r - (1 << k)]);
    }
};
template <class T, class F> auto make_sparse_table(F op, const std::vector<T>& a) { return SparseTable<T, F>(op, a); }
#line 19 "test/yosupo/staticrmq_sparse_table.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, Q;
    std::cin >> n >> Q;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    auto st = make_sparse_table<Int>([](Int x, Int y) { return std::min(x, y); }, a);
    REP(q, Q) {
        Int l, r;
        std::cin >> l >> r;
        std::cout << st.query(l, r) << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

