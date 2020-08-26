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


# :heavy_check_mark: test/aoj/GRL_1_A_abstract.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_A_abstract.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-26 17:58:25+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A">https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/AbstractDijkstra.hpp.html">src/Graph/AbstractDijkstra.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Aug 16 15:46:30 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/AbstractDijkstra.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m, r;
    std::cin >> n >> m >> r;
    struct Edge {
        Int to, cost;
    };
    std::vector<std::vector<Edge>> g(n);
    REP(i, m) {
        Int s, t, d;
        std::cin >> s >> t >> d;
        g[s].push_back({t, d});
    }
    auto delta = [&](Int from, auto update) -> void {
        for (Edge& edge : g[from]) {
            update(edge.to, edge.cost);
        }
    };
    auto dist = dijkstra<Int>(r, delta);
    REP(i, n) {
        if (dist.count(i)) {
            std::cout << dist[i] << "\n";
        } else {
            std::cout << "INF\n";
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_A_abstract.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Aug 16 15:46:30 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Graph/AbstractDijkstra.hpp"
/// @docs src/Graph/AbstractDijkstra.md
template <class Dist, class Key, class Delta>  // Delta: Key from, (Key to, Dist d -> void) update -> void
std::map<Key, Dist> dijkstra(Key s, Delta delta) {
    std::map<Key, Dist> dist;
    using P = std::pair<Dist, Key>;
    auto cmp_first = [](const P& a, const P& b) { return a.first > b.first; };
    std::priority_queue<P, std::vector<P>, decltype(cmp_first)> q{cmp_first};
    q.push({dist[s] = Dist(), s});
    while (!q.empty()) {
        std::pair<Dist, Key> p = q.top();
        q.pop();
        if (dist[p.second] < p.first) continue;
        delta(p.second, [&](Key to, Dist d) -> void {
            if (dist.count(to) && dist[to] <= p.first + d) return;
            q.push({dist[to] = p.first + d, to});
        });
    }
    return dist;
}
#line 20 "test/aoj/GRL_1_A_abstract.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m, r;
    std::cin >> n >> m >> r;
    struct Edge {
        Int to, cost;
    };
    std::vector<std::vector<Edge>> g(n);
    REP(i, m) {
        Int s, t, d;
        std::cin >> s >> t >> d;
        g[s].push_back({t, d});
    }
    auto delta = [&](Int from, auto update) -> void {
        for (Edge& edge : g[from]) {
            update(edge.to, edge.cost);
        }
    };
    auto dist = dijkstra<Int>(r, delta);
    REP(i, n) {
        if (dist.count(i)) {
            std::cout << dist[i] << "\n";
        } else {
            std::cout << "INF\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

