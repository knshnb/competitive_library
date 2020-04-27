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


# :heavy_check_mark: src/Graph/BellmanFord.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/BellmanFord.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 00:31:20+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

