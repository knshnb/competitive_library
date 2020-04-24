/// @docs src/Flow/FordFulkerson.md
template <class T = long long> struct FordFulkerson {
    struct Edge {
        int to, rev_idx;  // 逆辺はg[to][rev_idx]
        T cap;
        bool is_rev;
    };
    std::vector<std::vector<Edge>> g;
    FordFulkerson(int n) : g(n) {}

    void add_edge(int from, int to, T cap) {
        g[from].push_back({to, (int)g[to].size(), cap, false});
        g[to].push_back({from, (int)g[from].size() - 1, 0, true});
    }
    T max_flow(int s, int t) {
        std::vector<bool> used(g.size());
        auto dfs = [this, &used, &t](auto f, int v, T min_acc) -> T {
            if (v == t) return min_acc;
            if (used[v]) return 0;
            used[v] = true;
            for (Edge& e : g[v]) {
                if (e.cap == 0) continue;
                T dif = f(f, e.to, std::min(min_acc, e.cap));
                if (dif == 0) continue;
                e.cap -= dif, g[e.to][e.rev_idx].cap += dif;
                return dif;
            }
            return 0;
        };

        T flow = 0;
        while (1) {
            std::fill(used.begin(), used.end(), false);
            T f = dfs(dfs, s, std::numeric_limits<T>::max() / 2);
            if (f == 0) return flow;
            flow += f;
        }
    }
    // max_flow()の後に呼ぶと、{u, v, 流した流量}のvectorを返す
    std::vector<std::tuple<int, int, T>> construct() {
        std::vector<std::tuple<int, int, T>> ret;
        for (int i = 0; i < g.size(); i++) {
            for (Edge& e : g[i]) {
                if (e.is_rev) continue;
                T f = g[e.to][e.rev_idx].cap;
                if (f == 0) continue;
                ret.push_back({i, e.to, f});
            }
        }
        return ret;
    }
};
