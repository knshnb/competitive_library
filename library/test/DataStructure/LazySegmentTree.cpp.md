---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: test/DataStructure/LazySegmentTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f3169353e2f9b2307db4d03c988efb93">test/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DataStructure/LazySegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-26 00:06:56+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using treap = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define REP(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj), rend(obj)
#define fi first
#define se second
using ii = pair<int, int>;
vector<ii> dirs = {
    {1, 0}, {0, 1},  {-1, 0},  {0, -1},  // 4方向
    {1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // 斜め
    {0, 0},                              // 自身
};
template <class T> inline bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class S> vector<T> make_vec(size_t n, S x) { return vector<T>(n, x); }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}

// debug
template <class T> ostream& operator<<(ostream& s, vector<T>& d) {
    REP(i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " ");
    return s;
}
template <class T> ostream& operator<<(ostream& s, vector<vector<T>>& d) {
    REP(i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n");
    return s;
}
template <class T, class S> ostream& operator<<(ostream& s, pair<T, S>& p) {
    s << "{" << p.first << ", " << p.second << "}";
    return s;
}
template <class T> ostream& operator<<(ostream& s, set<T> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
template <class T> ostream& operator<<(ostream& s, multiset<T> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
template <class T, class S> ostream& operator<<(ostream& s, map<T, S> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
template <class T, class S> ostream& operator<<(ostream& s, unordered_map<T, S> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
#ifdef _MY_DEBUG
#define dump(...)                                                                                                     \
    cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), \
        cerr << "*/\n\n";
#else
#define dump(...)
#define endl "\n"
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) {
    cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...);
}

struct Fast {
    Fast() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
    }
} fast;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = 1000000007;
// *************** TEMPLATE END ***************

// T0: 元の配列のモノイド
// T1: T0に対する作用素モノイド
template <class T0, class T1> class BaseSegmentTree {
    // k番目のノードにのlazyを伝搬
    void eval(int k, int len) {
        // 定数倍高速化
        if (lazy[k] == u1) return;
        // len個分のlazy[k]を評価
        node[k] = g(node[k], p(lazy[k], len));
        if (k < N - 1) {
            // 最下段でなければ下のlazyに伝搬
            lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);
        }
        lazy[k] = u1;
    }
    // k番目のノード[l, r)について、[a, b)の範囲内にxを作用
    void update(int a, int b, T1 x, int k, int l, int r) {
        eval(k, r - l);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = f1(lazy[k], x);
            eval(k, r - l);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = f0(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    // k番目のノード[l, r)について、[a, b)のクエリを求める
    T0 query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return u0;
        eval(k, r - l);
        if (a <= l && r <= b) return node[k];
        T0 vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f0(vl, vr);
    }

public:
    int sz;  // 元の配列のサイズ
    int N;
    vector<T0> node;
    vector<T1> lazy;
    // T0上の演算、単位元
    virtual T0 f0(T0, T0) = 0;
    const T0 u0;
    // T1上の演算、単位元
    virtual T1 f1(T1, T1) = 0;
    const T1 u1;
    // T0に対するT1の作用
    virtual T0 g(T0, T1) = 0;
    // 多数のt1(T1)に対するf1の合成
    virtual T1 p(T1, int) = 0;

    BaseSegmentTree(T0 u0, T1 u1) : u0(u0), u1(u1) {}
    void set_by_vector(const vector<T0>& a) {
        sz = a.size();
        for (N = 1; N < sz; N *= 2)
            ;
        node.resize(2 * N - 1, u0);
        lazy.resize(2 * N - 1, u1);
        for (int i = 0; i < sz; i++) node[N - 1 + i] = a[i];
        for (int i = N - 2; i >= 0; i--) node[i] = f0(node[2 * i + 1], node[2 * i + 2]);
    }
    void set_by_unit(int n) {
        sz = n;
        for (N = 1; N < sz; N *= 2)
            ;
        node.resize(2 * N - 1, u0);
        lazy.resize(2 * N - 1, u1);
    }
    // [a, b)にxを作用
    void update(int a, int b, T1 x) {
        assert(0 <= a && a < b && b <= sz);
        update(a, b, x, 0, 0, N);
    }
    void update(int a, T1 x) { update(a, a + 1, x); }
    // [a, b)
    T0 query(int a, int b) { return query(a, b, 0, 0, N); }
    T0 query(int a) { return query(a, a + 1); }
};

template <class T0, class T1> struct MinUpdateQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr T0 _u0 = numeric_limits<T0>::max();
    static constexpr T1 _u1 = numeric_limits<T1>::min();
    MinUpdateQuery() : MinUpdateQuery(_u0, _u1) {}
    T0 f0(T0 x, T0 y) override { return min(x, y); }
    T1 f1(T1 x, T1 y) override { return y == _u1 ? x : y; }
    T0 g(T0 x, T1 y) override { return y == _u1 ? x : y; }
    T1 p(T1 x, int len) override { return x; }
};

