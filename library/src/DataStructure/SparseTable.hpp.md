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


# :heavy_check_mark: src/DataStructure/SparseTable.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/SparseTable.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-13 00:16:00+09:00




## 概要
冪等性を持つモノイドについて、区間畳み込みを高速に計算する。
構築O(n log n), クエリO(1)

## アルゴリズム
構築時には各点から始まるダブリングを計算。
クエリ時には、始点と終点からそれぞれ最も長い計算済みの区間を持ってきて(これはMSBから求まる)、2つの合成を求める。
2つの区間にはかぶりが生じるが、冪等性を仮定していることから正しい答えが求まることが保証される。


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/staticrmq_sparse_table.test.cpp.html">test/yosupo/staticrmq_sparse_table.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/SparseTable.hpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

