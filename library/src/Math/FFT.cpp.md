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


# :warning: src/Math/FFT.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#64f6d80a21cfb0c7e1026d02dde4f7fa">src/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/FFT.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 10:21:51-08:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct FFT {
    using comp = complex<double>;
    static void fft(vector<comp>& a, bool inv = false) {
        int N = a.size();
        if (N == 1) {
            return;
        }
        vector<comp> even(N / 2), odd(N / 2);
        for (int i = 0; i < N / 2; i++) {
            even[i] = a[2 * i];
            odd[i] = a[2 * i + 1];
        }
        fft(even, inv);
        fft(odd, inv);
        comp omega = polar(1.0, (-2 * inv + 1) * 2 * M_PI / N);
        comp acc_omega = comp(1);
        for (int i = 0; i < N / 2; i++) {
            a[i] = even[i] + acc_omega * odd[i];
            a[i + N / 2] = even[i] - acc_omega * odd[i];
            acc_omega *= omega;
        }
    }
    static void conv(vector<int>& a, vector<int>& b) {
        int N = 1;
        while (N < 2 * (max(a.size(), b.size() + 1))) {
            N *= 2;
        }
        vector<comp> ac(N, comp(0)), bc(N, comp(0));
        for (int i = 0; i < a.size(); i++) ac[i] = comp(a[i]);
        for (int i = 0; i < b.size(); i++) bc[i] = comp(b[i]);
        multiply(ac, bc);
        a.resize(N);
        for (int i = 0; i < N; i++) {
            a[i] = (int)(ac[i].real() + 0.5);
        }
    }

private:
    static void multiply(vector<comp>& a, vector<comp>& b) {
        int n = a.size();
        fft(a);
        fft(b);
        for (int i = 0; i < n; i++) {
            a[i] *= b[i] / comp(n);
        }
        fft(a, true);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/FFT.cpp"
struct FFT {
    using comp = complex<double>;
    static void fft(vector<comp>& a, bool inv = false) {
        int N = a.size();
        if (N == 1) {
            return;
        }
        vector<comp> even(N / 2), odd(N / 2);
        for (int i = 0; i < N / 2; i++) {
            even[i] = a[2 * i];
            odd[i] = a[2 * i + 1];
        }
        fft(even, inv);
        fft(odd, inv);
        comp omega = polar(1.0, (-2 * inv + 1) * 2 * M_PI / N);
        comp acc_omega = comp(1);
        for (int i = 0; i < N / 2; i++) {
            a[i] = even[i] + acc_omega * odd[i];
            a[i + N / 2] = even[i] - acc_omega * odd[i];
            acc_omega *= omega;
        }
    }
    static void conv(vector<int>& a, vector<int>& b) {
        int N = 1;
        while (N < 2 * (max(a.size(), b.size() + 1))) {
            N *= 2;
        }
        vector<comp> ac(N, comp(0)), bc(N, comp(0));
        for (int i = 0; i < a.size(); i++) ac[i] = comp(a[i]);
        for (int i = 0; i < b.size(); i++) bc[i] = comp(b[i]);
        multiply(ac, bc);
        a.resize(N);
        for (int i = 0; i < N; i++) {
            a[i] = (int)(ac[i].real() + 0.5);
        }
    }

private:
    static void multiply(vector<comp>& a, vector<comp>& b) {
        int n = a.size();
        fft(a);
        fft(b);
        for (int i = 0; i < n; i++) {
            a[i] *= b[i] / comp(n);
        }
        fft(a, true);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

