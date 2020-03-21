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


# :warning: src/Graph/StronglyConnectedComponent.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/StronglyConnectedComponent.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class DirectedGraph {
    vector<bool> used;
    vector<int> vs;  // dfsでpost-orderの順に頂点を格納
    void dfs(int v) {
        used[v] = true;
        for (int s : edge[v]) {
            if (!used[s]) dfs(s);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        cmp[v] = k;
        for (int s : redge[v]) {
            if (cmp[s] == -1) rdfs(s, k);
        }
    }

public:
    int N;
    vector<vector<int>> edge, redge;
    vector<int> cmp;  // 強連結成分のインデックス(トポロジカル順序)
    DirectedGraph(int n) {
        N = n;
        edge.resize(N);
        redge.resize(N);
    }
    void add_edge(int from, int to) {
        assert(0 <= from && from < N && 0 <= to && to < N);
        edge[from].push_back(to);
        redge[to].push_back(from);
    }
    // cmpに各頂点がトポロジカル順で何番目の強連結成分に入るかを格納し、強連結成分の個数を返す
    // O(E + V)
    int scc() {
        used.assign(N, false);
        vs.clear();
        vs.reserve(N);
        for (int v = 0; v < N; v++) {
            if (!used[v]) dfs(v);
        }
        assert(vs.size() == N);
        // dfsにおけるpost orderの番号が小さい順にrdfs
        // 同じ強連結成分に属するものはredgeを使って到達できる
        int k = 0;
        cmp.assign(N, -1);
        for (int i = N - 1; i >= 0; i--) {
            if (cmp[vs[i]] == -1) rdfs(vs[i], k++);
        }
        return k;
    }
    // 有向グラフの閉路検出、O(E + V)
    bool has_loop() { return scc() < N; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/StronglyConnectedComponent.cpp"
class DirectedGraph {
    vector<bool> used;
    vector<int> vs;  // dfsでpost-orderの順に頂点を格納
    void dfs(int v) {
        used[v] = true;
        for (int s : edge[v]) {
            if (!used[s]) dfs(s);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        cmp[v] = k;
        for (int s : redge[v]) {
            if (cmp[s] == -1) rdfs(s, k);
        }
    }

public:
    int N;
    vector<vector<int>> edge, redge;
    vector<int> cmp;  // 強連結成分のインデックス(トポロジカル順序)
    DirectedGraph(int n) {
        N = n;
        edge.resize(N);
        redge.resize(N);
    }
    void add_edge(int from, int to) {
        assert(0 <= from && from < N && 0 <= to && to < N);
        edge[from].push_back(to);
        redge[to].push_back(from);
    }
    // cmpに各頂点がトポロジカル順で何番目の強連結成分に入るかを格納し、強連結成分の個数を返す
    // O(E + V)
    int scc() {
        used.assign(N, false);
        vs.clear();
        vs.reserve(N);
        for (int v = 0; v < N; v++) {
            if (!used[v]) dfs(v);
        }
        assert(vs.size() == N);
        // dfsにおけるpost orderの番号が小さい順にrdfs
        // 同じ強連結成分に属するものはredgeを使って到達できる
        int k = 0;
        cmp.assign(N, -1);
        for (int i = N - 1; i >= 0; i--) {
            if (cmp[vs[i]] == -1) rdfs(vs[i], k++);
        }
        return k;
    }
    // 有向グラフの閉路検出、O(E + V)
    bool has_loop() { return scc() < N; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