template <class T0, class T1> struct SumAddQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    SumAddQuery() : SumAddQuery(0, 0) {}
    T0 f0(T0 x, T0 y) override { return x + y; }
    T1 f1(T1 x, T1 y) override { return x + y; }
    T0 g(T0 x, T1 y) override { return x + y; }
    T1 p(T1 x, int len) override { return x * len; }
};

template <class T0, class T1> struct MinAddQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr int _u0 = numeric_limits<T0>::max();
    MinAddQuery() : MinAddQuery(_u0, 0) {}
    T0 f0(T0 x, T0 y) override { return min(x, y); }
    T1 f1(T1 x, T1 y) override { return x + y; }
    T0 g(T0 x, T1 y) override { return x + y; }
    T1 p(T1 x, int len) override { return x; }
};

template <class T0, class T1> struct SumUpdateQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr int _u1 = numeric_limits<T1>::min();
    SumUpdateQuery() : SumUpdateQuery(0, _u1) {}
    T0 f0(T0 x, T0 y) override { return x + y; }
    T1 f1(T1 x, T1 y) override { return y == _u1 ? x : y; }
    T0 g(T0 x, T1 y) override { return y == _u1 ? x : y; }
    T1 p(T1 x, int len) override { return x == _u1 ? _u1 : x * len; }
};

template <class T0> struct SumAffineQuery : public BaseSegmentTree<T0, pair<T0, T0>> {
    using T1 = pair<T0, T0>;  // first * x + second
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr T1 _u1 = {1, 0};
    SumAffineQuery() : SumAffineQuery(0, {1, 0}) {}  // TODO: _u1を使うとコンパイル通らない原因不明
    T0 f0(T0 x, T0 y) override { return x + y; }
    T1 f1(T1 x, T1 y) override { return {x.first * y.first, x.second * y.first + y.second}; }
    T0 g(T0 x, T1 y) override { return y.first * x + y.second; }
    T1 p(T1 x, int len) override { return {x.first, x.second * len}; }
    // update(i, j, {a, b}); // [i, j)にax + bを作用
    // update(i, j, {0, a}); // update
    // update(i, j, {1, a}); // 加算
    // update(i, j, {a, 0}); // 倍
};

template <class T> struct MinmaxAffineQuery : public BaseSegmentTree<pair<T, T>, pair<T, T>> {
    using T0 = pair<T, T>;  // {min, max}
    using T1 = pair<T, T>;  // first * x + second
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr T0 get_u0() { return {numeric_limits<T>::max(), -numeric_limits<T>::max()}; }
    static constexpr T1 _u1 = {1, 0};
    MinmaxAffineQuery() : MinmaxAffineQuery(get_u0(), _u1) {}  // TODO: _u1を使うとコンパイル通らない原因不明
    T0 f0(T0 x, T0 y) override { return {min(x.first, y.first), max(x.second, y.second)}; }
    T1 f1(T1 x, T1 y) override { return {x.first * y.first, x.second * y.first + y.second}; }
    T0 g(T0 x, T1 y) override {
        T0 ret = {x.first * y.first + y.second, x.second * y.first + y.second};
        if (y.first < 0) swap(ret.first, ret.second);
        return ret;
    }
    T1 p(T1 x, int len) override { return x; }
    // update(i, j, {a, b}); // [i, j)にax + bを作用
    // update(i, j, {0, a}); // update
    // update(i, j, {1, a}); // 加算
    // update(i, j, {a, 0}); // 倍
};

