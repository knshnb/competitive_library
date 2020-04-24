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


# :warning: src/Flow/FordFulkerson.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#29f578163eb30c67e395a84ad90553a2">src/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Flow/FordFulkerson.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 20:42:50+09:00





## 概要
グラフの最大フローを求めるアルゴリズム。
最大流の流量をFとして、O(F|E|)。

## アルゴリズム
増加パス(容量以内の正辺と、今までに流した流量を逆に押し戻す逆辺のみからなるパス)を1つ見つけて目一杯流すことを繰り返す。
dfsで増加パスを見つけるのがO(|E|)、これが最大O(F)回行われる可能性がある(実用上はこれよりかなり早く動作することが多い)。

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/Flow/FordFulkerson.md
template <class T = long long> struct FordFulkerson {
    struct Edge {
        int to, rev_idx;  // 逆辺はg[to][rev_idx]
        T cap;
        bool is_rev;
    };
    std::vector<std::vector<Edge>> g;
    FordFulkerson(int n) : g(n) {}

    void add_edge(int from, int to, T cap) {
        g[from].push_back({to, (int)g[to].size(), cap, false});
        g[to].push_back({from, (int)g[from].size() - 1, 0, true});
    }
    T max_flow(int s, int t) {
        std::vector<bool> used(g.size());
        auto dfs = [this, &used, &t](auto f, int v, T min_acc) -> T {
            if (v == t) return min_acc;
            if (used[v]) return 0;
            used[v] = true;
            for (Edge& e : g[v]) {
                if (e.cap == 0) continue;
                T dif = f(f, e.to, std::min(min_acc, e.cap));
                if (dif == 0) continue;
                e.cap -= dif, g[e.to][e.rev_idx].cap += dif;
                return dif;
            }
            return 0;
        };

        T flow = 0;
        while (1) {
            std::fill(used.begin(), used.end(), false);
            T f = dfs(dfs, s, std::numeric_limits<T>::max() / 2);
            if (f == 0) return flow;
            flow += f;
        }
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
#line 1 "src/Flow/FordFulkerson.hpp"
/// @docs src/Flow/FordFulkerson.md
template <class T = long long> struct FordFulkerson {
    struct Edge {
        int to, rev_idx;  // 逆辺はg[to][rev_idx]
        T cap;
        bool is_rev;
    };
    std::vector<std::vector<Edge>> g;
    FordFulkerson(int n) : g(n) {}

    void add_edge(int from, int to, T cap) {
        g[from].push_back({to, (int)g[to].size(), cap, false});
        g[to].push_back({from, (int)g[from].size() - 1, 0, true});
    }
    T max_flow(int s, int t) {
        std::vector<bool> used(g.size());
        auto dfs = [this, &used, &t](auto f, int v, T min_acc) -> T {
            if (v == t) return min_acc;
            if (used[v]) return 0;
            used[v] = true;
            for (Edge& e : g[v]) {
                if (e.cap == 0) continue;
                T dif = f(f, e.to, std::min(min_acc, e.cap));
                if (dif == 0) continue;
                e.cap -= dif, g[e.to][e.rev_idx].cap += dif;
                return dif;
            }
            return 0;
        };

        T flow = 0;
        while (1) {
            std::fill(used.begin(), used.end(), false);
            T f = dfs(dfs, s, std::numeric_limits<T>::max() / 2);
            if (f == 0) return flow;
            flow += f;
        }
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

