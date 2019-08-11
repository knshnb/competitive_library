int euler_totient(int n) {
    vector<int> ps;
    {
        int tmp = n;
        for (int x = 2; x * x <= tmp; x++) {
            if (tmp % x) continue;
            ps.push_back(x);
            while (tmp % x == 0) tmp /= x;
        }
        if (tmp != 1) ps.push_back(tmp);
    }
    int m = ps.size();
    int ans = 0;
    for (int bit = 0; bit < 1LL << m; bit++) {
        int d = 1;
        for (int i = 0; i < m; i++) {
            if (bit >> i & 1) d *= ps[i];
        }
        int sign = __builtin_popcount(bit) % 2 ? -1 : 1;
        ans += sign * (n / d);
    }
    return ans;
}
