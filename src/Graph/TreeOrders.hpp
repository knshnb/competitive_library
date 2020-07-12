/// @docs src/Graph/TreeOrders.md
std::vector<int> pre_order(const std::vector<std::vector<int>>& g, int s = 0) {
    std::vector<int> ord;
    ord.reserve(g.size());
    auto dfs = [&g, &ord](auto&& self, int v, int prv) -> void {
        ord.push_back(v);
        for (int s : g[v]) {
            if (s == prv) continue;
            self(self, s, v);
        }
    };
    dfs(dfs, s, -1);
    return ord;
}
std::vector<int> post_order(const std::vector<std::vector<int>>& g, int s = 0) {
    std::vector<int> ord;
    ord.reserve(g.size());
    auto dfs = [&g, &ord](auto&& self, int v, int prv) -> void {
        for (int s : g[v]) {
            if (s == prv) continue;
            self(self, s, v);
        }
        ord.push_back(v);
    };
    dfs(dfs, s, -1);
    return ord;
}
