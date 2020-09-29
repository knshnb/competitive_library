---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1073.test.cpp
    title: test/yukicoder/1073.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Math/Matrix.hpp\"\ntemplate <class T> struct Matrix\
    \ {\n    std::vector<std::vector<T>> A;\n    Matrix() {}\n    Matrix(int n) :\
    \ A(n, std::vector<T>(n, 0)) {}\n    Matrix(const std::vector<std::vector<T>>\
    \ &A_) : A(A_) {}\n    static Matrix eye(int n) {\n        Matrix mat(n);\n  \
    \      for (int i = 0; i < n; i++) mat[i][i] = 1;\n        return mat;\n    }\n\
    \    int height() const { return (A.size()); }\n    int width() const { return\
    \ (A[0].size()); }\n    std::vector<T> &operator[](int k) { return A[k]; }\n \
    \   const std::vector<T> &operator[](int k) const { return (A[k]); }\n    Matrix\
    \ &operator+=(const Matrix &B) {\n        assert(A.size() == B.A.size() && A[0].size()\
    \ == B.A[0].size());\n        for (int i = 0; i < A.size(); i++)\n           \
    \ for (int j = 0; j < A[0].size(); j++) A[i][j] += B[i][j];\n        return *this;\n\
    \    }\n    Matrix &operator-=(const Matrix &B) {\n        assert(A.size() ==\
    \ B.A.size() && A[0].size() == B.A[0].size());\n        for (int i = 0; i < A.size();\
    \ i++)\n            for (int j = 0; j < A[0].size(); j++) A[i][j] -= B[i][j];\n\
    \        return *this;\n    }\n    Matrix &operator*=(const Matrix &B) {\n   \
    \     int n = height(), m = B.width(), p = width();\n        assert(p == B.height());\n\
    \        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));\n        for\
    \ (int i = 0; i < n; i++)\n            for (int j = 0; j < m; j++)\n         \
    \       for (int k = 0; k < p; k++) C[i][j] += A[i][k] * B[k][j];\n        std::swap(A,\
    \ C);\n        return *this;\n    }\n    Matrix operator+(const Matrix &B) const\
    \ { return Matrix(*this) += B; }\n    Matrix operator-(const Matrix &B) const\
    \ { return Matrix(*this) -= B; }\n    Matrix operator*(const Matrix &B) const\
    \ { return Matrix(*this) *= B; }\n    std::vector<T> operator*(const std::vector<T>\
    \ &x) const {\n        int n = height(), m = width();\n        assert(m == x.size());\n\
    \        std::vector<T> ret(n);\n        for (int i = 0; i < n; i++)\n       \
    \     for (int j = 0; j < m; j++) ret[i] += A[i][j] * x[j];\n        return ret;\n\
    \    }\n};\n"
  code: "template <class T> struct Matrix {\n    std::vector<std::vector<T>> A;\n\
    \    Matrix() {}\n    Matrix(int n) : A(n, std::vector<T>(n, 0)) {}\n    Matrix(const\
    \ std::vector<std::vector<T>> &A_) : A(A_) {}\n    static Matrix eye(int n) {\n\
    \        Matrix mat(n);\n        for (int i = 0; i < n; i++) mat[i][i] = 1;\n\
    \        return mat;\n    }\n    int height() const { return (A.size()); }\n \
    \   int width() const { return (A[0].size()); }\n    std::vector<T> &operator[](int\
    \ k) { return A[k]; }\n    const std::vector<T> &operator[](int k) const { return\
    \ (A[k]); }\n    Matrix &operator+=(const Matrix &B) {\n        assert(A.size()\
    \ == B.A.size() && A[0].size() == B.A[0].size());\n        for (int i = 0; i <\
    \ A.size(); i++)\n            for (int j = 0; j < A[0].size(); j++) A[i][j] +=\
    \ B[i][j];\n        return *this;\n    }\n    Matrix &operator-=(const Matrix\
    \ &B) {\n        assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());\n\
    \        for (int i = 0; i < A.size(); i++)\n            for (int j = 0; j < A[0].size();\
    \ j++) A[i][j] -= B[i][j];\n        return *this;\n    }\n    Matrix &operator*=(const\
    \ Matrix &B) {\n        int n = height(), m = B.width(), p = width();\n      \
    \  assert(p == B.height());\n        std::vector<std::vector<T>> C(n, std::vector<T>(m,\
    \ 0));\n        for (int i = 0; i < n; i++)\n            for (int j = 0; j < m;\
    \ j++)\n                for (int k = 0; k < p; k++) C[i][j] += A[i][k] * B[k][j];\n\
    \        std::swap(A, C);\n        return *this;\n    }\n    Matrix operator+(const\
    \ Matrix &B) const { return Matrix(*this) += B; }\n    Matrix operator-(const\
    \ Matrix &B) const { return Matrix(*this) -= B; }\n    Matrix operator*(const\
    \ Matrix &B) const { return Matrix(*this) *= B; }\n    std::vector<T> operator*(const\
    \ std::vector<T> &x) const {\n        int n = height(), m = width();\n       \
    \ assert(m == x.size());\n        std::vector<T> ret(n);\n        for (int i =\
    \ 0; i < n; i++)\n            for (int j = 0; j < m; j++) ret[i] += A[i][j] *\
    \ x[j];\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Matrix.hpp
  requiredBy: []
  timestamp: '2020-06-06 02:12:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1073.test.cpp
documentation_of: src/Math/Matrix.hpp
layout: document
redirect_from:
- /library/src/Math/Matrix.hpp
- /library/src/Math/Matrix.hpp.html
title: src/Math/Matrix.hpp
---
