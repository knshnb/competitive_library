## 概要
区間更新区間取得セグメント木。

参考
- http://tsutaj.hatenablog.com/entry/2017/03/30/224339
- https://beet-aizu.hatenablog.com/entry/2017/12/01/225955

## 使い方
### 変数
- `f0(T0, T0) -> T0`: 取得クエリのモノイド
- `f1(T1, T1) -> T1`: 作用素同士のモノイド
- `g(T0, T1) -> T0`: $\mathrm{T0}$に対する$\mathrm{T1}$の作用(更新クエリ)
- `p(T1 x, int len) -> T1`: 長さ$\mathrm{len}$の区間に$x$を作用させたとき、$\mathrm{f0}$による区間合成がどう変わるか

### メソッド
- `query(int l, int r) -> T`: $\[l, r)$の範囲のモノイドの合成を返す
- `update(int l, int t, T1 x)`: $\[l, r)$の範囲に$x$を作用

## 初期化例
- `Int`に対するAdd & Max
```cpp
constexpr Int INF = 1e18;
auto seg = make_lazy_segment_tree<Int, Int>(
    [](Int x, Int y) { return max(x, y); }, -INF, [](Int x, Int y) { return x + y; }, 0,
    [](Int x, Int y) { return x == -INF ? x : x + y; }, [](Int x, int len) { return x; });
```

- `mint`に対するAffine & Sum
```cpp
auto seg = make_lazy_segment_tree<mint, pmm>(
    std::plus<mint>(), 0,
    [](pmm x, pmm y) -> pmm {
        return {x.first * y.first, x.second * y.first + y.second};
    },
    {1, 0}, [](mint x, pmm y) { return y.first * x + y.second; },
    [](pmm x, int len) -> pmm {
        return {x.first, x.second * len};
    });
```
