// A[n-1]にはAx = bのbの値
template <class T> void gauss_jordan(vector<vector<T>>& A) {
    int n = A.size(), m = A[0].size();
    vector<bool> used(n);
    for (int col = 0; col < m - 1; col++) {
        int pivot = -1;
        for (int row = 0; row < n; row++) {
            if (!used[row] && A[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        used[pivot] = true;
        for (int row = 0; row < n; row++) {
            if (row == pivot) continue;
            T d = A[row][col] / A[pivot][col];  // 倍率
            for (int col2 = 0; col2 < m; col2++) {
                A[row][col2] -= A[pivot][col2] * d;
            }
        }
    }
}
