/// @docs src/String/RollingHash.md
template <class T> struct RollingHash {
    std::vector<int> hash, pows;
    int base, mod;
    RollingHash(const T &a, int base_, int mod_ = 1000000009)
        : hash(a.size() + 1), pows(a.size() + 1, 1), base(base_), mod(mod_) {
        for (int i = 0; i < a.size(); i++) {
            pows[i + 1] = (long long)pows[i] * base % mod;
            hash[i + 1] = ((long long)hash[i] * base % mod + a[i]) % mod;
            if (hash[i + 1] < 0) hash[i + 1] += mod;
        }
    }
    // 現在の文字列のサイズ
    int size() { return hash.size() - 1; }
    // [l, r)
    int get(int l, int r) {
        assert(l <= r);
        int ret = hash[r] + mod - (long long)hash[l] * pows[r - l] % mod;
        if (ret >= mod) ret -= mod;
        return ret;
    }
    void concat(const T &b) {
        int n = hash.size() - 1, m = b.size();
        pows.resize(n + m + 1);
        hash.resize(n + m + 1);
        for (int i = 0; i < m; i++) {
            pows[n + i + 1] = (long long)pows[n + i] * base % mod;
            hash[n + i + 1] = (long long)hash[n + i] * base % mod + b[i];
            if (hash[n + i + 1] >= mod) hash[n + i + 1] -= mod;
        }
    }
    void pop_back() {
        hash.pop_back();
        pows.pop_back();
    }
};

template <int HashNum> struct Bases {
    std::array<int, HashNum> contents;
    Bases() {
        std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
        for (int i = 0; i < HashNum; i++) contents[i] = rnd() % 1000000;
    }
};
template <class T, int HashNum = 4> struct MultiRollingHash {
    using multihash_t = std::array<int, HashNum>;
    static Bases<HashNum> bases;
    std::vector<RollingHash<T>> rhs;
    MultiRollingHash(const T &a) {
        for (int i = 0; i < HashNum; i++) {
            rhs.push_back(RollingHash<T>(a, bases.contents[i]));
        }
    }
    multihash_t get(int l, int r) {
        multihash_t ret;
        for (int i = 0; i < HashNum; i++) ret[i] = rhs[i].get(l, r);
        return ret;
    }
    int size() { return rhs[0].size(); }
    void concat(const T &b) {
        for (auto &rh : rhs) rh.concat(b);
    }
    void pop_back() {
        for (auto &rh : rhs) rh.pop_back();
    }
};
template <class T, int HashNum> Bases<HashNum> MultiRollingHash<T, HashNum>::bases;
