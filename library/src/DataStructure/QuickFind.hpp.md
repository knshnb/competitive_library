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


# :heavy_check_mark: src/DataStructure/QuickFind.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/QuickFind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 23:52:20+09:00




## 概要
素集合データ構造のマージを高速化するテクニック。
n要素の集合のマージを何度も行う際に、サイズの小さい方を大きい方にマージすることでのべ移動回数がO(n log n)回で抑えられる。
これは、各要素に注目すると、別の集合に移動されるたびに属する集合のサイズが2倍以上になるのでO(log n)回しか移動されないことからわかる。

データをマージする一般的なテク(通称、マージテク)とも呼ばれる。
名前はiwiwiさんのブログに由来するが、消えてしまった…。
アカデミア用語はWeighted-Union Heuristic。


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/unionfind_quick_find.test.cpp.html">test/yosupo/unionfind_quick_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/DataStructure/QuickFind.md
struct QuickFind {
    std::vector<int> belong_to;
    std::vector<std::vector<int>> groups;
    QuickFind(int n) : belong_to(n), groups(n, std::vector<int>(1)) {
        std::iota(belong_to.begin(), belong_to.end(), 0);
        for (int i = 0; i < n; i++) groups[i][0] = i;
    }
    void unite(int x, int y) {
        x = belong_to[x], y = belong_to[y];
        if (x == y) return;
        if (groups[x].size() < groups[y].size()) std::swap(x, y);
        // yをxにマージ
        for (int v : groups[y]) belong_to[v] = x;
        groups[x].insert(groups[x].end(), groups[y].begin(), groups[y].end());
        groups[y].clear();
    }
    bool is_same(int x, int y) { return belong_to[x] == belong_to[y]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/QuickFind.hpp"
/// @docs src/DataStructure/QuickFind.md
struct QuickFind {
    std::vector<int> belong_to;
    std::vector<std::vector<int>> groups;
    QuickFind(int n) : belong_to(n), groups(n, std::vector<int>(1)) {
        std::iota(belong_to.begin(), belong_to.end(), 0);
        for (int i = 0; i < n; i++) groups[i][0] = i;
    }
    void unite(int x, int y) {
        x = belong_to[x], y = belong_to[y];
        if (x == y) return;
        if (groups[x].size() < groups[y].size()) std::swap(x, y);
        // yをxにマージ
        for (int v : groups[y]) belong_to[v] = x;
        groups[x].insert(groups[x].end(), groups[y].begin(), groups[y].end());
        groups[y].clear();
    }
    bool is_same(int x, int y) { return belong_to[x] == belong_to[y]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

