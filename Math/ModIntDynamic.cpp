template <class T>
T pow(T x, int n, const T UNION = 1) {
  T ret = UNION;
  while (n) {
    if (n & 1) ret *= x;
    x *= x; n >>= 1;
  }
  return ret;
}

// ModInt::set_mod(m)してから使う
struct ModInt {
  static int MD;
  static void set_mod(int mod) { MD = mod; }
  int x;
  ModInt() : x(0) {}
  ModInt(int x_) { if ((x = x_ % MD + MD) >= MD) x -= MD; }

  ModInt& operator+=(ModInt that) { if ((x += that.x) >= MD) x -= MD; return *this; }
  ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MD; return *this; }
  ModInt& operator-=(ModInt that) { if ((x -= that.x) < 0) x += MD; return *this; }
  ModInt& operator/=(ModInt that) { x = (unsigned long long)x * that.inv().x % MD; return *this; }

  ModInt operator-() const { return -x < 0 ? MD - x : -x; }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt inv() const { return pow(*this, MD - 2); }
  friend ostream& operator<<(ostream& s, ModInt a) { s << a.x; return s; }
  friend istream& operator>>(istream& s, ModInt& a) { s >> a.x; return s; }
};
int ModInt::MD = 1000000007;
using mint = ModInt;

vector<mint> fact, fact_inv;
void init_factorial(int n) {
  fact = vector<mint>(n + 1, 1);
  fact_inv = vector<mint>(n + 1);
  for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
  fact_inv[n] = mint(1) / fact[n];
  for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
  // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
}
mint comb(int n, int r) {
  return fact[n] * fact_inv[r] * fact_inv[n - r];
}
