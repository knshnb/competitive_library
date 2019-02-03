#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (int i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define int long long
using namespace std;
using ll = long long;
using II = pair<int, int>; using VII = vector<II>; using VVII = vector<VII>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " "); return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& d) { REP (i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : "\n"); return s; }
template <class T, class S> ostream& operator<<(ostream &s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T, class S> ostream& operator<<(ostream& s, const map<T, S> m) { for (auto it = m.begin(); it != m.end(); it++) { s << *it << (next(it) == m.end() ? "" : "\n"); } return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
#else
  #define dump(...)
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
constexpr int MOD = 1e9 + 7;

struct UnionFind {
  int cnt; // 集合の数
  vector<int> number; // 0以上のとき親のindex, 負のときは集合サイズ
  vector<int> data1, data2; // 連結成分ごとのデータ
  UnionFind(int n) : cnt(n), number(n, -1) {}
  UnionFind(const vector<int>& data1, const vector<int>& data2) :
    cnt(data1.size()), number(data1.size(), -1), data1(data1), data2(data2) {}
  int root(int x) {
    return number[x] < 0 ? x : number[x] = root(number[x]);
  }
  void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (number[y] < number[x]) swap(x, y);
    // yをxにマージ
    number[x] += number[y];
    number[y] = x;
    data1[x] += data1[y]; // dataのマージ方法に合わせて変える
    data2[x] += data2[y]; //
    cnt--;
  }
  bool is_same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -number[root(x)]; }
  int& ref1(int x) { return data1[root(x)]; }
  int& ref2(int x) { return data2[root(x)]; }
};
