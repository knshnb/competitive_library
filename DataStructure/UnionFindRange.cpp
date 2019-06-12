// 1次元上の要素のマージをしていくときに、各連結成分の[left, right)を更新
struct UnionFind {
  int cnt; // 集合の数
  vector<int> number; // 0以上のとき親のindex, 負のときは集合サイズ
  vector<pair<int, int>> data; // [left, right)
  UnionFind(int n) : cnt(n), number(n, -1), data(n) {
    for (int i = 0; i < n; i++) data[i] = {i, i + 1};
  }
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
    // dataのマージ方法に合わせて変える
    data[x] = {min(data[x].first, data[y].first), max(data[x].second, data[y].second)};
    cnt--;
  }
  bool is_same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -number[root(x)]; }
  int& left(int x) { return data[root(x)].first; }
  int& right(int x) { return data[root(x)].second; }
  pair<int, int>& ref(int x) { return data[root(x)]; }
};
