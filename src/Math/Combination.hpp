template <class T> struct Combination {
    std::vector<T> fact, fact_inv;
    Combination(int n = 1000003) : fact(n + 1, 1), fact_inv(n + 1) {
        for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (i + 1);
        fact_inv[n] = (T)1 / fact[n];
        for (int i = n - 1; i >= 0; i--) fact_inv[i] = fact_inv[i + 1] * (i + 1);
        // for (int i = 0; i < n + 1; i++) assert(fact[i] * fact_inv[i] == 1);
    }
    T operator()(int n, int r) { return fact[n] * fact_inv[r] * fact_inv[n - r]; }
};
