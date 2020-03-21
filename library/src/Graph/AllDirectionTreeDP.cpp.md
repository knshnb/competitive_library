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


# :warning: src/Graph/AllDirectionTreeDP.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/AllDirectionTreeDP.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 全方位木DP
// ds[v]: vを根としたときのそれぞれの葉までの距離
signed main() {
    struct Edge {
        int to, c;
    };
    int n;
    cin >> n;
    vector<vector<Edge>> G(n);
    REP(i, n - 1) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    VVII ds(n);
    function<int(int, int)> dfs1 = [&](int v, int p) {
        int ma = 0;
        for (Edge e : G[v])
            if (e.to != p) {
                int tmp = dfs1(e.to, v) + e.c;
                ds[v].push_back({tmp, e.to});
                ma = max(ma, tmp);
            }
        return ma;
    };
    dfs1(0, -1);

    sort(RALL(ds[0]));
    function<void(int, int)> dfs2 = [&](int v, int p) {
        for (Edge e : G[v])
            if (e.to != p) {
                int tmp = (ds[v][0].se != e.to ? ds[v][0].fi : (ds[v].size() == 1 ? 0 : ds[v][1].fi)) + e.c;
                ds[e.to].push_back({tmp, v});
                sort(RALL(ds[e.to]));
                dfs2(e.to, v);
            }
    };
    dfs2(0, -1);

    int ans = 0;
    REP(i, n) {
        if (ds[i].size() == 0) continue;
        ans = max(ans, ds[i][0].fi);
    }
    cout << ans << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/AllDirectionTreeDP.cpp"
// 全方位木DP
// ds[v]: vを根としたときのそれぞれの葉までの距離
signed main() {
    struct Edge {
        int to, c;
    };
    int n;
    cin >> n;
    vector<vector<Edge>> G(n);
    REP(i, n - 1) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    VVII ds(n);
    function<int(int, int)> dfs1 = [&](int v, int p) {
        int ma = 0;
        for (Edge e : G[v])
            if (e.to != p) {
                int tmp = dfs1(e.to, v) + e.c;
                ds[v].push_back({tmp, e.to});
                ma = max(ma, tmp);
            }
        return ma;
    };
    dfs1(0, -1);

    sort(RALL(ds[0]));
    function<void(int, int)> dfs2 = [&](int v, int p) {
        for (Edge e : G[v])
            if (e.to != p) {
                int tmp = (ds[v][0].se != e.to ? ds[v][0].fi : (ds[v].size() == 1 ? 0 : ds[v][1].fi)) + e.c;
                ds[e.to].push_back({tmp, v});
                sort(RALL(ds[e.to]));
                dfs2(e.to, v);
            }
    };
    dfs2(0, -1);

    int ans = 0;
    REP(i, n) {
        if (ds[i].size() == 0) continue;
        ans = max(ans, ds[i][0].fi);
    }
    cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

