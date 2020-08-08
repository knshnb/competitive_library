/// @docs src/DataStructure/MoAlgorithm.md
struct Mo {
    struct Query {
        int l, r, idx;  // 配列に対する[l, r)のクエリ, idxはクエリの番号
        Query(int l_, int r_, int idx_) : l(l_), r(r_), idx(idx_) {}
    };
    int width;
    std::vector<Query> query;
    std::vector<bool> v;

    // widthは指定しないと自動でsqrt(n)にする
    Mo(int n, int width_ = -1) : width(width_ == -1 ? (int)sqrt(n) : width_), v(n) {}
    void add(int l, int r) {
        int idx = query.size();
        query.emplace_back(l, r, idx);
    }
    template <class F, class G, class H> void run(const F& add, const G& del, const H& rem) {
        std::sort(query.begin(), query.end(), [&](const Query& a, const Query& b) {
            int ablock = a.l / width, bblock = b.l / width;
            if (ablock != bblock) return ablock < bblock;
            if (ablock & 1) return a.r < b.r;
            return a.r > b.r;
        });
        int nl = 0, nr = 0;
        auto push = [&](int idx) {
            v[idx].flip();
            if (v[idx])
                add(idx);
            else
                del(idx);
        };
        for (Query& q : query) {
            while (nl > q.l) push(--nl);
            while (nr < q.r) push(nr++);
            while (nl < q.l) push(nl++);
            while (nr > q.r) push(--nr);
            rem(q.idx);
            while (nl > q.l) push(--nl);
        }
    }
};
