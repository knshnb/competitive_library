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

class RMQ {
public:
  int n;
  VI dat;
  const int SML = 0;
  RMQ(int n_) {
    n = 1;
    while (n < n_) { n *= 2; }
    dat = VI(2*n-1, SML);
  }
  // k番目をaに
  void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = max(dat[2*k+1], dat[2*k+2]);
    }
  }
  // k番目のノードの[l, r)について[a, b)を求める
  int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) { return SML; }
    if (a <= l && r <= b) { return dat[k]; }
    int vl = query(a, b, k*2+1, l, (l+r)/2);
    int vr = query(a, b, k*2+2, (l+r)/2, r);
    return max(vl, vr);
  }
  int query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

signed main() {
}
