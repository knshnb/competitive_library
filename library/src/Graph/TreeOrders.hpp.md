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


# :warning: src/Graph/TreeOrders.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/TreeOrders.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-12 16:30:58+09:00




## 概要
木を受け取り、dfs順を返す。
pre_order: トップダウン。dfsで訪れた順。
post_order: ボトムアップ。木dpとかで使う。


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/Graph/TreeOrders.md
std::vector<int> pre_order(const std::vector<std::vector<int>>& g, int s = 0) {
    std::vector<int> ord;
    ord.reserve(g.size());
    auto dfs = [&g, &ord](auto&& self, int v, int prv) -> void {
        ord.push_back(v);
        for (int s : g[v]) {
            if (s == prv) continue;
            self(self, s, v);
        }
    };
    dfs(dfs, s, -1);
    return ord;
}
std::vector<int> post_order(const std::vector<std::vector<int>>& g, int s = 0) {
    std::vector<int> ord;
    ord.reserve(g.size());
    auto dfs = [&g, &ord](auto&& self, int v, int prv) -> void {
        for (int s : g[v]) {
            if (s == prv) continue;
            self(self, s, v);
        }
        ord.push_back(v);
    };
    dfs(dfs, s, -1);
    return ord;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/TreeOrders.hpp"
/// @docs src/Graph/TreeOrders.md
std::vector<int> pre_order(const std::vector<std::vector<int>>& g, int s = 0) {
    std::vector<int> ord;
    ord.reserve(g.size());
    auto dfs = [&g, &ord](auto&& self, int v, int prv) -> void {
        ord.push_back(v);
        for (int s : g[v]) {
            if (s == prv) continue;
            self(self, s, v);
        }
    };
    dfs(dfs, s, -1);
    return ord;
}
std::vector<int> post_order(const std::vector<std::vector<int>>& g, int s = 0) {
    std::vector<int> ord;
    ord.reserve(g.size());
    auto dfs = [&g, &ord](auto&& self, int v, int prv) -> void {
        for (int s : g[v]) {
            if (s == prv) continue;
            self(self, s, v);
        }
        ord.push_back(v);
    };
    dfs(dfs, s, -1);
    return ord;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

