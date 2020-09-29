---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Helper/ArithmeticParser.hpp\"\n// \u56DB\u5247\u6F14\
    \u7B97\u306EParser\n#include <bits/stdc++.h>\n#define int long long\nusing namespace\
    \ std;\n\n// exp1 = exp2 [ ('+'|'-') exp2 ]*\n// exp2 = exp3 [ ('*'|'/') exp3\
    \ ]*\n// exp3 = '(' exp1 ')' | number\n\nint exp1(const string& s, int& i);\n\
    int exp2(const string& s, int& i);\nint exp3(const string& s, int& i);\nint number(const\
    \ string& s, int& i);\nint exp1(const string& s, int& i) {\n    int acc = exp2(s,\
    \ i);\n    while (1) {\n        if (s[i] == '+')\n            acc += exp2(s, ++i);\n\
    \        else if (s[i] == '-')\n            acc -= exp2(s, ++i);\n        else\n\
    \            return acc;\n    }\n}\nint exp2(const string& s, int& i) {\n    int\
    \ acc = exp3(s, i);\n    while (1) {\n        if (s[i] == '*')\n            acc\
    \ *= exp3(s, ++i);\n        else if (s[i] == '/')\n            acc /= exp3(s,\
    \ ++i);\n        else\n            return acc;\n    }\n}\nint exp3(const string&\
    \ s, int& i) {\n    if (s[i] == '(') {\n        int ret = exp1(s, ++i);\n    \
    \    assert(s[i] == ')');\n        i++;\n        return ret;\n    }\n    return\
    \ number(s, i);\n}\nint number(const string& s, int& i) {\n    int acc = 0;\n\
    \    while (isdigit(s[i])) {\n        acc = acc * 10 + (s[i++] - '0');\n    }\n\
    \    return acc;\n}\n\nvoid solve() {\n    string s;\n    cin >> s;\n    int i\
    \ = 0;\n    cout << exp1(s, i) << endl;\n    assert(s[i] == '=');\n}\nsigned main()\
    \ {\n    int T;\n    cin >> T;\n    while (T--) solve();\n}\n"
  code: "// \u56DB\u5247\u6F14\u7B97\u306EParser\n#include <bits/stdc++.h>\n#define\
    \ int long long\nusing namespace std;\n\n// exp1 = exp2 [ ('+'|'-') exp2 ]*\n\
    // exp2 = exp3 [ ('*'|'/') exp3 ]*\n// exp3 = '(' exp1 ')' | number\n\nint exp1(const\
    \ string& s, int& i);\nint exp2(const string& s, int& i);\nint exp3(const string&\
    \ s, int& i);\nint number(const string& s, int& i);\nint exp1(const string& s,\
    \ int& i) {\n    int acc = exp2(s, i);\n    while (1) {\n        if (s[i] == '+')\n\
    \            acc += exp2(s, ++i);\n        else if (s[i] == '-')\n           \
    \ acc -= exp2(s, ++i);\n        else\n            return acc;\n    }\n}\nint exp2(const\
    \ string& s, int& i) {\n    int acc = exp3(s, i);\n    while (1) {\n        if\
    \ (s[i] == '*')\n            acc *= exp3(s, ++i);\n        else if (s[i] == '/')\n\
    \            acc /= exp3(s, ++i);\n        else\n            return acc;\n   \
    \ }\n}\nint exp3(const string& s, int& i) {\n    if (s[i] == '(') {\n        int\
    \ ret = exp1(s, ++i);\n        assert(s[i] == ')');\n        i++;\n        return\
    \ ret;\n    }\n    return number(s, i);\n}\nint number(const string& s, int& i)\
    \ {\n    int acc = 0;\n    while (isdigit(s[i])) {\n        acc = acc * 10 + (s[i++]\
    \ - '0');\n    }\n    return acc;\n}\n\nvoid solve() {\n    string s;\n    cin\
    \ >> s;\n    int i = 0;\n    cout << exp1(s, i) << endl;\n    assert(s[i] == '=');\n\
    }\nsigned main() {\n    int T;\n    cin >> T;\n    while (T--) solve();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/ArithmeticParser.hpp
  requiredBy: []
  timestamp: '2020-03-29 16:30:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/ArithmeticParser.hpp
layout: document
redirect_from:
- /library/src/Helper/ArithmeticParser.hpp
- /library/src/Helper/ArithmeticParser.hpp.html
title: src/Helper/ArithmeticParser.hpp
---
