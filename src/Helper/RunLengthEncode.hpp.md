---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/RunLengthEncode.hpp\"\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> run_length_encode(const std::vector<T>& a) {\n    std::vector<std::pair<T,\
    \ int>> ret;\n    int cur = 0;\n    for (int i = 0; i < a.size(); i++) {\n   \
    \     cur++;\n        if (i == a.size() - 1 || a[i] != a[i + 1]) {\n         \
    \   ret.emplace_back(a[i], cur);\n            cur = 0;\n        }\n    }\n   \
    \ return ret;\n}\nstd::vector<std::pair<char, int>> run_length_encode(const std::string&\
    \ a) {\n    std::vector<std::pair<char, int>> ret;\n    int cur = 0;\n    for\
    \ (int i = 0; i < a.size(); i++) {\n        cur++;\n        if (i == a.size()\
    \ - 1 || a[i] != a[i + 1]) {\n            ret.emplace_back(a[i], cur);\n     \
    \       cur = 0;\n        }\n    }\n    return ret;\n}\n"
  code: "template <class T> std::vector<std::pair<T, int>> run_length_encode(const\
    \ std::vector<T>& a) {\n    std::vector<std::pair<T, int>> ret;\n    int cur =\
    \ 0;\n    for (int i = 0; i < a.size(); i++) {\n        cur++;\n        if (i\
    \ == a.size() - 1 || a[i] != a[i + 1]) {\n            ret.emplace_back(a[i], cur);\n\
    \            cur = 0;\n        }\n    }\n    return ret;\n}\nstd::vector<std::pair<char,\
    \ int>> run_length_encode(const std::string& a) {\n    std::vector<std::pair<char,\
    \ int>> ret;\n    int cur = 0;\n    for (int i = 0; i < a.size(); i++) {\n   \
    \     cur++;\n        if (i == a.size() - 1 || a[i] != a[i + 1]) {\n         \
    \   ret.emplace_back(a[i], cur);\n            cur = 0;\n        }\n    }\n   \
    \ return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/RunLengthEncode.hpp
  requiredBy: []
  timestamp: '2020-06-14 18:02:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/RunLengthEncode.hpp
layout: document
redirect_from:
- /library/src/Helper/RunLengthEncode.hpp
- /library/src/Helper/RunLengthEncode.hpp.html
title: src/Helper/RunLengthEncode.hpp
---
