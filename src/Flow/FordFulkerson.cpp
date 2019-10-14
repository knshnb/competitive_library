// Ford Fulkerson法 O(F * E)
class Graph {
    vector<bool> used;
    int t;  // ゴール
    // f: 流量
    int dfs(int v, int f) {
        if (v == t) return f;
        used[v] = true;
        for (edge& e : G[v]) {
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
    struct edge {
        int to, cap, rev;
    };
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
