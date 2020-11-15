---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_E.test.cpp
    title: test/aoj/DPL_1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/MakeVec.hpp\"\ntemplate <class T, class S> T\
    \ make_vec(S x) { return x; }\ntemplate <class T, class... Ts> auto make_vec(size_t\
    \ n, Ts... ts) {\n    return std::vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));\n\
    }\n"
  code: "template <class T, class S> T make_vec(S x) { return x; }\ntemplate <class\
    \ T, class... Ts> auto make_vec(size_t n, Ts... ts) {\n    return std::vector<decltype(make_vec<T>(ts...))>(n,\
    \ make_vec<T>(ts...));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/MakeVec.hpp
  requiredBy: []
  timestamp: '2020-03-29 16:30:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_1_E.test.cpp
  - test/aoj/GRL_1_C.test.cpp
documentation_of: src/Helper/MakeVec.hpp
layout: document
redirect_from:
- /library/src/Helper/MakeVec.hpp
- /library/src/Helper/MakeVec.hpp.html
title: src/Helper/MakeVec.hpp
---
