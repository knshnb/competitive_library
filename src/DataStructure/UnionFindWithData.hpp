struct UnionFind {
    int cnt;                  // 集合の数
    std::vector<int> number;  // 0以上のとき親のindex, 負のときは集合サイズ
    UnionFind(int n) : cnt(n), number(n, -1) {}
    int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]); }
    template <class F> void unite(int x, int y, F merge) {  // merge(x, y): yをxにマージ
        x = root(x), y = root(y);
        if (x == y) return;
        if (number[y] < number[x]) std::swap(x, y);
        // yをxにマージ
        number[x] += number[y];
        number[y] = x;
        cnt--;
        merge(x, y);
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
};
