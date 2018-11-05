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
#define debug2(x, y) cerr << #x << ": " << (x) << " " << #y << ": " << (y) << endl;
#define int long long
using namespace std;
using II = pair<int, int>;
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

class QuickFind {
public:
  int N;
  VI i2g; // 各頂点のグループ
  VVI g2i; // 各グループの頂点集合
  QuickFind(int n) : N(n) {
    i2g.resize(N);
    g2i = VVI(N, VI(1));
    REP (i, N) {
      i2g[i] = i;
      g2i[i][0] = i;
    }
  }
  // iを含むグループとjを含むグループをmerge
  void merge(int i, int j) {
    int gi = i2g[i], gj = i2g[j];
    if (gi == gj) return;
    if (g2i[gi].size() < g2i[j].size()) swap(gi, gj);
    // jをiにmerge
    for (int v: g2i[gj]) i2g[v] = gi;
    g2i[gi].insert(g2i[gi].end(), ALL(g2i[gj]));
    g2i[gj].clear();
  }
  bool same(int i, int j) {
    return i2g[i] == i2g[j];
  }
};

signed main() {
}

