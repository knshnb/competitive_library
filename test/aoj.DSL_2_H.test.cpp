#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include <bits/stdc++.h>  // clang-format off
using namespace std;
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Mar 21 19:52:09 JST 2020
 **/

#include "../src/DataStructure/LazySegmentTree.cpp"

const Int INF = 1e9;
signed main() {
    int n, Q;
    cin >> n >> Q;
    auto seg = make_lazy_segment_tree<Int, Int>(
        [](Int x, Int y) { return min(x, y); }, INF, [](Int x, Int y) { return x + y; }, 0,
        [](Int x, Int y) { return x == INF ? x : x + y; }, [](Int x, int len) { return x; });
    seg.set_by_vector(vector<Int>(n));
    REP(q, Q) {
        int c, s, t;
        cin >> c >> s >> t;
        t++;
        if (c == 0) {
            Int x;
            cin >> x;
            seg.update(s, t, x);
        } else {
            cout << seg.query(s, t) << endl;
        }
    }
}
