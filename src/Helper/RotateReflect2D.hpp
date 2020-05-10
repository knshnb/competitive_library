template <class T> std::vector<std::vector<T>> rotate_2D(const std::vector<std::vector<T>>& t, bool counterclockwise = true) {
    int H = t.size(), W = t[0].size();
    std::vector<std::vector<T>> ret(W, std::vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ret[j][i] = counterclockwise ? t[i][W - 1 - j] : t[H - 1 - i][j];
        }
    }
    return ret;
}

template <class T> std::vector<std::vector<T>> reflect_2D(const std::vector<std::vector<T>>& t) {
    int H = t.size(), W = t[0].size();
    std::vector<std::vector<T>> ret(W, std::vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ret[j][i] = t[i][j];
        }
    }
    return ret;
}
