template <class T, class F>
struct SegmentTree {
    const F op;
    const T e;
    SegmentTree(F op_, T e_) : op(op_), e(e_) {}
    int n;
    vector<T> t;
    void set_by_unit(int n_) {
        t.clear();
        n = n_;
        t.resize(2 * n, e);
    }
    void set_by_vector(const vector<T>& a) {
        t.clear();
        n = a.size();
        t.resize(2 * n, e);
        for (int i = 0; i < n; i++) t[i + n] = a[i];
        build();
    }
    void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
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
    // iをaに変更
    void update(int i, const T& a) {
        assert(0 <= i && i < n);
        t[i += n] = a;
        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
};
