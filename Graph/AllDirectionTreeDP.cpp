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
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
template <class T, class S> ostream& operator<<(ostream &s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "\t" << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl << "\t", dump_func(__VA_ARGS__);
#else
  #define dump(...)
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
const int MOD = 1e9 + 7;

// 全方位木DP
// ds[v]: vを根としたときのそれぞれの葉までの距離
signed main() {
  struct Edge {
    int to, c;
  };
  int n; cin >> n;
  vector<vector<Edge>> G(n);
  REP (i, n - 1) {
    int s, t, w; cin >> s >> t >> w;
    G[s].push_back({t, w});
    G[t].push_back({s, w});
  }
  VVII ds(n);
  function<int(int, int)> dfs1 = [&](int v, int p) {
    int ma = 0;
    for (Edge e: G[v]) if (e.to != p) {
      int tmp = dfs1(e.to, v) + e.c;
      ds[v].push_back({tmp, e.to});
      ma = max(ma, tmp);
    }
    return ma;
  };
  dfs1(0, -1);

  sort(RALL(ds[0]));
  function<void(int, int)> dfs2 = [&](int v, int p) {
    for (Edge e: G[v]) if (e.to != p) {
      int tmp = (ds[v][0].se != e.to ? ds[v][0].fi
                                     : (ds[v].size() == 1 ? 0 : ds[v][1].fi)) + e.c;
      ds[e.to].push_back({tmp, v});
      sort(RALL(ds[e.to]));
      dfs2(e.to, v);
    }
  };
  dfs2(0, -1);

  int ans = 0;
  REP (i, n) {
    if (ds[i].size() == 0) continue;
    ans = max(ans, ds[i][0].fi);
  }
  cout << ans << endl;
}
