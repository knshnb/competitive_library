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


# :heavy_check_mark: test/yosupo/zalgorithm_rolling_hash.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/zalgorithm_rolling_hash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-06 03:23:38+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/String/RollingHash.hpp.html">src/String/RollingHash.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Apr  5 20:03:46 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/String/RollingHash.hpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    Int n = s.size();
    MultiRollingHash rh(s);
    REP(i, n) {
        auto check = [&](Int mid) -> bool {
            return rh.get(0, mid) == rh.get(i, i + mid);
        };
        Int ok = 0, ng = n - i + 1;
        while (std::abs(ok - ng) > 1) {
            Int mid = (ok + ng) / 2;
            (check(mid) ? ok : ng) = mid;
        }
        std::cout << ok << " ";
    }
    std::cout << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/zalgorithm_rolling_hash.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Apr  5 20:03:46 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/String/RollingHash.hpp"
/// @docs src/String/RollingHash.md
template <class T> struct RollingHash {
    std::vector<int> hash, pows;
    int base, mod;
    RollingHash(const T &a, int base_, int mod_ = 1000000009)
        : hash(a.size() + 1), pows(a.size() + 1, 1), base(base_), mod(mod_) {
        for (int i = 0; i < a.size(); i++) {
            pows[i + 1] = (long long)pows[i] * base % mod;
            hash[i + 1] = ((long long)hash[i] * base % mod + a[i]) % mod;
            if (hash[i + 1] < 0) hash[i + 1] += mod;
        }
    }
    // 現在の文字列のサイズ
    int size() { return hash.size() - 1; }
    // [l, r)
    int get(int l, int r) {
        assert(l <= r);
        int ret = hash[r] + mod - (long long)hash[l] * pows[r - l] % mod;
        if (ret >= mod) ret -= mod;
        return ret;
    }
    void concat(const T &b) {
        int n = hash.size() - 1, m = b.size();
        pows.resize(n + m + 1);
        hash.resize(n + m + 1);
        for (int i = 0; i < m; i++) {
            pows[n + i + 1] = (long long)pows[n + i] * base % mod;
            hash[n + i + 1] = (long long)hash[n + i] * base % mod + b[i];
            if (hash[n + i + 1] >= mod) hash[n + i + 1] -= mod;
        }
    }
    void pop_back() {
        hash.pop_back();
        pows.pop_back();
    }
};

template <int HashNum> std::array<int, HashNum> make_rand_array() {
    std::array<int, HashNum> res;
    std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < HashNum; i++) res[i] = rnd() % 1000000;
    return res;
}
template <class T, int HashNum = 4> struct MultiRollingHash {
    using multihash_t = std::array<int, HashNum>;
    static std::array<int, HashNum> bases;
    std::vector<RollingHash<T>> rhs;
    MultiRollingHash(const T &a) {
        for (int i = 0; i < HashNum; i++) {
            rhs.push_back(RollingHash<T>(a, bases[i]));
        }
    }
    multihash_t get(int l, int r) {
        multihash_t ret;
        for (int i = 0; i < HashNum; i++) ret[i] = rhs[i].get(l, r);
        return ret;
    }
    int size() { return rhs[0].size(); }
    void concat(const T &b) {
        for (auto &rh : rhs) rh.concat(b);
    }
    void pop_back() {
        for (auto &rh : rhs) rh.pop_back();
    }
};
template <class T, int HashNum>
std::array<int, HashNum> MultiRollingHash<T, HashNum>::bases = make_rand_array<HashNum>();
#line 19 "test/yosupo/zalgorithm_rolling_hash.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    Int n = s.size();
    MultiRollingHash rh(s);
    REP(i, n) {
        auto check = [&](Int mid) -> bool {
            return rh.get(0, mid) == rh.get(i, i + mid);
        };
        Int ok = 0, ng = n - i + 1;
        while (std::abs(ok - ng) > 1) {
            Int mid = (ok + ng) / 2;
            (check(mid) ? ok : ng) = mid;
        }
        std::cout << ok << " ";
    }
    std::cout << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

