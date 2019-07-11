// Erdos-Gallai theorem: (O(n))
// https://en.wikipedia.org/wiki/Erdős–Gallai_theorem
bool is_graphic(const VI& d) {
  int n = d.size();
  if (accumulate(ALL(d), 0LL) % 2) return false;
  VI acc(n + 1);
  REP (i, n) {
    acc[i + 1] = acc[i] + d[i];
  }
  int l = n - 1; // d[l] >= i + 1を満たす最大のl
  REP (i, n) {
    int lhs = acc[i + 1];
    while (l >= i + 1 && d[l] < i + 1) l--;
    // [i + 1, l]: i + 1, [l + 1, n - 1]: acc
    int rhs = i * (i + 1) + (i + 1) * (l - i) + (acc[n] - acc[l + 1]);
    if (lhs > rhs) return false;
  }
  return true;
}

signed main() {
  // verify: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/3925879
  int n; cin >> n;
  VI d(n);
  REP (i, n) cin >> d[i];

  sort(RALL(d));
  if (is_graphic(d)) {
    cout << "YES" << endl;
  } else {
    d.back() += 1;
    sort(RALL(d));
    if (is_graphic(d)) {
      cout << "NO" << endl;
    } else {
      cout << "ABSOLUTELY NO" << endl;
    }
  }
}
