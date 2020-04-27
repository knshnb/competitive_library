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


# :heavy_check_mark: src/Graph/Dijkstra.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/Dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 03:13:15+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0423.test.cpp.html">test/aoj/0423.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T, bool directed = true> struct Dijkstra {
    struct Edge {
        int to;
        T cost;
    };
    std::vector<std::vector<Edge>> g;
    Dijkstra(int n) : g(n) {}
    void add_edge(int u, int v, T cost) {
        g[u].push_back({v, cost});
        if (!directed) g[v].push_back({u, cost});
    }
    std::vector<T> run(int s) {
        std::vector<T> dist(g.size(), std::numeric_limits<T>::max() / 2);
        // {d, v}
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> q;
        q.push({0, s});
        while (!q.empty()) {
            std::pair<T, int> p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] <= p.first) continue;
            dist[v] = p.first;
            for (const Edge& e : g[v]) {
                if (dist[e.to] <= p.first + e.cost) continue;  // 定数倍枝刈り
                q.emplace(p.first + e.cost, e.to);
            }
        }
        return dist;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/Dijkstra.hpp"
template <class T, bool directed = true> struct Dijkstra {
    struct Edge {
        int to;
        T cost;
    };
    std::vector<std::vector<Edge>> g;
    Dijkstra(int n) : g(n) {}
    void add_edge(int u, int v, T cost) {
        g[u].push_back({v, cost});
        if (!directed) g[v].push_back({u, cost});
    }
    std::vector<T> run(int s) {
        std::vector<T> dist(g.size(), std::numeric_limits<T>::max() / 2);
        // {d, v}
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> q;
        q.push({0, s});
        while (!q.empty()) {
            std::pair<T, int> p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] <= p.first) continue;
            dist[v] = p.first;
            for (const Edge& e : g[v]) {
                if (dist[e.to] <= p.first + e.cost) continue;  // 定数倍枝刈り
                q.emplace(p.first + e.cost, e.to);
            }
        }
        return dist;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

