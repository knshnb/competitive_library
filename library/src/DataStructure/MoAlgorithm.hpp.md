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


# :warning: src/DataStructure/MoAlgorithm.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/MoAlgorithm.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-03 01:22:03+09:00




## 概要
配列に対するオフライン区間クエリを扱うテクニック。
計算量O((N + Q) sqrt(N))。

## 参考
https://ei1333.hateblo.jp/entry/2017/09/11/211011


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/DataStructure/MoAlgorithm.md
struct Mo {
    struct Query {
        int l, r, idx;  // 配列に対する[l, r)のクエリ, idxはクエリの番号
        Query(int l_, int r_, int idx_) : l(l_), r(r_), idx(idx_) {}
    };
    int width;
    std::vector<Query> query;
    std::vector<bool> v;

    // widthは指定しないと自動でsqrt(n)にする
    Mo(int n, int width_ = -1) : width(width == -1 ? (int)sqrt(n) : width_), v(n) {}
    void add(int l, int r) {
        int idx = query.size();
        query.emplace_back(l, r, idx);
    }
    template <class F, class G, class H> void run(const F& add, const G& del, const H& rem) {
        std::sort(query.begin(), query.end(), [&](const Query& a, const Query& b) {
            int ablock = a.l / width, bblock = b.l / width;
            if (ablock != bblock) return ablock < bblock;
            if (ablock & 1) return a.r < b.r;
            return a.r > b.r;
        });
        int nl = 0, nr = 0;
        auto push = [&](int idx) {
            v[idx].flip();
            if (v[idx])
                add(idx);
            else
                del(idx);
        };
        for (Query& q : query) {
            while (nl > q.l) push(--nl);
            while (nr < q.r) push(nr++);
            while (nl < q.l) push(nl++);
            while (nr > q.r) push(--nr);
            rem(q.idx);
            while (nl > q.l) push(--nl);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/MoAlgorithm.hpp"
/// @docs src/DataStructure/MoAlgorithm.md
struct Mo {
    struct Query {
        int l, r, idx;  // 配列に対する[l, r)のクエリ, idxはクエリの番号
        Query(int l_, int r_, int idx_) : l(l_), r(r_), idx(idx_) {}
    };
    int width;
    std::vector<Query> query;
    std::vector<bool> v;

    // widthは指定しないと自動でsqrt(n)にする
    Mo(int n, int width_ = -1) : width(width == -1 ? (int)sqrt(n) : width_), v(n) {}
    void add(int l, int r) {
        int idx = query.size();
        query.emplace_back(l, r, idx);
    }
    template <class F, class G, class H> void run(const F& add, const G& del, const H& rem) {
        std::sort(query.begin(), query.end(), [&](const Query& a, const Query& b) {
            int ablock = a.l / width, bblock = b.l / width;
            if (ablock != bblock) return ablock < bblock;
            if (ablock & 1) return a.r < b.r;
            return a.r > b.r;
        });
        int nl = 0, nr = 0;
        auto push = [&](int idx) {
            v[idx].flip();
            if (v[idx])
                add(idx);
            else
                del(idx);
        };
        for (Query& q : query) {
            while (nl > q.l) push(--nl);
            while (nr < q.r) push(nr++);
            while (nl < q.l) push(nl++);
            while (nr > q.r) push(--nr);
            rem(q.idx);
            while (nl > q.l) push(--nl);
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

