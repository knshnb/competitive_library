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


# :warning: src/Flow/Dinic.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#29f578163eb30c67e395a84ad90553a2">src/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Flow/Dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Dinic法 O(E * V^2)
class Graph {
    int t;  // ゴール
    vector<int> level, iter;
    void bfs(int s) {
        for (int i = 0; i < level.size(); i++) level[i] = -1;
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    int dfs(int v, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    int V;
    struct edge {
        int to, cap, rev;
    };
    vector<vector<edge>> G;
    Graph(int V) : V(V), G(V), level(V), iter(V) {}

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge{to, cap, (int)G[to].size()});
        G[to].push_back(edge{from, 0, (int)G[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        this->t = t;
        while (1) {
            bfs(s);
            if (level[t] < 0) return flow;
            for (int i = 0; i < iter.size(); i++) iter[i] = 0;
            int f;
            while ((f = dfs(s, (1LL << 60))) > 0) {
                flow += f;
            }
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Flow/Dinic.hpp"
// Dinic法 O(E * V^2)
class Graph {
    int t;  // ゴール
    vector<int> level, iter;
    void bfs(int s) {
        for (int i = 0; i < level.size(); i++) level[i] = -1;
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    int dfs(int v, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    int V;
    struct edge {
        int to, cap, rev;
    };
    vector<vector<edge>> G;
    Graph(int V) : V(V), G(V), level(V), iter(V) {}

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge{to, cap, (int)G[to].size()});
        G[to].push_back(edge{from, 0, (int)G[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        this->t = t;
        while (1) {
            bfs(s);
            if (level[t] < 0) return flow;
            for (int i = 0; i < iter.size(); i++) iter[i] = 0;
            int f;
            while ((f = dfs(s, (1LL << 60))) > 0) {
                flow += f;
            }
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

