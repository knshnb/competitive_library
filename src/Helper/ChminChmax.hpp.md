---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549.test.cpp
    title: test/aoj/1549.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_E.test.cpp
    title: test/aoj/DPL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "src/Helper/ChminChmax.hpp"

    template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true :
    false; }

    template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true :
    false; }

    '
  code: 'template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true
    : false; }

    template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true :
    false; }

    '
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/ChminChmax.hpp
  requiredBy: []
  timestamp: '2020-05-24 02:38:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_1_E.test.cpp
  - test/aoj/1549.test.cpp
documentation_of: src/Helper/ChminChmax.hpp
layout: document
redirect_from:
- /library/src/Helper/ChminChmax.hpp
- /library/src/Helper/ChminChmax.hpp.html
title: src/Helper/ChminChmax.hpp
---
