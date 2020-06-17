/// @docs src/Math/PascalTriangle.md
template <class T = long long> struct PascalTriangle {
    std::vector<std::vector<T>> binom;
    PascalTriangle(int n) : binom(n + 1, std::vector<T>(n + 1)) {
        for (int i = 0; i < n + 1; i++) {
            binom[i][0] = 1;
            for (int j = 1; j < i + 1; j++) {
                binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
            }
        }
    }
    // nCr
    T operator()(int n, int r) {
        assert(0 <= n && 0 <= r && r <= n && n <= binom.size());
        return binom[n][r];
    }
};