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

template <int MD>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int x_) { if ((x = x_ % MD + MD) >= MD) x -= MD; }

  ModInt& operator+=(ModInt that) { if ((x += that.x) >= MD) x -= MD; return *this; }
  ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MD; return *this; }
  ModInt& operator-=(ModInt that) { if ((x -= that.x) <= MD) x += MD; return *this; }
  ModInt& operator/=(ModInt that) { x = (unsigned long long)x * that.inv().x % MD; return *this; }

  ModInt operator-() const { return -x < 0 ? MD - x : -x; }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  ModInt pow(int n) const {
    ModInt x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  ModInt inv() const { return (*this).pow(MD - 2); }
  friend ostream& operator<<(ostream& s, ModInt<MD> a) { s << a.x; return s; }
};
using mint = ModInt<MOD>;

signed main() {
}
