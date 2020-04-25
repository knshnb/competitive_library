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


# :warning: src/old/LongestCommonSubsequence.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/LongestCommonSubsequence.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 17:53:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Longest Common Subsequence: O(nm)
vector<vector<int>> LCS(const vector<int>& s, const vector<int>& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp;
}
// メモリ節約
vector<vector<int>> LCS2(const vector<int>& s, const vector<int>& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(2, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[1][j + 1] = s[i] == t[j] ? dp[0][j] + 1 : max(dp[0][j + 1], dp[1][j]);
        }
        swap(dp[0], dp[1]);
    }
    return dp;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/LongestCommonSubsequence.hpp"
// Longest Common Subsequence: O(nm)
vector<vector<int>> LCS(const vector<int>& s, const vector<int>& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp;
}
// メモリ節約
vector<vector<int>> LCS2(const vector<int>& s, const vector<int>& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(2, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[1][j + 1] = s[i] == t[j] ? dp[0][j] + 1 : max(dp[0][j + 1], dp[1][j]);
        }
        swap(dp[0], dp[1]);
    }
    return dp;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

