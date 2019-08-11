// ax + by = gcd(a, b) を満たす(x, y)
pair<int, int> ext_gcd(int a, int b) {
    if (b == 0) return {1, 0};
    pair<int, int> xy = ext_gcd(b, a % b);  // b(qx + y) + rx = ...
    swap(xy.fi, xy.se);
    xy.se -= (a / b) * xy.fi;
    return xy;
}
const pair<int, int> DUM = {0, -1};
// r = b[i] (mod m[i])
// r: 剰余, M: mod
pair<int, int> chinese_rem(const VI& b, const VI& m) {
    int r = 0, M = 1;
    for (int i = 0; i < b.size(); i++) {
        pair<int, int> xy = ext_gcd(M, m[i]);
        int d = __gcd(M, m[i]);
        if ((b[i] - r) % d != 0) return DUM;
        int tmp = ((b[i] - r) / d) * xy.fi % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    ((r %= M) += M) %= M;
    return {r, M};
}

signed main() {}
