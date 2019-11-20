template <class T> struct Accumulate2D {
    vector<vector<T>> t;  // 0-indexed!!
    Accumulate2D(int n, int m) : t(n + 1, vector<T>(m + 1)) {}
    T get(int i, int j) { return (i < 0 || j < 0) ? 0 : t[i][j]; }

    // i0 <= i < i1, j0 < j < j1の範囲に+x
    // このあとにrunする必要あり！
    void add(int i0, int j0, int i1, int j1, T x) {
        t[i0][j0] += x;
        t[i1][j0] -= x;
        t[i0][j1] -= x;
        t[i1][j1] += x;
    }

    // 累積和を取る
    void run() {
        for (int i = 0; i < t.size(); i++) {
            for (int j = 0; j < t[0].size(); j++) {
                t[i][j] += get(i, j - 1) + get(i - 1, j) - get(i - 1, j - 1);
            }
        }
    }

    // i0 <= i < i1, j0 < j < j1の範囲のsumを求める
    // runをしてから使う！
    T query(int i0, int j0, int i1, int j1) {
        return get(i1 - 1, j1 - 1) - get(i1 - 1, j0 - 1) - get(i0 - 1, j1 - 1) + get(i0 - 1, j0 - 1);
    }
};
