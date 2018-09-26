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
using PD = pair<double, double>;
using VPD = vector<PD>;
using VD = vector<double>;

int N, M;
VI p;
VD a, b;
map<int, int> trans;

class SegTree {
public:
  int n;
  VPD seg;
  SegTree(int n_) {
    n = 1;
    while (n < n_) { n *= 2; }
    seg = VPD(2*n - 1, {1, 0});
  }
  void update(int k, double a, double b) {
    k += n - 1;
    seg[k].first = a;
    seg[k].second = b;
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k].first = seg[k*2+1].first * seg[k*2+2].first;
      seg[k].second = seg[k*2+1].second * seg[k*2+2].first + seg[k*2+2].second;
    }
  }
};

signed main() {
  cin >> N >> M;
  p.resize(M); a.resize(M); b.resize(M);
  REP (i, M) {
    cin >> p[i] >> a[i] >> b[i];
    trans[p[i]] = 1;
  }
  int k = 0;
  for (auto& x: trans) {
    x.second = k++;
  }
  SegTree s(M);
  double mini = 1;
  double maxi = 1;
  REP (i, M) {
    s.update(trans[p[i]], a[i], b[i]);
    double tmp = s.seg[0].first + s.seg[0].second;
    mini = min(mini, tmp);
    maxi = max(maxi, tmp);
  }
  printf("%.10f\n%.10f\n", mini, maxi);
}
