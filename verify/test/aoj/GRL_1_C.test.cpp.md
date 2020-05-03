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


# :heavy_check_mark: test/aoj/GRL_1_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 20:57:15+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/WarshallFloyd.hpp.html">src/Graph/WarshallFloyd.hpp</a>
* :heavy_check_mark: <a href="../../../library/src/Helper/MakeVec.hpp.html">src/Helper/MakeVec.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"

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
 *    created: Sun May  3 17:28:08 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Helper/MakeVec.hpp"
#include "../../src/Graph/WarshallFloyd.hpp"
#undef CALL_FROM_TEST

const Int INF = 1e18;
signed main() {
    Int n, m;
    std::cin >> n >> m;
    auto adj = make_vec<Int>(n, n, INF);
    REP(i, n) adj[i][i] = 0;
    REP(_, m) {
        Int u, v, d;
        std::cin >> u >> v >> d;
        adj[u][v] = d;
    }
    warshall_floyd(adj, INF);
    REP(i, n) {
        if (adj[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }
    REP(i, n) {
        REP(j, n) {
            if (adj[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << adj[i][j];
            }
            if (j != n - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_C.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"

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
 *    created: Sun May  3 17:28:08 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Helper/MakeVec.hpp"
template <class T, class S> T make_vec(S x) { return x; }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return std::vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}
#line 1 "src/Graph/WarshallFloyd.hpp"
/// @docs src/Graph/WarshallFloyd.md
template <class T> void warshall_floyd(std::vector<std::vector<T>> &d, const T INF) {
    int n = d.size();
    for (int i = 0; i < n; i++) assert(d[i][i] == 0);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
#line 20 "test/aoj/GRL_1_C.test.cpp"
#undef CALL_FROM_TEST

const Int INF = 1e18;
signed main() {
    Int n, m;
    std::cin >> n >> m;
    auto adj = make_vec<Int>(n, n, INF);
    REP(i, n) adj[i][i] = 0;
    REP(_, m) {
        Int u, v, d;
        std::cin >> u >> v >> d;
        adj[u][v] = d;
    }
    warshall_floyd(adj, INF);
    REP(i, n) {
        if (adj[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }
    REP(i, n) {
        REP(j, n) {
            if (adj[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << adj[i][j];
            }
            if (j != n - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

