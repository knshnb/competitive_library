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


# :warning: src/DataStructure/UnionFindWithWeight.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/UnionFindWithWeight.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
    vector<int> par, rank, diff_weight;
    UnionFind(int n) {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        rank = vector<int>(n, 0);
        diff_weight = vector<int>(n, 0);
    }
    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = root(par[x]);
        }
    }
    bool unite(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            diff_weight[x] -= w;
            par[x] = y;
        } else {
            diff_weight[y] += w;
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int weight(int x) {
        root(x);
        return diff_weight[x];
    }
    int diff(int x, int y) {
        assert(same(x, y));
        return weight(y) - weight(x);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/UnionFindWithWeight.hpp"
struct UnionFind {
    vector<int> par, rank, diff_weight;
    UnionFind(int n) {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        rank = vector<int>(n, 0);
        diff_weight = vector<int>(n, 0);
    }
    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = root(par[x]);
        }
    }
    bool unite(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            diff_weight[x] -= w;
            par[x] = y;
        } else {
            diff_weight[y] += w;
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int weight(int x) {
        root(x);
        return diff_weight[x];
    }
    int diff(int x, int y) {
        assert(same(x, y));
        return weight(y) - weight(x);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

