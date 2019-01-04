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

// Erdos-Gallai theorem: (O(n))
// https://en.wikipedia.org/wiki/Erdős–Gallai_theorem
bool is_graphic(const VI& d) {
  int n = d.size();
  if (accumulate(ALL(d), 0LL) % 2) return false;
  VI acc(n + 1);
  REP (i, n) {
    acc[i + 1] = acc[i] + d[i];
  }
  int l = n - 1; // d[l] >= i + 1を満たす最大のl
  REP (i, n) {
    int lhs = acc[i + 1];
    while (l >= i + 1 && d[l] < i + 1) l--;
    // [i + 1, l]: i + 1, [l + 1, n - 1]: acc
    int rhs = i * (i + 1) + (i + 1) * (l - i) + (acc[n] - acc[l + 1]);
    if (lhs > rhs) return false;
  }
  return true;
}

signed main() {
  // verify: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/3925879
  int n; cin >> n;
  VI d(n);
  REP (i, n) cin >> d[i];

  sort(RALL(d));
  if (is_graphic(d)) {
    cout << "YES" << endl;
  } else {
    d.back() += 1;
    sort(RALL(d));
    if (is_graphic(d)) {
      cout << "NO" << endl;
    } else {
      cout << "ABSOLUTELY NO" << endl;
    }
  }
}
