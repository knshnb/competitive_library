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


# :heavy_check_mark: src/String/RollingHash.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac276d2326c527c8c7dbcbb63d85c6c7">src/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/String/RollingHash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-06 03:23:38+09:00




## 概要
文字列を多項式と捉えて、適当なmod,baseでhash化。
Sを与えて事前計算しておけば、S[l, r)のhashがO(1)で取得できる。
具体的には、各iについて
`hash[0, i) = S[0] * base^(i-1) + S[1] * base^(i-2) + ... + S[i-1] * base^0`
を計算しておくと、
`hash[l, r) = hash[0, r) - hash[0, l) * base^(r-1)`
となる。

衝突率を下げるため、modを素数に固定しbaseをいくつか乱択し、全てが一致するか確認している。
文字列の中で先頭の0の個数のみがちがうもの(00032と032など)は区別できないので注意！適当な定数を足す必要あり。

参考: Rolling Hashの衝突確率について(https://maspypy.com/rolling-hash%e3%81%ab%e3%81%a4%e3%81%84%e3%81%a6%ef%bc%88survey-%e7%a0%94%e7%a9%b6%ef%bc%89)


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/zalgorithm_rolling_hash.test.cpp.html">test/yosupo/zalgorithm_rolling_hash.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

