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
  bundledCode: "#line 1 \"src/old/FFT.hpp\"\nstruct FFT {\n    using comp = complex<double>;\n\
    \    static void fft(vector<comp>& a, bool inv = false) {\n        int N = a.size();\n\
    \        if (N == 1) {\n            return;\n        }\n        vector<comp> even(N\
    \ / 2), odd(N / 2);\n        for (int i = 0; i < N / 2; i++) {\n            even[i]\
    \ = a[2 * i];\n            odd[i] = a[2 * i + 1];\n        }\n        fft(even,\
    \ inv);\n        fft(odd, inv);\n        comp omega = polar(1.0, (-2 * inv + 1)\
    \ * 2 * M_PI / N);\n        comp acc_omega = comp(1);\n        for (int i = 0;\
    \ i < N / 2; i++) {\n            a[i] = even[i] + acc_omega * odd[i];\n      \
    \      a[i + N / 2] = even[i] - acc_omega * odd[i];\n            acc_omega *=\
    \ omega;\n        }\n    }\n    static void conv(vector<int>& a, vector<int>&\
    \ b) {\n        int N = 1;\n        while (N < 2 * (max(a.size(), b.size() + 1)))\
    \ {\n            N *= 2;\n        }\n        vector<comp> ac(N, comp(0)), bc(N,\
    \ comp(0));\n        for (int i = 0; i < a.size(); i++) ac[i] = comp(a[i]);\n\
    \        for (int i = 0; i < b.size(); i++) bc[i] = comp(b[i]);\n        multiply(ac,\
    \ bc);\n        a.resize(N);\n        for (int i = 0; i < N; i++) {\n        \
    \    a[i] = (int)(ac[i].real() + 0.5);\n        }\n    }\n\nprivate:\n    static\
    \ void multiply(vector<comp>& a, vector<comp>& b) {\n        int n = a.size();\n\
    \        fft(a);\n        fft(b);\n        for (int i = 0; i < n; i++) {\n   \
    \         a[i] *= b[i] / comp(n);\n        }\n        fft(a, true);\n    }\n};\n"
  code: "struct FFT {\n    using comp = complex<double>;\n    static void fft(vector<comp>&\
    \ a, bool inv = false) {\n        int N = a.size();\n        if (N == 1) {\n \
    \           return;\n        }\n        vector<comp> even(N / 2), odd(N / 2);\n\
    \        for (int i = 0; i < N / 2; i++) {\n            even[i] = a[2 * i];\n\
    \            odd[i] = a[2 * i + 1];\n        }\n        fft(even, inv);\n    \
    \    fft(odd, inv);\n        comp omega = polar(1.0, (-2 * inv + 1) * 2 * M_PI\
    \ / N);\n        comp acc_omega = comp(1);\n        for (int i = 0; i < N / 2;\
    \ i++) {\n            a[i] = even[i] + acc_omega * odd[i];\n            a[i +\
    \ N / 2] = even[i] - acc_omega * odd[i];\n            acc_omega *= omega;\n  \
    \      }\n    }\n    static void conv(vector<int>& a, vector<int>& b) {\n    \
    \    int N = 1;\n        while (N < 2 * (max(a.size(), b.size() + 1))) {\n   \
    \         N *= 2;\n        }\n        vector<comp> ac(N, comp(0)), bc(N, comp(0));\n\
    \        for (int i = 0; i < a.size(); i++) ac[i] = comp(a[i]);\n        for (int\
    \ i = 0; i < b.size(); i++) bc[i] = comp(b[i]);\n        multiply(ac, bc);\n \
    \       a.resize(N);\n        for (int i = 0; i < N; i++) {\n            a[i]\
    \ = (int)(ac[i].real() + 0.5);\n        }\n    }\n\nprivate:\n    static void\
    \ multiply(vector<comp>& a, vector<comp>& b) {\n        int n = a.size();\n  \
    \      fft(a);\n        fft(b);\n        for (int i = 0; i < n; i++) {\n     \
    \       a[i] *= b[i] / comp(n);\n        }\n        fft(a, true);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/FFT.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/FFT.hpp
layout: document
redirect_from:
- /library/src/old/FFT.hpp
- /library/src/old/FFT.hpp.html
title: src/old/FFT.hpp
---
