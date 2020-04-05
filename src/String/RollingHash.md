## 概要
文字列を多項式と捉えて、適当なmod,baseでhash化。
Sを与えて事前計算しておけば、S[l, r)のhashがO(1)で取得できる。
具体的には、各iについて
`hash[0, i) = S[0] * base^(i-1) + S[1] * base^(i-2) + ... + S[i-1] * base^0`
を計算しておくと、
`hash[l, r) = hash[0, r) - hash[0, l) * base^(r-1)`
となる。

衝突率を下げるため、modを素数に固定しbaseをいくつか乱択し、全てが一致するか確認している。
文字列の中で先頭の0の個数のみがちがうもの(00032と032など)は区別できないので注意！適当な定数を足す必要あり。

参考: Rolling Hashの衝突確率について(https://maspypy.com/rolling-hash%e3%81%ab%e3%81%a4%e3%81%84%e3%81%a6%ef%bc%88survey-%e7%a0%94%e7%a9%b6%ef%bc%89)
