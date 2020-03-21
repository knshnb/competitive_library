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


# :warning: src/DataStructure/SegmentTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-06 23:03:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T, class F> struct SegmentTree {
    const F op;
    const T e;
    SegmentTree(F op_, T e_) : op(op_), e(e_) {}
    int n;
    vector<T> t;
    void set_by_identity(int n_) {
        n = n_;
        t.clear(), t.resize(2 * n, e);
    }
    void set_by_vector(const vector<T>& a) {
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
    // iをaに変更
    void update(int i, const T& x) {
        assert(0 <= i && i < n);
        t[i += n] = x;
        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    friend string to_string(const SegmentTree<T, F>& seg) {
        return to_string(vector<T>(seg.t.begin() + seg.n, seg.t.end()));
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/SegmentTree.cpp"
template <class T, class F> struct SegmentTree {
    const F op;
    const T e;
    SegmentTree(F op_, T e_) : op(op_), e(e_) {}
    int n;
    vector<T> t;
    void set_by_identity(int n_) {
        n = n_;
        t.clear(), t.resize(2 * n, e);
    }
    void set_by_vector(const vector<T>& a) {
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
    // iをaに変更
    void update(int i, const T& x) {
        assert(0 <= i && i < n);
        t[i += n] = x;
        while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
    friend string to_string(const SegmentTree<T, F>& seg) {
        return to_string(vector<T>(seg.t.begin() + seg.n, seg.t.end()));
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

