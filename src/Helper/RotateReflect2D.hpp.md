---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/RotateReflect2D.hpp\"\ntemplate <class T> std::vector<std::vector<T>>\
    \ rotate_2D(const std::vector<std::vector<T>>& t, bool counterclockwise = true)\
    \ {\n    int H = t.size(), W = t[0].size();\n    std::vector<std::vector<T>> ret(W,\
    \ std::vector<T>(H));\n    for (int i = 0; i < H; i++) {\n        for (int j =\
    \ 0; j < W; j++) {\n            ret[j][i] = counterclockwise ? t[i][W - 1 - j]\
    \ : t[H - 1 - i][j];\n        }\n    }\n    return ret;\n}\n\ntemplate <class\
    \ T> std::vector<std::vector<T>> reflect_2D(const std::vector<std::vector<T>>&\
    \ t) {\n    int H = t.size(), W = t[0].size();\n    std::vector<std::vector<T>>\
    \ ret(W, std::vector<T>(H));\n    for (int i = 0; i < H; i++) {\n        for (int\
    \ j = 0; j < W; j++) {\n            ret[j][i] = t[i][j];\n        }\n    }\n \
    \   return ret;\n}\n"
  code: "template <class T> std::vector<std::vector<T>> rotate_2D(const std::vector<std::vector<T>>&\
    \ t, bool counterclockwise = true) {\n    int H = t.size(), W = t[0].size();\n\
    \    std::vector<std::vector<T>> ret(W, std::vector<T>(H));\n    for (int i =\
    \ 0; i < H; i++) {\n        for (int j = 0; j < W; j++) {\n            ret[j][i]\
    \ = counterclockwise ? t[i][W - 1 - j] : t[H - 1 - i][j];\n        }\n    }\n\
    \    return ret;\n}\n\ntemplate <class T> std::vector<std::vector<T>> reflect_2D(const\
    \ std::vector<std::vector<T>>& t) {\n    int H = t.size(), W = t[0].size();\n\
    \    std::vector<std::vector<T>> ret(W, std::vector<T>(H));\n    for (int i =\
    \ 0; i < H; i++) {\n        for (int j = 0; j < W; j++) {\n            ret[j][i]\
    \ = t[i][j];\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/RotateReflect2D.hpp
  requiredBy: []
  timestamp: '2020-05-10 22:28:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/RotateReflect2D.hpp
layout: document
redirect_from:
- /library/src/Helper/RotateReflect2D.hpp
- /library/src/Helper/RotateReflect2D.hpp.html
title: src/Helper/RotateReflect2D.hpp
---
