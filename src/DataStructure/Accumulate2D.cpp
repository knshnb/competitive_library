// インターフェイスは0-indexed
// update(i, j, x) -> run() -> query(i0, j0, i1, j1)
template <class T> struct Accumulate2D {
    int n, m;
    vector<vector<T>> t;  // 1-indexed!!
    Accumulate2D(int n_, int m_) : n(n_), m(m_), t(n_ + 1, vector<T>(m_ + 1)) {}
    void update(int i, int j, T x) { t[i + 1][j + 1] = x; }
    // 累積和を取る
    void run() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i + 1][j + 1] += t[i][j + 1] + t[i + 1][j] - t[i][j];
            }
        }
    }
    // i0 <= i < i1, j0 < j < j1の範囲のsum
    T query(int i0, int j0, int i1, int j1) { return t[i1][j1] - t[i1][j0] - t[i0][j1] + t[i0][j0]; }
    // もともとの値
    T query(int i, int j) { return query(i, j, i + 1, j + 1); }
};
