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


# :warning: src/Graph/GridGraph.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e5c608398952d411d1862b1f8dc05f5">src/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/GridGraph.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 二次元Grid Graphの斜め方向の累積和
class GridGraph {
    // queryを計算しやすいようにaccの範囲外の値も便宜的に定義
    int acc_any(int i, int j) {
        if (i + j < 0 || H + W - 1 <= i + j) return 0;
        if (i < 0 || j >= W) return 0;
        if (j < 0 && i + j < H) return acc[i + j][0];
        if (i >= H && i + j >= H) return acc[H - 1][i + j - (H - 1)];
        return acc[i][j];
    }

public:
    VVI t;
    int H, W;
    VVI acc;
    GridGraph(VVI& tbl) : t(tbl), H(tbl.size()), W(tbl[0].size()) { set_acc(); }
    VI& operator[](int i) { return t[i]; }
    bool exist(int i, int j) { return 0 <= i && i < H && 0 <= j && j < W && t[i][j]; }
    // 左下方向への累積和
    void set_acc() {
        acc = VVI(H, VI(W));
        REP(i, H) {
            REP(j, W) {
                int before = (i == 0 || j == W - 1) ? 0 : acc[i - 1][j + 1];
                acc[i][j] = before + t[i][j];
            }
        }
    }
    // 時計回りに90度回転
    void rotate() {
        VVI t2(W, VI(H));
        REP(i, H) {
            REP(j, W) { t2[j][H - i - 1] = t[i][j]; }
        }
        t = t2;
        swap(H, W);
        set_acc();
    }
    // [i0, i1)の斜めのsum
    int query(int i0, int j0, int i1, int j1) {
        assert(i0 + j0 == i1 + j1);
        assert(i1 > i0);
        return acc_any(i1 - 1, j1 + 1) - acc_any(i0 - 1, j0 + 1);
    }
};

signed main() {}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/GridGraph.cpp"
// 二次元Grid Graphの斜め方向の累積和
class GridGraph {
    // queryを計算しやすいようにaccの範囲外の値も便宜的に定義
    int acc_any(int i, int j) {
        if (i + j < 0 || H + W - 1 <= i + j) return 0;
        if (i < 0 || j >= W) return 0;
        if (j < 0 && i + j < H) return acc[i + j][0];
        if (i >= H && i + j >= H) return acc[H - 1][i + j - (H - 1)];
        return acc[i][j];
    }

public:
    VVI t;
    int H, W;
    VVI acc;
    GridGraph(VVI& tbl) : t(tbl), H(tbl.size()), W(tbl[0].size()) { set_acc(); }
    VI& operator[](int i) { return t[i]; }
    bool exist(int i, int j) { return 0 <= i && i < H && 0 <= j && j < W && t[i][j]; }
    // 左下方向への累積和
    void set_acc() {
        acc = VVI(H, VI(W));
        REP(i, H) {
            REP(j, W) {
                int before = (i == 0 || j == W - 1) ? 0 : acc[i - 1][j + 1];
                acc[i][j] = before + t[i][j];
            }
        }
    }
    // 時計回りに90度回転
    void rotate() {
        VVI t2(W, VI(H));
        REP(i, H) {
            REP(j, W) { t2[j][H - i - 1] = t[i][j]; }
        }
        t = t2;
        swap(H, W);
        set_acc();
    }
    // [i0, i1)の斜めのsum
    int query(int i0, int j0, int i1, int j1) {
        assert(i0 + j0 == i1 + j1);
        assert(i1 > i0);
        return acc_any(i1 - 1, j1 + 1) - acc_any(i0 - 1, j0 + 1);
    }
};

signed main() {}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

