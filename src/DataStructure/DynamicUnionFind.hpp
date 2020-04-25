struct DynamicUnionFind {
    std::unordered_map<int, int> number;

    int root(int x) {
        if (!number.count(x)) number[x] = -1;
        return number[x] < 0 ? x : number[x] = root(number[x]);
    }
    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (number[y] < number[x]) std::swap(x, y);
        // yをxにマージ
        number[x] += number[y];
        number[y] = x;
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
};
