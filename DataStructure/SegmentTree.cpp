template <class T = int>
class SegTree {
    using VT = vector<T>;
    int orig_n;
    // k番目のノードの[l, r)について[a, b)を求める
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return UNIT;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

public:
    int N;
    VT dat;
    function<T(T, T)> f;
    T UNIT;
    SegTree() {}
    SegTree(int n, function<T(T, T)> f_, const T unit) : orig_n(n), f(f_), UNIT(unit) {
        for (N = 1; N < n; N *= 2)
            ;
        dat = VT(2 * N - 1, UNIT);
    }
    SegTree(
        const VT& a, function<T(T, T)> f_ = [](int a, int b) { return min(a, b); }, T unit = 1e15)
        : orig_n(a.size()), f(f_), UNIT(unit) {
        for (N = 1; N < orig_n; N *= 2)
            ;
        dat = VT(2 * N - 1);
        REP(i, a.size()) { dat[N - 1 + i] = a[i]; }
        for (int k = N - 2; k >= 0; k--) {
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // k番目をaに
    void update(int k, T a) {
        k += N - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // [a, b)でのクエリ
    T query(int a, int b) {
        assert(0 <= a && a < b && b <= orig_n);
        return query(a, b, 0, 0, N);
    }
    T query(int a) { return query(a, a + 1); }
};
