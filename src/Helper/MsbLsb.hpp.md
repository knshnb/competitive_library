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
  bundledCode: "#line 1 \"src/Helper/MsbLsb.hpp\"\nint get_msb(long long x) {\n  \
    \  assert(x != 0);\n    return 63 - __builtin_clzll(x);\n}\nint get_lsb(long long\
    \ x) {\n    assert(x != 0);\n    return __builtin_ctzll(x);\n}\n"
  code: "int get_msb(long long x) {\n    assert(x != 0);\n    return 63 - __builtin_clzll(x);\n\
    }\nint get_lsb(long long x) {\n    assert(x != 0);\n    return __builtin_ctzll(x);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/MsbLsb.hpp
  requiredBy: []
  timestamp: '2020-03-29 16:30:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/MsbLsb.hpp
layout: document
redirect_from:
- /library/src/Helper/MsbLsb.hpp
- /library/src/Helper/MsbLsb.hpp.html
title: src/Helper/MsbLsb.hpp
---
