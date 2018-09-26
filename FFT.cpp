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

struct FFT {
  using comp = complex<double>;
  static void fft(vector<comp>& a, bool inv = false) {
    int N = a.size();
    if (N == 1) { return; }
    vector<comp> even(N / 2), odd(N / 2);
    REP (i, N / 2) {
      even[i] = a[2 * i];
      odd[i] = a[2 * i + 1];
    }
    fft(even, inv); fft(odd, inv);
    comp omega = polar(1.0, (-2 * inv + 1) * 2 * M_PI / N);
    comp acc_omega = comp(1);
    REP (i, N / 2) {
      a[i] = even[i] + acc_omega * odd[i];
      a[i + N / 2] = even[i] - acc_omega * odd[i];
      acc_omega *= omega;
    }
  }
  static void conv(VI& a, VI& b) {
    int N = 1;
    while (N < 2 * (max(a.size(), b.size() + 1))) {
      N *= 2;
    }
    vector<comp> ac(N, comp(0)), bc(N, comp(0));
    REP (i, a.size()) { ac[i] = comp(a[i]); }
    REP (i, b.size()) { bc[i] = comp(b[i]); }
    multiply(ac, bc);
    a.resize(N);
    REP (i, N) {
      a[i] = (int)(ac[i].real() + 0.5);
    }
  }
  private:
  static void multiply(vector<comp>& a, vector<comp>& b) {
    int n = a.size();
    fft(a); fft(b);
    REP (i, n) {
      a[i] *= b[i] / comp(n);
    }
    fft(a, true);
  }
};
signed main() {
}
