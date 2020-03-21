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


# :warning: src/DataStructure/Doubling.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/Doubling.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Doubling {
    int n;
    int size;                  // MSB + 1
    vector<vector<int>> next;  // next[k][i]: iから(1<<k)回でどこまで進めるか

    // edge[i]: 1回でiからどこまで進めるか
    Doubling(vector<int>& edge) : n(edge.size()), size(64 - __builtin_clzll(edge.size())) {
        next.resize(size, vector<int>(n + 1, n));
        for (int i = 0; i < n; i++) next[0][i] = edge[i];
        for (int k = 0; k < size - 1; k++) {
            for (int i = 0; i < n; i++) {
                next[k + 1][i] = next[k][next[k][i]];
            }
        }
    }
    // i番目のx個先
    int get(int i, int x) {
        int ret = i;
        for (int bit = 0; bit < size; bit++) {
            if (!(x >> bit & 1)) continue;
            ret = next[bit][ret];
        }
        return ret;
    }
    // iからはじめて何回進めば初めてj以上になるか
    // j以上になりえないときはnを返す
    int lower_bound(int i, int j) {
        int cur = i, acc = 0;
        for (int wid = size - 1; wid >= 0; wid--) {
            if (next[wid][cur] < j) {
                acc += 1LL << wid;
                cur = next[wid][cur];
            }
        }
        return min(n, acc + 1);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/Doubling.cpp"
struct Doubling {
    int n;
    int size;                  // MSB + 1
    vector<vector<int>> next;  // next[k][i]: iから(1<<k)回でどこまで進めるか

    // edge[i]: 1回でiからどこまで進めるか
    Doubling(vector<int>& edge) : n(edge.size()), size(64 - __builtin_clzll(edge.size())) {
        next.resize(size, vector<int>(n + 1, n));
        for (int i = 0; i < n; i++) next[0][i] = edge[i];
        for (int k = 0; k < size - 1; k++) {
            for (int i = 0; i < n; i++) {
                next[k + 1][i] = next[k][next[k][i]];
            }
        }
    }
    // i番目のx個先
    int get(int i, int x) {
        int ret = i;
        for (int bit = 0; bit < size; bit++) {
            if (!(x >> bit & 1)) continue;
            ret = next[bit][ret];
        }
        return ret;
    }
    // iからはじめて何回進めば初めてj以上になるか
    // j以上になりえないときはnを返す
    int lower_bound(int i, int j) {
        int cur = i, acc = 0;
        for (int wid = size - 1; wid >= 0; wid--) {
            if (next[wid][cur] < j) {
                acc += 1LL << wid;
                cur = next[wid][cur];
            }
        }
        return min(n, acc + 1);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

