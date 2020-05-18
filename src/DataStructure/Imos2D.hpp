/// @docs src/DataStructure/Imos2D.md
// 0-indexed
// t.add(i0, j0, i1, j1) -> t.run() -> t[i][j]
template <class T> struct Imos2D {
    int n, m;
    std::vector<std::vector<T>> t;  // 0-indexed!!, -x分のために配列の外側を1大きめに
    Imos2D(int n_, int m_) : n(n_), m(m_), t(n_ + 1, std::vector<T>(m_ + 1)) {}
    // i0 <= i < i1, j0 < j < j1の範囲に+x
    void add(int i0, int j0, int i1, int j1, T x) {
        t[i0][j0] += x, t[i1][j1] += x;
        t[i1][j0] -= x, t[i0][j1] -= x;
    }
    // 2方向に累積和をとる
    void build() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) t[i + 1][j] += t[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) t[i][j + 1] += t[i][j];
    }
    std::vector<T>& operator[](int i) { return t[i]; }
};
