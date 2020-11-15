---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549.test.cpp
    title: test/aoj/1549.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/WaveletMatrix.hpp\"\nint popcount(std::uint32_t\
    \ x) { return __builtin_popcount(x); }\nint popcount(std::uint64_t x) { return\
    \ __builtin_popcountll(x); }\n\ntemplate <class block_type = std::uint64_t> struct\
    \ BitVector {\n    static constexpr size_t b = sizeof(block_type) * CHAR_BIT;\
    \  // block\u306E\u30B5\u30A4\u30BA\n    int n;\n    std::vector<block_type> bit;\n\
    \    std::vector<int> acc;\n    BitVector() {}\n    BitVector(int n_) : n(n_),\
    \ bit(n / b + 1), acc(n / b + 1) {}\n    template <bool x = 1> void set(size_t\
    \ i) {\n        if (x)\n            bit[i / b] |= (block_type)1 << (i % b);\n\
    \        else\n            bit[i / b] &= ~((block_type)1 << (i % b));\n    }\n\
    \    void build() {\n        for (int i = 0; i < (int)acc.size() - 1; i++) {\n\
    \            acc[i + 1] = acc[i] + popcount(bit[i]);\n        }\n    }\n    //\
    \ [0, i)\u5185\u306Ex\u306E\u500B\u6570\n    template <bool x> int rank(size_t\
    \ i) {\n        if (x)\n            return acc[i / b] + (i % b ? popcount(bit[i\
    \ / b] << (b - i % b)) : 0);\n        else\n            return i - rank<1>(i);\n\
    \    }\n    // j\u756A\u76EE\u306Ex\u306Eindex\n    template <bool x> int select(size_t\
    \ j) {\n        int ok = n, ng = -1;\n        while (std::abs(ok - ng) > 1) {\n\
    \            int mid = (ok + ng) / 2;\n            (rank<x>(mid + 1) > j ? ok\
    \ : ng) = mid;\n        }\n        return ok;\n    }\n};\n\ntemplate <class T,\
    \ int maxlog = 31, class block_type = std::uint64_t> struct WaveletMatrix {\n\
    \    static_assert((T(1) << (maxlog - 1)) > 0);\n    using bv_type = BitVector<block_type>;\n\
    \    std::array<bv_type, maxlog> bvs;      // [maxlog, n]\u306E01\u884C\u5217\n\
    \    std::array<int, maxlog> offset = {};  // \u5404\u5217\u3067bit\u304C0\u306B\
    \u306A\u3063\u3066\u3044\u308B\u8981\u7D20\u306E\u6570\n\n    WaveletMatrix(const\
    \ std::vector<T>& a) {\n        std::vector<T> cur_data = a;\n        for (int\
    \ k = maxlog - 1; k >= 0; k--) {  // \u4E0A\u4F4Dbit\u304B\u3089\u898B\u308B\n\
    \            std::vector<T> zero, one;\n            bvs[k] = bv_type(a.size());\n\
    \            for (int i = 0; i < a.size(); i++) {\n                bool bit =\
    \ cur_data[i] >> k & 1;\n                if (bit)\n                    one.push_back(cur_data[i]),\
    \ bvs[k].template set<1>(i);\n                else\n                    zero.push_back(cur_data[i]);\n\
    \            }\n            offset[k] = zero.size();\n            cur_data = std::move(zero);\n\
    \            cur_data.insert(cur_data.end(), one.begin(), one.end());\n      \
    \      bvs[k].build();\n        }\n    }\n    // [l, r)\u306E{x\u672A\u6E80\u306E\
    \u500B\u6570, x\u306E\u500B\u6570, x\u3088\u308A\u5927\u306E\u500B\u6570}\n  \
    \  std::array<int, 3> rank_3way(int l, int r, int x) {\n        int lt = 0, eq\
    \ = r - l, gt = 0;\n        for (int k = maxlog - 1; k >= 0; k--) {\n        \
    \    int prv_num = r - l;\n            if (x >> k & 1) {\n                l =\
    \ offset[k] + bvs[k].template rank<1>(l);\n                r = offset[k] + bvs[k].template\
    \ rank<1>(r);\n                lt += prv_num - (r - l);\n            } else {\n\
    \                l = bvs[k].template rank<0>(l);\n                r = bvs[k].template\
    \ rank<0>(r);\n                gt += prv_num - (r - l);\n            }\n     \
    \       eq -= prv_num - (r - l);\n        }\n        return {lt, eq, gt};\n  \
    \  }\n    // [l, r)\u5185\u306E(\u5C0F\u3055\u3044\u65B9\u304B\u3089)j\u756A\u76EE\
    (0-index)\u306E\u6570\n    int quantile(int l, int r, int j) {\n        assert(j\
    \ < r - l);\n        T ret = 0;\n        for (int k = maxlog - 1; k >= 0; k--)\
    \ {\n            int zl = bvs[k].template rank<0>(l);\n            int zr = bvs[k].template\
    \ rank<0>(r);\n            if (zr - zl > j) {  // k\u30D3\u30C3\u30C8\u76EE\u306F\
    0\n                l = zl;\n                r = zr;\n            } else {  //\
    \ k\u30D3\u30C3\u30C8\u76EE\u306F1\n                l = offset[k] + (l - zl);\n\
    \                r = offset[k] + (r - zr);\n                ret |= (T)1 << k;\n\
    \                j -= zr - zl;\n            }\n        }\n        return ret;\n\
    \    }\n};\n"
  code: "int popcount(std::uint32_t x) { return __builtin_popcount(x); }\nint popcount(std::uint64_t\
    \ x) { return __builtin_popcountll(x); }\n\ntemplate <class block_type = std::uint64_t>\
    \ struct BitVector {\n    static constexpr size_t b = sizeof(block_type) * CHAR_BIT;\
    \  // block\u306E\u30B5\u30A4\u30BA\n    int n;\n    std::vector<block_type> bit;\n\
    \    std::vector<int> acc;\n    BitVector() {}\n    BitVector(int n_) : n(n_),\
    \ bit(n / b + 1), acc(n / b + 1) {}\n    template <bool x = 1> void set(size_t\
    \ i) {\n        if (x)\n            bit[i / b] |= (block_type)1 << (i % b);\n\
    \        else\n            bit[i / b] &= ~((block_type)1 << (i % b));\n    }\n\
    \    void build() {\n        for (int i = 0; i < (int)acc.size() - 1; i++) {\n\
    \            acc[i + 1] = acc[i] + popcount(bit[i]);\n        }\n    }\n    //\
    \ [0, i)\u5185\u306Ex\u306E\u500B\u6570\n    template <bool x> int rank(size_t\
    \ i) {\n        if (x)\n            return acc[i / b] + (i % b ? popcount(bit[i\
    \ / b] << (b - i % b)) : 0);\n        else\n            return i - rank<1>(i);\n\
    \    }\n    // j\u756A\u76EE\u306Ex\u306Eindex\n    template <bool x> int select(size_t\
    \ j) {\n        int ok = n, ng = -1;\n        while (std::abs(ok - ng) > 1) {\n\
    \            int mid = (ok + ng) / 2;\n            (rank<x>(mid + 1) > j ? ok\
    \ : ng) = mid;\n        }\n        return ok;\n    }\n};\n\ntemplate <class T,\
    \ int maxlog = 31, class block_type = std::uint64_t> struct WaveletMatrix {\n\
    \    static_assert((T(1) << (maxlog - 1)) > 0);\n    using bv_type = BitVector<block_type>;\n\
    \    std::array<bv_type, maxlog> bvs;      // [maxlog, n]\u306E01\u884C\u5217\n\
    \    std::array<int, maxlog> offset = {};  // \u5404\u5217\u3067bit\u304C0\u306B\
    \u306A\u3063\u3066\u3044\u308B\u8981\u7D20\u306E\u6570\n\n    WaveletMatrix(const\
    \ std::vector<T>& a) {\n        std::vector<T> cur_data = a;\n        for (int\
    \ k = maxlog - 1; k >= 0; k--) {  // \u4E0A\u4F4Dbit\u304B\u3089\u898B\u308B\n\
    \            std::vector<T> zero, one;\n            bvs[k] = bv_type(a.size());\n\
    \            for (int i = 0; i < a.size(); i++) {\n                bool bit =\
    \ cur_data[i] >> k & 1;\n                if (bit)\n                    one.push_back(cur_data[i]),\
    \ bvs[k].template set<1>(i);\n                else\n                    zero.push_back(cur_data[i]);\n\
    \            }\n            offset[k] = zero.size();\n            cur_data = std::move(zero);\n\
    \            cur_data.insert(cur_data.end(), one.begin(), one.end());\n      \
    \      bvs[k].build();\n        }\n    }\n    // [l, r)\u306E{x\u672A\u6E80\u306E\
    \u500B\u6570, x\u306E\u500B\u6570, x\u3088\u308A\u5927\u306E\u500B\u6570}\n  \
    \  std::array<int, 3> rank_3way(int l, int r, int x) {\n        int lt = 0, eq\
    \ = r - l, gt = 0;\n        for (int k = maxlog - 1; k >= 0; k--) {\n        \
    \    int prv_num = r - l;\n            if (x >> k & 1) {\n                l =\
    \ offset[k] + bvs[k].template rank<1>(l);\n                r = offset[k] + bvs[k].template\
    \ rank<1>(r);\n                lt += prv_num - (r - l);\n            } else {\n\
    \                l = bvs[k].template rank<0>(l);\n                r = bvs[k].template\
    \ rank<0>(r);\n                gt += prv_num - (r - l);\n            }\n     \
    \       eq -= prv_num - (r - l);\n        }\n        return {lt, eq, gt};\n  \
    \  }\n    // [l, r)\u5185\u306E(\u5C0F\u3055\u3044\u65B9\u304B\u3089)j\u756A\u76EE\
    (0-index)\u306E\u6570\n    int quantile(int l, int r, int j) {\n        assert(j\
    \ < r - l);\n        T ret = 0;\n        for (int k = maxlog - 1; k >= 0; k--)\
    \ {\n            int zl = bvs[k].template rank<0>(l);\n            int zr = bvs[k].template\
    \ rank<0>(r);\n            if (zr - zl > j) {  // k\u30D3\u30C3\u30C8\u76EE\u306F\
    0\n                l = zl;\n                r = zr;\n            } else {  //\
    \ k\u30D3\u30C3\u30C8\u76EE\u306F1\n                l = offset[k] + (l - zl);\n\
    \                r = offset[k] + (r - zr);\n                ret |= (T)1 << k;\n\
    \                j -= zr - zl;\n            }\n        }\n        return ret;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2020-08-15 16:14:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_5_D.test.cpp
  - test/aoj/1549.test.cpp
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: src/DataStructure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/src/DataStructure/WaveletMatrix.hpp
- /library/src/DataStructure/WaveletMatrix.hpp.html
title: src/DataStructure/WaveletMatrix.hpp
---
