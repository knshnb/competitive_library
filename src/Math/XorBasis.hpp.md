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
  bundledCode: "#line 1 \"src/Math/XorBasis.hpp\"\ntemplate <class T> std::vector<T>\
    \ xor_basis(const std::vector<T>& a) {\n    std::vector<T> regularized, original_basis;\n\
    \    for (const T x : a) {\n        T sweeped = x;\n        for (const T b : regularized)\
    \ sweeped = std::min(sweeped, sweeped ^ b);\n        if (sweeped) regularized.push_back(sweeped),\
    \ original_basis.push_back(x);\n    }\n    return original_basis;\n}\n"
  code: "template <class T> std::vector<T> xor_basis(const std::vector<T>& a) {\n\
    \    std::vector<T> regularized, original_basis;\n    for (const T x : a) {\n\
    \        T sweeped = x;\n        for (const T b : regularized) sweeped = std::min(sweeped,\
    \ sweeped ^ b);\n        if (sweeped) regularized.push_back(sweeped), original_basis.push_back(x);\n\
    \    }\n    return original_basis;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/XorBasis.hpp
  requiredBy: []
  timestamp: '2021-05-08 01:27:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/XorBasis.hpp
layout: document
redirect_from:
- /library/src/Math/XorBasis.hpp
- /library/src/Math/XorBasis.hpp.html
title: src/Math/XorBasis.hpp
---
