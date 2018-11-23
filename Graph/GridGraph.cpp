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
#define int long long
using namespace std;
using II = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
template <class T = int> inline T in() { T x; cin >> x; return x; }
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
const int MOD = 1e9 + 7;

// 二次元Grid Graphの斜め方向の累積和
class GridGraph {
  // queryを計算しやすいようにaccの範囲外の値も便宜的に定義
  int acc_any(int i, int j) {
    if (i + j < 0 || H + W - 1 <= i + j) return 0;
    if (i < 0 || j >= W) return 0;
    if (j < 0 && i + j < H) return acc[i + j][0];
    if (i >= H && i + j >= H) return acc[H - 1][i + j - (H - 1)];
    return acc[i][j];
  }
public:
  VVI t; int H, W;
  VVI acc;
  GridGraph(VVI& tbl) : t(tbl), H(tbl.size()), W(tbl[0].size()) {
    set_acc();
  }
  VI& operator[](int i) {
    return t[i];
  }
  bool exist(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W && t[i][j];
  }
  // 左下方向への累積和
  void set_acc() {
    acc = VVI(H, VI(W));
    REP (i, H) {
      REP (j, W) {
        int before = (i == 0 || j == W - 1) ? 0 : acc[i - 1][j + 1];
        acc[i][j] = before + t[i][j];
      }
    }
  }
  // 時計回りに90度回転
  void rotate() {
    VVI t2(W, VI(H));
    REP (i, H) {
      REP (j, W) {
        t2[j][H - i - 1] = t[i][j];
      }
    }
    t = t2;
    swap(H, W);
    set_acc();
  }
  // [i0, i1)の斜めのsum
  int query(int i0, int j0, int i1, int j1) {
    assert(i0 + j0 == i1 + j1);
    assert(i1 > i0);
    return acc_any(i1 - 1, j1 + 1) - acc_any(i0 - 1, j0 + 1);
  }
};

signed main() {
}
