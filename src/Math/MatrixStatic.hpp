template <class T, int size> struct Matrix {
    std::array<std::array<T, size>, size> A;
    Matrix() {}
    Matrix(const std::array<std::array<T, size>, size> &A_) : A(A_) {}
    static Matrix eye() {
        Matrix mat{};
        for (int i = 0; i < size; i++) mat[i][i] = 1;
        return mat;
    }
    std::array<T, size> &operator[](int k) { return A[k]; }
    const std::array<T, size> &operator[](int k) const { return (A[k]); }
    Matrix &operator+=(const Matrix &B) {
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) A[i][j] += B[i][j];
        return *this;
    }
    Matrix &operator-=(const Matrix &B) {
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) A[i][j] -= B[i][j];
        return *this;
    }
    Matrix &operator*=(const Matrix &B) {
        std::array<std::array<T, size>, size> C{};
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++) C[i][j] += A[i][k] * B[k][j];
        std::swap(A, C);
        return *this;
    }
    Matrix operator+(const Matrix &B) const { return Matrix(*this) += B; }
    Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B; }
    Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }
    std::array<T, size> operator*(const std::array<T, size> &x) const {
        std::array<T, size> ret{};
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) ret[i] += A[i][j] * x[j];
        return ret;
    }
};
