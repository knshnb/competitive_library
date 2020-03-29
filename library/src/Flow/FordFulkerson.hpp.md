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
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Ford Fulkerson法 O(F * E)
class Graph {
    vector<bool> used;
    int t;  // ゴール
    // f: 流量
    int dfs(int v, int f) {
        if (v == t) return f;
        used[v] = true;
        for (edge& e : G[v]) {
            if (used[e.to] || e.cap <= 0) continue;
            int res = dfs(e.to, min(f, e.cap));
            if (res <= 0) continue;
            e.cap -= res;
            G[e.to][e.rev].cap += res;
            return res;
        }
        return 0;
    }

public:
    int V;
    // G[e.to][e.rev]で逆辺にアクセスできるように
    // 逆辺のcapは、"正辺に流れている流量"(その分だけ逆に戻せるので)(はじめは全て0)
    struct edge {
        int to, cap, rev;
    };
    vector<vector<edge>> G;
    Graph(int V) : V(V), G(V), used(V) {}
    void add_edge(int from, int to, int cap) {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }
    int max_flow(int s, int t) {
        this->t = t;
        int ret = 0;
        while (1) {
            fill(ALL(used), false);
            int f = dfs(s, 1e18);
            if (f == 0) return ret;
            ret += f;
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Flow/FordFulkerson.hpp"
// Ford Fulkerson法 O(F * E)
class Graph {
    vector<bool> used;
    int t;  // ゴール
    // f: 流量
    int dfs(int v, int f) {
        if (v == t) return f;
        used[v] = true;
        for (edge& e : G[v]) {
            if (used[e.to] || e.cap <= 0) continue;
            int res = dfs(e.to, min(f, e.cap));
            if (res <= 0) continue;
            e.cap -= res;
            G[e.to][e.rev].cap += res;
            return res;
        }
        return 0;
    }

public:
    int V;
    // G[e.to][e.rev]で逆辺にアクセスできるように
    // 逆辺のcapは、"正辺に流れている流量"(その分だけ逆に戻せるので)(はじめは全て0)
    struct edge {
        int to, cap, rev;
    };
    vector<vector<edge>> G;
    Graph(int V) : V(V), G(V), used(V) {}
    void add_edge(int from, int to, int cap) {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }
    int max_flow(int s, int t) {
        this->t = t;
        int ret = 0;
        while (1) {
            fill(ALL(used), false);
            int f = dfs(s, 1e18);
            if (f == 0) return ret;
            ret += f;
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

