template <class T>
void warshall_floyd(vector<vector<T>> &d) {
    int n = d.size();
    for (int i = 0; i < n; i++) assert(d[i][i] == 0);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
