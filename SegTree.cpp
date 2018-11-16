#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (ll i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << ": " << (x) << endl
#define debug2(x, y) cerr << #x << ": " << (x) << " " << #y << ": " << y << endl;
#define int long long
using namespace std;
using II = pair<int, int>;
using VII = vector<II>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
template <class T = int> inline T in() { T x; cin >> x; return x; }
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
const int MOD = 1e9 + 7;

template <class T = int>
class SegTree {
  using VT = vector<T>;
  int orig_n;
  // k番目のノードの[l, r)について[a, b)を求める
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) { return UNIT; }
    if (a <= l && r <= b) { return dat[k]; }
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return f(vl, vr);
  }
public:
  int N;
  VT dat;
  function<T(T, T)> f;
  T UNIT;
  SegTree() {}
  SegTree(int n, function<T(T, T)> f_, const T unit) : orig_n(n), f(f_), UNIT(unit) {
    for (N = 1; N < n; N *= 2);
    dat = VT(2 * N - 1, UNIT);
  }
  SegTree(const VT& a, function<T(T, T)> f_ = [](int a, int b) { return min(a, b); }, T unit = 1e15)
  : orig_n(a.size()), f(f_), UNIT(unit) {
    for (N = 1; N < a.size(); N *= 2);
    dat = VT(2 * N - 1);
    REP (i, a.size()) {
      dat[N - 1 + i] = a[i];
    }
    for (int k = N - 2; k >= 0; k--) {
      dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }
  // k番目をaに
  void update(int k, int a) {
    k += N - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }
  // [a, b)でのクエリ
  T query(int a, int b) {
    assert(0 <= a && a < b && b <= orig_n);
    return query(a, b, 0, 0, N);
  }
};

signed main() {
}
