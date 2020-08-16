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


# :heavy_check_mark: src/Graph/AbstractDijkstra.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/AbstractDijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-16 16:02:11+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_A_abstract.test.cpp.html">test/aoj/GRL_1_A_abstract.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class Dist, class Key, class Delta>  // Delta: Key, (Key, Dist -> void) -> void
std::map<Key, Dist> dijkstra(Key s, Delta delta) {
    std::map<Key, Dist> dist;
    using P = std::pair<Dist, Key>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/AbstractDijkstra.hpp"
template <class Dist, class Key, class Delta>  // Delta: Key, (Key, Dist -> void) -> void
std::map<Key, Dist> dijkstra(Key s, Delta delta) {
    std::map<Key, Dist> dist;
    using P = std::pair<Dist, Key>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

