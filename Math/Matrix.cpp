#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (int i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define int long long
using namespace std;
using ll = long long;
using II = pair<int, int>; using VII = vector<II>; using VVII = vector<VII>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
template <class T> using V = vector<T>; template <class T> using VV = V<V<T>>; template <class T> using VVV = V<VV<T>>;
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " "); return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n"); return s; }
template <class T, class S> ostream& operator<<(ostream &s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T, class S> ostream& operator<<(ostream& s, const map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
#else
  #define dump(...)
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
constexpr int MOD = 1e9 + 7;

template <class T>
struct Matrix {
  vector<vector<T>> A;
  Matrix() {}
  Matrix(int n) : A(n, vector< T >(n, 0)) {}
  Matrix(const vector<vector<T>>& A) : A(A) {}
  static Matrix I(int n) {
    Matrix mat(n);
    for(int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }
  int height() const { return (A.size()); }
  int width() const { return (A[0].size()); }
  vector<T>& operator[](int k) { return A[k]; }
  const vector<T>& operator[](int k) const { return (A[k]); }
  Matrix& operator+=(const Matrix &B) {
    assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
    for(int i = 0; i < A.size(); i++)
      for(int j = 0; j < A[0].size(); j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }
  Matrix &operator-=(const Matrix &B) {
    assert(A.size() == B.A.size() && A[0].size() == B.A[0].size());
    for(int i = 0; i < A.size(); i++)
      for(int j = 0; j < A[0].size(); j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }
  Matrix &operator*=(const Matrix &B) {
    int n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector<vector<T>> C(n, vector<T>(m, 0));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        for(int k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return (*this);
  }
  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); } 
  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); } 
  friend ostream &operator<<(ostream &os, Matrix &p) {
    int n = p.height(), m = p.width();
    for(int i = 0; i < n; i++) {
      os << "[";
      for(int j = 0; j < m; j++) {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }
  T determinant() {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    for(int i = 0; i < width(); i++) {
      int idx = -1;
      for(int j = i; j < width(); j++) {
        if(B[j][i] != 0) idx = j;
      }
      if(idx == -1) return (0);
      if(i != idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for(int j = 0; j < width(); j++) {
        B[i][j] /= vv;
      }
      for(int j = i + 1; j < width(); j++) {
        T a = B[j][i];
        for(int k = 0; k < width(); k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

signed main() {
}
