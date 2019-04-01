// Longest Common Subsequence: O(nm)
vector<vector<int>> LCS(const vector<int>& s, const vector<int>& t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
    }
  }
  return dp;
}
// メモリ節約
vector<vector<int>> LCS2(const vector<int>& s, const vector<int>& t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(2, vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[1][j + 1] = s[i] == t[j] ? dp[0][j] + 1 : max(dp[0][j + 1], dp[1][j]);
    }
    swap(dp[0], dp[1]);
  }
  return dp;
}
