template <class T> vector<vector<T>> rotate_2D(const vector<vector<T>>& t, bool counterclockwise = true) {
    int H = t.size(), W = t[0].size();
    vector<vector<T>> ret(W, vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ret[j][i] = counterclockwise ? t[i][W - 1 - j] : t[H - 1 - i][j];
        }
    }
    return ret;
}
