struct UnionFind {
    int cnt;             // 集合の数
    vector<int> number;  // 0以上のとき親のindex, 負のときは集合サイズ
    struct Data {
        Data() {}
        void merge(Data& s) {
            // 自分で定義
        }
    };
    vector<Data> data;

    UnionFind(int n) : cnt(n), number(n, -1), data(n) {}
    int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]); }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (number[y] < number[x]) swap(x, y);
        // yをxにマージ
        number[x] += number[y];
        number[y] = x;
        // dataのマージ方法に合わせて変える
        data[x].merge(data[y]);

        cnt--;
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
    Data& ref(int x) { return data[root(x)]; }
};
