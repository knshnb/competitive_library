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


# :warning: src/Graph/Dijkstra.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/Dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class UndirectedGraph {
    struct Edge {
        int to, cost;
    };

public:
    vector<vector<Edge>> G;
    int V;
    UndirectedGraph(int V) : G(V), V(V) {}
    void add_edge(int u, int v, int cost) {
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }
    vector<int> dijkstra(int s) {
        vector<int> d(V, 1e18);
        d[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;  // {dist, v}
        que.push({0, s});
        while (!que.empty()) {
            pair<int, int> p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;  // 定数倍枝刈り
            for (Edge e : G[v]) {
                int tmp = d[v] + e.cost;
                if (d[e.to] <= tmp) continue;
                d[e.to] = tmp;
                que.push({tmp, e.to});
            }
        }
        return d;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/Dijkstra.hpp"
class UndirectedGraph {
    struct Edge {
        int to, cost;
    };

public:
    vector<vector<Edge>> G;
    int V;
    UndirectedGraph(int V) : G(V), V(V) {}
    void add_edge(int u, int v, int cost) {
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }
    vector<int> dijkstra(int s) {
        vector<int> d(V, 1e18);
        d[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;  // {dist, v}
        que.push({0, s});
        while (!que.empty()) {
            pair<int, int> p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;  // 定数倍枝刈り
            for (Edge e : G[v]) {
                int tmp = d[v] + e.cost;
                if (d[e.to] <= tmp) continue;
                d[e.to] = tmp;
                que.push({tmp, e.to});
            }
        }
        return d;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

