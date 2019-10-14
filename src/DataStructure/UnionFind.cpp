struct UnionFind {
    int cnt;                   // 集合の数
    vector<int> number;        // 0以上のとき親のindex, 負のときは集合サイズ
    vector<int> data1, data2;  // 連結成分ごとのデータ
    UnionFind(int n) : cnt(n), number(n, -1) {}
    UnionFind(const vector<int>& data1, const vector<int>& data2)
        : cnt(data1.size()), number(data1.size(), -1), data1(data1), data2(data2) {}
    int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]); }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (number[y] < number[x]) swap(x, y);
        // yをxにマージ
        number[x] += number[y];
        number[y] = x;
        // // dataのマージ方法に合わせて変える
        // data1[x] += data1[y];
        // data2[x] += data2[y];
        cnt--;
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
    int& ref1(int x) { return data1[root(x)]; }
    int& ref2(int x) { return data2[root(x)]; }
};
