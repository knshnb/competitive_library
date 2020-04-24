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


# :heavy_check_mark: test/yosupo/bipartitematching.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/bipartitematching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 20:42:50+09:00


* see: <a href="https://judge.yosupo.jp/problem/bipartitematching">https://judge.yosupo.jp/problem/bipartitematching</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Flow/Dinic.hpp.html">src/Flow/Dinic.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

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
 *    created: Fri Apr 24 16:25:41 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Flow/Dinic.hpp"
#undef CALL_FROM_TEST

signed main() {
    int L, R, M;
    std::cin >> L >> R >> M;
    Dinic ff(L + R + 2);
    int s = L + R, t = L + R + 1;
    REP(i, L) { ff.add_edge(s, (int)i, 1); }
    REP(i, R) { ff.add_edge((int)L + i, t, 1); }
    REP(_, M) {
        int a, b;
        std::cin >> a >> b;
        ff.add_edge(a, L + b, 1);
    }
    std::cout << ff.max_flow(s, t) << std::endl;
    for (auto& [u, v, f] : ff.construct()) {
        if (u < L && L <= v && v < L + R) {
            std::cout << u << " " << v - L << "\n";
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/bipartitematching.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

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
 *    created: Fri Apr 24 16:25:41 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Flow/Dinic.hpp"
/// @docs src/Flow/Dinic.md
template <class T = long long> struct Dinic {
    struct Edge {
        int to, rev_idx;  // 逆辺はg[to][rev_idx]
        T cap;
        bool is_rev;
    };
    std::vector<std::vector<Edge>> g;
    Dinic(int n) : g(n) {}

    void add_edge(int from, int to, T cap) {
        g[from].push_back({to, (int)g[to].size(), cap, false});
        g[to].push_back({from, (int)g[from].size() - 1, 0, true});
    }
    T max_flow(int s, int t) {
        std::vector<int> level(g.size());
        auto bfs = [this, &level, &s, &t]() {
            std::fill(level.begin(), level.end(), -1);
            std::queue<int> q;
            level[s] = 0, q.push(s);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (Edge& e : g[v]) {
                    if (e.cap == 0 || level[e.to] != -1) continue;
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
            return level[t] != -1;  // 終了していなければtrueを返す
        };
        std::vector<int> iter(g.size());
        auto dfs = [this, &level, &iter, &t](auto f, int v, T min_acc) -> T {
            if (v == t) return min_acc;
            for (int& i = iter[v]; i < g[v].size(); i++) {
                Edge& e = g[v][i];
                if (e.cap == 0 || level[e.to] <= level[v]) continue;
                T dif = f(f, e.to, std::min(min_acc, e.cap));
                if (dif == 0) continue;
                e.cap -= dif, g[e.to][e.rev_idx].cap += dif;
                return dif;
            }
            return 0;
        };

        T flow = 0;
        while (bfs()) {
            std::fill(iter.begin(), iter.end(), 0);
            while (1) {
                T f = dfs(dfs, s, std::numeric_limits<T>::max() / 2);
                if (f == 0) break;
                flow += f;
            }
        }
        return flow;
    }
    // max_flow()の後に呼ぶと、{u, v, 流した流量}のvectorを返す
    std::vector<std::tuple<int, int, T>> construct() {
        std::vector<std::tuple<int, int, T>> ret;
        for (int i = 0; i < g.size(); i++) {
            for (Edge& e : g[i]) {
                if (e.is_rev) continue;
                T f = g[e.to][e.rev_idx].cap;
                if (f == 0) continue;
                ret.push_back({i, e.to, f});
            }
        }
        return ret;
    }
};
#line 19 "test/yosupo/bipartitematching.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    int L, R, M;
    std::cin >> L >> R >> M;
    Dinic ff(L + R + 2);
    int s = L + R, t = L + R + 1;
    REP(i, L) { ff.add_edge(s, (int)i, 1); }
    REP(i, R) { ff.add_edge((int)L + i, t, 1); }
    REP(_, M) {
        int a, b;
        std::cin >> a >> b;
        ff.add_edge(a, L + b, 1);
    }
    std::cout << ff.max_flow(s, t) << std::endl;
    for (auto& [u, v, f] : ff.construct()) {
        if (u < L && L <= v && v < L + R) {
            std::cout << u << " " << v - L << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

