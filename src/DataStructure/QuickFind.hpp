/// @docs src/DataStructure/QuickFind.md
struct QuickFind {
    std::vector<int> belong_to;
    std::vector<std::vector<int>> groups;
    QuickFind(int n) : belong_to(n), groups(n, std::vector<int>(1)) {
        std::iota(belong_to.begin(), belong_to.end(), 0);
        for (int i = 0; i < n; i++) groups[i][0] = i;
    }
    void unite(int x, int y) {
        x = belong_to[x], y = belong_to[y];
        if (x == y) return;
        if (groups[x].size() < groups[y].size()) std::swap(x, y);
        // yをxにマージ
        for (int v : groups[y]) belong_to[v] = x;
        groups[x].insert(groups[x].end(), groups[y].begin(), groups[y].end());
        groups[y].clear();
    }
    bool is_same(int x, int y) { return belong_to[x] == belong_to[y]; }
};
