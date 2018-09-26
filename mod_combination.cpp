#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define REPI(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define int long long
using namespace std;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;

const int MOD = 1e9 + 7;
VI fact, inv;
int pow_mod(int x, int a) {
  if (a == 1) { return x; }
  int tmp = pow_mod(x, a / 2);
  int rest = a % 2 ? x : 1;
  return tmp * tmp % MOD * rest % MOD;
}
void init_fact_inv(int n) {
  fact = VI(n+1);
  inv = VI(n+1);
  fact[0] = 1;
  REP (i, n) {
    fact[i+1] = fact[i] * (i+1) % MOD;
  }
  inv[n] = pow_mod(fact[n], MOD - 2);
  assert(fact[n] * inv[n] % MOD == 1);
  for (int i = n-1; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % MOD;
    assert(fact[i] * inv[i] % MOD == 1);
  }
}
int comb(int n, int r) {
  return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
}
