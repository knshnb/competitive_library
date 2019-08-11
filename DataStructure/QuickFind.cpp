class QuickFind {
public:
    int N;
    vector<int> i2g;          // 各頂点のグループ
    vector<vector<int>> g2i;  // 各グループの頂点集合
    QuickFind(int n) : N(n) {
        i2g.resize(N);
        g2i = vector<vector<int>>(N, vector<int>(1));
        for (int i = 0; i < N; i++) {
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
        for (int v : g2i[gj]) i2g[v] = gi;
        g2i[gi].insert(g2i[gi].end(), ALL(g2i[gj]));
        g2i[gj].clear();
    }
    bool same(int i, int j) { return i2g[i] == i2g[j]; }
};
