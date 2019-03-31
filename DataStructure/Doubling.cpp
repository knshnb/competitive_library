struct Doubling {
  int BIT; // MSB + 1
  vector<vector<int>> next;
  Doubling(vector<int>& edge, int K = 1LL << 63) : // K = max(k | get(i, k))
  BIT(64 - __builtin_clzll(K)), next(64 - __builtin_clzll(K), vector<int>(edge.size() + 1, edge.size())) {
    for (int i = 0; i < edge.size(); i++) next[0][i] = edge[i];
    for (int bit = 0; bit < BIT - 1; bit++) {
      for (int i = 0; i < edge.size(); i++) {
        next[bit + 1][i] = next[bit][next[bit][i]];
      }
    }
  }
  // i番目のk個先
  int get(int i, int k) {
    int ret = i;
    for (int bit = 0; bit < BIT; bit++) {
      if (!(k >> bit & 1)) continue;
      ret = next[bit][ret];
    }
    return ret;
  }
};
