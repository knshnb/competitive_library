template <class T, bool directed = true> struct Dijkstra {
    struct Edge {
        int to;
        T cost;
    };
    std::vector<std::vector<Edge>> g;
    Dijkstra(int n) : g(n) {}
    void add_edge(int u, int v, T cost) {
        g[u].push_back({v, cost});
        if (!directed) g[v].push_back({u, cost});
    }
    std::vector<T> run(int s) {
        std::vector<T> dist(g.size(), std::numeric_limits<T>::max() / 2);
        // {d, v}
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> q;
        q.push({0, s});
        while (!q.empty()) {
            std::pair<T, int> p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] <= p.first) continue;
            dist[v] = p.first;
            for (const Edge& e : g[v]) {
                if (dist[e.to] <= p.first + e.cost) continue;  // 定数倍枝刈り
                q.emplace(p.first + e.cost, e.to);
            }
        }
        return dist;
    }
};
