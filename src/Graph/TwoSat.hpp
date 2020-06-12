#include "StronglyConnectedComponents.hpp"

struct TwoSat {
    int n;
    StronglyConnectedComponents scc;  // [0, n): x, [n, 2n): not x
    TwoSat(int n_) : n(n_), scc(2 * n_) {}
    // xの否定を表すindex
    int rev(int x) { return x < n ? x + n : x - n; }
    // (x \vee y)の条件を追加
    void add_condition(int x, bool not_x, int y, bool not_y) {
        if (not_x) x = rev(x);
        if (not_y) y = rev(y);
        scc.add_edge(rev(x), y);
        scc.add_edge(rev(y), x);
    }
    bool run() {
        scc.build();
        for (int x = 0; x < n; x++) {
            if (scc.belong_to[x] == scc.belong_to[rev(x)]) return false;
        }
        return true;
    }
    bool is_true(int x) {
        assert(0 <= x && x < n);
        return scc.belong_to[x] > scc.belong_to[rev(x)];
    }
};
