class UndirectedGraph {
    struct Edge {
        int to, cost;
    };

public:
    vector<vector<Edge>> G;
    int V;
    UndirectedGraph(int V) : G(V), V(V) {}
    void add_edge(int u, int v, int cost) {
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }
    vector<int> dijkstra(int s) {
        vector<int> d(V, 1e18);
        d[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;  // {dist, v}
        que.push({0, s});
        while (!que.empty()) {
            pair<int, int> p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;  // 定数倍枝刈り
            for (Edge e : G[v]) {
                int tmp = d[v] + e.cost;
                if (d[e.to] <= tmp) continue;
                d[e.to] = tmp;
                que.push({tmp, e.to});
            }
        }
        return d;
    }
};
