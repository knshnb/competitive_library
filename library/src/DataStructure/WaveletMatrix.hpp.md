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


# :heavy_check_mark: src/DataStructure/WaveletMatrix.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e73c6b5872115ad0f2896f8e8476ef39">src/DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/WaveletMatrix.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 22:45:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_5_D.test.cpp.html">test/aoj/ALDS1_5_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int popcount(std::uint32_t x) { return __builtin_popcount(x); }
int popcount(std::uint64_t x) { return __builtin_popcountll(x); }

template <bool select_by_memo = false, class block_type = std::uint32_t> struct BitVector {
    static constexpr int b = sizeof(block_type) * CHAR_BIT;  // blockのサイズ
    int n;
    std::vector<block_type> bit;
    std::vector<int> acc;
    BitVector() {}
    BitVector(int n_) : n(n_), bit(n / b + 1), acc(n / b + 1) {}
    void set(int i, bool x) {
        if (x)
            bit[i / b] |= (block_type)1 << (i % b);
        else
            bit[i / b] &= ~((block_type)1 << (i % b));
    }
    void build() {
        for (int i = 0; i < (int)acc.size() - 1; i++) {
            acc[i + 1] = acc[i] + popcount(bit[i]);
        }
    }
    // [0, i)内のxの個数
    template <bool x> int rank(int i) {
        if (x)
            return acc[i / b] + (i % b ? popcount(bit[i / b] << (b - i % b)) : 0);
        else
            return i - rank<true>(i);
    }
    // j番目のxのindex
    int select(int j, bool x) {
        int ok = n, ng = -1;
        while (std::abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            (rank(mid + 1, x) > j ? ok : ng) = mid;
        }
        return ok;
    }
};

template <class T, int maxlog = 32, bool select_by_memo = false, class block_type = std::uint32_t>
struct WaveletMatrix {
    using bv_type = BitVector<select_by_memo, block_type>;
    std::array<bv_type, maxlog> bvs;      // [maxlog, n]の01行列
    std::array<int, maxlog> offset = {};  // 各列でbitが0になっている要素の数

    WaveletMatrix(const std::vector<T>& a) {
        std::vector<T> cur_data = a;
        for (int k = maxlog - 1; k >= 0; k--) {  // 上位bitから見る
            std::vector<T> zero, one;
            bvs[k] = bv_type(a.size());
            for (int i = 0; i < a.size(); i++) {
                bool bit = cur_data[i] >> k & 1;
                if (bit)
                    one.push_back(cur_data[i]), bvs[k].set(i, 1);
                else
                    zero.push_back(cur_data[i]);
            }
            offset[k] = zero.size();
            cur_data = std::move(zero);
            cur_data.insert(cur_data.end(), one.begin(), one.end());
            bvs[k].build();
        }
    }
    // [l, r)の{x未満の個数, xの個数, xより大の個数}
    std::array<int, 3> rank_3way(int x, int l, int r) {
        int lt = 0, eq = r - l, gt = 0;
        for (int k = maxlog - 1; k >= 0; k--) {
            int prv_num = r - l;
            if (x >> k & 1) {
                l = offset[k] + bvs[k].template rank<1>(l);
                r = offset[k] + bvs[k].template rank<1>(r);
                lt += prv_num - (r - l);
            } else {
                l = bvs[k].template rank<0>(l);
                r = bvs[k].template rank<0>(r);
                gt += prv_num - (r - l);
            }
            eq -= prv_num - (r - l);
        }
        return {lt, eq, gt};
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/WaveletMatrix.hpp"
int popcount(std::uint32_t x) { return __builtin_popcount(x); }
int popcount(std::uint64_t x) { return __builtin_popcountll(x); }

template <bool select_by_memo = false, class block_type = std::uint32_t> struct BitVector {
    static constexpr int b = sizeof(block_type) * CHAR_BIT;  // blockのサイズ
    int n;
    std::vector<block_type> bit;
    std::vector<int> acc;
    BitVector() {}
    BitVector(int n_) : n(n_), bit(n / b + 1), acc(n / b + 1) {}
    void set(int i, bool x) {
        if (x)
            bit[i / b] |= (block_type)1 << (i % b);
        else
            bit[i / b] &= ~((block_type)1 << (i % b));
    }
    void build() {
        for (int i = 0; i < (int)acc.size() - 1; i++) {
            acc[i + 1] = acc[i] + popcount(bit[i]);
        }
    }
    // [0, i)内のxの個数
    template <bool x> int rank(int i) {
        if (x)
            return acc[i / b] + (i % b ? popcount(bit[i / b] << (b - i % b)) : 0);
        else
            return i - rank<true>(i);
    }
    // j番目のxのindex
    int select(int j, bool x) {
        int ok = n, ng = -1;
        while (std::abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            (rank(mid + 1, x) > j ? ok : ng) = mid;
        }
        return ok;
    }
};

template <class T, int maxlog = 32, bool select_by_memo = false, class block_type = std::uint32_t>
struct WaveletMatrix {
    using bv_type = BitVector<select_by_memo, block_type>;
    std::array<bv_type, maxlog> bvs;      // [maxlog, n]の01行列
    std::array<int, maxlog> offset = {};  // 各列でbitが0になっている要素の数

    WaveletMatrix(const std::vector<T>& a) {
        std::vector<T> cur_data = a;
        for (int k = maxlog - 1; k >= 0; k--) {  // 上位bitから見る
            std::vector<T> zero, one;
            bvs[k] = bv_type(a.size());
            for (int i = 0; i < a.size(); i++) {
                bool bit = cur_data[i] >> k & 1;
                if (bit)
                    one.push_back(cur_data[i]), bvs[k].set(i, 1);
                else
                    zero.push_back(cur_data[i]);
            }
            offset[k] = zero.size();
            cur_data = std::move(zero);
            cur_data.insert(cur_data.end(), one.begin(), one.end());
            bvs[k].build();
        }
    }
    // [l, r)の{x未満の個数, xの個数, xより大の個数}
    std::array<int, 3> rank_3way(int x, int l, int r) {
        int lt = 0, eq = r - l, gt = 0;
        for (int k = maxlog - 1; k >= 0; k--) {
            int prv_num = r - l;
            if (x >> k & 1) {
                l = offset[k] + bvs[k].template rank<1>(l);
                r = offset[k] + bvs[k].template rank<1>(r);
                lt += prv_num - (r - l);
            } else {
                l = bvs[k].template rank<0>(l);
                r = bvs[k].template rank<0>(r);
                gt += prv_num - (r - l);
            }
            eq -= prv_num - (r - l);
        }
        return {lt, eq, gt};
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

