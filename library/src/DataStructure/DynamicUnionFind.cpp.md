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


# :warning: src/DataStructure/DynamicUnionFind.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/DynamicUnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct DynamicUnionFind {
    unordered_map<int, int> number;
    // 頂点xが入っていなかったら追加
    struct Data {
        Data() {}
        void merge(Data& s) {
            // 自分で定義
        }
    };
    unordered_map<int, Data> data;

    int root(int x) {
        if (!number.count(x)) number[x] = -1;
        return number[x] < 0 ? x : number[x] = root(number[x]);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (number[y] < number[x]) swap(x, y);
        // yをxにマージ
        number[x] += number[y];
        number[y] = x;
        // dataのマージ方法に合わせて変える
        data[x].merge(data[y]);
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
    Data& ref(int x) { return data[root(x)]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/DynamicUnionFind.cpp"
struct DynamicUnionFind {
    unordered_map<int, int> number;
    // 頂点xが入っていなかったら追加
    struct Data {
        Data() {}
        void merge(Data& s) {
            // 自分で定義
        }
    };
    unordered_map<int, Data> data;

    int root(int x) {
        if (!number.count(x)) number[x] = -1;
        return number[x] < 0 ? x : number[x] = root(number[x]);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (number[y] < number[x]) swap(x, y);
        // yをxにマージ
        number[x] += number[y];
        number[y] = x;
        // dataのマージ方法に合わせて変える
        data[x].merge(data[y]);
    }
    bool is_same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -number[root(x)]; }
    Data& ref(int x) { return data[root(x)]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

