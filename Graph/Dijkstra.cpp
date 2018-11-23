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

class UndirectedGraph {
  struct Edge { int to, cost; };
public:
  vector<vector<Edge>> G;
  int V;
  UndirectedGraph(int V) : G(V), V(V) {}
  void add_edge(int u, int v, int cost) {
    G[u].push_back({v, cost});
    G[v].push_back({u, cost});
  }
  VI dijkstra(int s) {
    VI d(V, 1e18); d[s] = 0;
    priority_queue<II, VII, greater<II>> que; // {dist, v}
    que.push({0, s});
    while (!que.empty()) {
      II p = que.top(); que.pop();
      int v = p.second;
      if (d[v] < p.first) continue;
      for (Edge e: G[v]) {
        int tmp = d[v] + e.cost;
        if (d[e.to] <= tmp) continue;
        d[e.to] = tmp;
        que.push({tmp, e.to});
      }
    }
    return move(d);
  }
};

signed main() {
}
