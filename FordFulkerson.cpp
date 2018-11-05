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

// Ford Fulkerson法 O(F * E)
class Graph {
  vector<bool> used;
  int t; // ゴール
  // f: 流量
  int dfs(int v, int f) {
    if (v == t) return f;
    used[v] = true;
    for (edge& e: G[v]) {
      if (used[e.to] || e.cap <= 0) continue;
      int res = dfs(e.to, min(f, e.cap));
      if (res <= 0) continue;
      e.cap -= res;
      G[e.to][e.rev].cap += res;
      return res;
    }
    return 0;
  }
public:
  int V;
  // G[e.to][e.rev]で逆辺にアクセスできるように
  // 逆辺のcapは、"正辺に流れている流量"(その分だけ逆に戻せるので)(はじめは全て0)
  struct edge { int to, cap, rev; };
  vector<vector<edge>> G;
  Graph(int V) : V(V), G(V), used(V) {}
  void add_edge(int from, int to, int cap) {
    G[from].push_back({to, cap, (int)G[to].size()});
    G[to].push_back({from, 0, (int)G[from].size() - 1});
  }
  int max_flow(int s, int t) {
    this->t = t;
    int ret = 0;
    while (1) {
      fill(ALL(used), false);
      int f = dfs(s, 1e18);
      if (f == 0) return ret;
      ret += f;
    }
  }
};
signed main() {
}
