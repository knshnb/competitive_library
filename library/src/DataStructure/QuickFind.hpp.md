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


# :warning: src/DataStructure/QuickFind.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/QuickFind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class QuickFind {
public:
    int N;
    vector<int> i2g;          // 各頂点のグループ
    vector<vector<int>> g2i;  // 各グループの頂点集合
    QuickFind(int n) : N(n) {
        i2g.resize(N);
        g2i = vector<vector<int>>(N, vector<int>(1));
        for (int i = 0; i < N; i++) {
            i2g[i] = i;
            g2i[i][0] = i;
        }
    }
    // iを含むグループとjを含むグループをmerge
    void merge(int i, int j) {
        int gi = i2g[i], gj = i2g[j];
        if (gi == gj) return;
        if (g2i[gi].size() < g2i[j].size()) swap(gi, gj);
        // jをiにmerge
        for (int v : g2i[gj]) i2g[v] = gi;
        g2i[gi].insert(g2i[gi].end(), g2i[gj].begin(), g2i[gj].end());
        g2i[gj].clear();
    }
    bool same(int i, int j) { return i2g[i] == i2g[j]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/QuickFind.hpp"
class QuickFind {
public:
    int N;
    vector<int> i2g;          // 各頂点のグループ
    vector<vector<int>> g2i;  // 各グループの頂点集合
    QuickFind(int n) : N(n) {
        i2g.resize(N);
        g2i = vector<vector<int>>(N, vector<int>(1));
        for (int i = 0; i < N; i++) {
            i2g[i] = i;
            g2i[i][0] = i;
        }
    }
    // iを含むグループとjを含むグループをmerge
    void merge(int i, int j) {
        int gi = i2g[i], gj = i2g[j];
        if (gi == gj) return;
        if (g2i[gi].size() < g2i[j].size()) swap(gi, gj);
        // jをiにmerge
        for (int v : g2i[gj]) i2g[v] = gi;
        g2i[gi].insert(g2i[gi].end(), g2i[gj].begin(), g2i[gj].end());
        g2i[gj].clear();
    }
    bool same(int i, int j) { return i2g[i] == i2g[j]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

