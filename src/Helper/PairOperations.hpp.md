---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/PairOperations.hpp\"\ntemplate <class A, class\
    \ B, class C, class D>\nstd::pair<A, B>& operator+=(std::pair<A, B>& x, const\
    \ std::pair<C, D>& y) {\n    return x = {x.first + y.first, x.second + y.second};\n\
    }\ntemplate <class A, class B, class C, class D> std::pair<A, B> operator+(std::pair<A,\
    \ B> x, const std::pair<C, D>& y) {\n    return x += y;\n}\ntemplate <class T,\
    \ class integer> T& get(std::vector<std::vector<T>>& v, const std::pair<integer,\
    \ integer>& p) {\n    return v[p.first][p.second];\n}\n"
  code: "template <class A, class B, class C, class D>\nstd::pair<A, B>& operator+=(std::pair<A,\
    \ B>& x, const std::pair<C, D>& y) {\n    return x = {x.first + y.first, x.second\
    \ + y.second};\n}\ntemplate <class A, class B, class C, class D> std::pair<A,\
    \ B> operator+(std::pair<A, B> x, const std::pair<C, D>& y) {\n    return x +=\
    \ y;\n}\ntemplate <class T, class integer> T& get(std::vector<std::vector<T>>&\
    \ v, const std::pair<integer, integer>& p) {\n    return v[p.first][p.second];\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/PairOperations.hpp
  requiredBy: []
  timestamp: '2020-06-06 22:51:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/PairOperations.hpp
layout: document
redirect_from:
- /library/src/Helper/PairOperations.hpp
- /library/src/Helper/PairOperations.hpp.html
title: src/Helper/PairOperations.hpp
---
