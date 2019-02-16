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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = 1e9 + 7;

int euler_totient(int n) {
  VI ps;
  {
    int tmp = n;
    for (int x = 2; x * x <= tmp; x++) {
      if (tmp % x) continue;
      ps.push_back(x);
      while (tmp % x == 0) tmp /= x;
    }
    if (tmp != 1) ps.push_back(tmp);
  }
  int m = ps.size();
  int ans = 0;
  REP (bit, 1LL << m) {
    int d = 1;
    REP (i, m) {
      if (bit >> i & 1) d *= ps[i];
    }
    int sign = __builtin_popcount(bit) % 2 ? -1 : 1;
    ans += sign * (n / d);
  }
  return ans;
}
signed main() {
  int n; cin >> n;
  cout << euler_totient(n) << endl;
}
