#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define REPI(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define int long long
using namespace std;
using II = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
const int MOD = 1e9 + 7;

// MODにおける階乗とその逆元、事前計算O(N * log(MOD))、参照O(1)
class FactMod {
  int MOD;
  int N;
  // x^a
  int pow(int x, int a) {
    if (a == 0) { return 1; }
    int half = pow(x, a / 2);
    return half * half % MOD * (a % 2 ? x : 1) % MOD;
  }
public:
  VI fact;
  VI fact_inv;
  FactMod(int n = 0, int mod = 1e9 + 7) : N(n), MOD(mod) {
    fact = VI(N + 1); fact[0] = 1;
    REP (i, N) {
      fact[i + 1] = fact[i] * (i + 1) % MOD;
    }
    fact_inv = VI(N + 1); fact_inv[N] = inv(fact[N]);
    for (int i = N - 1; i >= 0; i--) {
      fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;
      assert(fact_inv[i] * fact[i] % MOD == 1);
    }
  }
  // xの逆元 x^(MOD - 2)
  int inv(int x) {
    return pow(x, MOD - 2);
  }
};

signed main() {
}
