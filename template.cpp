#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj), rend(obj)
#define fi first
#define se second
using ii = pair<int, int>;
vector<ii> dirs = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1},  // 4方向
  {1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // 斜め
  {0, 0},  // 自身
};
template <class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// debug
template <class T> ostream& operator<<(ostream& s, vector<T>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " "); return s; }
template <class T> ostream& operator<<(ostream& s, vector<vector<T>>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n"); return s; }
template <class T, class S> ostream& operator<<(ostream& s, pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T, class S> ostream& operator<<(ostream& s, map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
#else
  #define dump(...)
  #define endl "\n"
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }

struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = 1000000007;
// *************** TEMPLATE END *************** 

signed main() {
}
