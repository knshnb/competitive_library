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


# :heavy_check_mark: src/DataStructure/SlidingWindowAggregation.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/SlidingWindowAggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 17:31:02+09:00




## 概要
モノイド列について、以下のクエリを全て償却O(1)で行える。

- `push`
- `pop`
- `fold_all`: 現在queueに入っている要素全ての合成

実際は半群に対して適用可能だが、実装の都合上モノイドにしている(半群には単位元を形式的に追加して使用できる)。

## 使用例
```c++
    auto swag = make_swag<Int>([](Int x, Int y) { return std::gcd(x, y); }, 0);
```

## メモ
stackを2つ用いてqueueを作る非常にシンプルなアルゴリズム。
償却計算量の凄さに感動した。
<br/>
参考: https://snuke.hatenablog.com/entry/2018/09/18/135640


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1036.test.cpp.html">test/yukicoder/1036.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/DataStructure/SlidingWindowAggregation.md
template <class T, class F> struct SlidingWindowAggregation {
    const F op;
    const T e;
    std::stack<std::pair<T, T>> st1, st2;  // それぞれ、{val, acc}を要素に持つような前方向と後ろ方向のstack
    SlidingWindowAggregation(F op_, T e_) : op(op_), e(e_) { st1.emplace(e, e), st2.emplace(e, e); }
    int size() { return st1.size() + st2.size() - 2; }
    void push(T x) {
        T acc = op(st2.top().second, x);
        st2.emplace(x, acc);
    }
    void pop() {
        assert(st1.size() > 1 || st2.size() > 1);
        if (st1.size() > 1) {
            st1.pop();
        } else {
            while (st2.size() > 2) {
                T acc = op(st1.top().second, st2.top().first);
                st1.emplace(st2.top().first, acc);
                st2.pop();
            }
            st2.pop();
        }
    }
    T fold_all() { return op(st1.top().second, st2.top().second); }
};
template <class T, class F> auto make_swag(F op, T e_) { return SlidingWindowAggregation<T, F>(op, e_); }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/SlidingWindowAggregation.hpp"
/// @docs src/DataStructure/SlidingWindowAggregation.md
template <class T, class F> struct SlidingWindowAggregation {
    const F op;
    const T e;
    std::stack<std::pair<T, T>> st1, st2;  // それぞれ、{val, acc}を要素に持つような前方向と後ろ方向のstack
    SlidingWindowAggregation(F op_, T e_) : op(op_), e(e_) { st1.emplace(e, e), st2.emplace(e, e); }
    int size() { return st1.size() + st2.size() - 2; }
    void push(T x) {
        T acc = op(st2.top().second, x);
        st2.emplace(x, acc);
    }
    void pop() {
        assert(st1.size() > 1 || st2.size() > 1);
        if (st1.size() > 1) {
            st1.pop();
        } else {
            while (st2.size() > 2) {
                T acc = op(st1.top().second, st2.top().first);
                st1.emplace(st2.top().first, acc);
                st2.pop();
            }
            st2.pop();
        }
    }
    T fold_all() { return op(st1.top().second, st2.top().second); }
};
template <class T, class F> auto make_swag(F op, T e_) { return SlidingWindowAggregation<T, F>(op, e_); }

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

