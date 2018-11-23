#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define REPI(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define int long long
using VI = vector<int>;
using VVI = vector<VI>;

class DirectedGraph {
public:
  int N;
  VVI edge, redge;
  VI cmp; // 強連結成分のインデックス(トポロジカル順序)
  DirectedGraph(int n) {
    N = n;
    edge = VVI(N); redge = VVI(N);
    cmp = VI(N);
  }
  void addEdge(int from, int to) {
    assert(0 <= from && from < N && 0 <= to && to < N);
    edge[from].push_back(to);
    redge[to].push_back(from);
  }
  int scc() {
    vector<bool> used(N);
    VI vs;
    function<void(int)> dfs = [&](int v) {
      used[v] = true;
      for (int vv: edge[v]) {
        if (used[vv]) { continue; }
        dfs(vv);
      }
      vs.push_back(v);
    };
    function<void(int, int)> rdfs = [&](int v, int k) {
      used[v] = true;
      cmp[v] = k;
      for (int vv: redge[v]) {
        if (used[vv]) { continue; }
        rdfs(vv, k);
      }
    };
    REP (v, N) {
      if (used[v]) { continue; }
      dfs(v);
    }
    used = vector<bool>(N);
    int k = 0;
    assert(vs.size() == N);
    for (int i = N - 1; i >= 0; i--) {
      int v = vs[i];
      if (used[v]) { continue; }
      rdfs(v, k++);
    }
    return k;
  }
};
signed main() {
}
