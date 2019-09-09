// 0-indexed
class BinaryIndexedTree {
    int max_pow;  // N以下の最大の2べき
public:
    vector<int> bit;
    int N;
    BinaryIndexedTree(int n, int x = 0) : N(n), bit(n, x) {
        for (max_pow = 1; max_pow <= N / 2; max_pow *= 2)
            ;
    }
    BinaryIndexedTree(const vector<int>& a) : N(a.size()), bit(a) {
        for (max_pow = 1; max_pow <= N / 2; max_pow *= 2)
            ;
        REP(i, N - 1) if ((i | (i + 1)) < N) { bit[i | (i + 1)] += bit[i]; }
    }
    // k番目にxを加算
    void add(int k, int x) {
        for (int i = k; i < N; i |= i + 1) {
            bit[i] += x;
        }
    }

    // [0, k)、k == 0のときは0を返す
    int sum(int k) {
        int ret = 0;
        for (int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += bit[i];
        }
        return ret;
    }
    int sum() { return sum(N); }

    // [a, b)
    int query(int a, int b) {
        assert(a <= b);
        return sum(b) - sum(a);
    }
    int operator[](int k) { return query(k, k + 1); }

    // k番目をxに
    void update(int k, int x) { add(k, x - operator[](k)); }

    // 注: 中身が全て正のときしか動かない
    // sum(i + 1) >= xとなるような最小のi
    int lower_bound(int x) {
        int i = -1;
        for (int w = max_pow; w > 0; w /= 2) {
            if (i + w < N && bit[i + w] < x) {
                x -= bit[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) >= xとなるような最小のi
    int lower_bound(int begin, int x) {
        int lb = lower_bound(x + sum(begin));
        return max(begin, lb);
    }
    // sum(i + 1) > xとなるような最小のi
    int upper_bound(int x) {
        int i = -1;
        for (int w = max_pow; w > 0; w /= 2) {
            if (i + w < N && bit[i + w] <= x) {
                x -= bit[i + w];
                i += w;
            }
        }
        return i + 1;
    }
    // query[begin, i + 1) > xとなるような最小のi
    int upper_bound(int begin, int x) {
        int ub = upper_bound(x + sum(begin));
        return max(begin, ub);
    }
};

// 大きい方からlower_boundなどをしたいときのwrapper
// 政府逆転させて(-N, 0]にして、平行移動して[0, N)にしている
class ReversedBinaryIndexedTree : public BinaryIndexedTree {
public:
    using BinaryIndexedTree::BinaryIndexedTree;
    int rev(int k) { return N - 1 - k; }
    void add(int k, int x) { BinaryIndexedTree::add(rev(k), x); }
    // (k, N-1]
    int sum(int k) { return BinaryIndexedTree::sum(rev(k)); }
    // query(i - 1, N-1] >= xとなるような最大nのi
    int lower_bound(int x) { return rev(BinaryIndexedTree::lower_bound(x)); }
    // query(i - 1, N-1] > xとなるような最大nのi
    int upper_bound(int x) { return rev(BinaryIndexedTree::upper_bound(x)); }
};
