template <class T>
struct Edge {
    int from, to;
    T cost;
};
// O(EV)、負のサイクルを通った後に到達できる点についてはdist[v]=INFを返す
template <class T>
vector<T> bellman_ford(vector<Edge<T>>& edges, int n, int s) {
    constexpr T INF = 1e18; // Tの型に応じて書き換える必要あり
    vector<T> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            if (dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }
    vector<int> can_diverge(n); // s->負のサイクル->vの順で到達可能かどうか
    for (Edge<T>& e : edges) {
        // sから到達できる負のサイクル検出
        if (dist[e.to] < INF && dist[e.from] + e.cost < dist[e.to]) {
            can_diverge[e.from] = true;
            can_diverge[e.to] = true;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (Edge<T>& e : edges) {
            can_diverge[e.to] |= can_diverge[e.from];
        }
    }
    for (int i = 0; i < n; i++) {
        if (can_diverge[i]) dist[i] = -INF;
    }
    return dist;
}
