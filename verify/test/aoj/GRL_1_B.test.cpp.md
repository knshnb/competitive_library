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


# :heavy_check_mark: test/aoj/GRL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 00:31:20+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/BellmanFord.hpp.html">src/Graph/BellmanFord.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

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
 *    created: Tue Apr 28 00:15:10 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/BellmanFord.hpp"
#undef CALL_FROM_TEST

signed main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    BellmanFord<Int> bf(n);
    REP(_, m) {
        Int u, v, c;
        std::cin >> u >> v >> c;
        bf.add_edge(u, v, c);
    }
    auto dist = bf.run(s);
    if (std::find(dist.begin(), dist.end(), -bf.INF) != dist.end()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
        for (Int d : dist) {
            if (d == bf.INF) {
                std::cout << "INF" << "\n";
            } else {
                std::cout << d << "\n";
            }
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

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
 *    created: Tue Apr 28 00:15:10 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Graph/BellmanFord.hpp"
// O(EV)、負のサイクルを通った後に到達できる点については-INF, 到達不可能な点についてはINFを返す
template <class T> struct BellmanFord {
    struct Edge {
        int from, to;
        T cost;
    };
    const T INF = std::numeric_limits<T>::max() / 2;
    int n;
    std::vector<Edge> edges;

    BellmanFord(int n_) : n(n_) {}
    void add_edge(int u, int v, T cost) { edges.push_back({u, v, cost}); }
    std::vector<T> run(int s) {
        std::vector<T> dist(n, INF);
        dist[s] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (Edge& e : edges) {
                if (dist[e.from] == INF) continue;
                dist[e.to] = std::min(dist[e.to], dist[e.from] + e.cost);
            }
        }
        for (Edge& e : edges) {
            // sから到達できる負のサイクル検出
            if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to]) {
                dist[e.from] = -INF;
                dist[e.to] = -INF;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (Edge& e : edges) {
                if (dist[e.from] == -INF) dist[e.to] = -INF;
            }
        }
        return dist;
    }
};
#line 19 "test/aoj/GRL_1_B.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    BellmanFord<Int> bf(n);
    REP(_, m) {
        Int u, v, c;
        std::cin >> u >> v >> c;
        bf.add_edge(u, v, c);
    }
    auto dist = bf.run(s);
    if (std::find(dist.begin(), dist.end(), -bf.INF) != dist.end()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
        for (Int d : dist) {
            if (d == bf.INF) {
                std::cout << "INF" << "\n";
            } else {
                std::cout << d << "\n";
            }
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

