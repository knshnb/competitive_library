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


# :warning: src/old/SuffixArrayDoubling.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ed8431f95262b19a48e972d3753d06d7">src/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/old/SuffixArrayDoubling.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-10 21:10:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T = int> class SegTree {
    using VT = vector<T>;
    int orig_n;
    // k番目のノードの[l, r)について[a, b)を求める
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return UNIT;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

public:
    int N;
    VT dat;
    function<T(T, T)> f;
    int UNIT;
    SegTree(int n, function<T(T, T)> f_, const T unit) {
        orig_n = n;
        f = f_;
        UNIT = unit;
        for (N = 1; N < n; N *= 2)
            ;
        dat = VT(2 * N - 1, UNIT);
    }
    SegTree(
        VT a = {}, function<T(T, T)> f_ = [](int a, int b) { return min(a, b); }, T unit = 1e15) {
        orig_n = a.size();
        f = f_;
        UNIT = unit;
        for (N = 1; N < a.size(); N *= 2)
            ;
        dat = VT(2 * N - 1);
        REP(i, a.size()) { dat[N - 1 + i] = a[i]; }
        for (int k = N - 2; k >= 0; k--) {
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // k番目をaに
    void update(int k, int a) {
        k += N - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // [a, b)でのクエリ
    T query(int a, int b) {
        assert(0 <= a && a < b && b <= orig_n);
        return query(a, b, 0, 0, N);
    }
};

class SuffixArray {
    SegTree<> rmq;
    void set_lcp() {
        // S[i]を順番に見ていきS[i - 1] -　1文字以上が共通することを利用してしゃくとり
        lcp_next_rank = vector<int>(N);
        int h = 0;
        REP(i, N) {
            if (h > 0) h--;
            if (rank[i] == N - 1) continue;
            int j = sorted[rank[i] + 1];  // 比べる対象(辞書順が一つ大きいもの)
            for (; i + h < N && j + h < N; h++) {
                if (S[i + h] != S[j + h]) break;
            }
            lcp_next_rank[rank[i]] = h;
        }
        // S[i..], S[j..]のlcpが求められるようにRMQ上にのせる
        rmq = SegTree<int>(
            lcp_next_rank, [](int a, int b) { return min(a, b); }, 1e15);
    }

public:
    int N;
    string S;
    vector<int> rank;    // rank[i]: iから始まるsuffixの辞書順での順位
    vector<int> sorted;  // sorted[i]: suffixが辞書順i番目となる開始位置のindex
    vector<int> lcp_next_rank;  // lcp[i]: S[sorted[i]..]とS[sorted[i + 1]..]が先頭何文字一致しているか、lcp[N - 1] = 0
    SuffixArray(string s) {
        S = s;
        N = S.size();
        sorted = vector<int>(N);
        rank = vector<int>(N);
        REP(i, N) {
            sorted[i] = i;
            rank[i] = S[i];
        }

        int k;
        function<bool(int, int)> compare_sa = [this, &k](int i, int j) {
            if (rank[i] != rank[j]) {
                return rank[i] < rank[j];
            }
            int ri = i + k < N ? rank[i + k] : -1;
            int rj = j + k < N ? rank[j + k] : -1;
            return ri < rj;
        };

        for (k = 1; k < N; k *= 2) {
            sort(sorted.begin(), sorted.end(), compare_sa);
            vector<int> tmp(N, 0);
            REPI(i, 1, N) { tmp[sorted[i]] = tmp[sorted[i - 1]] + compare_sa(sorted[i - 1], sorted[i]); }
            rank = tmp;
        }
        set_lcp();
    }

    // sizeがTと等しく初めてT以上になるようなSの部分文字列(sortedのイテレータを返す)
    vector<int>::iterator lower_bound(string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sorted[mid], T.size(), T) < 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sorted.begin() + r;
    }

    // sizeがTと等しく初めてTより大きくなるようなSの部分文字列(sortedのイテレータを返す)
    vector<int>::iterator upper_bound(string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sorted[mid], T.size(), T) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sorted.begin() + r;
    }

    // S2が部分文字列として何回出現するか
    int count(string S2) { return upper_bound(S2) - lower_bound(S2); }

    // S[i..], S[j..]が先頭何文字一致しているか
    int lcp(int i, int j) {
        assert(0 <= i && 0 <= j && i < N && j < N);
        if (i == j) return N - i;
        int l = min(rank[i], rank[j]);
        int r = max(rank[i], rank[j]);
        return rmq.query(l, r);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/old/SuffixArrayDoubling.hpp"
template <class T = int> class SegTree {
    using VT = vector<T>;
    int orig_n;
    // k番目のノードの[l, r)について[a, b)を求める
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return UNIT;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

public:
    int N;
    VT dat;
    function<T(T, T)> f;
    int UNIT;
    SegTree(int n, function<T(T, T)> f_, const T unit) {
        orig_n = n;
        f = f_;
        UNIT = unit;
        for (N = 1; N < n; N *= 2)
            ;
        dat = VT(2 * N - 1, UNIT);
    }
    SegTree(
        VT a = {}, function<T(T, T)> f_ = [](int a, int b) { return min(a, b); }, T unit = 1e15) {
        orig_n = a.size();
        f = f_;
        UNIT = unit;
        for (N = 1; N < a.size(); N *= 2)
            ;
        dat = VT(2 * N - 1);
        REP(i, a.size()) { dat[N - 1 + i] = a[i]; }
        for (int k = N - 2; k >= 0; k--) {
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // k番目をaに
    void update(int k, int a) {
        k += N - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // [a, b)でのクエリ
    T query(int a, int b) {
        assert(0 <= a && a < b && b <= orig_n);
        return query(a, b, 0, 0, N);
    }
};

class SuffixArray {
    SegTree<> rmq;
    void set_lcp() {
        // S[i]を順番に見ていきS[i - 1] -　1文字以上が共通することを利用してしゃくとり
        lcp_next_rank = vector<int>(N);
        int h = 0;
        REP(i, N) {
            if (h > 0) h--;
            if (rank[i] == N - 1) continue;
            int j = sorted[rank[i] + 1];  // 比べる対象(辞書順が一つ大きいもの)
            for (; i + h < N && j + h < N; h++) {
                if (S[i + h] != S[j + h]) break;
            }
            lcp_next_rank[rank[i]] = h;
        }
        // S[i..], S[j..]のlcpが求められるようにRMQ上にのせる
        rmq = SegTree<int>(
            lcp_next_rank, [](int a, int b) { return min(a, b); }, 1e15);
    }

public:
    int N;
    string S;
    vector<int> rank;    // rank[i]: iから始まるsuffixの辞書順での順位
    vector<int> sorted;  // sorted[i]: suffixが辞書順i番目となる開始位置のindex
    vector<int> lcp_next_rank;  // lcp[i]: S[sorted[i]..]とS[sorted[i + 1]..]が先頭何文字一致しているか、lcp[N - 1] = 0
    SuffixArray(string s) {
        S = s;
        N = S.size();
        sorted = vector<int>(N);
        rank = vector<int>(N);
        REP(i, N) {
            sorted[i] = i;
            rank[i] = S[i];
        }

        int k;
        function<bool(int, int)> compare_sa = [this, &k](int i, int j) {
            if (rank[i] != rank[j]) {
                return rank[i] < rank[j];
            }
            int ri = i + k < N ? rank[i + k] : -1;
            int rj = j + k < N ? rank[j + k] : -1;
            return ri < rj;
        };

        for (k = 1; k < N; k *= 2) {
            sort(sorted.begin(), sorted.end(), compare_sa);
            vector<int> tmp(N, 0);
            REPI(i, 1, N) { tmp[sorted[i]] = tmp[sorted[i - 1]] + compare_sa(sorted[i - 1], sorted[i]); }
            rank = tmp;
        }
        set_lcp();
    }

    // sizeがTと等しく初めてT以上になるようなSの部分文字列(sortedのイテレータを返す)
    vector<int>::iterator lower_bound(string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sorted[mid], T.size(), T) < 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sorted.begin() + r;
    }

    // sizeがTと等しく初めてTより大きくなるようなSの部分文字列(sortedのイテレータを返す)
    vector<int>::iterator upper_bound(string T) {
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sorted[mid], T.size(), T) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return sorted.begin() + r;
    }

    // S2が部分文字列として何回出現するか
    int count(string S2) { return upper_bound(S2) - lower_bound(S2); }

    // S[i..], S[j..]が先頭何文字一致しているか
    int lcp(int i, int j) {
        assert(0 <= i && 0 <= j && i < N && j < N);
        if (i == j) return N - i;
        int l = min(rank[i], rank[j]);
        int r = max(rank[i], rank[j]);
        return rmq.query(l, r);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