void aoj_rmq_and_ruq() {
    int n, Q;
    cin >> n >> Q;
    MinUpdateQuery<int, int> seg;
    seg.set_by_vector(vector<int>(n, (1LL << 31) - 1));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rmq_and_ruq2() {
    int n, Q;
    cin >> n >> Q;
    MinmaxAffineQuery<int> seg;
    seg.set_by_vector(vector<ii>(n, {(1LL << 31) - 1, (1LL << 31) - 1}));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {0, x});
        } else {
            cout << seg.query(s, t).fi << endl;
        }
    }
}
void aoj_rsq_and_raq() {
    int n, Q;
    cin >> n >> Q;
    SumAddQuery<int, int> seg;
    seg.set_by_unit(n);
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        s--;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rsq_and_raq2() {
    int n, Q;
    cin >> n >> Q;
    SumAffineQuery<int> seg;
    seg.set_by_unit(n);
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        s--;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {1, x});
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rmq_and_raq() {
    int n, Q;
    cin >> n >> Q;
    MinAddQuery<int, int> seg;
    seg.set_by_vector(vector<int>(n));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rmq_and_raq2() {
    int n, Q;
    cin >> n >> Q;
    MinmaxAffineQuery<int> seg;
    seg.set_by_vector(vector<ii>(n));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {1, x});
        } else {
            cout << seg.query(s, t).fi << endl;
        }
    }
}
void aoj_rsq_and_ruq() {
    int n, Q;
    cin >> n >> Q;
    SumUpdateQuery<int, int> seg;
    seg.set_by_vector(vector<int>(n));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rsq_and_ruq2() {
    int n, Q;
    cin >> n >> Q;
    SumAffineQuery<int> seg;
    seg.set_by_unit(n);
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {0, x});
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}

signed main() {
    // aoj_rmq_and_ruq();
    // aoj_rmq_and_ruq2();
    // aoj_rsq_and_raq();
    // aoj_rsq_and_raq2();
    // aoj_rmq_and_raq();
    aoj_rmq_and_raq2();
    // aoj_rsq_and_ruq();
    // aoj_rsq_and_ruq2();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/DataStructure/LazySegmentTree.cpp"
#include <bits/stdc++.h>
#line 4 "test/DataStructure/LazySegmentTree.cpp"
using namespace std;
using namespace __gnu_pbds;
template <class T> using treap = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define REP(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj), rend(obj)
#define fi first
#define se second
using ii = pair<int, int>;
vector<ii> dirs = {
    {1, 0}, {0, 1},  {-1, 0},  {0, -1},  // 4方向
    {1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // 斜め
    {0, 0},                              // 自身
};
template <class T> inline bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class S> vector<T> make_vec(size_t n, S x) { return vector<T>(n, x); }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}

// debug
template <class T> ostream& operator<<(ostream& s, vector<T>& d) {
    REP(i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " ");
    return s;
}
template <class T> ostream& operator<<(ostream& s, vector<vector<T>>& d) {
    REP(i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n");
    return s;
}
template <class T, class S> ostream& operator<<(ostream& s, pair<T, S>& p) {
    s << "{" << p.first << ", " << p.second << "}";
    return s;
}
template <class T> ostream& operator<<(ostream& s, set<T> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
template <class T> ostream& operator<<(ostream& s, multiset<T> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
template <class T, class S> ostream& operator<<(ostream& s, map<T, S> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
template <class T, class S> ostream& operator<<(ostream& s, unordered_map<T, S> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        s << *it << (next(it) == m.end() ? "" : "\n");
    }
    return s;
}
#ifdef _MY_DEBUG
#define dump(...)                                                                                                     \
    cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), \
        cerr << "*/\n\n";
#else
#define dump(...)
#define endl "\n"
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) {
    cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...);
}

struct Fast {
    Fast() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
    }
} fast;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = 1000000007;
// *************** TEMPLATE END ***************

