struct TreeDoubling {
  struct Edge { int to, color, len; }; // 場合に応じて書き換える、toは必須
  vector<vector<Edge>> g;
  int n, size; // MSB + 1
  int root;
  vector<int> depth;
  vector<vector<int>> parent; // ダミー頂点n(親もn)
  TreeDoubling(int n) : g(n), n(n), depth(n), size(64 - __builtin_clzll(n)) {
    parent.resize(size, vector<int>(n + 1, n));
  }
  void dfs(int v, int prev, int d) {
    depth[v] = d;
    parent[0][v] = prev;
    for (auto& s : g[v]) if (s.to != prev) {
      dfs(s.to, v, d + 1);
    }
  }
  void build(int root_ = 0) {
    root = root_;
    dfs(root, n, 0);
    for (int k = 0; k < size - 1; k++) {
      for (int i = 0; i < n; i++) {
        parent[k + 1][i] = parent[k][parent[k][i]];
      }
    }
  }
  
  // vからd個分親にさかのぼった頂点、rootよりも上はnを返す
  int query(int v, int d) {
    int ret = v;
    for (int j = 0; j < size; j++) {
      if (d >> j & 1) ret = parent[j][ret];
    }
    return ret;
  }
  int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    v = query(v, depth[v] - depth[u]);
    if (u == v) return u;

    for (int j = size - 1; j >= 0; j--) {
      if (parent[j][u] == parent[j][v]) continue;
      u = parent[j][u];
      v = parent[j][v];
    }
    assert(parent[0][u] == parent[0][v]);
    return parent[0][u];
  }
};

