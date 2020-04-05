/// @docs src/Math/Eratosthenes.md
struct Eratosthenes {
    std::vector<bool> is_prime;
    std::vector<int> primes;
    Eratosthenes(int n) {
        is_prime.assign(n, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (!is_prime[i]) continue;
            for (int j = i * 2; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
    }
};
