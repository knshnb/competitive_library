template <class T> struct Graph {
    struct Edge {
        int to;
        T cost;
    };
    vector<vector<Edge>> g;
    int n;
    bool is_directed;
    Graph(int n_, bool is_directed_ = true) : g(n_), n(n_), is_directed(is_directed_) {}
    void add_edge(int u, int v, T cost) {
        g[u].emplace_back(v, cost);
        if (!is_directed) g[v].emplace_back(u, cost);
    }
    vector<T> dijkstra(int s) {
        // constexpr T INF = numeric_limits<T>::max() / 10;
        // constexpr T ZERO = 0;
        constexpr T INF = {1e18, 1e18};
        constexpr T ZERO = {0, 0};
        // 上2つは型によって書き換える必要あり
        vector<T> d(n, INF);
        d[0] = ZERO;
        using T_i = pair<T, int>;  // {dist, v}
        priority_queue<T_i, vector<T_i>, greater<T_i>> q;
        q.push({d[0], s});
        while (!q.empty()) {
            T_i p = q.top();
            q.pop();
            int v = p.second;
            if (d[v] < p.first) continue;  // 定数倍枝刈り
            for (Edge e : g[v]) {
                T nxt = d[v] + e.cost;
                if (d[e.to] <= nxt) continue;
                d[e.to] = nxt;
                q.emplace(nxt, e.to);
            }
        }
        return d;
    }
};