// T0: 元の配列のモノイド
// T1: T0に対する作用素モノイド
template <class T0, class T1> class BaseSegmentTree {
    // k番目のノードにのlazyを伝搬
    void eval(int k, int len) {
        // 定数倍高速化
        if (lazy[k] == u1) return;
        // len個分のlazy[k]を評価
        node[k] = g(node[k], p(lazy[k], len));
        if (k < N - 1) {
            // 最下段でなければ下のlazyに伝搬
            lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);
        }
        lazy[k] = u1;
    }
    // k番目のノード[l, r)について、[a, b)の範囲内にxを作用
    void update(int a, int b, T1 x, int k, int l, int r) {
        eval(k, r - l);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = f1(lazy[k], x);
            eval(k, r - l);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = f0(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    // k番目のノード[l, r)について、[a, b)のクエリを求める
    T0 query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return u0;
        eval(k, r - l);
        if (a <= l && r <= b) return node[k];
        T0 vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f0(vl, vr);
    }

public:
    int sz;  // 元の配列のサイズ
    int N;
    vector<T0> node;
    vector<T1> lazy;
    // T0上の演算、単位元
    virtual T0 f0(T0, T0) = 0;
    const T0 u0;
    // T1上の演算、単位元
    virtual T1 f1(T1, T1) = 0;
    const T1 u1;
    // T0に対するT1の作用
    virtual T0 g(T0, T1) = 0;
    // 多数のt1(T1)に対するf1の合成
    virtual T1 p(T1, int) = 0;

    BaseSegmentTree(T0 u0, T1 u1) : u0(u0), u1(u1) {}
    void set_by_vector(const vector<T0>& a) {
        sz = a.size();
        for (N = 1; N < sz; N *= 2)
            ;
        node.resize(2 * N - 1, u0);
        lazy.resize(2 * N - 1, u1);
        for (int i = 0; i < sz; i++) node[N - 1 + i] = a[i];
        for (int i = N - 2; i >= 0; i--) node[i] = f0(node[2 * i + 1], node[2 * i + 2]);
    }
    void set_by_unit(int n) {
        sz = n;
        for (N = 1; N < sz; N *= 2)
            ;
        node.resize(2 * N - 1, u0);
        lazy.resize(2 * N - 1, u1);
    }
    // [a, b)にxを作用
    void update(int a, int b, T1 x) {
        assert(0 <= a && a < b && b <= sz);
        update(a, b, x, 0, 0, N);
    }
    void update(int a, T1 x) { update(a, a + 1, x); }
    // [a, b)
    T0 query(int a, int b) { return query(a, b, 0, 0, N); }
    T0 query(int a) { return query(a, a + 1); }
};

template <class T0, class T1> struct MinUpdateQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr T0 _u0 = numeric_limits<T0>::max();
    static constexpr T1 _u1 = numeric_limits<T1>::min();
    MinUpdateQuery() : MinUpdateQuery(_u0, _u1) {}
    T0 f0(T0 x, T0 y) override { return min(x, y); }
    T1 f1(T1 x, T1 y) override { return y == _u1 ? x : y; }
    T0 g(T0 x, T1 y) override { return y == _u1 ? x : y; }
    T1 p(T1 x, int len) override { return x; }
};

template <class T0, class T1> struct SumAddQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    SumAddQuery() : SumAddQuery(0, 0) {}
    T0 f0(T0 x, T0 y) override { return x + y; }
    T1 f1(T1 x, T1 y) override { return x + y; }
    T0 g(T0 x, T1 y) override { return x + y; }
    T1 p(T1 x, int len) override { return x * len; }
};

template <class T0, class T1> struct MinAddQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr int _u0 = numeric_limits<T0>::max();
    MinAddQuery() : MinAddQuery(_u0, 0) {}
    T0 f0(T0 x, T0 y) override { return min(x, y); }
    T1 f1(T1 x, T1 y) override { return x + y; }
    T0 g(T0 x, T1 y) override { return x + y; }
    T1 p(T1 x, int len) override { return x; }
};

template <class T0, class T1> struct SumUpdateQuery : public BaseSegmentTree<T0, T1> {
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr int _u1 = numeric_limits<T1>::min();
    SumUpdateQuery() : SumUpdateQuery(0, _u1) {}
    T0 f0(T0 x, T0 y) override { return x + y; }
    T1 f1(T1 x, T1 y) override { return y == _u1 ? x : y; }
    T0 g(T0 x, T1 y) override { return y == _u1 ? x : y; }
    T1 p(T1 x, int len) override { return x == _u1 ? _u1 : x * len; }
};

