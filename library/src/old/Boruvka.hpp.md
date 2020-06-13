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


# :warning: src/old/Boruvka.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/Boruvka.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 20:39:55+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// F(現在の木の個数, vector<頂点->集合のindex>) -> vector<集合のindex->(cost, to)>
// 使い方: https://codeforces.com/contest/1242/submission/64467604
template <class T, class F> T boruvka(int n, const F& f) {
    struct UnionFind {
        vector<int> number;  // 0以上のとき親のindex, 負のときは集合サイズ
        UnionFind(int n) : number(n, -1) {}
        int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]); }
        bool unite(int x, int y) {
            x = root(x), y = root(y);
            if (x == y) return false;
            if (number[y] < number[x]) swap(x, y);
            number[x] += number[y];
            number[y] = x;
            return true;
        }
    };

    UnionFind uf(n);
    T res(0);
    bool update = true;
    vector<int> belongs(n), rev(n);
    while (update) {
        update = false;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (i == uf.root(i)) rev[ptr] = i, belongs[i] = ptr++;
        }
        for (int i = 0; i < n; i++) belongs[i] = belongs[uf.root(i)];
        vector<pair<T, int>> v = f(ptr, belongs);
        for (int i = 0; i < ptr; i++) {
            if (v[i].second >= 0 && uf.unite(rev[i], rev[v[i].second])) res += v[i].first, update = true;
        }
        if (!update) break;
    }
    return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/Boruvka.hpp"
// F(現在の木の個数, vector<頂点->集合のindex>) -> vector<集合のindex->(cost, to)>
// 使い方: https://codeforces.com/contest/1242/submission/64467604
template <class T, class F> T boruvka(int n, const F& f) {
    struct UnionFind {
        vector<int> number;  // 0以上のとき親のindex, 負のときは集合サイズ
        UnionFind(int n) : number(n, -1) {}
        int root(int x) { return number[x] < 0 ? x : number[x] = root(number[x]); }
        bool unite(int x, int y) {
            x = root(x), y = root(y);
            if (x == y) return false;
            if (number[y] < number[x]) swap(x, y);
            number[x] += number[y];
            number[y] = x;
            return true;
        }
    };

    UnionFind uf(n);
    T res(0);
    bool update = true;
    vector<int> belongs(n), rev(n);
    while (update) {
        update = false;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (i == uf.root(i)) rev[ptr] = i, belongs[i] = ptr++;
        }
        for (int i = 0; i < n; i++) belongs[i] = belongs[uf.root(i)];
        vector<pair<T, int>> v = f(ptr, belongs);
        for (int i = 0; i < ptr; i++) {
            if (v[i].second >= 0 && uf.unite(rev[i], rev[v[i].second])) res += v[i].first, update = true;
        }
        if (!update) break;
    }
    return res;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

