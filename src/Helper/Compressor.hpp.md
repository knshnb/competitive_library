---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/Compressor.hpp\"\ntemplate <class T> struct Compressor\
    \ {\n    std::vector<T> val;\n    void insert(T x) { val.push_back(x); }\n   \
    \ void insert(const std::vector<T>& v) { val.insert(val.begin(), v.begin(), v.end());\
    \ }\n    void build() {\n        std::sort(val.begin(), val.end());\n        val.erase(std::unique(val.begin(),\
    \ val.end()), val.end());\n    }\n    int operator()(T x) { return std::lower_bound(val.begin(),\
    \ val.end(), x) - val.begin(); }\n    T operator[](int idx) { return val[idx];\
    \ }\n    int size() { return val.size(); }\n};\n"
  code: "template <class T> struct Compressor {\n    std::vector<T> val;\n    void\
    \ insert(T x) { val.push_back(x); }\n    void insert(const std::vector<T>& v)\
    \ { val.insert(val.begin(), v.begin(), v.end()); }\n    void build() {\n     \
    \   std::sort(val.begin(), val.end());\n        val.erase(std::unique(val.begin(),\
    \ val.end()), val.end());\n    }\n    int operator()(T x) { return std::lower_bound(val.begin(),\
    \ val.end(), x) - val.begin(); }\n    T operator[](int idx) { return val[idx];\
    \ }\n    int size() { return val.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/Compressor.hpp
  requiredBy: []
  timestamp: '2020-08-15 16:14:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: src/Helper/Compressor.hpp
layout: document
redirect_from:
- /library/src/Helper/Compressor.hpp
- /library/src/Helper/Compressor.hpp.html
title: src/Helper/Compressor.hpp
---
