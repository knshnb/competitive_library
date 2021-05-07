---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/String/SuffixArray.md
    links: []
  bundledCode: "#line 1 \"src/String/SuffixArray.hpp\"\n/// @docs src/String/SuffixArray.md\n\
    class SuffixArray {\n    std::vector<int> sa_is(const std::vector<int>& str, const\
    \ int k) {\n        const int n = str.size();\n        std::vector<bool> is_S(n);\n\
    \        is_S[n - 1] = true;\n        std::vector<bool> is_LMS(n);\n        std::vector<int>\
    \ LMSs;\n        for (int i = n - 2; i >= 0; i--) {\n            is_S[i] = str[i]\
    \ < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);\n        }\n        for\
    \ (int i = 0; i < n; i++) {\n            if (is_S[i] & (i == 0 || !is_S[i - 1]))\
    \ {\n                is_LMS[i] = true;\n                LMSs.push_back(i);\n \
    \           }\n        }\n        std::vector<int> pseudo_sa = induced_sort(str,\
    \ LMSs, is_S, k);\n        std::vector<int> orderedLMSs(LMSs.size());\n      \
    \  int index = 0;\n        for (int x : pseudo_sa) {\n            if (is_LMS[x])\
    \ {\n                orderedLMSs[index++] = x;\n            }\n        }\n   \
    \     pseudo_sa[orderedLMSs[0]] = 0;\n        int rank = 0;\n        if (orderedLMSs.size()\
    \ > 1) {\n            pseudo_sa[orderedLMSs[1]] = ++rank;\n        }\n       \
    \ for (int i =  1; i < orderedLMSs.size() - 1; i++) {\n            bool is_diff\
    \ = false;\n            for (int j = 0; j < n; j++) {\n                int p =\
    \ orderedLMSs[i] + j;\n                int q = orderedLMSs[i + 1] + j;\n     \
    \           if (str[p] != str[q] || is_LMS[p] != is_LMS[q]) {\n              \
    \      is_diff = true;\n                    break;\n                }\n      \
    \          if (j > 0 && is_LMS[p]) {\n                    break;\n           \
    \     }\n            }\n            pseudo_sa[orderedLMSs[i + 1]] = is_diff ?\
    \ ++rank : rank;\n        }\n        std::vector<int> new_str(LMSs.size());\n\
    \        index = 0;\n        for (int i = 0; i < n; i++) {\n            if (is_LMS[i])\
    \ {\n                new_str[index++] = pseudo_sa[i];\n            }\n       \
    \ }\n        std::vector<int> LMS_sa;\n        if (rank + 1 == LMSs.size()) {\n\
    \            LMS_sa = orderedLMSs;\n        } else {\n            LMS_sa = sa_is(new_str,\
    \ rank + 1);\n            for (int& x : LMS_sa) {\n                x = LMSs[x];\n\
    \            }\n        }\n        return induced_sort(str, LMS_sa, is_S, k);\n\
    \    }\n\n    std::vector<int> induced_sort(const std::vector<int>& str, const\
    \ std::vector<int>& LMSs, const std::vector<bool>& is_S, const int k) {\n    \
    \    int n = str.size();\n        std::vector<int> buckets(n);\n        std::vector<int>\
    \ chars(k + 1);\n        for (int c : str) {\n            chars[c + 1]++;\n  \
    \      }\n        for (int i = 0; i < k; i++) { chars[i + 1] += chars[i]; }\n\
    \        std::vector<int> count(k);\n        for (int i = LMSs.size() - 1; i >=\
    \ 0; i--) {\n            int c = str[LMSs[i]];\n            buckets[chars[c +\
    \ 1] - 1 - count[c]++] = LMSs[i];\n        }\n        count = std::vector<int>(k);\n\
    \        for (int i = 0; i < n; i++) {\n            if (buckets[i] == 0 || is_S[buckets[i]\
    \ - 1]) {\n                continue;\n            }\n            int c = str[buckets[i]\
    \ - 1];\n            buckets[chars[c] + count[c]++] = buckets[i] - 1;\n      \
    \  }\n        count = std::vector<int>(k);\n        for (int i = n - 1; i >= 0;\
    \ i--) {\n            if (buckets[i] == 0 || !is_S[buckets[i] - 1]) {\n      \
    \          continue;\n            }\n            int c = str[buckets[i] - 1];\n\
    \            buckets[chars[c + 1] - 1 - count[c]++] = buckets[i] - 1;\n      \
    \  }\n        return buckets;\n    }\n\npublic:\n    std::string S;\n    int N;\n\
    \    std::vector<int> sa;  // sa[i]: suffix\u304C\u8F9E\u66F8\u9806i\u756A\u76EE\
    \u3068\u306A\u308B\u958B\u59CB\u4F4D\u7F6E\u306Eindex\n    SuffixArray(std::string\
    \ str_in) : S(str_in), N(str_in.size()) {\n        str_in += \"$\";\n        std::vector<int>\
    \ str(N + 1);\n        for (int i = 0; i < N + 1; i++) { str[i] = str_in[i] -\
    \ '$'; }\n        sa = sa_is(str, 128);\n        sa.erase(sa.begin());\n    }\n\
    \    int operator[](int index) { return sa[index]; }\n\n    // size\u304CT\u3068\
    \u7B49\u3057\u304F\u521D\u3081\u3066T\u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\
    \u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sa)\n    std::vector<int>::iterator\
    \ lower_bound(std::string T) {\n        int l = -1, r = N;\n        while (r -\
    \ l > 1) {\n            int mid = (l + r) / 2;\n            if (S.compare(sa[mid],\
    \ T.size(), T) < 0) {\n                l = mid;\n            } else {\n      \
    \          r = mid;\n            }\n        }\n        return sa.begin() + r;\n\
    \    }\n\n    // size\u304CT\u3068\u7B49\u3057\u304F\u521D\u3081\u3066T\u3088\u308A\
    \u5927\u304D\u304F\u306A\u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\u6587\u5B57\
    \u5217(sa)\n    std::vector<int>::iterator upper_bound(std::string T) {\n    \
    \    int l = -1, r = N;\n        while (r - l > 1) {\n            int mid = (l\
    \ + r) / 2;\n            if (S.compare(sa[mid], T.size(), T) <= 0) {\n       \
    \         l = mid;\n            } else {\n                r = mid;\n         \
    \   }\n        }\n        return sa.begin() + r;\n    }\n\n    // S2\u304C\u90E8\
    \u5206\u6587\u5B57\u5217\u3068\u3057\u3066\u4F55\u56DE\u51FA\u73FE\u3059\u308B\
    \u304B\n    int count(std::string S2) { return upper_bound(S2) - lower_bound(S2);\
    \ }\n};\n"
  code: "/// @docs src/String/SuffixArray.md\nclass SuffixArray {\n    std::vector<int>\
    \ sa_is(const std::vector<int>& str, const int k) {\n        const int n = str.size();\n\
    \        std::vector<bool> is_S(n);\n        is_S[n - 1] = true;\n        std::vector<bool>\
    \ is_LMS(n);\n        std::vector<int> LMSs;\n        for (int i = n - 2; i >=\
    \ 0; i--) {\n            is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1]\
    \ && is_S[i + 1]);\n        }\n        for (int i = 0; i < n; i++) {\n       \
    \     if (is_S[i] & (i == 0 || !is_S[i - 1])) {\n                is_LMS[i] = true;\n\
    \                LMSs.push_back(i);\n            }\n        }\n        std::vector<int>\
    \ pseudo_sa = induced_sort(str, LMSs, is_S, k);\n        std::vector<int> orderedLMSs(LMSs.size());\n\
    \        int index = 0;\n        for (int x : pseudo_sa) {\n            if (is_LMS[x])\
    \ {\n                orderedLMSs[index++] = x;\n            }\n        }\n   \
    \     pseudo_sa[orderedLMSs[0]] = 0;\n        int rank = 0;\n        if (orderedLMSs.size()\
    \ > 1) {\n            pseudo_sa[orderedLMSs[1]] = ++rank;\n        }\n       \
    \ for (int i =  1; i < orderedLMSs.size() - 1; i++) {\n            bool is_diff\
    \ = false;\n            for (int j = 0; j < n; j++) {\n                int p =\
    \ orderedLMSs[i] + j;\n                int q = orderedLMSs[i + 1] + j;\n     \
    \           if (str[p] != str[q] || is_LMS[p] != is_LMS[q]) {\n              \
    \      is_diff = true;\n                    break;\n                }\n      \
    \          if (j > 0 && is_LMS[p]) {\n                    break;\n           \
    \     }\n            }\n            pseudo_sa[orderedLMSs[i + 1]] = is_diff ?\
    \ ++rank : rank;\n        }\n        std::vector<int> new_str(LMSs.size());\n\
    \        index = 0;\n        for (int i = 0; i < n; i++) {\n            if (is_LMS[i])\
    \ {\n                new_str[index++] = pseudo_sa[i];\n            }\n       \
    \ }\n        std::vector<int> LMS_sa;\n        if (rank + 1 == LMSs.size()) {\n\
    \            LMS_sa = orderedLMSs;\n        } else {\n            LMS_sa = sa_is(new_str,\
    \ rank + 1);\n            for (int& x : LMS_sa) {\n                x = LMSs[x];\n\
    \            }\n        }\n        return induced_sort(str, LMS_sa, is_S, k);\n\
    \    }\n\n    std::vector<int> induced_sort(const std::vector<int>& str, const\
    \ std::vector<int>& LMSs, const std::vector<bool>& is_S, const int k) {\n    \
    \    int n = str.size();\n        std::vector<int> buckets(n);\n        std::vector<int>\
    \ chars(k + 1);\n        for (int c : str) {\n            chars[c + 1]++;\n  \
    \      }\n        for (int i = 0; i < k; i++) { chars[i + 1] += chars[i]; }\n\
    \        std::vector<int> count(k);\n        for (int i = LMSs.size() - 1; i >=\
    \ 0; i--) {\n            int c = str[LMSs[i]];\n            buckets[chars[c +\
    \ 1] - 1 - count[c]++] = LMSs[i];\n        }\n        count = std::vector<int>(k);\n\
    \        for (int i = 0; i < n; i++) {\n            if (buckets[i] == 0 || is_S[buckets[i]\
    \ - 1]) {\n                continue;\n            }\n            int c = str[buckets[i]\
    \ - 1];\n            buckets[chars[c] + count[c]++] = buckets[i] - 1;\n      \
    \  }\n        count = std::vector<int>(k);\n        for (int i = n - 1; i >= 0;\
    \ i--) {\n            if (buckets[i] == 0 || !is_S[buckets[i] - 1]) {\n      \
    \          continue;\n            }\n            int c = str[buckets[i] - 1];\n\
    \            buckets[chars[c + 1] - 1 - count[c]++] = buckets[i] - 1;\n      \
    \  }\n        return buckets;\n    }\n\npublic:\n    std::string S;\n    int N;\n\
    \    std::vector<int> sa;  // sa[i]: suffix\u304C\u8F9E\u66F8\u9806i\u756A\u76EE\
    \u3068\u306A\u308B\u958B\u59CB\u4F4D\u7F6E\u306Eindex\n    SuffixArray(std::string\
    \ str_in) : S(str_in), N(str_in.size()) {\n        str_in += \"$\";\n        std::vector<int>\
    \ str(N + 1);\n        for (int i = 0; i < N + 1; i++) { str[i] = str_in[i] -\
    \ '$'; }\n        sa = sa_is(str, 128);\n        sa.erase(sa.begin());\n    }\n\
    \    int operator[](int index) { return sa[index]; }\n\n    // size\u304CT\u3068\
    \u7B49\u3057\u304F\u521D\u3081\u3066T\u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\
    \u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sa)\n    std::vector<int>::iterator\
    \ lower_bound(std::string T) {\n        int l = -1, r = N;\n        while (r -\
    \ l > 1) {\n            int mid = (l + r) / 2;\n            if (S.compare(sa[mid],\
    \ T.size(), T) < 0) {\n                l = mid;\n            } else {\n      \
    \          r = mid;\n            }\n        }\n        return sa.begin() + r;\n\
    \    }\n\n    // size\u304CT\u3068\u7B49\u3057\u304F\u521D\u3081\u3066T\u3088\u308A\
    \u5927\u304D\u304F\u306A\u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\u6587\u5B57\
    \u5217(sa)\n    std::vector<int>::iterator upper_bound(std::string T) {\n    \
    \    int l = -1, r = N;\n        while (r - l > 1) {\n            int mid = (l\
    \ + r) / 2;\n            if (S.compare(sa[mid], T.size(), T) <= 0) {\n       \
    \         l = mid;\n            } else {\n                r = mid;\n         \
    \   }\n        }\n        return sa.begin() + r;\n    }\n\n    // S2\u304C\u90E8\
    \u5206\u6587\u5B57\u5217\u3068\u3057\u3066\u4F55\u56DE\u51FA\u73FE\u3059\u308B\
    \u304B\n    int count(std::string S2) { return upper_bound(S2) - lower_bound(S2);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/SuffixArray.hpp
  requiredBy: []
  timestamp: '2020-04-10 21:10:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/suffixarray.test.cpp
documentation_of: src/String/SuffixArray.hpp
layout: document
redirect_from:
- /library/src/String/SuffixArray.hpp
- /library/src/String/SuffixArray.hpp.html
title: src/String/SuffixArray.hpp
---
## 概要
SA-ISによるSuffix Arrayの実装。構築O(N)
