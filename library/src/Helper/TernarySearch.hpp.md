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


# :heavy_check_mark: src/Helper/TernarySearch.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1b49b634354b8edb1dc8ef8a73014950">src/Helper</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Helper/TernarySearch.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 16:56:39+09:00




## 概要
配列の長さが$2n$($n$は扱いたい範囲の要素数)でよいセグメント木。
実装方針の参考: https://codeforces.com/blog/entry/18051

## 使い方
### 変数
- `op(T a, T b) -> T`: T上のモノイド
- `e`: モノイドの単位元

### メソッド
- `query(int l, int r) -> T`: [l, r)の範囲のモノイドの合成を返す
- `update(int i, T x)`: $i$番目の要素を$x$に変更
- `operate(int i, T x)`: $i$番目の要素に$x$を作用

## 初期化例
- `Int`に対するmin
```cpp
auto seg_mi = make_segment_tree<Int>([](Int a, Int b) { return min(a, b); }, 1e18);
```

- `Int`に対するmax
```cpp
auto seg_ma = make_segment_tree<Int>([](Int a, Int b) { return max(a, b); }, -1e18);
```

- `Int`に対するmax
```cpp
auto seg_ma = make_segment_tree<Int>(std::plus<Int>(), -1e18);
```

- `Int`に対するAffine
```cpp
auto seg_affine = make_segment_tree<pair<Int, Int>>(
    [](pair<Int, Int> a, pair<Int, Int> b) -> pair<Int, Int> {
        return {a.first * b.first, b.first * a.second + b.second};
    },
    {1, 0});
```

## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1028.test.cpp.html">test/yukicoder/1028.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/DataStructure/SegmentTree.md
template <class F, class T = long long> T ternary_search(T l, T r, F f, bool is_max = true) {
    auto g = [&f, &is_max](T x) { return is_max ? f(x) : -f(x); };
    while (std::abs(l - r) > 2) {
        Int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (g(m1) < g(m2))
            l = m1;
        else
            r = m2;
    }
    // 極値のindexは[l, r)の範囲で、abs(l - r) <= 2になっている
    if (l + 1 < r && g(l + 1) > g(l)) l = l + 1;
    return l;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Helper/TernarySearch.hpp"
/// @docs src/DataStructure/SegmentTree.md
template <class F, class T = long long> T ternary_search(T l, T r, F f, bool is_max = true) {
    auto g = [&f, &is_max](T x) { return is_max ? f(x) : -f(x); };
    while (std::abs(l - r) > 2) {
        Int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (g(m1) < g(m2))
            l = m1;
        else
            r = m2;
    }
    // 極値のindexは[l, r)の範囲で、abs(l - r) <= 2になっている
    if (l + 1 < r && g(l + 1) > g(l)) l = l + 1;
    return l;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

