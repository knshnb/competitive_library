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
  bundledCode: "#line 1 \"src/old/GridGraph.hpp\"\n// \u4E8C\u6B21\u5143Grid Graph\u306E\
    \u659C\u3081\u65B9\u5411\u306E\u7D2F\u7A4D\u548C\nclass GridGraph {\n    // query\u3092\
    \u8A08\u7B97\u3057\u3084\u3059\u3044\u3088\u3046\u306Bacc\u306E\u7BC4\u56F2\u5916\
    \u306E\u5024\u3082\u4FBF\u5B9C\u7684\u306B\u5B9A\u7FA9\n    int acc_any(int i,\
    \ int j) {\n        if (i + j < 0 || H + W - 1 <= i + j) return 0;\n        if\
    \ (i < 0 || j >= W) return 0;\n        if (j < 0 && i + j < H) return acc[i +\
    \ j][0];\n        if (i >= H && i + j >= H) return acc[H - 1][i + j - (H - 1)];\n\
    \        return acc[i][j];\n    }\n\npublic:\n    VVI t;\n    int H, W;\n    VVI\
    \ acc;\n    GridGraph(VVI& tbl) : t(tbl), H(tbl.size()), W(tbl[0].size()) { set_acc();\
    \ }\n    VI& operator[](int i) { return t[i]; }\n    bool exist(int i, int j)\
    \ { return 0 <= i && i < H && 0 <= j && j < W && t[i][j]; }\n    // \u5DE6\u4E0B\
    \u65B9\u5411\u3078\u306E\u7D2F\u7A4D\u548C\n    void set_acc() {\n        acc\
    \ = VVI(H, VI(W));\n        REP(i, H) {\n            REP(j, W) {\n           \
    \     int before = (i == 0 || j == W - 1) ? 0 : acc[i - 1][j + 1];\n         \
    \       acc[i][j] = before + t[i][j];\n            }\n        }\n    }\n    //\
    \ \u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\n    void rotate() {\n  \
    \      VVI t2(W, VI(H));\n        REP(i, H) {\n            REP(j, W) { t2[j][H\
    \ - i - 1] = t[i][j]; }\n        }\n        t = t2;\n        swap(H, W);\n   \
    \     set_acc();\n    }\n    // [i0, i1)\u306E\u659C\u3081\u306Esum\n    int query(int\
    \ i0, int j0, int i1, int j1) {\n        assert(i0 + j0 == i1 + j1);\n       \
    \ assert(i1 > i0);\n        return acc_any(i1 - 1, j1 + 1) - acc_any(i0 - 1, j0\
    \ + 1);\n    }\n};\n\nsigned main() {}\n"
  code: "// \u4E8C\u6B21\u5143Grid Graph\u306E\u659C\u3081\u65B9\u5411\u306E\u7D2F\
    \u7A4D\u548C\nclass GridGraph {\n    // query\u3092\u8A08\u7B97\u3057\u3084\u3059\
    \u3044\u3088\u3046\u306Bacc\u306E\u7BC4\u56F2\u5916\u306E\u5024\u3082\u4FBF\u5B9C\
    \u7684\u306B\u5B9A\u7FA9\n    int acc_any(int i, int j) {\n        if (i + j <\
    \ 0 || H + W - 1 <= i + j) return 0;\n        if (i < 0 || j >= W) return 0;\n\
    \        if (j < 0 && i + j < H) return acc[i + j][0];\n        if (i >= H &&\
    \ i + j >= H) return acc[H - 1][i + j - (H - 1)];\n        return acc[i][j];\n\
    \    }\n\npublic:\n    VVI t;\n    int H, W;\n    VVI acc;\n    GridGraph(VVI&\
    \ tbl) : t(tbl), H(tbl.size()), W(tbl[0].size()) { set_acc(); }\n    VI& operator[](int\
    \ i) { return t[i]; }\n    bool exist(int i, int j) { return 0 <= i && i < H &&\
    \ 0 <= j && j < W && t[i][j]; }\n    // \u5DE6\u4E0B\u65B9\u5411\u3078\u306E\u7D2F\
    \u7A4D\u548C\n    void set_acc() {\n        acc = VVI(H, VI(W));\n        REP(i,\
    \ H) {\n            REP(j, W) {\n                int before = (i == 0 || j ==\
    \ W - 1) ? 0 : acc[i - 1][j + 1];\n                acc[i][j] = before + t[i][j];\n\
    \            }\n        }\n    }\n    // \u6642\u8A08\u56DE\u308A\u306B90\u5EA6\
    \u56DE\u8EE2\n    void rotate() {\n        VVI t2(W, VI(H));\n        REP(i, H)\
    \ {\n            REP(j, W) { t2[j][H - i - 1] = t[i][j]; }\n        }\n      \
    \  t = t2;\n        swap(H, W);\n        set_acc();\n    }\n    // [i0, i1)\u306E\
    \u659C\u3081\u306Esum\n    int query(int i0, int j0, int i1, int j1) {\n     \
    \   assert(i0 + j0 == i1 + j1);\n        assert(i1 > i0);\n        return acc_any(i1\
    \ - 1, j1 + 1) - acc_any(i0 - 1, j0 + 1);\n    }\n};\n\nsigned main() {}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/GridGraph.hpp
  requiredBy: []
  timestamp: '2020-04-28 00:07:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/GridGraph.hpp
layout: document
redirect_from:
- /library/src/old/GridGraph.hpp
- /library/src/old/GridGraph.hpp.html
title: src/old/GridGraph.hpp
---
