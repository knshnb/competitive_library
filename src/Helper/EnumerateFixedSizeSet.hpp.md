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
  bundledCode: "#line 1 \"src/Helper/EnumerateFixedSizeSet.hpp\"\n// |S| = k\u306A\
    \u96C6\u5408(nCk)(\u6607\u9806)\nfor (long long S = (1LL << k) - 1; S < (1LL <<\
    \ n);\n     S = ((S | (S - 1)) + 1) | (((~(S | (S - 1)) & -~(S | (S - 1))) - 1)\
    \ >> (__builtin_ctz(S) + 1))) {\n}\n"
  code: "// |S| = k\u306A\u96C6\u5408(nCk)(\u6607\u9806)\nfor (long long S = (1LL\
    \ << k) - 1; S < (1LL << n);\n     S = ((S | (S - 1)) + 1) | (((~(S | (S - 1))\
    \ & -~(S | (S - 1))) - 1) >> (__builtin_ctz(S) + 1))) {\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/EnumerateFixedSizeSet.hpp
  requiredBy: []
  timestamp: '2020-03-29 16:30:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/EnumerateFixedSizeSet.hpp
layout: document
redirect_from:
- /library/src/Helper/EnumerateFixedSizeSet.hpp
- /library/src/Helper/EnumerateFixedSizeSet.hpp.html
title: src/Helper/EnumerateFixedSizeSet.hpp
---
