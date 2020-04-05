template <class T> T pow(T x, int n, const T UNION = 1) {
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
    static int runtime_mod;
    static std::unordered_map<int, int> to_inv;
    // テンプレート引数が負のときは実行時ModInt
    static int mod() { return Mod < 0 ? runtime_mod : Mod; }
    static void set_runtime_mod(int mod) {
        static_assert(Mod < 0);
        runtime_mod = mod;
        to_inv.clear();
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
        x = (unsigned long long)x * rhs.inv().x % mod();
        return *this;
    }
    ModInt operator-() const { return -x < 0 ? mod() - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    ModInt inv() const { return to_inv.count(this->x) ? to_inv[this->x] : (to_inv[this->x] = pow(*this, mod() - 2).x); }

    friend std::ostream& operator<<(std::ostream& s, ModInt<Mod> a) {
        s << a.x;
        return s;
    }
    friend std::istream& operator>>(std::istream& s, ModInt<Mod>& a) {
        long long tmp;
        s >> tmp;
        a = ModInt<Mod>(tmp);
        return s;
    }
    friend std::string to_string(ModInt<Mod> a) { return std::to_string(a.x); }
};
template <int Mod> std::unordered_map<int, int> ModInt<Mod>::to_inv;
template <int Mod> int ModInt<Mod>::runtime_mod;

#ifndef CALL_FROM_TEST
using mint = ModInt<1000000007>;
#endif
