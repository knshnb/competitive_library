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


# :warning: src/Helper/ArithmeticParser.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1b49b634354b8edb1dc8ef8a73014950">src/Helper</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Helper/ArithmeticParser.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 16:30:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 四則演算のParser
#include <bits/stdc++.h>
#define int long long
using namespace std;

// exp1 = exp2 [ ('+'|'-') exp2 ]*
// exp2 = exp3 [ ('*'|'/') exp3 ]*
// exp3 = '(' exp1 ')' | number

int exp1(const string& s, int& i);
int exp2(const string& s, int& i);
int exp3(const string& s, int& i);
int number(const string& s, int& i);
int exp1(const string& s, int& i) {
    int acc = exp2(s, i);
    while (1) {
        if (s[i] == '+')
            acc += exp2(s, ++i);
        else if (s[i] == '-')
            acc -= exp2(s, ++i);
        else
            return acc;
    }
}
int exp2(const string& s, int& i) {
    int acc = exp3(s, i);
    while (1) {
        if (s[i] == '*')
            acc *= exp3(s, ++i);
        else if (s[i] == '/')
            acc /= exp3(s, ++i);
        else
            return acc;
    }
}
int exp3(const string& s, int& i) {
    if (s[i] == '(') {
        int ret = exp1(s, ++i);
        assert(s[i] == ')');
        i++;
        return ret;
    }
    return number(s, i);
}
int number(const string& s, int& i) {
    int acc = 0;
    while (isdigit(s[i])) {
        acc = acc * 10 + (s[i++] - '0');
    }
    return acc;
}

void solve() {
    string s;
    cin >> s;
    int i = 0;
    cout << exp1(s, i) << endl;
    assert(s[i] == '=');
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Helper/ArithmeticParser.hpp"
// 四則演算のParser
#include <bits/stdc++.h>
#define int long long
using namespace std;

// exp1 = exp2 [ ('+'|'-') exp2 ]*
// exp2 = exp3 [ ('*'|'/') exp3 ]*
// exp3 = '(' exp1 ')' | number

int exp1(const string& s, int& i);
int exp2(const string& s, int& i);
int exp3(const string& s, int& i);
int number(const string& s, int& i);
int exp1(const string& s, int& i) {
    int acc = exp2(s, i);
    while (1) {
        if (s[i] == '+')
            acc += exp2(s, ++i);
        else if (s[i] == '-')
            acc -= exp2(s, ++i);
        else
            return acc;
    }
}
int exp2(const string& s, int& i) {
    int acc = exp3(s, i);
    while (1) {
        if (s[i] == '*')
            acc *= exp3(s, ++i);
        else if (s[i] == '/')
            acc /= exp3(s, ++i);
        else
            return acc;
    }
}
int exp3(const string& s, int& i) {
    if (s[i] == '(') {
        int ret = exp1(s, ++i);
        assert(s[i] == ')');
        i++;
        return ret;
    }
    return number(s, i);
}
int number(const string& s, int& i) {
    int acc = 0;
    while (isdigit(s[i])) {
        acc = acc * 10 + (s[i++] - '0');
    }
    return acc;
}

void solve() {
    string s;
    cin >> s;
    int i = 0;
    cout << exp1(s, i) << endl;
    assert(s[i] == '=');
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

