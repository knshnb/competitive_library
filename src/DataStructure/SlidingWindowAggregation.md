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
