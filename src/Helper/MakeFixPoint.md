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