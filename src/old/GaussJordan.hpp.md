---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/GaussJordan.hpp\"\n// A[n-1]\u306B\u306FAx = b\u306E\
    b\u306E\u5024\ntemplate <class T> void gauss_jordan(vector<vector<T>>& A) {\n\
    \    int n = A.size(), m = A[0].size();\n    vector<bool> used(n);\n    for (int\
    \ col = 0; col < m - 1; col++) {\n        int pivot = -1;\n        for (int row\
    \ = 0; row < n; row++) {\n            if (!used[row] && A[row][col] != 0) {\n\
    \                pivot = row;\n                break;\n            }\n       \
    \ }\n        if (pivot == -1) continue;\n        used[pivot] = true;\n       \
    \ for (int row = 0; row < n; row++) {\n            if (row == pivot) continue;\n\
    \            T d = A[row][col] / A[pivot][col];  // \u500D\u7387\n           \
    \ for (int col2 = 0; col2 < m; col2++) {\n                A[row][col2] -= A[pivot][col2]\
    \ * d;\n            }\n        }\n    }\n}\n"
  code: "// A[n-1]\u306B\u306FAx = b\u306Eb\u306E\u5024\ntemplate <class T> void gauss_jordan(vector<vector<T>>&\
    \ A) {\n    int n = A.size(), m = A[0].size();\n    vector<bool> used(n);\n  \
    \  for (int col = 0; col < m - 1; col++) {\n        int pivot = -1;\n        for\
    \ (int row = 0; row < n; row++) {\n            if (!used[row] && A[row][col] !=\
    \ 0) {\n                pivot = row;\n                break;\n            }\n\
    \        }\n        if (pivot == -1) continue;\n        used[pivot] = true;\n\
    \        for (int row = 0; row < n; row++) {\n            if (row == pivot) continue;\n\
    \            T d = A[row][col] / A[pivot][col];  // \u500D\u7387\n           \
    \ for (int col2 = 0; col2 < m; col2++) {\n                A[row][col2] -= A[pivot][col2]\
    \ * d;\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/GaussJordan.hpp
  requiredBy: []
  timestamp: '2020-06-13 20:39:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/GaussJordan.hpp
layout: document
redirect_from:
- /library/src/old/GaussJordan.hpp
- /library/src/old/GaussJordan.hpp.html
title: src/old/GaussJordan.hpp
---
