auto dfs = [&](auto f, Int v, Int prv) -> void {
    for (Int s : g[v]) {
        if (s == prv) continue;
        f(f, s, v);
    }
};
dfs(dfs, 0, -1);
