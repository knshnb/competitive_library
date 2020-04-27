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


# :warning: src/old/ReversedBinaryIndexedTree.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/ReversedBinaryIndexedTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 00:07:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 0-indexed
class BinaryIndexedTree {
    int max_pow;  // N以下の最大の2べき
public:
    vector<int> bit;
    int N;
    BinaryIndexedTree(int n, int x = 0) : N(n), bit(n, x) {
        for (max_pow = 1; max_pow <= N / 2; max_pow *= 2)
            ;
    }
    BinaryIndexedTree(const vector<int>& a) : N(a.size()), bit(a) {
        for (max_pow = 1; max_pow <= N / 2; max_pow *= 2)
            ;
        REP(i, N - 1) if ((i | (i + 1)) < N) { bit[i | (i + 1)] += bit[i]; }
    }
    // k番目にxを加算
    void add(int k, int x) {
        for (int i = k; i < N; i |= i + 1) {
            bit[i] += x;
        }
    }

    // [0, k)、k == 0のときは0を返す
    int sum(int k) {
        int ret = 0;
        for (int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += bit[i];
        }
        return ret;
    }
    int sum() { return sum(N); }

    // [a, b)
    int query(int a, int b) {
        assert(a <= b);
        return sum(b) - sum(a);
    }
    int operator[](int k) { return query(k, k + 1); }

    // k番目をxに
    void update(int k, int x) { add(k, x - operator[](k)); }

    // 注: 中身が全て正のときしか動かない
    // sum(i + 1) >= xとなるような最小のi
    int lower_bound(int x) {
        int i = -1;
        for (int w = max_pow; w > 0; w /= 2) {
            if (i + w < N && bit[i + w] < x) {
                x -= bit[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) >= xとなるような最小のi
    int lower_bound(int begin, int x) {
        int lb = lower_bound(x + sum(begin));
        return max(begin, lb);
    }
    // sum(i + 1) > xとなるような最小のi
    int upper_bound(int x) {
        int i = -1;
        for (int w = max_pow; w > 0; w /= 2) {
            if (i + w < N && bit[i + w] <= x) {
                x -= bit[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) > xとなるような最小のi
    int upper_bound(int begin, int x) {
        int ub = upper_bound(x + sum(begin));
        return max(begin, ub);
    }
};

// 大きい方からlower_boundなどをしたいときのwrapper
// 政府逆転させて(-N, 0]にして、平行移動して[0, N)にしている
class ReversedBinaryIndexedTree : public BinaryIndexedTree {
public:
    using BinaryIndexedTree::BinaryIndexedTree;
    int rev(int k) { return N - 1 - k; }
    void add(int k, int x) { BinaryIndexedTree::add(rev(k), x); }
    // (k, N-1]
    int sum(int k) { return BinaryIndexedTree::sum(rev(k)); }
    // query(i - 1, N-1] >= xとなるような最大nのi
    int lower_bound(int x) { return rev(BinaryIndexedTree::lower_bound(x)); }
    // query(i - 1, N-1] > xとなるような最大nのi
    int upper_bound(int x) { return rev(BinaryIndexedTree::upper_bound(x)); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/ReversedBinaryIndexedTree.hpp"
// 0-indexed
class BinaryIndexedTree {
    int max_pow;  // N以下の最大の2べき
public:
    vector<int> bit;
    int N;
    BinaryIndexedTree(int n, int x = 0) : N(n), bit(n, x) {
        for (max_pow = 1; max_pow <= N / 2; max_pow *= 2)
            ;
    }
    BinaryIndexedTree(const vector<int>& a) : N(a.size()), bit(a) {
        for (max_pow = 1; max_pow <= N / 2; max_pow *= 2)
            ;
        REP(i, N - 1) if ((i | (i + 1)) < N) { bit[i | (i + 1)] += bit[i]; }
    }
    // k番目にxを加算
    void add(int k, int x) {
        for (int i = k; i < N; i |= i + 1) {
            bit[i] += x;
        }
    }

    // [0, k)、k == 0のときは0を返す
    int sum(int k) {
        int ret = 0;
        for (int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += bit[i];
        }
        return ret;
    }
    int sum() { return sum(N); }

    // [a, b)
    int query(int a, int b) {
        assert(a <= b);
        return sum(b) - sum(a);
    }
    int operator[](int k) { return query(k, k + 1); }

    // k番目をxに
    void update(int k, int x) { add(k, x - operator[](k)); }

    // 注: 中身が全て正のときしか動かない
    // sum(i + 1) >= xとなるような最小のi
    int lower_bound(int x) {
        int i = -1;
        for (int w = max_pow; w > 0; w /= 2) {
            if (i + w < N && bit[i + w] < x) {
                x -= bit[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) >= xとなるような最小のi
    int lower_bound(int begin, int x) {
        int lb = lower_bound(x + sum(begin));
        return max(begin, lb);
    }
    // sum(i + 1) > xとなるような最小のi
    int upper_bound(int x) {
        int i = -1;
        for (int w = max_pow; w > 0; w /= 2) {
            if (i + w < N && bit[i + w] <= x) {
                x -= bit[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) > xとなるような最小のi
    int upper_bound(int begin, int x) {
        int ub = upper_bound(x + sum(begin));
        return max(begin, ub);
    }
};

// 大きい方からlower_boundなどをしたいときのwrapper
// 政府逆転させて(-N, 0]にして、平行移動して[0, N)にしている
class ReversedBinaryIndexedTree : public BinaryIndexedTree {
public:
    using BinaryIndexedTree::BinaryIndexedTree;
    int rev(int k) { return N - 1 - k; }
    void add(int k, int x) { BinaryIndexedTree::add(rev(k), x); }
    // (k, N-1]
    int sum(int k) { return BinaryIndexedTree::sum(rev(k)); }
    // query(i - 1, N-1] >= xとなるような最大nのi
    int lower_bound(int x) { return rev(BinaryIndexedTree::lower_bound(x)); }
    // query(i - 1, N-1] > xとなるような最大nのi
    int upper_bound(int x) { return rev(BinaryIndexedTree::upper_bound(x)); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

