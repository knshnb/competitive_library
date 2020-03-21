---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: src/Geometry/Geometry.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#426bb254552b21fb2d009880f952cd8b">src/Geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Geometry/Geometry.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 14:14:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const double EPS = 1e-8;
const double INF = 1e12;
#define X real()
#define Y imag()
#define EQ(a, b) (abs((a) - (b)) < EPS)
// 点、ベクトル
using P = complex<double>;
const P DUM = {INF + 12345, INF + 67890};
namespace std {
bool operator<(const P& a, const P& b) { return a.X != b.X ? a.X < b.X : a.Y < b.Y; }
}  // namespace std
double dot(const P& a, const P& b) { return a.X * b.X + a.Y * b.Y; }
double cross(const P& a, const P& b) { return a.X * b.Y - a.Y * b.X; }
double manhattan(const P& a, const P& b) { return abs(a.X - b.X) + abs(a.Y - b.Y); }

// 直線 ax + by + c = 0;
struct Line {
    double a, b, c;
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
};
bool parallel(const Line& l1, const Line& l2) { return EQ(l1.a * l2.b, l1.b * l2.a); }
P intersection(const Line& l1, const Line& l2) {
    if (parallel(l1, l2)) return DUM;
    P vec = {l1.b * l2.c - l2.b * l1.c, l2.a * l1.c - l1.a * l2.c};
    return vec / (l1.a * l2.b - l1.b * l2.a);
}

// 線分
struct Segment {
    P p1, p2;
    Segment(const P& p1, const P& p2) : p1(p1), p2(p2) {}
    double len() const { return abs(p2 - p1); }
    bool between(P p) const { return (p1.X - p.X) * (p2.X - p.X) < EPS && (p1.Y - p.Y) * (p2.Y - p.Y) < EPS; }
    Line to_line() const {
        P v = p2 - p1;
        return Line(v.Y, v.X, -(v.Y * p1.X + v.X * p1.Y));
    }
};
// 線分と点の距離
double dist(const Segment& s, const P& p) {
    if (dot(s.p2 - s.p1, p - s.p1) < EPS) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < EPS) return abs(p - s.p2);
    return abs(cross(s.p2 - s.p1, p - s.p1)) / s.len();
}

// 直線と線分の交点
P intersection(const Line& l1, const Segment& s) {
    Line l2 = s.to_line();
    P p = intersection(l1, l2);
    if (!s.between(p)) return DUM;
    return p;
}

// 円
struct Circle {
    P p;
    double r;
    Circle(const P& p, double r) : p(p), r(r) {}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Geometry/Geometry.cpp"
const double EPS = 1e-8;
const double INF = 1e12;
#define X real()
#define Y imag()
#define EQ(a, b) (abs((a) - (b)) < EPS)
// 点、ベクトル
using P = complex<double>;
const P DUM = {INF + 12345, INF + 67890};
namespace std {
bool operator<(const P& a, const P& b) { return a.X != b.X ? a.X < b.X : a.Y < b.Y; }
}  // namespace std
double dot(const P& a, const P& b) { return a.X * b.X + a.Y * b.Y; }
double cross(const P& a, const P& b) { return a.X * b.Y - a.Y * b.X; }
double manhattan(const P& a, const P& b) { return abs(a.X - b.X) + abs(a.Y - b.Y); }

// 直線 ax + by + c = 0;
struct Line {
    double a, b, c;
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
};
bool parallel(const Line& l1, const Line& l2) { return EQ(l1.a * l2.b, l1.b * l2.a); }
P intersection(const Line& l1, const Line& l2) {
    if (parallel(l1, l2)) return DUM;
    P vec = {l1.b * l2.c - l2.b * l1.c, l2.a * l1.c - l1.a * l2.c};
    return vec / (l1.a * l2.b - l1.b * l2.a);
}

// 線分
struct Segment {
    P p1, p2;
    Segment(const P& p1, const P& p2) : p1(p1), p2(p2) {}
    double len() const { return abs(p2 - p1); }
    bool between(P p) const { return (p1.X - p.X) * (p2.X - p.X) < EPS && (p1.Y - p.Y) * (p2.Y - p.Y) < EPS; }
    Line to_line() const {
        P v = p2 - p1;
        return Line(v.Y, v.X, -(v.Y * p1.X + v.X * p1.Y));
    }
};
// 線分と点の距離
double dist(const Segment& s, const P& p) {
    if (dot(s.p2 - s.p1, p - s.p1) < EPS) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < EPS) return abs(p - s.p2);
    return abs(cross(s.p2 - s.p1, p - s.p1)) / s.len();
}

// 直線と線分の交点
P intersection(const Line& l1, const Segment& s) {
    Line l2 = s.to_line();
    P p = intersection(l1, l2);
    if (!s.between(p)) return DUM;
    return p;
}

// 円
struct Circle {
    P p;
    double r;
    Circle(const P& p, double r) : p(p), r(r) {}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

