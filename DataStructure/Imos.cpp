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

const int MAX_TIME = 1e5;
int N;
VI S, T;

void solve() {
  VI imos(MAX_TIME+1, 0);
  REP (i, N) {
    imos[S[i]] += 1;
    imos[T[i]] -= 1;
  }
  REP (i, MAX_TIME) {
    imos[i+1] += imos[i];
  }
  assert(imos[MAX_TIME] == 0);
}
