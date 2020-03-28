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


# :warning: src/Helper/Rotate2D.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1b49b634354b8edb1dc8ef8a73014950">src/Helper</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Helper/Rotate2D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 00:05:09+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> std::vector<std::vector<T>> rotate_2D(const std::vector<std::vector<T>>& t, bool counterclockwise = true) {
    int H = t.size(), W = t[0].size();
    std::vector<std::vector<T>> ret(W, std::vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ret[j][i] = counterclockwise ? t[i][W - 1 - j] : t[H - 1 - i][j];
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Helper/Rotate2D.cpp"
template <class T> std::vector<std::vector<T>> rotate_2D(const std::vector<std::vector<T>>& t, bool counterclockwise = true) {
    int H = t.size(), W = t[0].size();
    std::vector<std::vector<T>> ret(W, std::vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ret[j][i] = counterclockwise ? t[i][W - 1 - j] : t[H - 1 - i][j];
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

