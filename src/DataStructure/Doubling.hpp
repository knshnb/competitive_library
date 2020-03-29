struct Doubling {
    int n;
    int size;                  // MSB + 1
    vector<vector<int>> next;  // next[k][i]: iから(1<<k)回でどこまで進めるか

    // edge[i]: 1回でiからどこまで進めるか
    Doubling(vector<int>& edge) : n(edge.size()), size(64 - __builtin_clzll(edge.size())) {
        next.resize(size, vector<int>(n + 1, n));
        for (int i = 0; i < n; i++) next[0][i] = edge[i];
        for (int k = 0; k < size - 1; k++) {
            for (int i = 0; i < n; i++) {
                next[k + 1][i] = next[k][next[k][i]];
            }
        }
    }
    // i番目のx個先
    int get(int i, int x) {
        int ret = i;
        for (int bit = 0; bit < size; bit++) {
            if (!(x >> bit & 1)) continue;
            ret = next[bit][ret];
        }
        return ret;
    }
    // iからはじめて何回進めば初めてj以上になるか
    // j以上になりえないときはnを返す
    int lower_bound(int i, int j) {
        int cur = i, acc = 0;
        for (int wid = size - 1; wid >= 0; wid--) {
            if (next[wid][cur] < j) {
                acc += 1LL << wid;
                cur = next[wid][cur];
            }
        }
        return min(n, acc + 1);
    }
};