template <class T0> struct SumAffineQuery : public BaseSegmentTree<T0, pair<T0, T0>> {
    using T1 = pair<T0, T0>;  // first * x + second
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr T1 _u1 = {1, 0};
    SumAffineQuery() : SumAffineQuery(0, {1, 0}) {}  // TODO: _u1を使うとコンパイル通らない原因不明
    T0 f0(T0 x, T0 y) override { return x + y; }
    T1 f1(T1 x, T1 y) override { return {x.first * y.first, x.second * y.first + y.second}; }
    T0 g(T0 x, T1 y) override { return y.first * x + y.second; }
    T1 p(T1 x, int len) override { return {x.first, x.second * len}; }
    // update(i, j, {a, b}); // [i, j)にax + bを作用
    // update(i, j, {0, a}); // update
    // update(i, j, {1, a}); // 加算
    // update(i, j, {a, 0}); // 倍
};

template <class T> struct MinmaxAffineQuery : public BaseSegmentTree<pair<T, T>, pair<T, T>> {
    using T0 = pair<T, T>;  // {min, max}
    using T1 = pair<T, T>;  // first * x + second
    using BaseSegmentTree<T0, T1>::BaseSegmentTree;
    static constexpr T0 get_u0() { return {numeric_limits<T>::max(), -numeric_limits<T>::max()}; }
    static constexpr T1 _u1 = {1, 0};
    MinmaxAffineQuery() : MinmaxAffineQuery(get_u0(), _u1) {}  // TODO: _u1を使うとコンパイル通らない原因不明
    T0 f0(T0 x, T0 y) override { return {min(x.first, y.first), max(x.second, y.second)}; }
    T1 f1(T1 x, T1 y) override { return {x.first * y.first, x.second * y.first + y.second}; }
    T0 g(T0 x, T1 y) override {
        T0 ret = {x.first * y.first + y.second, x.second * y.first + y.second};
        if (y.first < 0) swap(ret.first, ret.second);
        return ret;
    }
    T1 p(T1 x, int len) override { return x; }
    // update(i, j, {a, b}); // [i, j)にax + bを作用
    // update(i, j, {0, a}); // update
    // update(i, j, {1, a}); // 加算
    // update(i, j, {a, 0}); // 倍
};

void aoj_rmq_and_ruq() {
    int n, Q;
    cin >> n >> Q;
    MinUpdateQuery<int, int> seg;
    seg.set_by_vector(vector<int>(n, (1LL << 31) - 1));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rmq_and_ruq2() {
    int n, Q;
    cin >> n >> Q;
    MinmaxAffineQuery<int> seg;
    seg.set_by_vector(vector<ii>(n, {(1LL << 31) - 1, (1LL << 31) - 1}));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {0, x});
        } else {
            cout << seg.query(s, t).fi << endl;
        }
    }
}
void aoj_rsq_and_raq() {
    int n, Q;
    cin >> n >> Q;
    SumAddQuery<int, int> seg;
    seg.set_by_unit(n);
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        s--;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rsq_and_raq2() {
    int n, Q;
    cin >> n >> Q;
    SumAffineQuery<int> seg;
    seg.set_by_unit(n);
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        s--;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {1, x});
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rmq_and_raq() {
    int n, Q;
    cin >> n >> Q;
    MinAddQuery<int, int> seg;
    seg.set_by_vector(vector<int>(n));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rmq_and_raq2() {
    int n, Q;
    cin >> n >> Q;
    MinmaxAffineQuery<int> seg;
    seg.set_by_vector(vector<ii>(n));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {1, x});
        } else {
            cout << seg.query(s, t).fi << endl;
        }
    }
}
void aoj_rsq_and_ruq() {
    int n, Q;
    cin >> n >> Q;
    SumUpdateQuery<int, int> seg;
    seg.set_by_vector(vector<int>(n));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
void aoj_rsq_and_ruq2() {
    int n, Q;
    cin >> n >> Q;
    SumAffineQuery<int> seg;
    seg.set_by_unit(n);
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            int x;
            cin >> x;
            seg.update(s, t, {0, x});
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}

signed main() {
    // aoj_rmq_and_ruq();
    // aoj_rmq_and_ruq2();
    // aoj_rsq_and_raq();
    // aoj_rsq_and_raq2();
    // aoj_rmq_and_raq();
    aoj_rmq_and_raq2();
    // aoj_rsq_and_ruq();
    // aoj_rsq_and_ruq2();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

