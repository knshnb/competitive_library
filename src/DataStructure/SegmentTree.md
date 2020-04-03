## 概要
配列の長さが$2n$($n$は扱いたい範囲の要素数)でよいセグメント木。
実装方針の参考: https://codeforces.com/blog/entry/18051

## 使い方
### 変数
- `op(T a, T b) -> T`: T上のモノイド
- `e`: モノイドの単位元

### メソッド
- `query(int l, int r) -> T`: [l, r)の範囲のモノイドの合成を返す
- `update(int i, T x)`: $i$番目の要素を$x$に変更
- `operate(int i, T x)`: $i$番目の要素に$x$を作用

## 初期化例
- `Int`に対するmin
```cpp
auto seg_mi = make_segment_tree<Int>([](Int a, Int b) { return min(a, b); }, 1e18);
```

- `Int`に対するmax
```cpp
auto seg_ma = make_segment_tree<Int>([](Int a, Int b) { return max(a, b); }, -1e18);
```

- `Int`に対するmax
```cpp
auto seg_ma = make_segment_tree<Int>(std::plus<Int>(), -1e18);
```

- `Int`に対するAffine
```cpp
auto seg_affine = make_segment_tree<pair<Int, Int>>(
    [](pair<Int, Int> a, pair<Int, Int> b) -> pair<Int, Int> {
        return {a.first * b.first, b.first * a.second + b.second};
    },
    {1, 0});
```