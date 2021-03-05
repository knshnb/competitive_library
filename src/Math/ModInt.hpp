template <class T> T pow(T x, long long n, const T UNION = 1) {
    T ret = UNION;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

/// @docs src/Math/ModInt.md
template <int Mod> struct ModInt {
    int x;
    static int& runtime_mod() {
        static int runtime_mod_;
        return runtime_mod_;
    }
    // テンプレート引数が負のときは実行時ModInt
    static constexpr int mod() { return Mod < 0 ? runtime_mod() : Mod; }
    static std::unordered_map<int, int>& to_inv() {
        static std::unordered_map<int, int> to_inv_;
        return to_inv_;
    }
    static void set_runtime_mod(int mod) {
        static_assert(Mod < 0, "template parameter Mod must be negative for runtime ModInt");
        runtime_mod() = mod, to_inv().clear();
    }
    ModInt() : x(0) {}
    ModInt(long long x_) {
        if ((x = x_ % mod() + mod()) >= mod()) x -= mod();
    }

    ModInt& operator+=(ModInt rhs) {
        if ((x += rhs.x) >= mod()) x -= mod();
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (unsigned long long)x * rhs.x % mod();
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        if ((x -= rhs.x) < 0) x += mod();
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        ModInt inv = to_inv().count(rhs.x) ? to_inv()[rhs.x] : (to_inv()[rhs.x] = pow(rhs, mod() - 2).x);
        return *this *= inv;
    }
    ModInt operator-() const { return -x < 0 ? mod() - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }

    // 計算結果をmapに保存するべき乗
    ModInt save_pow(int n) const {
        static std::map<std::pair<int, int>, int> tbl_pow;
        if (tbl_pow.count({x, n})) return tbl_pow[{x, n}];
        if (n == 0) return 1;
        if (n % 2) return tbl_pow[{x, n}] = (*this * save_pow(n - 1)).x;
        return tbl_pow[{x, n}] = (save_pow(n / 2) * save_pow(n / 2)).x;
    }
    // 1 + r + r^2 + ... + r^(n-1)を逆元がない（modが素数でない）場合に計算
    static ModInt geometric_progression(ModInt r, int n) {
        if (n == 0) return 0;
        if (n % 2) return geometric_progression(r, n - 1) + r.save_pow(n - 1);
        return geometric_progression(r, n / 2) * (r.save_pow(n / 2) + 1);
    }
    // a + r * (a - d) + r^2 * (a - 2d) + ... + r^(n-1) * (a - (n - 1)d)
    static ModInt linear_sum(ModInt r, ModInt a, ModInt d, int n) {
        if (n == 0) return 0;
        if (n % 2) return linear_sum(r, a, d, n - 1) + r.save_pow(n - 1) * (a - d * (n - 1));
        return linear_sum(r, a, d, n / 2) * (r.save_pow(n / 2) + 1) -
               d * (n / 2) * r.save_pow(n / 2) * geometric_progression(r, n / 2);
    }

    friend std::ostream& operator<<(std::ostream& s, ModInt<Mod> a) { return s << a.x; }
    friend std::istream& operator>>(std::istream& s, ModInt<Mod>& a) {
        long long tmp;
        s >> tmp;
        a = ModInt<Mod>(tmp);
        return s;
    }
    friend std::string to_string(ModInt<Mod> a) { return std::to_string(a.x); }
};

#ifndef CALL_FROM_TEST
using mint = ModInt<1000000007>;
#endif
