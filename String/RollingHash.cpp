using ull = unsigned long long;
struct RollingHash {
    vector<ull> hash, pows;
    ull base, mod;
    RollingHash(const string &S, ull base, ull mod = 1000000009)
        : hash(S.size() + 1), pows(S.size() + 1, 1), mod(mod), base(base) {
        for (int i = 0; i < S.size(); i++) {
            pows[i + 1] = pows[i] * base % mod;
            hash[i + 1] = hash[i] * base % mod + S[i];
            if (hash[i + 1] >= mod) hash[i + 1] -= mod;
        }
    }
    // [l, r)
    ull get(int l, int r) {
        assert(l <= r);
        ull ret = hash[r] + mod - hash[l] * pows[r - l] % mod;
        if (ret >= mod) ret -= mod;
        return ret;
    }
    void concat(const string &T) {
        int n = hash.size() - 1, m = T.size();
        pows.resize(n + m + 1);
        hash.resize(n + m + 1);
        for (int i = 0; i < m; i++) {
            pows[n + i + 1] = pows[n + i] * base % mod;
            hash[n + i + 1] = hash[n + i] * base % mod + T[i];
            if (hash[n + i + 1] >= mod) hash[n + i + 1] -= mod;
        }
    }
};

constexpr int HASH_NUM = 4;
struct bases_t {
    int use[HASH_NUM];
    int &operator[](int i) { return use[i]; }
    bases_t() {
        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
        for (int i = 0; i < HASH_NUM; i++) use[i] = rnd() % 10000;
    }
} bases;

using multihash_t = array<int, HASH_NUM>;
struct MultiRollingHash {
    vector<RollingHash> rhs;
    MultiRollingHash(const string &S) {
        for (int i = 0; i < HASH_NUM; i++) {
            rhs.push_back(RollingHash(S, bases[i]));
        }
    }
    multihash_t get(int l, int r) {
        multihash_t ret;
        for (int i = 0; i < HASH_NUM; i++) ret[i] = rhs[i].get(l, r);
        return ret;
    }
    void concat(const string &T) {
        for (int i = 0; i < HASH_NUM; i++) rhs[i].concat(T);
    }
};
