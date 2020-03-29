// 0-indexed
template <class T> struct FenwickTree {
    const T e;
    FenwickTree(T e_ = 0) : e(e_) {}
    int n;
    vector<T> t;
    void set_by_identity(int n_) {
        n = n_;
        t.clear(), t.resize(n, e);
    }
    void set_by_vector(const vector<T>& a) {
        n = a.size();
        t.clear(), t = a;
        for (int i = 0; i < n - 1; i++) {
            if ((i | (i + 1)) < n) t[i | (i + 1)] = op(t[i | (i + 1)], t[i]);
        }
    }
    // a番目にxを加算
    void add(int a, T x) {
        for (int i = a; i < n; i |= i + 1) {
            t[i] += x;
        }
    }

    // [0, a)、a == 0のときは0を返す
    T query(int a) const {
        T ret = 0;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += t[i];
        }
        return ret;
    }
    // [a, b)
    T query(int a, int b) const {
        assert(a <= b);
        return query(b) - query(a);
    }
    T operator[](int a) const { return query(a, a + 1); }
    // k番目をxに
    void update(int a, T x) { add(a, x - operator[](a)); }

    // 注: 中身が全て正のときしか動かない
    // query[0, i] >= xとなるような最小のi
    int lower_bound(T x) const {
        int i = -1;
        for (int w = 1 << __lg(n); w > 0; w >>= 1) {
            if (i + w < n && t[i + w] < x) {
                x -= t[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) >= xとなるような最小のi
    int lower_bound(int begin, T x) const {
        int lb = lower_bound(x + query(begin));
        return max(begin, lb);
    }
    // query(i + 1) > xとなるような最小のi
    int upper_bound(T x) const {
        int i = -1;
        for (int w = 1 << __lg(n); w > 0; w /= 2) {
            if (i + w < n && t[i + w] <= x) {
                x -= t[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) > xとなるような最小のi
    int upper_bound(int begin, T x) const {
        int ub = upper_bound(x + query(begin));
        return max(begin, ub);
    }
    friend string to_string(const FenwickTree<T>& ft) {
        vector<T> ret(ft.n);
        for (int i = 0; i < ft.n; i++) ret[i] = ft.operator[](i);
        return to_string(ret);
    }
};
