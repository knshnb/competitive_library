class DirectedGraph {
    vector<bool> used;
    vector<int> vs;  // dfsでpost-orderの順に頂点を格納
    void dfs(int v) {
        used[v] = true;
        for (int s : edge[v]) {
            if (!used[s]) dfs(s);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        cmp[v] = k;
        for (int s : redge[v]) {
            if (cmp[s] == -1) rdfs(s, k);
        }
    }

public:
    int N;
    vector<vector<int>> edge, redge;
    vector<int> cmp;  // 強連結成分のインデックス(トポロジカル順序)
    DirectedGraph(int n) {
        N = n;
        edge.resize(N);
        redge.resize(N);
    }
    void add_edge(int from, int to) {
        assert(0 <= from && from < N && 0 <= to && to < N);
        edge[from].push_back(to);
        redge[to].push_back(from);
    }
    // cmpに各頂点がトポロジカル順で何番目の強連結成分に入るかを格納し、強連結成分の個数を返す
    // O(E + V)
    int scc() {
        used.assign(N, false);
        vs.clear();
        vs.reserve(N);
        for (int v = 0; v < N; v++) {
            if (!used[v]) dfs(v);
        }
        assert(vs.size() == N);
        // dfsにおけるpost orderの番号が小さい順にrdfs
        // 同じ強連結成分に属するものはredgeを使って到達できる
        int k = 0;
        cmp.assign(N, -1);
        for (int i = N - 1; i >= 0; i--) {
            if (cmp[vs[i]] == -1) rdfs(vs[i], k++);
        }
        return k;
    }
    // 有向グラフの閉路検出、O(E + V)
    bool has_loop() { return scc() < N; }
};
