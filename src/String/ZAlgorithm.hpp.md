---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/String/ZAlgorithm.md
    links: []
  bundledCode: "#line 1 \"src/String/ZAlgorithm.hpp\"\n/// @docs src/String/ZAlgorithm.md\n\
    template <class T> std::vector<int> Z_algorithm(const T& s) {\n    std::vector<int>\
    \ a(s.size());\n    for (int i = 1, rm_idx = 0; i < s.size(); i++) {\n       \
    \ if (a[i - rm_idx] < a[rm_idx] - (i - rm_idx)) {\n            a[i] = a[i - rm_idx];\n\
    \        } else {\n            a[i] = std::max(0, a[rm_idx] - (i - rm_idx));\n\
    \            while (i + a[i] < s.size() && s[a[i]] == s[i + a[i]]) a[i]++;\n \
    \           rm_idx = i;\n        }\n    }\n    a[0] = s.size();\n    return a;\n\
    }\n"
  code: "/// @docs src/String/ZAlgorithm.md\ntemplate <class T> std::vector<int> Z_algorithm(const\
    \ T& s) {\n    std::vector<int> a(s.size());\n    for (int i = 1, rm_idx = 0;\
    \ i < s.size(); i++) {\n        if (a[i - rm_idx] < a[rm_idx] - (i - rm_idx))\
    \ {\n            a[i] = a[i - rm_idx];\n        } else {\n            a[i] = std::max(0,\
    \ a[rm_idx] - (i - rm_idx));\n            while (i + a[i] < s.size() && s[a[i]]\
    \ == s[i + a[i]]) a[i]++;\n            rm_idx = i;\n        }\n    }\n    a[0]\
    \ = s.size();\n    return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/ZAlgorithm.hpp
  requiredBy: []
  timestamp: '2020-04-07 02:27:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/zalgorithm.test.cpp
documentation_of: src/String/ZAlgorithm.hpp
layout: document
redirect_from:
- /library/src/String/ZAlgorithm.hpp
- /library/src/String/ZAlgorithm.hpp.html
title: src/String/ZAlgorithm.hpp
---
## 概要
文字列s[0:]とs[i:]の共通prefixの長さの配列を返す、O(|s|)。

基本的なアイディアは、以前に先頭からの文字列との共通prefixとして計算された値を使い回すこと。
左から順に求める配列aを計算しながら、それまでに一番右まで到達した部分についてaをもう一度たどると先頭とのprefix一致がショートカットできる。

アルゴリズム参考: https://snuke.hatenablog.com/entry/2014/12/03/214243
<br/>
実装のrm_idx(rightmost index)は、それまでに共通prefixとして一番右まで到達したときのインデックスを表す。
苦労して結構うまく実装できたと思ったらsnukeさんのコードとほとんど同じだった、完…
