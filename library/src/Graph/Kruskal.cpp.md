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


# :warning: src/Graph/Kruskal.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/Kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class UnionFind {
public:
    VI par, rank;
    UnionFind(int n) {
        par = VI(n);
        iota(par.begin(), par.end(), 0);
        rank = VI(n, 0);
    }
    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = root(par[x]);
        }
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
    bool same(int x, int y) { return root(x) == root(y); }
};

struct edge {
    int u, v, cost;
};
bool comp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }
int kruskal(int V, vector<edge>& es) {
    sort(es.begin(), es.end(), comp);
    UnionFind uf(V);
    int ans = 0;
    for (edge e : es) {
        if (uf.same(e.u, e.v)) {
            continue;
        }
        uf.unite(e.u, e.v);
        ans += e.cost;
    }
    return ans;
}
signed main() {
    int V, E;
    cin >> V >> E;
    vector<edge> es(E);
    REP(i, E) { cin >> es[i].u >> es[i].v >> es[i].cost; }
    cout << kruskal(V, es) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/Kruskal.cpp"
class UnionFind {
public:
    VI par, rank;
    UnionFind(int n) {
        par = VI(n);
        iota(par.begin(), par.end(), 0);
        rank = VI(n, 0);
    }
    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = root(par[x]);
        }
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
    bool same(int x, int y) { return root(x) == root(y); }
};

struct edge {
    int u, v, cost;
};
bool comp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }
int kruskal(int V, vector<edge>& es) {
    sort(es.begin(), es.end(), comp);
    UnionFind uf(V);
    int ans = 0;
    for (edge e : es) {
        if (uf.same(e.u, e.v)) {
            continue;
        }
        uf.unite(e.u, e.v);
        ans += e.cost;
    }
    return ans;
}
signed main() {
    int V, E;
    cin >> V >> E;
    vector<edge> es(E);
    REP(i, E) { cin >> es[i].u >> es[i].v >> es[i].cost; }
    cout << kruskal(V, es) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

