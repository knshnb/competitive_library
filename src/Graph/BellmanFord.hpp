// O(EV)、負のサイクルを通った後に到達できる点については-INF, 到達不可能な点についてはINFを返す
template <class T> struct BellmanFord {
    struct Edge {
        int from, to;
        T cost;
    };
    const T INF = std::numeric_limits<T>::max() / 2;
    int n;
    std::vector<Edge> edges;

    BellmanFord(int n_) : n(n_) {}
    void add_edge(int u, int v, T cost) { edges.push_back({u, v, cost}); }
    std::vector<T> run(int s) {
        std::vector<T> dist(n, INF);
        dist[s] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (Edge& e : edges) {
                if (dist[e.from] == INF) continue;
                dist[e.to] = std::min(dist[e.to], dist[e.from] + e.cost);
            }
        }
        for (Edge& e : edges) {
            // sから到達できる負のサイクル検出
            if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to]) {
                dist[e.from] = -INF;
                dist[e.to] = -INF;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (Edge& e : edges) {
                if (dist[e.from] == -INF) dist[e.to] = -INF;
            }
        }
        return dist;
    }
};
