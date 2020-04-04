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


# :heavy_check_mark: test/yosupo/scc.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/scc.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-04 18:54:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/StronglyConnectedComponents.hpp.html">src/Graph/StronglyConnectedComponents.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Fri Apr  3 13:28:22 JST 2020
 **/

#define CALL_FROM_TEST
#include "../../src/Graph/StronglyConnectedComponents.hpp"
#undef CALL_FROM_TEST

signed main() {
    int n, m;
    std::cin >> n >> m;
    StronglyConnectedComponents scc(n);
    REP(i, m) {
        int u, v;
        std::cin >> u >> v;
        scc.add_edge(u, v);
    }
    scc.build();
    std::vector<std::vector<int>> groups(scc.size);
    REP(i, n) { groups[scc.belong_to[i]].push_back(i); }
    std::cout << scc.size << std::endl;
    for (auto& group : groups) {
        std::cout << group.size() << " ";
        for (int v : group) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/scc.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Fri Apr  3 13:28:22 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "src/Graph/StronglyConnectedComponents.hpp"
/// @docs src/Graph/StronglyConnectedComponents.md
struct StronglyConnectedComponents {
    int n, size;  // sizeはbuild()後に強連結成分の数を格納
    std::vector<std::vector<int>> edge, redge;
    std::vector<int> belong_to;
    StronglyConnectedComponents(int n_) : n(n_), edge(n_), redge(n_) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        edge[u].push_back(v);
        redge[v].push_back(u);
    }
    void build() {
        std::vector<int> ord;  // post-order
        // 正方向の辺でdfs、post-orderをふる
        std::vector<bool> visited(n, false);
        auto dfs1 = [&](auto f, int v) -> void {
            if (visited[v]) return;
            visited[v] = true;
            for (int s : edge[v]) {
                f(f, s);
            }
            ord.push_back(v);
        };
        for (int i = 0; i < n; i++) dfs1(dfs1, i);

        // post-order逆順にdfs、到達可能な同値類に分ける
        belong_to.assign(n, -1);
        int cur_group = 0;
        auto dfs2 = [&](auto f, int v) -> void {
            if (belong_to[v] != -1) return;
            belong_to[v] = cur_group;
            for (int s : redge[v]) {
                f(f, s);
            }
        };
        std::reverse(ord.begin(), ord.end());
        for (int i : ord) {
            if (belong_to[i] == -1) {
                dfs2(dfs2, i);
                cur_group++;
            }
        }
        size = cur_group;
    }
    bool has_loop() {
        build();
        return size < n;
    }
};
#line 19 "test/yosupo/scc.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    int n, m;
    std::cin >> n >> m;
    StronglyConnectedComponents scc(n);
    REP(i, m) {
        int u, v;
        std::cin >> u >> v;
        scc.add_edge(u, v);
    }
    scc.build();
    std::vector<std::vector<int>> groups(scc.size);
    REP(i, n) { groups[scc.belong_to[i]].push_back(i); }
    std::cout << scc.size << std::endl;
    for (auto& group : groups) {
        std::cout << group.size() << " ";
        for (int v : group) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

