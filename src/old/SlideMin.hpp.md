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
  bundledCode: "#line 1 \"src/old/SlideMin.hpp\"\n// \u81EA\u5206\u3092\u542B\u3093\
    \u3060K\u500B\u524D\u307E\u3067\u306E\u4E2D\u3067\u306E\u6700\u5C0F\u5024\u306E\
    index\u306E\u914D\u5217\u3092\u8FD4\u3059\n// \u6700\u5C0F(\u6700\u5927)\u5024\
    \u306Eindex\u3092\u8FD4\u3059\u3053\u3068\u306B\u6CE8\u610F!\ntemplate <class\
    \ T = int> vector<int> slide_min(const vector<T>& a, int w, function<bool(T, T)>\
    \ cmp = less<T>()) {\n    int n = a.size();\n    vector<int> ret(n);\n    deque<int>\
    \ dq;\n    for (int i = 0; i < n; i++) {\n        while (!dq.empty() && !cmp(a[dq.back()],\
    \ a[i])) {\n            dq.pop_back();\n        }\n        dq.push_back(i);\n\
    \        while (dq.front() <= i - w) {\n            dq.pop_front();\n        }\n\
    \        ret[i] = dq.front();\n    }\n    return ret;\n}\n"
  code: "// \u81EA\u5206\u3092\u542B\u3093\u3060K\u500B\u524D\u307E\u3067\u306E\u4E2D\
    \u3067\u306E\u6700\u5C0F\u5024\u306Eindex\u306E\u914D\u5217\u3092\u8FD4\u3059\n\
    // \u6700\u5C0F(\u6700\u5927)\u5024\u306Eindex\u3092\u8FD4\u3059\u3053\u3068\u306B\
    \u6CE8\u610F!\ntemplate <class T = int> vector<int> slide_min(const vector<T>&\
    \ a, int w, function<bool(T, T)> cmp = less<T>()) {\n    int n = a.size();\n \
    \   vector<int> ret(n);\n    deque<int> dq;\n    for (int i = 0; i < n; i++) {\n\
    \        while (!dq.empty() && !cmp(a[dq.back()], a[i])) {\n            dq.pop_back();\n\
    \        }\n        dq.push_back(i);\n        while (dq.front() <= i - w) {\n\
    \            dq.pop_front();\n        }\n        ret[i] = dq.front();\n    }\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/SlideMin.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:31:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/SlideMin.hpp
layout: document
redirect_from:
- /library/src/old/SlideMin.hpp
- /library/src/old/SlideMin.hpp.html
title: src/old/SlideMin.hpp
---
