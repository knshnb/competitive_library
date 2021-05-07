---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/LongestCommonSubsequence.hpp\"\n// Longest Common\
    \ Subsequence: O(nm)\nvector<vector<int>> LCS(const vector<int>& s, const vector<int>&\
    \ t) {\n    int n = s.size(), m = t.size();\n    vector<vector<int>> dp(n + 1,\
    \ vector<int>(m + 1));\n    for (int i = 0; i < n; i++) {\n        for (int j\
    \ = 0; j < m; j++) {\n            dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] +\
    \ 1 : max(dp[i][j + 1], dp[i + 1][j]);\n        }\n    }\n    return dp;\n}\n\
    // \u30E1\u30E2\u30EA\u7BC0\u7D04\nvector<vector<int>> LCS2(const vector<int>&\
    \ s, const vector<int>& t) {\n    int n = s.size(), m = t.size();\n    vector<vector<int>>\
    \ dp(2, vector<int>(m + 1));\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ j = 0; j < m; j++) {\n            dp[1][j + 1] = s[i] == t[j] ? dp[0][j] + 1\
    \ : max(dp[0][j + 1], dp[1][j]);\n        }\n        swap(dp[0], dp[1]);\n   \
    \ }\n    return dp;\n}\n"
  code: "// Longest Common Subsequence: O(nm)\nvector<vector<int>> LCS(const vector<int>&\
    \ s, const vector<int>& t) {\n    int n = s.size(), m = t.size();\n    vector<vector<int>>\
    \ dp(n + 1, vector<int>(m + 1));\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j = 0; j < m; j++) {\n            dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j]\
    \ + 1 : max(dp[i][j + 1], dp[i + 1][j]);\n        }\n    }\n    return dp;\n}\n\
    // \u30E1\u30E2\u30EA\u7BC0\u7D04\nvector<vector<int>> LCS2(const vector<int>&\
    \ s, const vector<int>& t) {\n    int n = s.size(), m = t.size();\n    vector<vector<int>>\
    \ dp(2, vector<int>(m + 1));\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ j = 0; j < m; j++) {\n            dp[1][j + 1] = s[i] == t[j] ? dp[0][j] + 1\
    \ : max(dp[0][j + 1], dp[1][j]);\n        }\n        swap(dp[0], dp[1]);\n   \
    \ }\n    return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/LongestCommonSubsequence.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/LongestCommonSubsequence.hpp
layout: document
redirect_from:
- /library/src/old/LongestCommonSubsequence.hpp
- /library/src/old/LongestCommonSubsequence.hpp.html
title: src/old/LongestCommonSubsequence.hpp
---
