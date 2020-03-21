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


# :warning: src/Graph/BellmanFord.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/BellmanFord.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-20 20:00:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> struct Edge {
    int from, to;
    T cost;
};
// O(EV)、負のサイクルを通った後に到達できる点についてはdist[v]=INFを返す
template <class T> vector<T> bellman_ford(vector<Edge<T>>& edges, int n, int s) {
    constexpr T INF = 1e18;  // Tの型に応じて書き換える必要あり
    vector<T> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            if (dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }
    for (Edge<T>& e : edges) {
        // sから到達できる負のサイクル検出
        if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to]) {
            dist[e.from] = -INF;
            dist[e.to] = -INF;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            if (dist[e.from] == -INF) dist[e.to] = -INF;
        }
    }
    return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/BellmanFord.cpp"
template <class T> struct Edge {
    int from, to;
    T cost;
};
// O(EV)、負のサイクルを通った後に到達できる点についてはdist[v]=INFを返す
template <class T> vector<T> bellman_ford(vector<Edge<T>>& edges, int n, int s) {
    constexpr T INF = 1e18;  // Tの型に応じて書き換える必要あり
    vector<T> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            if (dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }
    for (Edge<T>& e : edges) {
        // sから到達できる負のサイクル検出
        if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to]) {
            dist[e.from] = -INF;
            dist[e.to] = -INF;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            if (dist[e.from] == -INF) dist[e.to] = -INF;
        }
    }
    return dist;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

