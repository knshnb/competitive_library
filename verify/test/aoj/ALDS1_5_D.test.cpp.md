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


# :heavy_check_mark: test/aoj/ALDS1_5_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_5_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-08 22:55:05+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/WaveletMatrix.hpp.html">src/DataStructure/WaveletMatrix.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Fri Aug  7 22:18:24 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/DataStructure/WaveletMatrix.hpp"
#undef CALL_FROM_TEST

signed main() {
    Int n;
    std::cin >> n;
    std::vector<int> a(n);
    REP(i, n) std::cin >> a[i];
    WaveletMatrix<int, 32> wm(a);

    Int ans1 = 0;
    REP(i, n) { ans1 += wm.rank_3way(a[i], 0, i)[2]; }
    Int ans2 = 0;
    REP(i, n) { ans2 += wm.rank_3way(a[i], i + 1, n)[0]; }
    assert(ans1 == ans2);
    std::cout << ans1 << std::endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_5_D.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Fri Aug  7 22:18:24 JST 2020
 **/

#define CALL_FROM_TEST
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

template <class T, int maxlog = 31, bool select_by_memo = false, class block_type = std::uint32_t>
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
    // [l, r)内の(小さい方から)j番目(0-index)の数
    int quantile(int l, int r, int j) {
        T ret = 0;
        for (int k = maxlog - 1; k >= 0; k--) {
            int zl = bvs[k].template rank<0>(l);
            int zr = bvs[k].template rank<0>(r);
            if (zr - zl > j) {  // kビット目は0
                l = zl;
                r = zr;
            } else {  // kビット目は1
                l = offset[k] + (l - zl);
                r = offset[k] + (r - zr);
                ret |= (T)1 << k;
                j -= zr - zl;
            }
        }
        return ret;
    }
};
#line 20 "test/aoj/ALDS1_5_D.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n;
    std::cin >> n;
    std::vector<int> a(n);
    REP(i, n) std::cin >> a[i];
    WaveletMatrix<int, 32> wm(a);

    Int ans1 = 0;
    REP(i, n) { ans1 += wm.rank_3way(a[i], 0, i)[2]; }
    Int ans2 = 0;
    REP(i, n) { ans2 += wm.rank_3way(a[i], i + 1, n)[0]; }
    assert(ans1 == ans2);
    std::cout << ans1 << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

