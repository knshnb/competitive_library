auto dfs = [&](auto&& self, int v, int prv) -> void {
    for (int s : g[v]) {
        if (s == prv) continue;
        self(self, s, v);
    }
};
dfs(dfs, 0, -1);
