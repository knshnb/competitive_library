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


# :heavy_check_mark: src/Flow/Dinic.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#29f578163eb30c67e395a84ad90553a2">src/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Flow/Dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 21:15:34+09:00




## 概要
グラフの最大フローを求めるアルゴリズム。計算量はO(|E||V|^2)。
実用上はこれよりかなり早く動くことが多い。
<br/>
また、二部グラフの最大マッチングを求めるときはO(E sqrt(V))になる。

## アルゴリズム
最短の増加路にフローを流していく。
<br/>
参考: https://ta1sa.hatenablog.com/entry/2020/04/13/123802

## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/bipartitematching.test.cpp.html">test/yosupo/bipartitematching.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
        auto bfs = [this, &level, &s, &t]() -> bool {
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
        auto bfs = [this, &level, &s, &t]() -> bool {
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

