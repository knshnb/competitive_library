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


# :warning: src/Graph/AbstractDijkstra.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/AbstractDijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> struct Graph {
    struct Edge {
        int to;
        T cost;
    };
    vector<vector<Edge>> g;
    int n;
    bool is_directed;
    Graph(int n_, bool is_directed_ = true) : g(n_), n(n_), is_directed(is_directed_) {}
    void add_edge(int u, int v, T cost) {
        g[u].emplace_back(v, cost);
        if (!is_directed) g[v].emplace_back(u, cost);
    }
    vector<T> dijkstra(int s) {
        // constexpr T INF = numeric_limits<T>::max() / 10;
        // constexpr T ZERO = 0;
        constexpr T INF = {1e18, 1e18};
        constexpr T ZERO = {0, 0};
        // 上2つは型によって書き換える必要あり
        vector<T> d(n, INF);
        d[0] = ZERO;
        using T_i = pair<T, int>;  // {dist, v}
        priority_queue<T_i, vector<T_i>, greater<T_i>> q;
        q.push({d[0], s});
        while (!q.empty()) {
            T_i p = q.top();
            q.pop();
            int v = p.second;
            if (d[v] < p.first) continue;  // 定数倍枝刈り
            for (Edge e : g[v]) {
                T nxt = d[v] + e.cost;
                if (d[e.to] <= nxt) continue;
                d[e.to] = nxt;
                q.emplace(nxt, e.to);
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
#line 1 "src/Graph/AbstractDijkstra.hpp"
template <class T> struct Graph {
    struct Edge {
        int to;
        T cost;
    };
    vector<vector<Edge>> g;
    int n;
    bool is_directed;
    Graph(int n_, bool is_directed_ = true) : g(n_), n(n_), is_directed(is_directed_) {}
    void add_edge(int u, int v, T cost) {
        g[u].emplace_back(v, cost);
        if (!is_directed) g[v].emplace_back(u, cost);
    }
    vector<T> dijkstra(int s) {
        // constexpr T INF = numeric_limits<T>::max() / 10;
        // constexpr T ZERO = 0;
        constexpr T INF = {1e18, 1e18};
        constexpr T ZERO = {0, 0};
        // 上2つは型によって書き換える必要あり
        vector<T> d(n, INF);
        d[0] = ZERO;
        using T_i = pair<T, int>;  // {dist, v}
        priority_queue<T_i, vector<T_i>, greater<T_i>> q;
        q.push({d[0], s});
        while (!q.empty()) {
            T_i p = q.top();
            q.pop();
            int v = p.second;
            if (d[v] < p.first) continue;  // 定数倍枝刈り
            for (Edge e : g[v]) {
                T nxt = d[v] + e.cost;
                if (d[e.to] <= nxt) continue;
                d[e.to] = nxt;
                q.emplace(nxt, e.to);
            }
        }
        return d;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

