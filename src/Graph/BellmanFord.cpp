template <class T>
struct Edge {
    int from, to;
    T cost;
};
// O(EV)、負のサイクルを通った後に到達できる点についてはdist[v]=INFを返す
template <class T>
vector<T> bellman_ford(vector<Edge<T>>& edges, int n, int s) {
    constexpr T INF = 1e18;  // Tの型に応じて書き換える必要あり
    vector<T> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            if (dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }
    for (Edge<T>& e : edges) {
        // sから到達できる負のサイクル検出
        if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to]) {
            dist[e.from] = -INF;
            dist[e.to] = -INF;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            if (dist[e.from] == -INF) dist[e.to] = -INF;
        }
    }
    return dist;
}
