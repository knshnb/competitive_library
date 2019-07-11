// 全方位木DP
// ds[v]: vを根としたときのそれぞれの葉までの距離
signed main() {
  struct Edge {
    int to, c;
  };
  int n; cin >> n;
  vector<vector<Edge>> G(n);
  REP (i, n - 1) {
    int s, t, w; cin >> s >> t >> w;
    G[s].push_back({t, w});
    G[t].push_back({s, w});
  }
  VVII ds(n);
  function<int(int, int)> dfs1 = [&](int v, int p) {
    int ma = 0;
    for (Edge e: G[v]) if (e.to != p) {
      int tmp = dfs1(e.to, v) + e.c;
      ds[v].push_back({tmp, e.to});
      ma = max(ma, tmp);
    }
    return ma;
  };
  dfs1(0, -1);

  sort(RALL(ds[0]));
  function<void(int, int)> dfs2 = [&](int v, int p) {
    for (Edge e: G[v]) if (e.to != p) {
      int tmp = (ds[v][0].se != e.to ? ds[v][0].fi
                                     : (ds[v].size() == 1 ? 0 : ds[v][1].fi)) + e.c;
      ds[e.to].push_back({tmp, v});
      sort(RALL(ds[e.to]));
      dfs2(e.to, v);
    }
  };
  dfs2(0, -1);

  int ans = 0;
  REP (i, n) {
    if (ds[i].size() == 0) continue;
    ans = max(ans, ds[i][0].fi);
  }
  cout << ans << endl;
}
