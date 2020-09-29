---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: src/DataStructure/SlidingWindowAggregation.md
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SlidingWindowAggregation.hpp\"\n/// @docs\
    \ src/DataStructure/SlidingWindowAggregation.md\ntemplate <class T, class F> struct\
    \ SlidingWindowAggregation {\n    const F op;\n    const T e;\n    std::stack<std::pair<T,\
    \ T>> st1, st2;  // \u305D\u308C\u305E\u308C\u3001{val, acc}\u3092\u8981\u7D20\
    \u306B\u6301\u3064\u3088\u3046\u306A\u524D\u65B9\u5411\u3068\u5F8C\u308D\u65B9\
    \u5411\u306Estack\n    SlidingWindowAggregation(F op_, T e_) : op(op_), e(e_)\
    \ { st1.emplace(e, e), st2.emplace(e, e); }\n    int size() { return st1.size()\
    \ + st2.size() - 2; }\n    void push(T x) {\n        T acc = op(st2.top().second,\
    \ x);\n        st2.emplace(x, acc);\n    }\n    void pop() {\n        assert(st1.size()\
    \ > 1 || st2.size() > 1);\n        if (st1.size() > 1) {\n            st1.pop();\n\
    \        } else {\n            while (st2.size() > 2) {\n                T acc\
    \ = op(st1.top().second, st2.top().first);\n                st1.emplace(st2.top().first,\
    \ acc);\n                st2.pop();\n            }\n            st2.pop();\n \
    \       }\n    }\n    T fold_all() { return op(st1.top().second, st2.top().second);\
    \ }\n};\ntemplate <class T, class F> auto make_swag(F op, T e_) { return SlidingWindowAggregation<T,\
    \ F>(op, e_); }\n"
  code: "/// @docs src/DataStructure/SlidingWindowAggregation.md\ntemplate <class\
    \ T, class F> struct SlidingWindowAggregation {\n    const F op;\n    const T\
    \ e;\n    std::stack<std::pair<T, T>> st1, st2;  // \u305D\u308C\u305E\u308C\u3001\
    {val, acc}\u3092\u8981\u7D20\u306B\u6301\u3064\u3088\u3046\u306A\u524D\u65B9\u5411\
    \u3068\u5F8C\u308D\u65B9\u5411\u306Estack\n    SlidingWindowAggregation(F op_,\
    \ T e_) : op(op_), e(e_) { st1.emplace(e, e), st2.emplace(e, e); }\n    int size()\
    \ { return st1.size() + st2.size() - 2; }\n    void push(T x) {\n        T acc\
    \ = op(st2.top().second, x);\n        st2.emplace(x, acc);\n    }\n    void pop()\
    \ {\n        assert(st1.size() > 1 || st2.size() > 1);\n        if (st1.size()\
    \ > 1) {\n            st1.pop();\n        } else {\n            while (st2.size()\
    \ > 2) {\n                T acc = op(st1.top().second, st2.top().first);\n   \
    \             st1.emplace(st2.top().first, acc);\n                st2.pop();\n\
    \            }\n            st2.pop();\n        }\n    }\n    T fold_all() { return\
    \ op(st1.top().second, st2.top().second); }\n};\ntemplate <class T, class F> auto\
    \ make_swag(F op, T e_) { return SlidingWindowAggregation<T, F>(op, e_); }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2020-04-25 17:31:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1036.test.cpp
documentation_of: src/DataStructure/SlidingWindowAggregation.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SlidingWindowAggregation.hpp
- /library/src/DataStructure/SlidingWindowAggregation.hpp.html
title: src/DataStructure/SlidingWindowAggregation.hpp
---
## 概要
モノイド列について、以下のクエリを全て償却O(1)で行える。

- `push`
- `pop`
- `fold_all`: 現在queueに入っている要素全ての合成

実際は半群に対して適用可能だが、実装の都合上モノイドにしている(半群には単位元を形式的に追加して使用できる)。

## 使用例
```c++
auto swag = make_swag<Int>([](Int x, Int y) { return std::gcd(x, y); }, 0);
```

## メモ
stackを2つ用いてqueueを作る非常にシンプルなアルゴリズム。
償却計算量の凄さに感動した。
<br/>
参考: https://snuke.hatenablog.com/entry/2018/09/18/135640
