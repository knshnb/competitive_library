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

signed main() {
}
