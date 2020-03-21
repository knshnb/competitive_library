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


# :warning: src/String/SuffixArray.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac276d2326c527c8c7dbcbb63d85c6c7">src/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/String/SuffixArray.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// SA-ISによるSuffix Arrayの実装。構築O(N)
class SuffixArray {
    vector<int> sa_is(const vector<int>& str, const int k) {
        const int n = str.size();
        vector<bool> is_S(n);
        is_S[n - 1] = true;
        vector<bool> is_LMS(n);
        vector<int> LMSs;
        for (int i = n - 2; i >= 0; i--) {
            is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);
        }
        REP(i, n) {
            if (is_S[i] & (i == 0 || !is_S[i - 1])) {
                is_LMS[i] = true;
                LMSs.push_back(i);
            }
        }
        vector<int> pseudo_sa = induced_sort(str, LMSs, is_S, k);
        vector<int> orderedLMSs(LMSs.size());
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
        REPI(i, 1, orderedLMSs.size() - 1) {
            bool is_diff = false;
            REP(j, n) {
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
        vector<int> new_str(LMSs.size());
        index = 0;
        REP(i, n) {
            if (is_LMS[i]) {
                new_str[index++] = pseudo_sa[i];
            }
        }
        vector<int> LMS_sa;
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

    vector<int> induced_sort(const vector<int>& str, const vector<int>& LMSs, const vector<bool>& is_S, const int k) {
        int n = str.size();
        vector<int> buckets(n);
        vector<int> chars(k + 1);
        for (int c : str) {
            chars[c + 1]++;
        }
        REP(i, k) { chars[i + 1] += chars[i]; }
        vector<int> count(k);
        for (int i = LMSs.size() - 1; i >= 0; i--) {
            int c = str[LMSs[i]];
            buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];
        }
        count = vector<int>(k);
        REP(i, n) {
            if (buckets[i] == 0 || is_S[buckets[i] - 1]) {
                continue;
            }
            int c = str[buckets[i] - 1];
            buckets[chars[c] + count[c]++] = buckets[i] - 1;
        }
        count = vector<int>(k);
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
    string S;
    int N;
    vector<int> sa;  // sa[i]: suffixが辞書順i番目となる開始位置のindex
    SuffixArray(string str_in) : S(str_in), N(str_in.size()) {
        str_in += "$";
        vector<int> str(N + 1);
        REP(i, N + 1) { str[i] = str_in[i] - '$'; }
        sa = sa_is(str, 128);
        sa.erase(sa.begin());
    }
    int operator[](int index) { return sa[index]; }

    // sizeがTと等しく初めてT以上になるようなSの部分文字列(sa)
    vector<int>::iterator lower_bound(string T) {
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
    vector<int>::iterator upper_bound(string T) {
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
    int count(string S2) { return upper_bound(S2) - lower_bound(S2); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/String/SuffixArray.cpp"
// SA-ISによるSuffix Arrayの実装。構築O(N)
class SuffixArray {
    vector<int> sa_is(const vector<int>& str, const int k) {
        const int n = str.size();
        vector<bool> is_S(n);
        is_S[n - 1] = true;
        vector<bool> is_LMS(n);
        vector<int> LMSs;
        for (int i = n - 2; i >= 0; i--) {
            is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);
        }
        REP(i, n) {
            if (is_S[i] & (i == 0 || !is_S[i - 1])) {
                is_LMS[i] = true;
                LMSs.push_back(i);
            }
        }
        vector<int> pseudo_sa = induced_sort(str, LMSs, is_S, k);
        vector<int> orderedLMSs(LMSs.size());
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
        REPI(i, 1, orderedLMSs.size() - 1) {
            bool is_diff = false;
            REP(j, n) {
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
        vector<int> new_str(LMSs.size());
        index = 0;
        REP(i, n) {
            if (is_LMS[i]) {
                new_str[index++] = pseudo_sa[i];
            }
        }
        vector<int> LMS_sa;
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

    vector<int> induced_sort(const vector<int>& str, const vector<int>& LMSs, const vector<bool>& is_S, const int k) {
        int n = str.size();
        vector<int> buckets(n);
        vector<int> chars(k + 1);
        for (int c : str) {
            chars[c + 1]++;
        }
        REP(i, k) { chars[i + 1] += chars[i]; }
        vector<int> count(k);
        for (int i = LMSs.size() - 1; i >= 0; i--) {
            int c = str[LMSs[i]];
            buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];
        }
        count = vector<int>(k);
        REP(i, n) {
            if (buckets[i] == 0 || is_S[buckets[i] - 1]) {
                continue;
            }
            int c = str[buckets[i] - 1];
            buckets[chars[c] + count[c]++] = buckets[i] - 1;
        }
        count = vector<int>(k);
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
    string S;
    int N;
    vector<int> sa;  // sa[i]: suffixが辞書順i番目となる開始位置のindex
    SuffixArray(string str_in) : S(str_in), N(str_in.size()) {
        str_in += "$";
        vector<int> str(N + 1);
        REP(i, N + 1) { str[i] = str_in[i] - '$'; }
        sa = sa_is(str, 128);
        sa.erase(sa.begin());
    }
    int operator[](int index) { return sa[index]; }

    // sizeがTと等しく初めてT以上になるようなSの部分文字列(sa)
    vector<int>::iterator lower_bound(string T) {
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
    vector<int>::iterator upper_bound(string T) {
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
    int count(string S2) { return upper_bound(S2) - lower_bound(S2); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

