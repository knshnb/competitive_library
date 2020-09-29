---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/Doubling.hpp\"\nstruct Doubling {\n  \
    \  int n;\n    int size;                            // MSB + 1\n    std::vector<std::vector<int>>\
    \ next;  // next[k][i]: i\u304B\u3089(1<<k)\u56DE\u3067\u3069\u3053\u307E\u3067\
    \u9032\u3081\u308B\u304B\n\n    // edge[i]: 1\u56DE\u3067i\u304B\u3089\u3069\u3053\
    \u307E\u3067\u9032\u3081\u308B\u304B\n    Doubling(std::vector<int>& edge) : n(edge.size()),\
    \ size(64 - __builtin_clzll(edge.size())) {\n        next.resize(size, std::vector<int>(n\
    \ + 1, n));\n        for (int i = 0; i < n; i++) next[0][i] = edge[i];\n     \
    \   for (int k = 0; k < size - 1; k++) {\n            for (int i = 0; i < n; i++)\
    \ {\n                next[k + 1][i] = next[k][next[k][i]];\n            }\n  \
    \      }\n    }\n    // i\u756A\u76EE\u306Ex\u500B\u5148\n    int get(int i, int\
    \ x) {\n        int ret = i;\n        for (int bit = 0; bit < size; bit++) {\n\
    \            if (!(x >> bit & 1)) continue;\n            ret = next[bit][ret];\n\
    \        }\n        return ret;\n    }\n    // i\u304B\u3089\u306F\u3058\u3081\
    \u3066\u4F55\u56DE\u9032\u3081\u3070\u521D\u3081\u3066j\u4EE5\u4E0A\u306B\u306A\
    \u308B\u304B\n    // j\u4EE5\u4E0A\u306B\u306A\u308A\u3048\u306A\u3044\u3068\u304D\
    \u306Fn\u3092\u8FD4\u3059\n    int lower_bound(int i, int j) {\n        int cur\
    \ = i, acc = 0;\n        for (int wid = size - 1; wid >= 0; wid--) {\n       \
    \     if (next[wid][cur] < j) {\n                acc += 1LL << wid;\n        \
    \        cur = next[wid][cur];\n            }\n        }\n        return std::min(n,\
    \ acc + 1);\n    }\n};\n"
  code: "struct Doubling {\n    int n;\n    int size;                            //\
    \ MSB + 1\n    std::vector<std::vector<int>> next;  // next[k][i]: i\u304B\u3089\
    (1<<k)\u56DE\u3067\u3069\u3053\u307E\u3067\u9032\u3081\u308B\u304B\n\n    // edge[i]:\
    \ 1\u56DE\u3067i\u304B\u3089\u3069\u3053\u307E\u3067\u9032\u3081\u308B\u304B\n\
    \    Doubling(std::vector<int>& edge) : n(edge.size()), size(64 - __builtin_clzll(edge.size()))\
    \ {\n        next.resize(size, std::vector<int>(n + 1, n));\n        for (int\
    \ i = 0; i < n; i++) next[0][i] = edge[i];\n        for (int k = 0; k < size -\
    \ 1; k++) {\n            for (int i = 0; i < n; i++) {\n                next[k\
    \ + 1][i] = next[k][next[k][i]];\n            }\n        }\n    }\n    // i\u756A\
    \u76EE\u306Ex\u500B\u5148\n    int get(int i, int x) {\n        int ret = i;\n\
    \        for (int bit = 0; bit < size; bit++) {\n            if (!(x >> bit &\
    \ 1)) continue;\n            ret = next[bit][ret];\n        }\n        return\
    \ ret;\n    }\n    // i\u304B\u3089\u306F\u3058\u3081\u3066\u4F55\u56DE\u9032\u3081\
    \u3070\u521D\u3081\u3066j\u4EE5\u4E0A\u306B\u306A\u308B\u304B\n    // j\u4EE5\u4E0A\
    \u306B\u306A\u308A\u3048\u306A\u3044\u3068\u304D\u306Fn\u3092\u8FD4\u3059\n  \
    \  int lower_bound(int i, int j) {\n        int cur = i, acc = 0;\n        for\
    \ (int wid = size - 1; wid >= 0; wid--) {\n            if (next[wid][cur] < j)\
    \ {\n                acc += 1LL << wid;\n                cur = next[wid][cur];\n\
    \            }\n        }\n        return std::min(n, acc + 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/Doubling.hpp
  requiredBy: []
  timestamp: '2020-05-10 22:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/Doubling.hpp
layout: document
redirect_from:
- /library/src/DataStructure/Doubling.hpp
- /library/src/DataStructure/Doubling.hpp.html
title: src/DataStructure/Doubling.hpp
---
