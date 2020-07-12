/// @docs src/DataStructure/SparseTable.md
template <class T, class F> struct SparseTable {
    const F op;
    std::vector<std::vector<T>> t;
    SparseTable(F op_, const std::vector<T>& a) : op(op_), t({a}) {
        for (int k = 1; 1 << k < a.size() + 1; k++) {
            t.emplace_back(a.size() - (1 << k) + 1);
            for (int i = 0; i < a.size() - (1 << k) + 1; i++) {
                t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r) const {
        assert(0 <= l && l < r && r <= t[0].size());
        int k = std::__lg(r - l);
        return op(t[k][l], t[k][r - (1 << k)]);
    }
};
template <class T, class F> auto make_sparse_table(F op, const std::vector<T>& a) { return SparseTable<T, F>(op, a); }