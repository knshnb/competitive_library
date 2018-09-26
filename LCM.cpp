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

int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}
int lcm(int x, int y) {
  return x * y / gcd(x, y);
}

signed main() {
}
