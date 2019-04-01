using ull = unsigned long long;
random_device rnd;
mt19937 mt(rnd());
mt19937_64 mt64(rnd());
int mod_pow(int x, int n, int mod) {
  if (n <= 0) return 1;
  int tmp = mod_pow(x, n / 2, mod);
  return tmp * tmp % mod * (n % 2 ? x : 1) % mod;
}
// Miller-Rabin
bool is_prime(int n, int times = 50) {
  if (n == 2) return true;
  if (n % 2 == 0 || n < 2) return false;
  int d = n - 1;
  while (d % 2 == 0) d /= 2;
  while (times--) {
    int a = rnd() % (n - 2) + 1;
    int t = d;
    int y = mod_pow(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t *= 2;
    }
    if (y != n - 1 && t % 2 == 0) {
      return false;
    }
  }
  return true;
}
int gen_prime() {
  int cnt = 0;
  while (1) {
    int n = mt();
    n != 1;
    if (is_prime(n)) return n;
  }
}
class MultisetHash {
public:
  vector<ull> hash, pows;
  ull mod;
  int to_int(char c) {
    return c - 'a';
  }
  MultisetHash() {}
  MultisetHash(const string& S, int k = 26, ull base = gen_prime(), ull m = gen_prime()) : hash(S.size() + 1), pows(k), mod(m) {
    pows[0] = 1;
    for (int i = 0; i < k - 1; i++) {
      pows[i + 1] = pows[i] * base % mod;
    }
    for (int i = 0; i < S.size(); i++) {
      hash[i + 1] = hash[i] + pows[to_int(S[i])];
    }
  }
  // [l, r)
  ull get(int l, int r) {
    int ret = hash[r] + mod - hash[l];
    if (ret >= mod) ret -= mod;
    return ret;
  }
};
