auto dfs = [&](auto dfs, Int v, Int prv) -> void {
    for (Int s : g[v]) {
        if (s == prv) continue;
        dfs(dfs, s, v);
    }
};
dfs(dfs, 0, -1);
