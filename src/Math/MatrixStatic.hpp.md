---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1073_matrix_static.test.cpp
    title: test/yukicoder/1073_matrix_static.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Math/MatrixStatic.hpp\"\ntemplate <class T, int size>\
    \ struct Matrix {\n    std::array<std::array<T, size>, size> A;\n    Matrix()\
    \ {}\n    Matrix(const std::array<std::array<T, size>, size> &A_) : A(A_) {}\n\
    \    static Matrix eye() {\n        Matrix mat{};\n        for (int i = 0; i <\
    \ size; i++) mat[i][i] = 1;\n        return mat;\n    }\n    std::array<T, size>\
    \ &operator[](int k) { return A[k]; }\n    const std::array<T, size> &operator[](int\
    \ k) const { return (A[k]); }\n    Matrix &operator+=(const Matrix &B) {\n   \
    \     for (int i = 0; i < A.size(); i++)\n            for (int j = 0; j < A[0].size();\
    \ j++) A[i][j] += B[i][j];\n        return *this;\n    }\n    Matrix &operator-=(const\
    \ Matrix &B) {\n        for (int i = 0; i < A.size(); i++)\n            for (int\
    \ j = 0; j < A[0].size(); j++) A[i][j] -= B[i][j];\n        return *this;\n  \
    \  }\n    Matrix &operator*=(const Matrix &B) {\n        std::array<std::array<T,\
    \ size>, size> C{};\n        for (int i = 0; i < size; i++)\n            for (int\
    \ j = 0; j < size; j++)\n                for (int k = 0; k < size; k++) C[i][j]\
    \ += A[i][k] * B[k][j];\n        std::swap(A, C);\n        return *this;\n   \
    \ }\n    Matrix operator+(const Matrix &B) const { return Matrix(*this) += B;\
    \ }\n    Matrix operator-(const Matrix &B) const { return Matrix(*this) -= B;\
    \ }\n    Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B;\
    \ }\n    std::array<T, size> operator*(const std::array<T, size> &x) const {\n\
    \        std::array<T, size> ret{};\n        for (int i = 0; i < size; i++)\n\
    \            for (int j = 0; j < size; j++) ret[i] += A[i][j] * x[j];\n      \
    \  return ret;\n    }\n};\n"
  code: "template <class T, int size> struct Matrix {\n    std::array<std::array<T,\
    \ size>, size> A;\n    Matrix() {}\n    Matrix(const std::array<std::array<T,\
    \ size>, size> &A_) : A(A_) {}\n    static Matrix eye() {\n        Matrix mat{};\n\
    \        for (int i = 0; i < size; i++) mat[i][i] = 1;\n        return mat;\n\
    \    }\n    std::array<T, size> &operator[](int k) { return A[k]; }\n    const\
    \ std::array<T, size> &operator[](int k) const { return (A[k]); }\n    Matrix\
    \ &operator+=(const Matrix &B) {\n        for (int i = 0; i < A.size(); i++)\n\
    \            for (int j = 0; j < A[0].size(); j++) A[i][j] += B[i][j];\n     \
    \   return *this;\n    }\n    Matrix &operator-=(const Matrix &B) {\n        for\
    \ (int i = 0; i < A.size(); i++)\n            for (int j = 0; j < A[0].size();\
    \ j++) A[i][j] -= B[i][j];\n        return *this;\n    }\n    Matrix &operator*=(const\
    \ Matrix &B) {\n        std::array<std::array<T, size>, size> C{};\n        for\
    \ (int i = 0; i < size; i++)\n            for (int j = 0; j < size; j++)\n   \
    \             for (int k = 0; k < size; k++) C[i][j] += A[i][k] * B[k][j];\n \
    \       std::swap(A, C);\n        return *this;\n    }\n    Matrix operator+(const\
    \ Matrix &B) const { return Matrix(*this) += B; }\n    Matrix operator-(const\
    \ Matrix &B) const { return Matrix(*this) -= B; }\n    Matrix operator*(const\
    \ Matrix &B) const { return Matrix(*this) *= B; }\n    std::array<T, size> operator*(const\
    \ std::array<T, size> &x) const {\n        std::array<T, size> ret{};\n      \
    \  for (int i = 0; i < size; i++)\n            for (int j = 0; j < size; j++)\
    \ ret[i] += A[i][j] * x[j];\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/MatrixStatic.hpp
  requiredBy: []
  timestamp: '2020-06-06 02:12:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1073_matrix_static.test.cpp
documentation_of: src/Math/MatrixStatic.hpp
layout: document
redirect_from:
- /library/src/Math/MatrixStatic.hpp
- /library/src/Math/MatrixStatic.hpp.html
title: src/Math/MatrixStatic.hpp
---
