int n = in();
vector<vector<int>> g(n);
for (int i = 0; i < n - 1; i++) {
    int u = in(), v = in();
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
}
