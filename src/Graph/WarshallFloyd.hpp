/// @docs src/Graph/WarshallFloyd.md
template <class T> void warshall_floyd(std::vector<std::vector<T>> &d, const T INF) {
    int n = d.size();
    for (int i = 0; i < n; i++) assert(d[i][i] == 0);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
