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

// 1-indexed であることに注意!
class BIT {
public:
  int n;
  VI dat;
  BIT(int n_) {
    n = n_;
    dat = VI(n+1, 0);
  }
  void add(int i, int x) {
    while (i <= n) {
      dat[i] += x;
      i += i & -i;
    }
  }
  int sum(int i) {
    int acc = 0;
    while (i > 0) {
      acc += dat[i];
      i -= i & -i;
    }
    return acc;
  }
};

