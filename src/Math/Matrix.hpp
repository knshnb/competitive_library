template <class T> struct Matrix {
    std::vector<std::vector<T>> A;
    Matrix() {}
    Matrix(int n) : A(n, std::vector<T>(n, 0)) {}
    Matrix(const std::vector<std::vector<T>> &A_) : A(A_) {}
    static Matrix eye(int n) {
        Matrix mat(n);
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return mat;
    }
    int height() const { return (A.size()); }
    int width() const { return (A[0].size()); }
    std::vector<T> &operator[](int k) { return A[k]; }
    const std::vector<T> &operator[](int k) const { return (A[k]); }
    Matrix &operator+=(const Matrix &B) {
        assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) A[i][j] += B[i][j];
        return *this;
    }
    Matrix &operator-=(const Matrix &B) {
        assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) A[i][j] -= B[i][j];
        return *this;
    }
    Matrix &operator*=(const Matrix &B) {
        int n = height(), m = B.width(), p = width();
        assert(p == B.height());
        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < p; k++) C[i][j] += A[i][k] * B[k][j];
        std::swap(A, C);
        return *this;
    }
    Matrix operator+(const Matrix &B) const { return Matrix(*this) += B; }
    Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B; }
    Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }
    std::vector<T> operator*(const std::vector<T> &x) const {
        int n = height(), m = width();
        assert(m == x.size());
        std::vector<T> ret(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ret[i] += A[i][j] * x[j];
        return ret;
    }
};
