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

using ull = unsigned long long;
random_device rnd;
mt19937 mt(rnd());
mt19937_64 mt64(rnd());
int mod_pow(int x, int n, int mod) {
  if (n <= 0) return 1;
  int tmp = mod_pow(x, n / 2, mod);
  return tmp * tmp % mod * (n % 2 ? x : 1) % mod;
}
// Miller-Rabin
bool is_prime(int n, int times = 50) {
  if (n == 2) return true;
  if (n % 2 == 0 || n < 2) return false;
  int d = n - 1;
  while (d % 2 == 0) d /= 2;
  while (times--) {
    int a = rnd() % (n - 2) + 1;
    int t = d;
    int y = mod_pow(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t *= 2;
    }
    if (y != n - 1 && t % 2 == 0) {
      return false;
    }
  }
  return true;
}
int gen_prime() {
  int cnt = 0;
  while (1) {
    int n = mt();
    n != 1;
    if (is_prime(n)) return n;
  }
}
class RollingHash {
public:
  vector<ull> hash, pows;
  ull mod;
  RollingHash(const string& S, ull base = gen_prime(), ull m = gen_prime()) : hash(S.size() + 1), pows(S.size() + 1), mod(m) {
    pows[0] = 1;
    REP (i, S.size()) {
      pows[i + 1] = pows[i] * base % mod;
      hash[i + 1] = hash[i] * base % mod + S[i];
      if (hash[i + 1] >= mod) hash[i + 1] -= mod;
    }
  }
  // [l, r)
  ull get(int l, int r) {
    assert(l <= r);
    ull ret = hash[r] + mod - hash[l] * pows[r - l] % mod;
    if (ret >= mod) ret -= mod;
    return ret;
  }
};
using UU = pair<ull, ull>;
class DoubleRollingHash {
public:
  RollingHash rh1, rh2;
  DoubleRollingHash(const string& S) : rh1(S), rh2(S) {}
  // [l, r)
  UU get(int l, int r) {
    return {rh1.get(l, r), rh2.get(l, r)};
  }
};

signed main() {
}
