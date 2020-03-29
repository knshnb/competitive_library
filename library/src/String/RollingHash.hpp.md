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


# :warning: src/String/RollingHash.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac276d2326c527c8c7dbcbb63d85c6c7">src/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/String/RollingHash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
using ull = unsigned long long;
template <class T> struct RollingHash {
    vector<ull> hash, pows;
    ull base, mod;
    RollingHash(const T &a, ull base, ull mod = 1000000009)
        : hash(a.size() + 1), pows(a.size() + 1, 1), mod(mod), base(base) {
        for (int i = 0; i < a.size(); i++) {
            pows[i + 1] = pows[i] * base % mod;
            hash[i + 1] = hash[i] * base % mod + a[i];
            if (hash[i + 1] >= mod) hash[i + 1] -= mod;
        }
    }
    // 現在の文字列のサイズ
    int size() { return hash.size() - 1; }
    // [l, r)
    ull get(int l, int r) {
        assert(l <= r);
        ull ret = hash[r] + mod - hash[l] * pows[r - l] % mod;
        if (ret >= mod) ret -= mod;
        return ret;
    }
    void concat(const T &b) {
        int n = hash.size() - 1, m = b.size();
        pows.resize(n + m + 1);
        hash.resize(n + m + 1);
        for (int i = 0; i < m; i++) {
            pows[n + i + 1] = pows[n + i] * base % mod;
            hash[n + i + 1] = hash[n + i] * base % mod + b[i];
            if (hash[n + i + 1] >= mod) hash[n + i + 1] -= mod;
        }
    }
    void pop_back() {
        hash.pop_back();
        pows.pop_back();
    }
};

constexpr int HASH_NUM = 4;
struct bases_t {
    int use[HASH_NUM];
    int &operator[](int i) { return use[i]; }
    bases_t() {
        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
        for (int i = 0; i < HASH_NUM; i++) use[i] = rnd() % 10000;
    }
} bases;

using multihash_t = array<int, HASH_NUM>;
template <class T = vector<int>> struct MultiRollingHash {
    vector<RollingHash<T>> rhs;
    MultiRollingHash(const T &a) {
        for (int i = 0; i < HASH_NUM; i++) {
            rhs.push_back(RollingHash<T>(a, bases[i]));
        }
    }
    multihash_t get(int l, int r) {
        multihash_t ret;
        for (int i = 0; i < HASH_NUM; i++) ret[i] = rhs[i].get(l, r);
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/String/RollingHash.hpp"
using ull = unsigned long long;
template <class T> struct RollingHash {
    vector<ull> hash, pows;
    ull base, mod;
    RollingHash(const T &a, ull base, ull mod = 1000000009)
        : hash(a.size() + 1), pows(a.size() + 1, 1), mod(mod), base(base) {
        for (int i = 0; i < a.size(); i++) {
            pows[i + 1] = pows[i] * base % mod;
            hash[i + 1] = hash[i] * base % mod + a[i];
            if (hash[i + 1] >= mod) hash[i + 1] -= mod;
        }
    }
    // 現在の文字列のサイズ
    int size() { return hash.size() - 1; }
    // [l, r)
    ull get(int l, int r) {
        assert(l <= r);
        ull ret = hash[r] + mod - hash[l] * pows[r - l] % mod;
        if (ret >= mod) ret -= mod;
        return ret;
    }
    void concat(const T &b) {
        int n = hash.size() - 1, m = b.size();
        pows.resize(n + m + 1);
        hash.resize(n + m + 1);
        for (int i = 0; i < m; i++) {
            pows[n + i + 1] = pows[n + i] * base % mod;
            hash[n + i + 1] = hash[n + i] * base % mod + b[i];
            if (hash[n + i + 1] >= mod) hash[n + i + 1] -= mod;
        }
    }
    void pop_back() {
        hash.pop_back();
        pows.pop_back();
    }
};

constexpr int HASH_NUM = 4;
struct bases_t {
    int use[HASH_NUM];
    int &operator[](int i) { return use[i]; }
    bases_t() {
        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
        for (int i = 0; i < HASH_NUM; i++) use[i] = rnd() % 10000;
    }
} bases;

using multihash_t = array<int, HASH_NUM>;
template <class T = vector<int>> struct MultiRollingHash {
    vector<RollingHash<T>> rhs;
    MultiRollingHash(const T &a) {
        for (int i = 0; i < HASH_NUM; i++) {
            rhs.push_back(RollingHash<T>(a, bases[i]));
        }
    }
    multihash_t get(int l, int r) {
        multihash_t ret;
        for (int i = 0; i < HASH_NUM; i++) ret[i] = rhs[i].get(l, r);
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

