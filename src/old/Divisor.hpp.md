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
  bundledCode: "#line 1 \"src/old/Divisor.hpp\"\n// ret[x]: x\u306E\u7D04\u6570\u306E\
    vector\n// \u69CB\u7BC9: O(nlogn)\nvector<vector<signed>> divisor(signed n) {\n\
    \    vector<vector<signed>> ret(n + 1);\n    for (signed i = 1; i < n + 1; i++)\
    \ {\n        ret[i].reserve(log(n) + 1);\n    }\n    for (signed i = 1; i < n\
    \ + 1; i++) {\n        for (signed j = i; j < n + 1; j += i) {\n            ret[j].push_back(i);\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "// ret[x]: x\u306E\u7D04\u6570\u306Evector\n// \u69CB\u7BC9: O(nlogn)\nvector<vector<signed>>\
    \ divisor(signed n) {\n    vector<vector<signed>> ret(n + 1);\n    for (signed\
    \ i = 1; i < n + 1; i++) {\n        ret[i].reserve(log(n) + 1);\n    }\n    for\
    \ (signed i = 1; i < n + 1; i++) {\n        for (signed j = i; j < n + 1; j +=\
    \ i) {\n            ret[j].push_back(i);\n        }\n    }\n    return ret;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/Divisor.hpp
  requiredBy: []
  timestamp: '2020-06-13 20:39:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/Divisor.hpp
layout: document
redirect_from:
- /library/src/old/Divisor.hpp
- /library/src/old/Divisor.hpp.html
title: src/old/Divisor.hpp
---
