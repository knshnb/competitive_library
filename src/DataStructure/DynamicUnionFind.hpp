struct DynamicUnionFind {
    unordered_map<int, int> number;
    // 頂点xが入っていなかったら追加
    struct Data {
        Data() {}
        void merge(Data& s) {
            // 自分で定義
        }
    };
    unordered_map<int, Data> data;

    int root(int x) {
        if (!number.count(x)) number[x] = -1;
        return number[x] < 0 ? x : number[x] = root(number[x]);
    }
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
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
    Data& ref(int x) { return data[root(x)]; }
};
