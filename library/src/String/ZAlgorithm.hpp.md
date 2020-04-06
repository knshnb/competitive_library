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


# :heavy_check_mark: src/String/ZAlgorithm.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac276d2326c527c8c7dbcbb63d85c6c7">src/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/String/ZAlgorithm.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 02:21:00+09:00




## 概要
文字列s[0:]とs[i:]の共通prefixの長さの配列を返す、O(|s|)。

基本的なアイディアは、以前に先頭からの文字列との共通prefixとして計算された値を使い回すこと。
左から順に求める配列aを計算しながら、それまでに一番右まで到達した部分についてaをもう一度たどると先頭とのprefix一致がショートカットできる。

アルゴリズム参考: https://snuke.hatenablog.com/entry/2014/12/03/214243
</br>
実装のrm_idx(rightmost index)は、それまでに共通prefixとして一番右まで到達したときのインデックスを表す。
苦労して結構うまく実装できたと思ったらsnukeさんのコードとほとんど同じだった、完…


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/// @docs src/String/ZAlgorithm.md
template <class T> std::vector<int> Z_algorithm(const T& s) {
    std::vector<int> a(s.size());
    for (int i = 1, rm_idx = 0; i < s.size(); i++) {
        if (a[i - rm_idx] < a[rm_idx] - (i - rm_idx)) {
            a[i] = a[i - rm_idx];
        } else {
            a[i] = std::max(0, a[rm_idx] - (i - rm_idx));
            while (i + a[i] < s.size() && s[a[i]] == s[i + a[i]]) a[i]++;
            rm_idx = i;
        }
    }
    a[0] = s.size();
    return a;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/String/ZAlgorithm.hpp"
/// @docs src/String/ZAlgorithm.md
template <class T> std::vector<int> Z_algorithm(const T& s) {
    std::vector<int> a(s.size());
    for (int i = 1, rm_idx = 0; i < s.size(); i++) {
        if (a[i - rm_idx] < a[rm_idx] - (i - rm_idx)) {
            a[i] = a[i - rm_idx];
        } else {
            a[i] = std::max(0, a[rm_idx] - (i - rm_idx));
            while (i + a[i] < s.size() && s[a[i]] == s[i + a[i]]) a[i]++;
            rm_idx = i;
        }
    }
    a[0] = s.size();
    return a;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

