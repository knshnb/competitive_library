// F(現在の木の個数, vector<頂点->集合のindex>) -> vector<集合のindex->(cost, to)>
// 使い方: https://codeforces.com/contest/1242/submission/64467604
template <class T, class F>
T boruvka(int n, const F& f) {
    struct UnionFind {
        vector<int> number;  // 0以上のとき親のindex, 負のときは集合サイズ
        UnionFind(int n) : number(n, -1) {}
        int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]); }
        bool unite(int x, int y) {
            x = root(x), y = root(y);
            if (x == y) return false;
            if (number[y] < number[x]) swap(x, y);
            number[x] += number[y];
            number[y] = x;
            return true;
        }
    };

    UnionFind uf(n);
    T res(0);
    bool update = true;
    vector<int> belongs(n), rev(n);
    while (update) {
        update = false;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (i == uf.root(i)) rev[ptr] = i, belongs[i] = ptr++;
        }
        for (int i = 0; i < n; i++) belongs[i] = belongs[uf.root(i)];
        vector<pair<T, int>> v = f(ptr, belongs);
        for (int i = 0; i < ptr; i++) {
            if (v[i].second >= 0 && uf.unite(rev[i], rev[v[i].second])) res += v[i].first, update = true;
        }
        if (!update) break;
    }
    return res;
}
