---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/3925879
    - "https://en.wikipedia.org/wiki/Erd\u0151s\u2013Gallai_theorem"
  bundledCode: "#line 1 \"src/old/ErdosGallai.hpp\"\n// Erdos-Gallai theorem: (O(n))\n\
    // https://en.wikipedia.org/wiki/Erd\u0151s\u2013Gallai_theorem\nbool is_graphic(const\
    \ VI& d) {\n    int n = d.size();\n    if (accumulate(ALL(d), 0LL) % 2) return\
    \ false;\n    VI acc(n + 1);\n    REP(i, n) { acc[i + 1] = acc[i] + d[i]; }\n\
    \    int l = n - 1;  // d[l] >= i + 1\u3092\u6E80\u305F\u3059\u6700\u5927\u306E\
    l\n    REP(i, n) {\n        int lhs = acc[i + 1];\n        while (l >= i + 1 &&\
    \ d[l] < i + 1) l--;\n        // [i + 1, l]: i + 1, [l + 1, n - 1]: acc\n    \
    \    int rhs = i * (i + 1) + (i + 1) * (l - i) + (acc[n] - acc[l + 1]);\n    \
    \    if (lhs > rhs) return false;\n    }\n    return true;\n}\n\nsigned main()\
    \ {\n    // verify: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/3925879\n\
    \    int n;\n    cin >> n;\n    VI d(n);\n    REP(i, n) cin >> d[i];\n\n    sort(RALL(d));\n\
    \    if (is_graphic(d)) {\n        cout << \"YES\" << endl;\n    } else {\n  \
    \      d.back() += 1;\n        sort(RALL(d));\n        if (is_graphic(d)) {\n\
    \            cout << \"NO\" << endl;\n        } else {\n            cout << \"\
    ABSOLUTELY NO\" << endl;\n        }\n    }\n}\n"
  code: "// Erdos-Gallai theorem: (O(n))\n// https://en.wikipedia.org/wiki/Erd\u0151\
    s\u2013Gallai_theorem\nbool is_graphic(const VI& d) {\n    int n = d.size();\n\
    \    if (accumulate(ALL(d), 0LL) % 2) return false;\n    VI acc(n + 1);\n    REP(i,\
    \ n) { acc[i + 1] = acc[i] + d[i]; }\n    int l = n - 1;  // d[l] >= i + 1\u3092\
    \u6E80\u305F\u3059\u6700\u5927\u306El\n    REP(i, n) {\n        int lhs = acc[i\
    \ + 1];\n        while (l >= i + 1 && d[l] < i + 1) l--;\n        // [i + 1, l]:\
    \ i + 1, [l + 1, n - 1]: acc\n        int rhs = i * (i + 1) + (i + 1) * (l - i)\
    \ + (acc[n] - acc[l + 1]);\n        if (lhs > rhs) return false;\n    }\n    return\
    \ true;\n}\n\nsigned main() {\n    // verify: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/3925879\n\
    \    int n;\n    cin >> n;\n    VI d(n);\n    REP(i, n) cin >> d[i];\n\n    sort(RALL(d));\n\
    \    if (is_graphic(d)) {\n        cout << \"YES\" << endl;\n    } else {\n  \
    \      d.back() += 1;\n        sort(RALL(d));\n        if (is_graphic(d)) {\n\
    \            cout << \"NO\" << endl;\n        } else {\n            cout << \"\
    ABSOLUTELY NO\" << endl;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/ErdosGallai.hpp
  requiredBy: []
  timestamp: '2020-06-13 20:39:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/ErdosGallai.hpp
layout: document
redirect_from:
- /library/src/old/ErdosGallai.hpp
- /library/src/old/ErdosGallai.hpp.html
title: src/old/ErdosGallai.hpp
---
