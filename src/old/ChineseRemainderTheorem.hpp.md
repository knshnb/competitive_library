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
  bundledCode: "#line 1 \"src/old/ChineseRemainderTheorem.hpp\"\n// ax + by = gcd(a,\
    \ b) \u3092\u6E80\u305F\u3059(x, y)\npair<int, int> ext_gcd(int a, int b) {\n\
    \    if (b == 0) return {1, 0};\n    pair<int, int> xy = ext_gcd(b, a % b);  //\
    \ b(qx + y) + rx = ...\n    swap(xy.fi, xy.se);\n    xy.se -= (a / b) * xy.fi;\n\
    \    return xy;\n}\nconst pair<int, int> DUM = {0, -1};\n// r = b[i] (mod m[i])\n\
    // r: \u5270\u4F59, M: mod\npair<int, int> chinese_rem(const VI& b, const VI&\
    \ m) {\n    int r = 0, M = 1;\n    for (int i = 0; i < b.size(); i++) {\n    \
    \    pair<int, int> xy = ext_gcd(M, m[i]);\n        int d = __gcd(M, m[i]);\n\
    \        if ((b[i] - r) % d != 0) return DUM;\n        int tmp = ((b[i] - r) /\
    \ d) * xy.fi % (m[i] / d);\n        r += M * tmp;\n        M *= m[i] / d;\n  \
    \  }\n    ((r %= M) += M) %= M;\n    return {r, M};\n}\n\nsigned main() {}\n"
  code: "// ax + by = gcd(a, b) \u3092\u6E80\u305F\u3059(x, y)\npair<int, int> ext_gcd(int\
    \ a, int b) {\n    if (b == 0) return {1, 0};\n    pair<int, int> xy = ext_gcd(b,\
    \ a % b);  // b(qx + y) + rx = ...\n    swap(xy.fi, xy.se);\n    xy.se -= (a /\
    \ b) * xy.fi;\n    return xy;\n}\nconst pair<int, int> DUM = {0, -1};\n// r =\
    \ b[i] (mod m[i])\n// r: \u5270\u4F59, M: mod\npair<int, int> chinese_rem(const\
    \ VI& b, const VI& m) {\n    int r = 0, M = 1;\n    for (int i = 0; i < b.size();\
    \ i++) {\n        pair<int, int> xy = ext_gcd(M, m[i]);\n        int d = __gcd(M,\
    \ m[i]);\n        if ((b[i] - r) % d != 0) return DUM;\n        int tmp = ((b[i]\
    \ - r) / d) * xy.fi % (m[i] / d);\n        r += M * tmp;\n        M *= m[i] /\
    \ d;\n    }\n    ((r %= M) += M) %= M;\n    return {r, M};\n}\n\nsigned main()\
    \ {}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/ChineseRemainderTheorem.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/ChineseRemainderTheorem.hpp
layout: document
redirect_from:
- /library/src/old/ChineseRemainderTheorem.hpp
- /library/src/old/ChineseRemainderTheorem.hpp.html
title: src/old/ChineseRemainderTheorem.hpp
---
