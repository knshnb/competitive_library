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


# :warning: src/old/GaussJordan.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/GaussJordan.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 20:39:55+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// A[n-1]にはAx = bのbの値
template <class T> void gauss_jordan(vector<vector<T>>& A) {
    int n = A.size(), m = A[0].size();
    vector<bool> used(n);
    for (int col = 0; col < m - 1; col++) {
        int pivot = -1;
        for (int row = 0; row < n; row++) {
            if (!used[row] && A[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        used[pivot] = true;
        for (int row = 0; row < n; row++) {
            if (row == pivot) continue;
            T d = A[row][col] / A[pivot][col];  // 倍率
            for (int col2 = 0; col2 < m; col2++) {
                A[row][col2] -= A[pivot][col2] * d;
            }
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/GaussJordan.hpp"
// A[n-1]にはAx = bのbの値
template <class T> void gauss_jordan(vector<vector<T>>& A) {
    int n = A.size(), m = A[0].size();
    vector<bool> used(n);
    for (int col = 0; col < m - 1; col++) {
        int pivot = -1;
        for (int row = 0; row < n; row++) {
            if (!used[row] && A[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        used[pivot] = true;
        for (int row = 0; row < n; row++) {
            if (row == pivot) continue;
            T d = A[row][col] / A[pivot][col];  // 倍率
            for (int col2 = 0; col2 < m; col2++) {
                A[row][col2] -= A[pivot][col2] * d;
            }
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

