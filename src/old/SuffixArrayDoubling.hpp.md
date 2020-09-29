---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/SuffixArrayDoubling.hpp\"\ntemplate <class T = int>\
    \ class SegTree {\n    using VT = vector<T>;\n    int orig_n;\n    // k\u756A\u76EE\
    \u306E\u30CE\u30FC\u30C9\u306E[l, r)\u306B\u3064\u3044\u3066[a, b)\u3092\u6C42\
    \u3081\u308B\n    T query(int a, int b, int k, int l, int r) {\n        if (r\
    \ <= a || b <= l) {\n            return UNIT;\n        }\n        if (a <= l &&\
    \ r <= b) {\n            return dat[k];\n        }\n        T vl = query(a, b,\
    \ k * 2 + 1, l, (l + r) / 2);\n        T vr = query(a, b, k * 2 + 2, (l + r) /\
    \ 2, r);\n        return f(vl, vr);\n    }\n\npublic:\n    int N;\n    VT dat;\n\
    \    function<T(T, T)> f;\n    int UNIT;\n    SegTree(int n, function<T(T, T)>\
    \ f_, const T unit) {\n        orig_n = n;\n        f = f_;\n        UNIT = unit;\n\
    \        for (N = 1; N < n; N *= 2)\n            ;\n        dat = VT(2 * N - 1,\
    \ UNIT);\n    }\n    SegTree(\n        VT a = {}, function<T(T, T)> f_ = [](int\
    \ a, int b) { return min(a, b); }, T unit = 1e15) {\n        orig_n = a.size();\n\
    \        f = f_;\n        UNIT = unit;\n        for (N = 1; N < a.size(); N *=\
    \ 2)\n            ;\n        dat = VT(2 * N - 1);\n        REP(i, a.size()) {\
    \ dat[N - 1 + i] = a[i]; }\n        for (int k = N - 2; k >= 0; k--) {\n     \
    \       dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);\n        }\n    }\n    //\
    \ k\u756A\u76EE\u3092a\u306B\n    void update(int k, int a) {\n        k += N\
    \ - 1;\n        dat[k] = a;\n        while (k > 0) {\n            k = (k - 1)\
    \ / 2;\n            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);\n        }\n \
    \   }\n    // [a, b)\u3067\u306E\u30AF\u30A8\u30EA\n    T query(int a, int b)\
    \ {\n        assert(0 <= a && a < b && b <= orig_n);\n        return query(a,\
    \ b, 0, 0, N);\n    }\n};\n\nclass SuffixArray {\n    SegTree<> rmq;\n    void\
    \ set_lcp() {\n        // S[i]\u3092\u9806\u756A\u306B\u898B\u3066\u3044\u304D\
    S[i - 1] -\u30001\u6587\u5B57\u4EE5\u4E0A\u304C\u5171\u901A\u3059\u308B\u3053\u3068\
    \u3092\u5229\u7528\u3057\u3066\u3057\u3083\u304F\u3068\u308A\n        lcp_next_rank\
    \ = vector<int>(N);\n        int h = 0;\n        REP(i, N) {\n            if (h\
    \ > 0) h--;\n            if (rank[i] == N - 1) continue;\n            int j =\
    \ sorted[rank[i] + 1];  // \u6BD4\u3079\u308B\u5BFE\u8C61(\u8F9E\u66F8\u9806\u304C\
    \u4E00\u3064\u5927\u304D\u3044\u3082\u306E)\n            for (; i + h < N && j\
    \ + h < N; h++) {\n                if (S[i + h] != S[j + h]) break;\n        \
    \    }\n            lcp_next_rank[rank[i]] = h;\n        }\n        // S[i..],\
    \ S[j..]\u306Elcp\u304C\u6C42\u3081\u3089\u308C\u308B\u3088\u3046\u306BRMQ\u4E0A\
    \u306B\u306E\u305B\u308B\n        rmq = SegTree<int>(\n            lcp_next_rank,\
    \ [](int a, int b) { return min(a, b); }, 1e15);\n    }\n\npublic:\n    int N;\n\
    \    string S;\n    vector<int> rank;    // rank[i]: i\u304B\u3089\u59CB\u307E\
    \u308Bsuffix\u306E\u8F9E\u66F8\u9806\u3067\u306E\u9806\u4F4D\n    vector<int>\
    \ sorted;  // sorted[i]: suffix\u304C\u8F9E\u66F8\u9806i\u756A\u76EE\u3068\u306A\
    \u308B\u958B\u59CB\u4F4D\u7F6E\u306Eindex\n    vector<int> lcp_next_rank;  //\
    \ lcp[i]: S[sorted[i]..]\u3068S[sorted[i + 1]..]\u304C\u5148\u982D\u4F55\u6587\
    \u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3001lcp[N - 1] = 0\n    SuffixArray(string\
    \ s) {\n        S = s;\n        N = S.size();\n        sorted = vector<int>(N);\n\
    \        rank = vector<int>(N);\n        REP(i, N) {\n            sorted[i] =\
    \ i;\n            rank[i] = S[i];\n        }\n\n        int k;\n        function<bool(int,\
    \ int)> compare_sa = [this, &k](int i, int j) {\n            if (rank[i] != rank[j])\
    \ {\n                return rank[i] < rank[j];\n            }\n            int\
    \ ri = i + k < N ? rank[i + k] : -1;\n            int rj = j + k < N ? rank[j\
    \ + k] : -1;\n            return ri < rj;\n        };\n\n        for (k = 1; k\
    \ < N; k *= 2) {\n            sort(sorted.begin(), sorted.end(), compare_sa);\n\
    \            vector<int> tmp(N, 0);\n            REPI(i, 1, N) { tmp[sorted[i]]\
    \ = tmp[sorted[i - 1]] + compare_sa(sorted[i - 1], sorted[i]); }\n           \
    \ rank = tmp;\n        }\n        set_lcp();\n    }\n\n    // size\u304CT\u3068\
    \u7B49\u3057\u304F\u521D\u3081\u3066T\u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\
    \u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sorted\u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u8FD4\u3059)\n    vector<int>::iterator lower_bound(string T) {\n\
    \        int l = -1, r = N;\n        while (r - l > 1) {\n            int mid\
    \ = (l + r) / 2;\n            if (S.compare(sorted[mid], T.size(), T) < 0) {\n\
    \                l = mid;\n            } else {\n                r = mid;\n  \
    \          }\n        }\n        return sorted.begin() + r;\n    }\n\n    // size\u304C\
    T\u3068\u7B49\u3057\u304F\u521D\u3081\u3066T\u3088\u308A\u5927\u304D\u304F\u306A\
    \u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sorted\u306E\u30A4\
    \u30C6\u30EC\u30FC\u30BF\u3092\u8FD4\u3059)\n    vector<int>::iterator upper_bound(string\
    \ T) {\n        int l = -1, r = N;\n        while (r - l > 1) {\n            int\
    \ mid = (l + r) / 2;\n            if (S.compare(sorted[mid], T.size(), T) <= 0)\
    \ {\n                l = mid;\n            } else {\n                r = mid;\n\
    \            }\n        }\n        return sorted.begin() + r;\n    }\n\n    //\
    \ S2\u304C\u90E8\u5206\u6587\u5B57\u5217\u3068\u3057\u3066\u4F55\u56DE\u51FA\u73FE\
    \u3059\u308B\u304B\n    int count(string S2) { return upper_bound(S2) - lower_bound(S2);\
    \ }\n\n    // S[i..], S[j..]\u304C\u5148\u982D\u4F55\u6587\u5B57\u4E00\u81F4\u3057\
    \u3066\u3044\u308B\u304B\n    int lcp(int i, int j) {\n        assert(0 <= i &&\
    \ 0 <= j && i < N && j < N);\n        if (i == j) return N - i;\n        int l\
    \ = min(rank[i], rank[j]);\n        int r = max(rank[i], rank[j]);\n        return\
    \ rmq.query(l, r);\n    }\n};\n"
  code: "template <class T = int> class SegTree {\n    using VT = vector<T>;\n   \
    \ int orig_n;\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306E[l, r)\u306B\u3064\
    \u3044\u3066[a, b)\u3092\u6C42\u3081\u308B\n    T query(int a, int b, int k, int\
    \ l, int r) {\n        if (r <= a || b <= l) {\n            return UNIT;\n   \
    \     }\n        if (a <= l && r <= b) {\n            return dat[k];\n       \
    \ }\n        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);\n        T vr = query(a,\
    \ b, k * 2 + 2, (l + r) / 2, r);\n        return f(vl, vr);\n    }\n\npublic:\n\
    \    int N;\n    VT dat;\n    function<T(T, T)> f;\n    int UNIT;\n    SegTree(int\
    \ n, function<T(T, T)> f_, const T unit) {\n        orig_n = n;\n        f = f_;\n\
    \        UNIT = unit;\n        for (N = 1; N < n; N *= 2)\n            ;\n   \
    \     dat = VT(2 * N - 1, UNIT);\n    }\n    SegTree(\n        VT a = {}, function<T(T,\
    \ T)> f_ = [](int a, int b) { return min(a, b); }, T unit = 1e15) {\n        orig_n\
    \ = a.size();\n        f = f_;\n        UNIT = unit;\n        for (N = 1; N <\
    \ a.size(); N *= 2)\n            ;\n        dat = VT(2 * N - 1);\n        REP(i,\
    \ a.size()) { dat[N - 1 + i] = a[i]; }\n        for (int k = N - 2; k >= 0; k--)\
    \ {\n            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);\n        }\n    }\n\
    \    // k\u756A\u76EE\u3092a\u306B\n    void update(int k, int a) {\n        k\
    \ += N - 1;\n        dat[k] = a;\n        while (k > 0) {\n            k = (k\
    \ - 1) / 2;\n            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);\n       \
    \ }\n    }\n    // [a, b)\u3067\u306E\u30AF\u30A8\u30EA\n    T query(int a, int\
    \ b) {\n        assert(0 <= a && a < b && b <= orig_n);\n        return query(a,\
    \ b, 0, 0, N);\n    }\n};\n\nclass SuffixArray {\n    SegTree<> rmq;\n    void\
    \ set_lcp() {\n        // S[i]\u3092\u9806\u756A\u306B\u898B\u3066\u3044\u304D\
    S[i - 1] -\u30001\u6587\u5B57\u4EE5\u4E0A\u304C\u5171\u901A\u3059\u308B\u3053\u3068\
    \u3092\u5229\u7528\u3057\u3066\u3057\u3083\u304F\u3068\u308A\n        lcp_next_rank\
    \ = vector<int>(N);\n        int h = 0;\n        REP(i, N) {\n            if (h\
    \ > 0) h--;\n            if (rank[i] == N - 1) continue;\n            int j =\
    \ sorted[rank[i] + 1];  // \u6BD4\u3079\u308B\u5BFE\u8C61(\u8F9E\u66F8\u9806\u304C\
    \u4E00\u3064\u5927\u304D\u3044\u3082\u306E)\n            for (; i + h < N && j\
    \ + h < N; h++) {\n                if (S[i + h] != S[j + h]) break;\n        \
    \    }\n            lcp_next_rank[rank[i]] = h;\n        }\n        // S[i..],\
    \ S[j..]\u306Elcp\u304C\u6C42\u3081\u3089\u308C\u308B\u3088\u3046\u306BRMQ\u4E0A\
    \u306B\u306E\u305B\u308B\n        rmq = SegTree<int>(\n            lcp_next_rank,\
    \ [](int a, int b) { return min(a, b); }, 1e15);\n    }\n\npublic:\n    int N;\n\
    \    string S;\n    vector<int> rank;    // rank[i]: i\u304B\u3089\u59CB\u307E\
    \u308Bsuffix\u306E\u8F9E\u66F8\u9806\u3067\u306E\u9806\u4F4D\n    vector<int>\
    \ sorted;  // sorted[i]: suffix\u304C\u8F9E\u66F8\u9806i\u756A\u76EE\u3068\u306A\
    \u308B\u958B\u59CB\u4F4D\u7F6E\u306Eindex\n    vector<int> lcp_next_rank;  //\
    \ lcp[i]: S[sorted[i]..]\u3068S[sorted[i + 1]..]\u304C\u5148\u982D\u4F55\u6587\
    \u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3001lcp[N - 1] = 0\n    SuffixArray(string\
    \ s) {\n        S = s;\n        N = S.size();\n        sorted = vector<int>(N);\n\
    \        rank = vector<int>(N);\n        REP(i, N) {\n            sorted[i] =\
    \ i;\n            rank[i] = S[i];\n        }\n\n        int k;\n        function<bool(int,\
    \ int)> compare_sa = [this, &k](int i, int j) {\n            if (rank[i] != rank[j])\
    \ {\n                return rank[i] < rank[j];\n            }\n            int\
    \ ri = i + k < N ? rank[i + k] : -1;\n            int rj = j + k < N ? rank[j\
    \ + k] : -1;\n            return ri < rj;\n        };\n\n        for (k = 1; k\
    \ < N; k *= 2) {\n            sort(sorted.begin(), sorted.end(), compare_sa);\n\
    \            vector<int> tmp(N, 0);\n            REPI(i, 1, N) { tmp[sorted[i]]\
    \ = tmp[sorted[i - 1]] + compare_sa(sorted[i - 1], sorted[i]); }\n           \
    \ rank = tmp;\n        }\n        set_lcp();\n    }\n\n    // size\u304CT\u3068\
    \u7B49\u3057\u304F\u521D\u3081\u3066T\u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\
    \u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sorted\u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u8FD4\u3059)\n    vector<int>::iterator lower_bound(string T) {\n\
    \        int l = -1, r = N;\n        while (r - l > 1) {\n            int mid\
    \ = (l + r) / 2;\n            if (S.compare(sorted[mid], T.size(), T) < 0) {\n\
    \                l = mid;\n            } else {\n                r = mid;\n  \
    \          }\n        }\n        return sorted.begin() + r;\n    }\n\n    // size\u304C\
    T\u3068\u7B49\u3057\u304F\u521D\u3081\u3066T\u3088\u308A\u5927\u304D\u304F\u306A\
    \u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sorted\u306E\u30A4\
    \u30C6\u30EC\u30FC\u30BF\u3092\u8FD4\u3059)\n    vector<int>::iterator upper_bound(string\
    \ T) {\n        int l = -1, r = N;\n        while (r - l > 1) {\n            int\
    \ mid = (l + r) / 2;\n            if (S.compare(sorted[mid], T.size(), T) <= 0)\
    \ {\n                l = mid;\n            } else {\n                r = mid;\n\
    \            }\n        }\n        return sorted.begin() + r;\n    }\n\n    //\
    \ S2\u304C\u90E8\u5206\u6587\u5B57\u5217\u3068\u3057\u3066\u4F55\u56DE\u51FA\u73FE\
    \u3059\u308B\u304B\n    int count(string S2) { return upper_bound(S2) - lower_bound(S2);\
    \ }\n\n    // S[i..], S[j..]\u304C\u5148\u982D\u4F55\u6587\u5B57\u4E00\u81F4\u3057\
    \u3066\u3044\u308B\u304B\n    int lcp(int i, int j) {\n        assert(0 <= i &&\
    \ 0 <= j && i < N && j < N);\n        if (i == j) return N - i;\n        int l\
    \ = min(rank[i], rank[j]);\n        int r = max(rank[i], rank[j]);\n        return\
    \ rmq.query(l, r);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/SuffixArrayDoubling.hpp
  requiredBy: []
  timestamp: '2020-04-10 21:10:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/SuffixArrayDoubling.hpp
layout: document
redirect_from:
- /library/src/old/SuffixArrayDoubling.hpp
- /library/src/old/SuffixArrayDoubling.hpp.html
title: src/old/SuffixArrayDoubling.hpp
---
