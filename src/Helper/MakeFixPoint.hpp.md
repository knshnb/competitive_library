---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: src/Helper/MakeFixPoint.md
    links: []
  bundledCode: "#line 1 \"src/Helper/MakeFixPoint.hpp\"\n/// @docs src/Helper/MakeFixPoint.md\n\
    template <typename F> struct FixPoint : F {\n    FixPoint(F&& f) : F(std::forward<F>(f))\
    \ {}\n    template <typename... Args> decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\ntemplate <typename F> decltype(auto) make_fix_point(F&& f) { return\
    \ FixPoint<F>{std::forward<F>(f)}; }\n"
  code: "/// @docs src/Helper/MakeFixPoint.md\ntemplate <typename F> struct FixPoint\
    \ : F {\n    FixPoint(F&& f) : F(std::forward<F>(f)) {}\n    template <typename...\
    \ Args> decltype(auto) operator()(Args&&... args) const {\n        return F::operator()(*this,\
    \ std::forward<Args>(args)...);\n    }\n};\ntemplate <typename F> decltype(auto)\
    \ make_fix_point(F&& f) { return FixPoint<F>{std::forward<F>(f)}; }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Helper/MakeFixPoint.hpp
  requiredBy: []
  timestamp: '2021-03-05 20:51:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Helper/MakeFixPoint.hpp
layout: document
redirect_from:
- /library/src/Helper/MakeFixPoint.hpp
- /library/src/Helper/MakeFixPoint.hpp.html
title: src/Helper/MakeFixPoint.hpp
---
## 概要
ラムダ式による再帰のヘルパー

## 使い方
```
int main() {
    dfs = make_fix_point([&](auto&& self) -> T {
        return self();
    });
    dfs();
}
```