---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0646.test.cpp
    title: test/aoj/0646.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/Helper/BinarySearch.md
    links: []
  bundledCode: "#line 1 \"src/Helper/BinarySearch.hpp\"\n/// @docs src/Helper/BinarySearch.md\n\
    template <class F> long long binary_search(long long ok, long long ng, F check)\
    \ {\n    while (std::abs(ok - ng) > 1) {\n        long long mid = (ok + ng) /\
    \ 2;\n        (check(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n"
  code: "/// @docs src/Helper/BinarySearch.md\ntemplate <class F> long long binary_search(long\
    \ long ok, long long ng, F check) {\n    while (std::abs(ok - ng) > 1) {\n   \
    \     long long mid = (ok + ng) / 2;\n        (check(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/BinarySearch.hpp
  requiredBy: []
  timestamp: '2020-04-28 01:08:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0646.test.cpp
documentation_of: src/Helper/BinarySearch.hpp
layout: document
redirect_from:
- /library/src/Helper/BinarySearch.hpp
- /library/src/Helper/BinarySearch.hpp.html
title: src/Helper/BinarySearch.hpp
---
## 概要
整数の範囲についての二分探索。計算量はO(log |ok - ng|)。
