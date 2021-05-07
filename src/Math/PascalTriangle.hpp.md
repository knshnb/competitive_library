---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: src/Math/PascalTriangle.md
    links: []
  bundledCode: "#line 1 \"src/Math/PascalTriangle.hpp\"\n/// @docs src/Math/PascalTriangle.md\n\
    template <class T = long long> struct PascalTriangle {\n    std::vector<std::vector<T>>\
    \ binom;\n    PascalTriangle(int n) : binom(n + 1, std::vector<T>(n + 1)) {\n\
    \        for (int i = 0; i < n + 1; i++) {\n            binom[i][0] = 1;\n   \
    \         for (int j = 1; j < i + 1; j++) {\n                binom[i][j] = binom[i\
    \ - 1][j - 1] + binom[i - 1][j];\n            }\n        }\n    }\n    // nCr\n\
    \    T operator()(int n, int r) {\n        assert(0 <= n && 0 <= r && r <= n &&\
    \ n <= binom.size());\n        return binom[n][r];\n    }\n};\n"
  code: "/// @docs src/Math/PascalTriangle.md\ntemplate <class T = long long> struct\
    \ PascalTriangle {\n    std::vector<std::vector<T>> binom;\n    PascalTriangle(int\
    \ n) : binom(n + 1, std::vector<T>(n + 1)) {\n        for (int i = 0; i < n +\
    \ 1; i++) {\n            binom[i][0] = 1;\n            for (int j = 1; j < i +\
    \ 1; j++) {\n                binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];\n\
    \            }\n        }\n    }\n    // nCr\n    T operator()(int n, int r) {\n\
    \        assert(0 <= n && 0 <= r && r <= n && n <= binom.size());\n        return\
    \ binom[n][r];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/PascalTriangle.hpp
  requiredBy: []
  timestamp: '2020-06-18 02:53:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/PascalTriangle.hpp
layout: document
redirect_from:
- /library/src/Math/PascalTriangle.hpp
- /library/src/Math/PascalTriangle.hpp.html
title: src/Math/PascalTriangle.hpp
---
## 概要
パスカルの三角形によるコンビネーションテーブルの作成。
O(n^2)。
<br/>
素数でないModで逆元計算ができないときや、整数の範囲で階乗がオーバーフローしてしまうときに使える。

