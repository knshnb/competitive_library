#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (ll i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << ": " << (x) << endl
#define debug2(x, y) cerr << #x << ": " << (x) << " " << #y << ": " << y << endl;
#define int long long
using namespace std;
using II = pair<int, int>;
using VII = vector<II>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
const int MOD = 1e9 + 7;

// T0: 元の配列のモノイド
// T1: T0に対する作用素モノイド
template <class T0, class T1>
class SegmentTree {
  // k番目のノードにのlazyを伝搬
  void eval(int k, int len) {
    // u1が正確に単位元ならいらない
    // if (lazy[k] == u1) return;
    // len個分のlazy[k]を評価
    node[k] = g(node[k], p(lazy[k], len));
    if (k < N - 1) {
      // 最下段でなければ下のlazyに伝搬
      lazy[2 * k + 1] = f1(lazy[2 * k + 1], lazy[k]);
      lazy[2 * k + 2] = f1(lazy[2 * k + 2], lazy[k]);
    }
    lazy[k] = u1;
  }
  // k番目のノード[l, r)について、[a, b)の範囲内にxを作用
  void update(int a, int b, T1 x, int k, int l, int r) {
    eval(k, r - l);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = f1(lazy[k], x);
      eval(k, r - l);
    } else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = f0(node[2 * k + 1], node[2 * k + 2]);
    }
  }
  // k番目のノード[l, r)について、[a, b)のクエリを求める
  T0 query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return u0;
    eval(k, r - l);
    if (a <= l && r <= b) return node[k];
    T0 vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T0 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return f0(vl, vr);
  }
public:
  int sz; // 元の配列のサイズ
  int N;
  vector<T0> node;
  vector<T1> lazy;
  // T0上の演算、単位元
  using F0 = function<T0(T0, T0)>;
  F0 f0; T0 u0;
  // T1上の演算、単位元
  using F1 = function<T1(T1, T1)>;
  F1 f1; T1 u1;
  // 作用
  using G = function<T0(T0, T1)>;
  G g;
  // 多数のt1(T1)に対するf1の合成
  using P = function<T1(T1, int)>;
  P p;
  SegmentTree(const vector<T0>& a, F0 f0, T0 u0, F1 f1, T1 u1, G g, P p)
  : sz(a.size()), f0(f0), u0(u0), f1(f1), u1(u1), g(g), p(p) {
    for (N = 1; N < sz; N *= 2);
    node.resize(2 * N - 1);
    lazy.resize(2 * N - 1, u1);
    REP (i, sz) node[N - 1 + i] = a[i];
    for (int i = N - 2; i >= 0; i--) node[i] = f0(node[2 * i + 1], node[2 * i + 2]);
  }
  // [a, b)にxを作用
  void update(int a, int b, T1 x) {
    assert(0 <= a && a < b && b <= sz);
    update(a, b, x, 0, 0, N);
  }
  // [a, b)
  T0 query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
};

signed main() {
  // // Min & Update
  // SegmentTree<int, int> seg(
  //   VI(n, (1LL << 31) - 1),
  //   [](int x, int y) { return min(x, y); }, 1e18,
  //   [](int x, int y) { return y == 1e18 ? x : y; }, 1e18,
  //   [](int x, int y) { return y == 1e18 ? x : y; },
  //   [](int y, int len) { return y; }
  // );

  // // Sum & Add
  // SegmentTree<int, int> seg(
  //   VI(n, 0),
  //   plus<int>(), 0,
  //   plus<int>(), 0,
  //   plus<int>(),
  //   multiplies<int>()
  // );

  // // Min & Add
  // SegmentTree<int, int> seg(
  //   VI(n, 0),
  //   [](int x, int y) { return min(x, y); }, 1e18,
  //   plus<int>(), 0,
  //   plus<int>(),
  //   [](int y, int len) { return y; }
  // );

  // // Sum & Update
  // constexpr int u1 = 1e18;
  // SegmentTree<int, int> seg(
  //   VI(n),
  //   plus<int>(), 0,
  //   [](int x, int y) { return y == u1 ? x : y; }, u1,
  //   [](int x, int y) { return y == u1 ? x : y; },
  //   [](int y, int len) { return y == u1 ? u1 : y * len; }
  // );
}