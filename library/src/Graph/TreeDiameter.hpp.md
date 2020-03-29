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


# :warning: src/Graph/TreeDiameter.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/TreeDiameter.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 木の直径がdiameterに格納される
signed main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int diameter = 0;
    function<int(int, int)> dfs = [&](int v, int p) {
        int ma = 0;
        for (int s : g[v])
            if (s != p) {
                int tmp = dfs(s, v) + 1;
                diameter = max(diameter, ma + tmp);
                ma = max(ma, tmp);
            }
        return ma;
    };
    dfs(0, -1);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/TreeDiameter.hpp"
// 木の直径がdiameterに格納される
signed main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int diameter = 0;
    function<int(int, int)> dfs = [&](int v, int p) {
        int ma = 0;
        for (int s : g[v])
            if (s != p) {
                int tmp = dfs(s, v) + 1;
                diameter = max(diameter, ma + tmp);
                ma = max(ma, tmp);
            }
        return ma;
    };
    dfs(0, -1);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

