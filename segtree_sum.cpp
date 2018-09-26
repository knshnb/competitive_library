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

class SegTree {
public:
  int n;
  VI dat;
  const int INITIAL = 0;
  SegTree(int n_) {
    n = 1;
    while (n < n_) { n *= 2; }
    dat = VI(2*n-1, INITIAL);
  }
  // k番目をaに
  void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = dat[2*k+1] + dat[2*k+2];
    }
  }
  // k番目のノードの[l, r)について[a, b)を求める
  int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) { return 0; }
    if (a <= l && r <= b) { return dat[k]; }
    int vl = query(a, b, k*2+1, l, (l+r)/2);
    int vr = query(a, b, k*2+2, (l+r)/2, r);
    return vl + vr;
  }
  int query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

const int MOD = 1e9 + 7;
int N;
VI a;

void solve() {
  VI fact(N + 1); fact[0] = 1;
  REP (i, N) {
    fact[i+1] = fact[i] * (i+1) % MOD;
  }
  SegTree seg(N);
  int ans = 1;
  REP (i, N) {
    ans += (a[i] - seg.query(0, a[i])) * fact[N-i-1] % MOD;
    ans %= MOD;
    seg.update(a[i], 1);
  }
  cout << ans << endl;
}

signed main() {
  cin >> N;
  a.resize(N);
  REP (i, N) {
    cin >> a[i]; a[i]--;
  }
  solve();
}
