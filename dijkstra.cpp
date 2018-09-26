#define INF 1e18
using P = pair<int, int>; // (distance, v)
struct neigh { int to, cost; };
vector<int> dijkstra(vector<vector<neigh>>& G, int start) {
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> d = vector<int>(G.size(), INF);
  d[start] = 0;
  que.push(P(0, start));

  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) { continue; }
    for (int i = 0; i < G[v].size(); i++) {
      neigh e = G[v][i];
      if (d[v] + e.cost < d[e.to]) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  return d;
}
