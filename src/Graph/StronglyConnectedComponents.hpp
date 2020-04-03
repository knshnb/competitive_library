/// @docs src/Graph/StronglyConnectedComponents.md
struct StronglyConnectedComponents {
    int n, size;  // sizeはbuild()後に強連結成分の数を格納
    std::vector<std::vector<int>> edge, redge;
    std::vector<int> belong_to;
    StronglyConnectedComponents(int n_) : n(n_), edge(n_), redge(n_) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        edge[u].push_back(v);
        redge[v].push_back(u);
    }
    void build() {
        std::vector<int> ord;  // post-order
        // 正方向の辺でdfs、post-orderをふる
        std::vector<bool> visited(n, false);
        auto dfs1 = [&](auto f, int v) -> void {
            if (visited[v]) return;
            visited[v] = true;
            for (int s : edge[v]) {
                f(f, s);
            }
            ord.push_back(v);
        };
        for (int i = 0; i < n; i++) dfs1(dfs1, i);

        // post-order逆順にdfs、到達可能な同値類に分ける
        belong_to.assign(n, -1);
        int cur_group = 0;
        auto dfs2 = [&](auto f, int v) -> void {
            if (belong_to[v] != -1) return;
            belong_to[v] = cur_group;
            for (int s : redge[v]) {
                f(f, s);
            }
        };
        std::reverse(ord.begin(), ord.end());
        for (int i : ord) {
            if (belong_to[i] == -1) {
                dfs2(dfs2, i);
                cur_group++;
            }
        }
        size = cur_group;
    }
    bool has_loop() {
        build();
        return size < n;
    }
};
