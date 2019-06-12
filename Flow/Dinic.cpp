// Dinic法 O(E * V^2)
class Graph {
  int t; // ゴール
  vector<int> level, iter;
  void bfs(int s) {
    for (int i = 0; i < level.size(); i++) level[i] = -1;
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  int dfs(int v, int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
public:
  int V;
  struct edge { int to, cap, rev; };
  vector<vector<edge>> G;
  Graph(int V) : V(V), G(V), level(V), iter(V) {}

  void add_edge(int from, int to, int cap) {
    G[from].push_back(edge{ to, cap, (int)G[to].size() });
    G[to].push_back(edge{ from, 0, (int)G[from].size() - 1 });
  }

  int max_flow(int s, int t) {
    int flow = 0;
    this->t = t;
    while (1) {
      bfs(s);
      if (level[t] < 0) return flow;
      for (int i = 0; i < iter.size(); i++) iter[i] = 0;
      int f;
      while ((f = dfs(s, (1LL << 60))) > 0) {
        flow += f;
      }
    }
  }
};
