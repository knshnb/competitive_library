random_device rnd;
mt19937 mt(rnd());
mt19937_64 mt64(rnd());
int mod_pow(int x, int n, int mod) {
    if (n <= 0) return 1;
    int tmp = mod_pow(x, n / 2, mod);
    return tmp * tmp % mod * (n % 2 ? x : 1) % mod;
}
int mod_inv(int x, int mod) { return mod_pow(x, mod - 2, mod); }
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
