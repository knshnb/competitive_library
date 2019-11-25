// インターフェイスは0-indexed
// add(i0, j0, i1, j1) -> run() -> get(i, j)
template <class T> struct Imos2D {
    int n, m;
    vector<vector<T>> t;  // 1-indexed!!, -x分のために配列の外側も1大きめ
    Imos2D(int n_, int m_) : n(n_), m(m_), t(n_ + 2, vector<T>(m_ + 2)) {}
    // i0 <= i < i1, j0 < j < j1の範囲に+x
    void add(int i0, int j0, int i1, int j1, T x) {
        i0++, j0++, i1++, j1++;
        t[i0][j0] += x;
        t[i1][j0] -= x;
        t[i0][j1] -= x;
        t[i1][j1] += x;
    }
    // 累積和を取る
    void run() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i + 1][j + 1] += t[i][j + 1] + t[i + 1][j] - t[i][j];
            }
        }
    }
    T get(int i, int j) { return t[i + 1][j + 1]; }
};
