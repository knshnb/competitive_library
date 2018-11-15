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

template <int MOD = MOD>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int x_) { if ((x = x_ % MOD + MOD) >= MOD) x -= MOD; }
  int get() const { return x; }

  ModInt& operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt& operator-=(ModInt that) { if ((x -= that.x) <= MOD) x += MOD; return *this; }

  ModInt operator-() const { return -x < 0 ? MOD - x : -x; }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
};
template <int MOD> ostream& operator<<(ostream &s, const ModInt<MOD> a) { s << a.x; return s; }
using mint = ModInt<>;

template <class T = int>
T pow(T a, int x) {
  if (x == 0) return 1;
  T tmp = pow(a, x / 2);
  return tmp * tmp * (x % 2 ? a : 1);
}

signed main() {
}
