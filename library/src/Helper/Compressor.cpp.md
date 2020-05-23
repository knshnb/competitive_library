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


# :warning: src/Helper/Compressor.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1b49b634354b8edb1dc8ef8a73014950">src/Helper</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Helper/Compressor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-22 22:25:40+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T> struct Compressor {
    std::vector<T> val;
    void insert(T x) { val.push_back(x); }
    void insert(const std::vector<T>& v) { val.insert(val.begin(), v.begin(), v.end()); }
    void build() {
        std::sort(val.begin(), val.end());
        val.erase(std::unique(val.begin(), val.end()), val.end());
    }
    int operator()(T x) { return std::lower_bound(val.begin(), val.end(), x) - val.begin(); }
    T operator[](int idx) { return val[idx]; }
    int size() { return val.size(); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Helper/Compressor.cpp"
template <class T> struct Compressor {
    std::vector<T> val;
    void insert(T x) { val.push_back(x); }
    void insert(const std::vector<T>& v) { val.insert(val.begin(), v.begin(), v.end()); }
    void build() {
        std::sort(val.begin(), val.end());
        val.erase(std::unique(val.begin(), val.end()), val.end());
    }
    int operator()(T x) { return std::lower_bound(val.begin(), val.end(), x) - val.begin(); }
    T operator[](int idx) { return val[idx]; }
    int size() { return val.size(); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

