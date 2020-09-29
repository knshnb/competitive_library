---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/LongestCommonPrefix.hpp\"\ntemplate <class T = int>\
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
    \ b, 0, 0, N);\n    }\n};\n\n// SA-IS\u306B\u3088\u308BSuffix Array\u306E\u5B9F\
    \u88C5\u3002\u69CB\u7BC9O(N)\nclass SuffixArray {\n    vector<int> sa_is(const\
    \ vector<int>& str, const int k) {\n        const int n = str.size();\n      \
    \  vector<bool> is_S(n);\n        is_S[n - 1] = true;\n        vector<bool> is_LMS(n);\n\
    \        vector<int> LMSs;\n        for (int i = n - 2; i >= 0; i--) {\n     \
    \       is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);\n\
    \        }\n        REP(i, n) {\n            if (is_S[i] & (i == 0 || !is_S[i\
    \ - 1])) {\n                is_LMS[i] = true;\n                LMSs.push_back(i);\n\
    \            }\n        }\n        vector<int> pseudo_sa = induced_sort(str, LMSs,\
    \ is_S, k);\n        vector<int> orderedLMSs(LMSs.size());\n        int index\
    \ = 0;\n        for (int x : pseudo_sa) {\n            if (is_LMS[x]) {\n    \
    \            orderedLMSs[index++] = x;\n            }\n        }\n        pseudo_sa[orderedLMSs[0]]\
    \ = 0;\n        int rank = 0;\n        if (orderedLMSs.size() > 1) {\n       \
    \     pseudo_sa[orderedLMSs[1]] = ++rank;\n        }\n        REPI(i, 1, orderedLMSs.size()\
    \ - 1) {\n            bool is_diff = false;\n            REP(j, n) {\n       \
    \         int p = orderedLMSs[i] + j;\n                int q = orderedLMSs[i +\
    \ 1] + j;\n                if (str[p] != str[q] || is_LMS[p] != is_LMS[q]) {\n\
    \                    is_diff = true;\n                    break;\n           \
    \     }\n                if (j > 0 && is_LMS[p]) {\n                    break;\n\
    \                }\n            }\n            pseudo_sa[orderedLMSs[i + 1]] =\
    \ is_diff ? ++rank : rank;\n        }\n        vector<int> new_str(LMSs.size());\n\
    \        index = 0;\n        REP(i, n) {\n            if (is_LMS[i]) {\n     \
    \           new_str[index++] = pseudo_sa[i];\n            }\n        }\n     \
    \   vector<int> LMS_sa;\n        if (rank + 1 == LMSs.size()) {\n            LMS_sa\
    \ = orderedLMSs;\n        } else {\n            LMS_sa = sa_is(new_str, rank +\
    \ 1);\n            for (int& x : LMS_sa) {\n                x = LMSs[x];\n   \
    \         }\n        }\n        return induced_sort(str, LMS_sa, is_S, k);\n \
    \   }\n\n    vector<int> induced_sort(const vector<int>& str, const vector<int>&\
    \ LMSs, const vector<bool>& is_S, const int k) {\n        int n = str.size();\n\
    \        vector<int> buckets(n);\n        vector<int> chars(k + 1);\n        for\
    \ (int c : str) {\n            chars[c + 1]++;\n        }\n        REP(i, k) {\
    \ chars[i + 1] += chars[i]; }\n        vector<int> count(k);\n        for (int\
    \ i = LMSs.size() - 1; i >= 0; i--) {\n            int c = str[LMSs[i]];\n   \
    \         buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];\n        }\n     \
    \   count = vector<int>(k);\n        REP(i, n) {\n            if (buckets[i] ==\
    \ 0 || is_S[buckets[i] - 1]) {\n                continue;\n            }\n   \
    \         int c = str[buckets[i] - 1];\n            buckets[chars[c] + count[c]++]\
    \ = buckets[i] - 1;\n        }\n        count = vector<int>(k);\n        for (int\
    \ i = n - 1; i >= 0; i--) {\n            if (buckets[i] == 0 || !is_S[buckets[i]\
    \ - 1]) {\n                continue;\n            }\n            int c = str[buckets[i]\
    \ - 1];\n            buckets[chars[c + 1] - 1 - count[c]++] = buckets[i] - 1;\n\
    \        }\n        return buckets;\n    }\n\npublic:\n    string S;\n    int\
    \ N;\n    vector<int> sa;  // sa[i]: suffix\u304C\u8F9E\u66F8\u9806i\u756A\u76EE\
    \u3068\u306A\u308B\u958B\u59CB\u4F4D\u7F6E\u306Eindex\n    SuffixArray(string\
    \ str_in) : S(str_in), N(str_in.size()) {\n        str_in += \"$\";\n        vector<int>\
    \ str(N + 1);\n        REP(i, N + 1) { str[i] = str_in[i] - '$'; }\n        sa\
    \ = sa_is(str, 128);\n        sa.erase(sa.begin());\n    }\n    int operator[](int\
    \ index) { return sa[index]; }\n\n    // size\u304CT\u3068\u7B49\u3057\u304F\u521D\
    \u3081\u3066T\u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\
    \u6587\u5B57\u5217(sa)\n    vector<int>::iterator lower_bound(string T) {\n  \
    \      int l = -1, r = N;\n        while (r - l > 1) {\n            int mid =\
    \ (l + r) / 2;\n            if (S.compare(sa[mid], T.size(), T) < 0) {\n     \
    \           l = mid;\n            } else {\n                r = mid;\n       \
    \     }\n        }\n        return sa.begin() + r;\n    }\n\n    // size\u304C\
    T\u3068\u7B49\u3057\u304F\u521D\u3081\u3066T\u3088\u308A\u5927\u304D\u304F\u306A\
    \u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sa)\n    vector<int>::iterator\
    \ upper_bound(string T) {\n        int l = -1, r = N;\n        while (r - l >\
    \ 1) {\n            int mid = (l + r) / 2;\n            if (S.compare(sa[mid],\
    \ T.size(), T) <= 0) {\n                l = mid;\n            } else {\n     \
    \           r = mid;\n            }\n        }\n        return sa.begin() + r;\n\
    \    }\n\n    // S2\u304C\u90E8\u5206\u6587\u5B57\u5217\u3068\u3057\u3066\u4F55\
    \u56DE\u51FA\u73FE\u3059\u308B\u304B\n    int count(string S2) { return upper_bound(S2)\
    \ - lower_bound(S2); }\n};\n\nclass LongestCommonPrefix {\n    SegTree<> rmq;\n\
    \    vector<int> lcp;  // lcp[i]: S[sa[i]..]\u3068S[sa[i + 1]..]\u304C\u5148\u982D\
    \u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3001lcp[N - 1] =\
    \ 0\n    vector<int> lcp_begin;  // lcp_begin[i]: S[0..]\u3068S[i]\u304C\u5148\
    \u982D\u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\npublic:\n\
    \    const string S;\n    int N;\n    vector<int> sa;\n    vector<int> rank; \
    \ // rank[i]: i\u304B\u3089\u59CB\u307E\u308Bsuffix\u306E\u8F9E\u66F8\u9806\u3067\
    \u306E\u9806\u4F4D\n    LongestCommonPrefix();\n    LongestCommonPrefix(const\
    \ string& str) : S(str), N(str.size()), rank(str.size()), lcp(str.size()) {\n\
    \        sa = SuffixArray(str).sa;\n        // rank\u306E\u8A2D\u5B9A\n      \
    \  REP(i, N) { rank[sa[i]] = i; }\n        // S[i]\u3092\u9806\u756A\u306B\u898B\
    \u3066\u3044\u304DS[i - 1] -\u30001\u6587\u5B57\u4EE5\u4E0A\u304C\u5171\u901A\u3059\
    \u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\u3057\u3083\u304F\u3068\u308A\
    \n        lcp = vector<int>(N);\n        int h = 0;\n        REP(i, N) {\n   \
    \         if (h > 0) h--;\n            if (rank[i] == N - 1) continue;\n     \
    \       int j = sa[rank[i] + 1];  // \u6BD4\u3079\u308B\u5BFE\u8C61(\u8F9E\u66F8\
    \u9806\u304C\u4E00\u3064\u5927\u304D\u3044\u3082\u306E)\n            for (; i\
    \ + h < N && j + h < N; h++) {\n                if (S[i + h] != S[j + h]) break;\n\
    \            }\n            lcp[rank[i]] = h;\n        }\n        // \u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\n        set_query1();\n\
    \        set_query2();\n    }\n    int operator[](int index) { return lcp[index];\
    \ }\n\n    // S[i..], S[j..]\u304C\u5148\u982D\u4F55\u6587\u5B57\u4E00\u81F4\u3057\
    \u3066\u3044\u308B\u304B\n    int query(int i, int j) {\n        assert(0 <= i\
    \ && 0 <= j && i < N && j < N);\n        if (i == j) return N - i;\n        int\
    \ l = min(rank[i], rank[j]);\n        int r = max(rank[i], rank[j]);\n       \
    \ return rmq.query(l, r);\n    }\n    void set_query2() {\n        // S[i..],\
    \ S[j..]\u306Elcp\u304C\u6C42\u3081\u3089\u308C\u308B\u3088\u3046\u306BRMQ\u4E0A\
    \u306B\u306E\u305B\u308B\n        rmq = SegTree<int>(\n            lcp, [](int\
    \ a, int b) { return min(a, b); }, 1e15);\n    }\n\n    // S[i..]\u304CS[0..]\u3068\
    \u5148\u982D\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\n    int query(int\
    \ i) { return lcp_begin[i]; }\n    void set_query1() {\n        lcp_begin = vector<int>(N);\n\
    \        lcp_begin[0] = N;\n        for (int i = rank[0] - 1; i >= 0; i--) {\n\
    \            lcp_begin[sa[i]] = min(lcp_begin[sa[i + 1]], lcp[i]);\n        }\n\
    \        for (int i = rank[0] + 1; i < N; i++) {\n            lcp_begin[sa[i]]\
    \ = min(lcp_begin[sa[i - 1]], lcp[i - 1]);\n        }\n    }\n};\n"
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
    \ b, 0, 0, N);\n    }\n};\n\n// SA-IS\u306B\u3088\u308BSuffix Array\u306E\u5B9F\
    \u88C5\u3002\u69CB\u7BC9O(N)\nclass SuffixArray {\n    vector<int> sa_is(const\
    \ vector<int>& str, const int k) {\n        const int n = str.size();\n      \
    \  vector<bool> is_S(n);\n        is_S[n - 1] = true;\n        vector<bool> is_LMS(n);\n\
    \        vector<int> LMSs;\n        for (int i = n - 2; i >= 0; i--) {\n     \
    \       is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);\n\
    \        }\n        REP(i, n) {\n            if (is_S[i] & (i == 0 || !is_S[i\
    \ - 1])) {\n                is_LMS[i] = true;\n                LMSs.push_back(i);\n\
    \            }\n        }\n        vector<int> pseudo_sa = induced_sort(str, LMSs,\
    \ is_S, k);\n        vector<int> orderedLMSs(LMSs.size());\n        int index\
    \ = 0;\n        for (int x : pseudo_sa) {\n            if (is_LMS[x]) {\n    \
    \            orderedLMSs[index++] = x;\n            }\n        }\n        pseudo_sa[orderedLMSs[0]]\
    \ = 0;\n        int rank = 0;\n        if (orderedLMSs.size() > 1) {\n       \
    \     pseudo_sa[orderedLMSs[1]] = ++rank;\n        }\n        REPI(i, 1, orderedLMSs.size()\
    \ - 1) {\n            bool is_diff = false;\n            REP(j, n) {\n       \
    \         int p = orderedLMSs[i] + j;\n                int q = orderedLMSs[i +\
    \ 1] + j;\n                if (str[p] != str[q] || is_LMS[p] != is_LMS[q]) {\n\
    \                    is_diff = true;\n                    break;\n           \
    \     }\n                if (j > 0 && is_LMS[p]) {\n                    break;\n\
    \                }\n            }\n            pseudo_sa[orderedLMSs[i + 1]] =\
    \ is_diff ? ++rank : rank;\n        }\n        vector<int> new_str(LMSs.size());\n\
    \        index = 0;\n        REP(i, n) {\n            if (is_LMS[i]) {\n     \
    \           new_str[index++] = pseudo_sa[i];\n            }\n        }\n     \
    \   vector<int> LMS_sa;\n        if (rank + 1 == LMSs.size()) {\n            LMS_sa\
    \ = orderedLMSs;\n        } else {\n            LMS_sa = sa_is(new_str, rank +\
    \ 1);\n            for (int& x : LMS_sa) {\n                x = LMSs[x];\n   \
    \         }\n        }\n        return induced_sort(str, LMS_sa, is_S, k);\n \
    \   }\n\n    vector<int> induced_sort(const vector<int>& str, const vector<int>&\
    \ LMSs, const vector<bool>& is_S, const int k) {\n        int n = str.size();\n\
    \        vector<int> buckets(n);\n        vector<int> chars(k + 1);\n        for\
    \ (int c : str) {\n            chars[c + 1]++;\n        }\n        REP(i, k) {\
    \ chars[i + 1] += chars[i]; }\n        vector<int> count(k);\n        for (int\
    \ i = LMSs.size() - 1; i >= 0; i--) {\n            int c = str[LMSs[i]];\n   \
    \         buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];\n        }\n     \
    \   count = vector<int>(k);\n        REP(i, n) {\n            if (buckets[i] ==\
    \ 0 || is_S[buckets[i] - 1]) {\n                continue;\n            }\n   \
    \         int c = str[buckets[i] - 1];\n            buckets[chars[c] + count[c]++]\
    \ = buckets[i] - 1;\n        }\n        count = vector<int>(k);\n        for (int\
    \ i = n - 1; i >= 0; i--) {\n            if (buckets[i] == 0 || !is_S[buckets[i]\
    \ - 1]) {\n                continue;\n            }\n            int c = str[buckets[i]\
    \ - 1];\n            buckets[chars[c + 1] - 1 - count[c]++] = buckets[i] - 1;\n\
    \        }\n        return buckets;\n    }\n\npublic:\n    string S;\n    int\
    \ N;\n    vector<int> sa;  // sa[i]: suffix\u304C\u8F9E\u66F8\u9806i\u756A\u76EE\
    \u3068\u306A\u308B\u958B\u59CB\u4F4D\u7F6E\u306Eindex\n    SuffixArray(string\
    \ str_in) : S(str_in), N(str_in.size()) {\n        str_in += \"$\";\n        vector<int>\
    \ str(N + 1);\n        REP(i, N + 1) { str[i] = str_in[i] - '$'; }\n        sa\
    \ = sa_is(str, 128);\n        sa.erase(sa.begin());\n    }\n    int operator[](int\
    \ index) { return sa[index]; }\n\n    // size\u304CT\u3068\u7B49\u3057\u304F\u521D\
    \u3081\u3066T\u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\
    \u6587\u5B57\u5217(sa)\n    vector<int>::iterator lower_bound(string T) {\n  \
    \      int l = -1, r = N;\n        while (r - l > 1) {\n            int mid =\
    \ (l + r) / 2;\n            if (S.compare(sa[mid], T.size(), T) < 0) {\n     \
    \           l = mid;\n            } else {\n                r = mid;\n       \
    \     }\n        }\n        return sa.begin() + r;\n    }\n\n    // size\u304C\
    T\u3068\u7B49\u3057\u304F\u521D\u3081\u3066T\u3088\u308A\u5927\u304D\u304F\u306A\
    \u308B\u3088\u3046\u306AS\u306E\u90E8\u5206\u6587\u5B57\u5217(sa)\n    vector<int>::iterator\
    \ upper_bound(string T) {\n        int l = -1, r = N;\n        while (r - l >\
    \ 1) {\n            int mid = (l + r) / 2;\n            if (S.compare(sa[mid],\
    \ T.size(), T) <= 0) {\n                l = mid;\n            } else {\n     \
    \           r = mid;\n            }\n        }\n        return sa.begin() + r;\n\
    \    }\n\n    // S2\u304C\u90E8\u5206\u6587\u5B57\u5217\u3068\u3057\u3066\u4F55\
    \u56DE\u51FA\u73FE\u3059\u308B\u304B\n    int count(string S2) { return upper_bound(S2)\
    \ - lower_bound(S2); }\n};\n\nclass LongestCommonPrefix {\n    SegTree<> rmq;\n\
    \    vector<int> lcp;  // lcp[i]: S[sa[i]..]\u3068S[sa[i + 1]..]\u304C\u5148\u982D\
    \u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\u3001lcp[N - 1] =\
    \ 0\n    vector<int> lcp_begin;  // lcp_begin[i]: S[0..]\u3068S[i]\u304C\u5148\
    \u982D\u4F55\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\npublic:\n\
    \    const string S;\n    int N;\n    vector<int> sa;\n    vector<int> rank; \
    \ // rank[i]: i\u304B\u3089\u59CB\u307E\u308Bsuffix\u306E\u8F9E\u66F8\u9806\u3067\
    \u306E\u9806\u4F4D\n    LongestCommonPrefix();\n    LongestCommonPrefix(const\
    \ string& str) : S(str), N(str.size()), rank(str.size()), lcp(str.size()) {\n\
    \        sa = SuffixArray(str).sa;\n        // rank\u306E\u8A2D\u5B9A\n      \
    \  REP(i, N) { rank[sa[i]] = i; }\n        // S[i]\u3092\u9806\u756A\u306B\u898B\
    \u3066\u3044\u304DS[i - 1] -\u30001\u6587\u5B57\u4EE5\u4E0A\u304C\u5171\u901A\u3059\
    \u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\u3057\u3083\u304F\u3068\u308A\
    \n        lcp = vector<int>(N);\n        int h = 0;\n        REP(i, N) {\n   \
    \         if (h > 0) h--;\n            if (rank[i] == N - 1) continue;\n     \
    \       int j = sa[rank[i] + 1];  // \u6BD4\u3079\u308B\u5BFE\u8C61(\u8F9E\u66F8\
    \u9806\u304C\u4E00\u3064\u5927\u304D\u3044\u3082\u306E)\n            for (; i\
    \ + h < N && j + h < N; h++) {\n                if (S[i + h] != S[j + h]) break;\n\
    \            }\n            lcp[rank[i]] = h;\n        }\n        // \u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\n        set_query1();\n\
    \        set_query2();\n    }\n    int operator[](int index) { return lcp[index];\
    \ }\n\n    // S[i..], S[j..]\u304C\u5148\u982D\u4F55\u6587\u5B57\u4E00\u81F4\u3057\
    \u3066\u3044\u308B\u304B\n    int query(int i, int j) {\n        assert(0 <= i\
    \ && 0 <= j && i < N && j < N);\n        if (i == j) return N - i;\n        int\
    \ l = min(rank[i], rank[j]);\n        int r = max(rank[i], rank[j]);\n       \
    \ return rmq.query(l, r);\n    }\n    void set_query2() {\n        // S[i..],\
    \ S[j..]\u306Elcp\u304C\u6C42\u3081\u3089\u308C\u308B\u3088\u3046\u306BRMQ\u4E0A\
    \u306B\u306E\u305B\u308B\n        rmq = SegTree<int>(\n            lcp, [](int\
    \ a, int b) { return min(a, b); }, 1e15);\n    }\n\n    // S[i..]\u304CS[0..]\u3068\
    \u5148\u982D\u6587\u5B57\u4E00\u81F4\u3057\u3066\u3044\u308B\u304B\n    int query(int\
    \ i) { return lcp_begin[i]; }\n    void set_query1() {\n        lcp_begin = vector<int>(N);\n\
    \        lcp_begin[0] = N;\n        for (int i = rank[0] - 1; i >= 0; i--) {\n\
    \            lcp_begin[sa[i]] = min(lcp_begin[sa[i + 1]], lcp[i]);\n        }\n\
    \        for (int i = rank[0] + 1; i < N; i++) {\n            lcp_begin[sa[i]]\
    \ = min(lcp_begin[sa[i - 1]], lcp[i - 1]);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/LongestCommonPrefix.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:53:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/LongestCommonPrefix.hpp
layout: document
redirect_from:
- /library/src/old/LongestCommonPrefix.hpp
- /library/src/old/LongestCommonPrefix.hpp.html
title: src/old/LongestCommonPrefix.hpp
---
