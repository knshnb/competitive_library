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

class BIT {
public:
  int n;
  VI dat;
  BIT(int n_) {
    n = n_;
    dat = VI(n, 0);
  }
  void add(int i, int x) {
    i++;
    while (i <= n) {
      dat[i-1] += x;
      i += i & -i;
    }
  }
  int sum(int i) {
    i++;
    int acc = 0;
    while (i > 0) {
      acc += dat[i-1];
      i -= i & -i;
    }
    return acc;
  }
};
