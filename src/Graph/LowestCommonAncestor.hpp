// edgeを貼ったあとにbuild()を忘れない！
struct TreeDoubling {
    struct Edge {
        int to, len;
    };  // 場合に応じて書き換える、toは必須
    std::vector<std::vector<Edge>> g;
    int n, size;  // MSB + 1
    int root;
    std::vector<int> depth;
    std::vector<std::vector<int>> parent;  // ダミー頂点n(親もn)
    TreeDoubling(int n_) : g(n_), n(n_), size(64 - __builtin_clzll(n_) + 1), depth(n_) {
        parent.resize(size, std::vector<int>(n + 1, n));
    }
    void build(int root_ = 0) {
        auto dfs = [&](auto f, int v, int prv) -> void {
            for (Edge& e : g[v]) {
                if (e.to == prv) continue;
                depth[e.to] = depth[v] + e.len;
                parent[0][e.to] = v;
                f(f, e.to, v);
            }
        };
        root = root_;
        depth[root] = 0;
        dfs(dfs, root, -1);
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
        if (depth[u] > depth[v]) std::swap(u, v);
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
    int dist(int u, int v) { return depth[u] + depth[v] - depth[lca(u, v)] * 2; }
};
