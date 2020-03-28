template <class T, class F> struct SegmentTree {
    const F op;
    const T e;
    SegmentTree(F op_, T e_) : op(op_), e(e_) {}
    int n;
    std::vector<T> t;
    void set_by_identity(int n_) {
        n = n_;
        t.clear(), t.resize(2 * n, e);
    }
    void set_by_vector(const std::vector<T>& a) {
        n = a.size();
        t.clear(), t.resize(2 * n, e);
        for (int i = 0; i < n; i++) t[i + n] = a[i];
        build();
    }
    void build() {
        for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    T& operator[](int i) { return t[i + n]; }
    // [l, r)
    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        T resl = e, resr = e;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = op(resl, t[l++]);
            if (r & 1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
    // iをxに変更
    void update(int i, const T& x) {
        assert(0 <= i && i < n);
        t[i += n] = x;
        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    // iにxを作用 (a[i] = op(a[i], x))
    void operate(int i, const T& x) {
        assert(0 <= i && i < n);
        i += n;
        t[i] = op(t[i], x);
        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    friend std::string to_string(const SegmentTree<T, F>& seg) {
        return to_string(std::vector<T>(seg.t.begin() + seg.n, seg.t.end()));
    }
};
template <class T, class F> auto make_segment_tree(F op, T e) { return SegmentTree<T, F>(op, e); }
// example
//     auto seg_mi = make_segment_tree<Int>([](Int a, Int b) { return min(a, b); }, 1e18);
//     auto seg_ma = make_segment_tree<Int>([](Int a, Int b) { return max(a, b); }, -1e18);
//     auto seg_affine = make_segment_tree<pair<Int, Int>>(
//         [](pair<Int, Int> a, pair<Int, Int> b) -> pair<Int, Int> {
//             return {a.first * b.first, b.first * a.second + b.second};
//         },
//         {1, 0});
