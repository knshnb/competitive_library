#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (ll i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define debug(x) cerr << #x << ": " << (x) << endl
#define debug2(x, y) cerr << #x << ": " << (x) << " " << #y << ": " << y << endl;
#define int long long
using namespace std;
using II = pair<int, int>;
using VII = vector<II>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
template <class T, class S> ostream& operator<<(ostream &s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
const int MOD = 1e9 + 7;

// ax + by = gcd(a, b) を満たす(x, y)
II ext_gcd(int a, int b) {
  if (b == 0) return {1, 0};
  II xy = ext_gcd(b, a % b); // b(qx + y) + rx = ...
  swap(xy.fi, xy.se);
  xy.se -= (a / b) * xy.fi;
  return xy;
}
const II DUM = {0, -1};
// r = b[i] (mod m[i])
// r: 剰余, M: mod
II chinese_rem(const VI& b, const VI& m) {
  int r = 0, M = 1;
  REP (i, b.size()) {
    II xy = ext_gcd(M, m[i]);
    int d = __gcd(M, m[i]);
    if ((b[i] - r) % d != 0) return DUM;
    int tmp = ((b[i] - r) / d) * xy.fi % (m[i] / d);
    r += M * tmp;
    M *= m[i] / d;
  }
  ((r %= M) += M) %= M;
  return {r, M};
}

signed main() {
}
