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
