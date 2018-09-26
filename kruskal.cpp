#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define REPI(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define int long long
using namespace std;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;

class UnionFind {
public:
  VI par, rank;
  UnionFind(int n) {
    par = VI(n); iota(par.begin(), par.end(), 0);
    rank = VI(n, 0);
  }
  int root(int x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) { return; }
    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) { rank[x]++; }
    }
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};

struct edge { int u, v, cost; };
bool comp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }
int kruskal(int V, vector<edge>& es) {
  sort(es.begin(), es.end(), comp);
  UnionFind uf(V);
  int ans = 0;
  for (edge e: es) {
    if (uf.same(e.u, e.v)) { continue; }
    uf.unite(e.u, e.v);
    ans += e.cost;
  }
  return ans;
}
signed main() {
  int V, E;
  cin >> V >> E;
  vector<edge> es(E);
  REP (i, E) {
    cin >> es[i].u >> es[i].v >> es[i].cost;
  }
  cout << kruskal(V, es) << endl;
}
