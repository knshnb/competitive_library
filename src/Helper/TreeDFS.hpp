auto dfs = [&](auto f, int v, int prv) -> void {
    for (int s : g[v]) {
        if (s == prv) continue;
        f(f, s, v);
    }
};
dfs(dfs, 0, -1);
