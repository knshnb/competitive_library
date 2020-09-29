---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/EulerTotient.hpp\"\nint euler_totient(int n) {\n\
    \    vector<int> ps;\n    {\n        int tmp = n;\n        for (int x = 2; x *\
    \ x <= tmp; x++) {\n            if (tmp % x) continue;\n            ps.push_back(x);\n\
    \            while (tmp % x == 0) tmp /= x;\n        }\n        if (tmp != 1)\
    \ ps.push_back(tmp);\n    }\n    int m = ps.size();\n    int ans = 0;\n    for\
    \ (int bit = 0; bit < 1LL << m; bit++) {\n        int d = 1;\n        for (int\
    \ i = 0; i < m; i++) {\n            if (bit >> i & 1) d *= ps[i];\n        }\n\
    \        int sign = __builtin_popcount(bit) % 2 ? -1 : 1;\n        ans += sign\
    \ * (n / d);\n    }\n    return ans;\n}\n"
  code: "int euler_totient(int n) {\n    vector<int> ps;\n    {\n        int tmp =\
    \ n;\n        for (int x = 2; x * x <= tmp; x++) {\n            if (tmp % x) continue;\n\
    \            ps.push_back(x);\n            while (tmp % x == 0) tmp /= x;\n  \
    \      }\n        if (tmp != 1) ps.push_back(tmp);\n    }\n    int m = ps.size();\n\
    \    int ans = 0;\n    for (int bit = 0; bit < 1LL << m; bit++) {\n        int\
    \ d = 1;\n        for (int i = 0; i < m; i++) {\n            if (bit >> i & 1)\
    \ d *= ps[i];\n        }\n        int sign = __builtin_popcount(bit) % 2 ? -1\
    \ : 1;\n        ans += sign * (n / d);\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/EulerTotient.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/EulerTotient.hpp
layout: document
redirect_from:
- /library/src/old/EulerTotient.hpp
- /library/src/old/EulerTotient.hpp.html
title: src/old/EulerTotient.hpp
---
