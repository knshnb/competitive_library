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


# :warning: src/String/Manacher.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac276d2326c527c8c7dbcbb63d85c6c7">src/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/String/Manacher.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> vector<int> manacher(const vector<T>& s) {
    vector<int> R(s.size());
    int i = 0, j = 0;
    while (i < s.size()) {
        while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < s.size() && k + R[i - k] < j) R[i + k] = R[i - k], ++k;
        i += k;
        j -= k;
    }
    return R;
}

struct Manacher {
    vector<int> a;
    template <class T> Manacher(const vector<T>& s, T DUMMY = -1) {
        int m = s.size() * 2 - 1;
        vector<T> t(m, DUMMY);
        for (int i = 0; i < s.size(); i++) {
            t[i * 2] = s[i];
        }
        a = manacher(t);
    }
    Manacher(const string& s, char DUMMY = '$') {
        int m = s.size() * 2 - 1;
        vector<char> t(m, DUMMY);
        for (int i = 0; i < s.size(); i++) {
            t[i * 2] = s[i];
        }
        a = manacher(t);
    }

    // [l, r)が回文かどうか
    bool is_palindrome(int l, int r) { return a[l + r - 1] >= r - l; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/String/Manacher.hpp"
template <class T> vector<int> manacher(const vector<T>& s) {
    vector<int> R(s.size());
    int i = 0, j = 0;
    while (i < s.size()) {
        while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < s.size() && k + R[i - k] < j) R[i + k] = R[i - k], ++k;
        i += k;
        j -= k;
    }
    return R;
}

struct Manacher {
    vector<int> a;
    template <class T> Manacher(const vector<T>& s, T DUMMY = -1) {
        int m = s.size() * 2 - 1;
        vector<T> t(m, DUMMY);
        for (int i = 0; i < s.size(); i++) {
            t[i * 2] = s[i];
        }
        a = manacher(t);
    }
    Manacher(const string& s, char DUMMY = '$') {
        int m = s.size() * 2 - 1;
        vector<char> t(m, DUMMY);
        for (int i = 0; i < s.size(); i++) {
            t[i * 2] = s[i];
        }
        a = manacher(t);
    }

    // [l, r)が回文かどうか
    bool is_palindrome(int l, int r) { return a[l + r - 1] >= r - l; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

