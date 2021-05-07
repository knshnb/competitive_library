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
  bundledCode: "#line 1 \"src/String/Trie.hpp\"\ntemplate <char margin = 'A', int\
    \ char_size = 26> struct Trie {\n    struct TrieNode {\n        std::array<int,\
    \ char_size> node;\n        TrieNode() { node.fill(-1); };\n        typename std::array<int,\
    \ char_size>::iterator begin() { return node.begin(); }\n        typename std::array<int,\
    \ char_size>::iterator end() { return node.end(); }\n        int& operator[](int\
    \ i) { return node[i]; }\n    };\n    std::vector<TrieNode> tree;\n    std::vector<int>\
    \ num;  // \u90E8\u5206\u6728\u5185\u306E\u500B\u6570\n    Trie() : tree(1), num(1)\
    \ {}\n    void insert(const std::string& s) {\n        num[0]++;\n        int\
    \ t = 0;\n        for (char c : s) {\n            int d = c - margin;\n      \
    \      if (tree[t][d] == -1) {\n                tree[t][d] = tree.size();\n  \
    \              tree.emplace_back();\n                num.push_back(0);\n     \
    \       }\n            t = tree[t][d];\n            num[t]++;\n        }\n   \
    \ }\n    void erase(const std::string& s) {\n        int par = 0;\n        num[par]--;\n\
    \        for (char c : s) {\n            int d = c - margin;\n            int\
    \ nxt = tree[par][d];\n            assert(nxt != -1 && \"s does not exist\");\n\
    \            if (--num[nxt] == 0) tree[par][d] = -1;\n            par = nxt;\n\
    \        }\n    }\n};\n"
  code: "template <char margin = 'A', int char_size = 26> struct Trie {\n    struct\
    \ TrieNode {\n        std::array<int, char_size> node;\n        TrieNode() { node.fill(-1);\
    \ };\n        typename std::array<int, char_size>::iterator begin() { return node.begin();\
    \ }\n        typename std::array<int, char_size>::iterator end() { return node.end();\
    \ }\n        int& operator[](int i) { return node[i]; }\n    };\n    std::vector<TrieNode>\
    \ tree;\n    std::vector<int> num;  // \u90E8\u5206\u6728\u5185\u306E\u500B\u6570\
    \n    Trie() : tree(1), num(1) {}\n    void insert(const std::string& s) {\n \
    \       num[0]++;\n        int t = 0;\n        for (char c : s) {\n          \
    \  int d = c - margin;\n            if (tree[t][d] == -1) {\n                tree[t][d]\
    \ = tree.size();\n                tree.emplace_back();\n                num.push_back(0);\n\
    \            }\n            t = tree[t][d];\n            num[t]++;\n        }\n\
    \    }\n    void erase(const std::string& s) {\n        int par = 0;\n       \
    \ num[par]--;\n        for (char c : s) {\n            int d = c - margin;\n \
    \           int nxt = tree[par][d];\n            assert(nxt != -1 && \"s does\
    \ not exist\");\n            if (--num[nxt] == 0) tree[par][d] = -1;\n       \
    \     par = nxt;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/Trie.hpp
  requiredBy: []
  timestamp: '2020-08-26 20:43:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/Trie.hpp
layout: document
redirect_from:
- /library/src/String/Trie.hpp
- /library/src/String/Trie.hpp.html
title: src/String/Trie.hpp
---
