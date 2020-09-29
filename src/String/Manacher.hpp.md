---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/String/Manacher.hpp\"\ntemplate <class T> vector<int>\
    \ manacher(const vector<T>& s) {\n    vector<int> R(s.size());\n    int i = 0,\
    \ j = 0;\n    while (i < s.size()) {\n        while (i - j >= 0 && i + j < s.size()\
    \ && s[i - j] == s[i + j]) ++j;\n        R[i] = j;\n        int k = 1;\n     \
    \   while (i - k >= 0 && i + k < s.size() && k + R[i - k] < j) R[i + k] = R[i\
    \ - k], ++k;\n        i += k;\n        j -= k;\n    }\n    return R;\n}\n\nstruct\
    \ Manacher {\n    vector<int> a;\n    template <class T> Manacher(const vector<T>&\
    \ s, T DUMMY = -1) {\n        int m = s.size() * 2 - 1;\n        vector<T> t(m,\
    \ DUMMY);\n        for (int i = 0; i < s.size(); i++) {\n            t[i * 2]\
    \ = s[i];\n        }\n        a = manacher(t);\n    }\n    Manacher(const string&\
    \ s, char DUMMY = '$') {\n        int m = s.size() * 2 - 1;\n        vector<char>\
    \ t(m, DUMMY);\n        for (int i = 0; i < s.size(); i++) {\n            t[i\
    \ * 2] = s[i];\n        }\n        a = manacher(t);\n    }\n\n    // [l, r)\u304C\
    \u56DE\u6587\u304B\u3069\u3046\u304B\n    bool is_palindrome(int l, int r) { return\
    \ a[l + r - 1] >= r - l; }\n};\n"
  code: "template <class T> vector<int> manacher(const vector<T>& s) {\n    vector<int>\
    \ R(s.size());\n    int i = 0, j = 0;\n    while (i < s.size()) {\n        while\
    \ (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) ++j;\n        R[i]\
    \ = j;\n        int k = 1;\n        while (i - k >= 0 && i + k < s.size() && k\
    \ + R[i - k] < j) R[i + k] = R[i - k], ++k;\n        i += k;\n        j -= k;\n\
    \    }\n    return R;\n}\n\nstruct Manacher {\n    vector<int> a;\n    template\
    \ <class T> Manacher(const vector<T>& s, T DUMMY = -1) {\n        int m = s.size()\
    \ * 2 - 1;\n        vector<T> t(m, DUMMY);\n        for (int i = 0; i < s.size();\
    \ i++) {\n            t[i * 2] = s[i];\n        }\n        a = manacher(t);\n\
    \    }\n    Manacher(const string& s, char DUMMY = '$') {\n        int m = s.size()\
    \ * 2 - 1;\n        vector<char> t(m, DUMMY);\n        for (int i = 0; i < s.size();\
    \ i++) {\n            t[i * 2] = s[i];\n        }\n        a = manacher(t);\n\
    \    }\n\n    // [l, r)\u304C\u56DE\u6587\u304B\u3069\u3046\u304B\n    bool is_palindrome(int\
    \ l, int r) { return a[l + r - 1] >= r - l; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/Manacher.hpp
  requiredBy: []
  timestamp: '2020-03-29 16:30:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/Manacher.hpp
layout: document
redirect_from:
- /library/src/String/Manacher.hpp
- /library/src/String/Manacher.hpp.html
title: src/String/Manacher.hpp
---
