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

struct Eratosthenes {
  vector<bool> is_prime;
  VI primes;
  Eratosthenes(int n) {
    is_prime = vector<bool>(n, true); is_prime[1] = false;
    REPI (i, 2, n) {
      if (!is_prime[i]) { continue; }
      for (int j = i * 2; j < n; j += i) {
        is_prime[j] = false;
      }
    }
    REPI (i, 2, n) {
      if (is_prime[i]) {
        primes.push_back(i);
      }
    }
  }
};
signed main() {
}
