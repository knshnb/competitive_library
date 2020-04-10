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


# :heavy_check_mark: test/yosupo/suffixarray.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/suffixarray.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-10 21:10:59+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/String/SuffixArray.hpp.html">src/String/SuffixArray.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

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
 *    created: Thu Apr  9 23:40:03 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/String/SuffixArray.hpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    SuffixArray sa(s);
    for (int x : sa.sa) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/suffixarray.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

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
 *    created: Thu Apr  9 23:40:03 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/String/SuffixArray.hpp"
/// @docs src/String/SuffixArray.md
class SuffixArray {
    std::vector<int> sa_is(const std::vector<int>& str, const int k) {
        const int n = str.size();
        std::vector<bool> is_S(n);
        is_S[n - 1] = true;
        std::vector<bool> is_LMS(n);
        std::vector<int> LMSs;
        for (int i = n - 2; i >= 0; i--) {
            is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            if (is_S[i] & (i == 0 || !is_S[i - 1])) {
                is_LMS[i] = true;
                LMSs.push_back(i);
            }
        }
        std::vector<int> pseudo_sa = induced_sort(str, LMSs, is_S, k);
        std::vector<int> orderedLMSs(LMSs.size());
        int index = 0;
        for (int x : pseudo_sa) {
            if (is_LMS[x]) {
                orderedLMSs[index++] = x;
            }
        }
        pseudo_sa[orderedLMSs[0]] = 0;
        int rank = 0;
        if (orderedLMSs.size() > 1) {
            pseudo_sa[orderedLMSs[1]] = ++rank;
        }
        for (int i =  1; i < orderedLMSs.size() - 1; i++) {
            bool is_diff = false;
            for (int j = 0; j < n; j++) {
                int p = orderedLMSs[i] + j;
                int q = orderedLMSs[i + 1] + j;
                if (str[p] != str[q] || is_LMS[p] != is_LMS[q]) {
                    is_diff = true;
                    break;
                }
                if (j > 0 && is_LMS[p]) {
                    break;
                }
            }
            pseudo_sa[orderedLMSs[i + 1]] = is_diff ? ++rank : rank;
        }
        std::vector<int> new_str(LMSs.size());
        index = 0;
        for (int i = 0; i < n; i++) {
            if (is_LMS[i]) {
                new_str[index++] = pseudo_sa[i];
            }
        }
        std::vector<int> LMS_sa;
        if (rank + 1 == LMSs.size()) {
            LMS_sa = orderedLMSs;
        } else {
            LMS_sa = sa_is(new_str, rank + 1);
            for (int& x : LMS_sa) {
                x = LMSs[x];
            }
        }
        return induced_sort(str, LMS_sa, is_S, k);
    }

    std::vector<int> induced_sort(const std::vector<int>& str, const std::vector<int>& LMSs, const std::vector<bool>& is_S, const int k) {
        int n = str.size();
        std::vector<int> buckets(n);
        std::vector<int> chars(k + 1);
        for (int c : str) {
            chars[c + 1]++;
        }
        for (int i = 0; i < k; i++) { chars[i + 1] += chars[i]; }
        std::vector<int> count(k);
        for (int i = LMSs.size() - 1; i >= 0; i--) {
            int c = str[LMSs[i]];
            buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];
        }
        count = std::vector<int>(k);
        for (int i = 0; i < n; i++) {
            if (buckets[i] == 0 || is_S[buckets[i] - 1]) {
                continue;
            }
            int c = str[buckets[i] - 1];
            buckets[chars[c] + count[c]++] = buckets[i] - 1;
        }
        count = std::vector<int>(k);
        for (int i = n - 1; i >= 0; i--) {
            if (buckets[i] == 0 || !is_S[buckets[i] - 1]) {
                continue;
            }
            int c = str[buckets[i] - 1];
            buckets[chars[c + 1] - 1 - count[c]++] = buckets[i] - 1;
        }
        return buckets;
    }

public:
    std::string S;
    int N;
    std::vector<int> sa;  // sa[i]: suffixが辞書順i番目となる開始位置のindex
    SuffixArray(std::string str_in) : S(str_in), N(str_in.size()) {
        str_in += "$";
        std::vector<int> str(N + 1);
        for (int i = 0; i < N + 1; i++) { str[i] = str_in[i] - '$'; }
        sa = sa_is(str, 128);
        sa.erase(sa.begin());
    }
    int operator[](int index) { return sa[index]; }

    // sizeがTと等しく初めてT以上になるようなSの部分文字列(sa)
    std::vector<int>::iterator lower_bound(std::string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sa[mid], T.size(), T) < 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sa.begin() + r;
    }

    // sizeがTと等しく初めてTより大きくなるようなSの部分文字列(sa)
    std::vector<int>::iterator upper_bound(std::string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sa[mid], T.size(), T) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sa.begin() + r;
    }

    // S2が部分文字列として何回出現するか
    int count(std::string S2) { return upper_bound(S2) - lower_bound(S2); }
};
#line 19 "test/yosupo/suffixarray.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    std::string s;
    std::cin >> s;
    SuffixArray sa(s);
    for (int x : sa.sa) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

