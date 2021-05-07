---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/old/Geometry/Geometry.hpp\"\nconst double EPS = 1e-8;\n\
    const double INF = 1e12;\n#define X real()\n#define Y imag()\n#define EQ(a, b)\
    \ (abs((a) - (b)) < EPS)\n// \u70B9\u3001\u30D9\u30AF\u30C8\u30EB\nusing P = complex<double>;\n\
    const P DUM = {INF + 12345, INF + 67890};\nnamespace std {\nbool operator<(const\
    \ P& a, const P& b) { return a.X != b.X ? a.X < b.X : a.Y < b.Y; }\n}  // namespace\
    \ std\ndouble dot(const P& a, const P& b) { return a.X * b.X + a.Y * b.Y; }\n\
    double cross(const P& a, const P& b) { return a.X * b.Y - a.Y * b.X; }\ndouble\
    \ manhattan(const P& a, const P& b) { return abs(a.X - b.X) + abs(a.Y - b.Y);\
    \ }\n\n// \u76F4\u7DDA ax + by + c = 0;\nstruct Line {\n    double a, b, c;\n\
    \    Line(double a, double b, double c) : a(a), b(b), c(c) {}\n};\nbool parallel(const\
    \ Line& l1, const Line& l2) { return EQ(l1.a * l2.b, l1.b * l2.a); }\nP intersection(const\
    \ Line& l1, const Line& l2) {\n    if (parallel(l1, l2)) return DUM;\n    P vec\
    \ = {l1.b * l2.c - l2.b * l1.c, l2.a * l1.c - l1.a * l2.c};\n    return vec /\
    \ (l1.a * l2.b - l1.b * l2.a);\n}\n\n// \u7DDA\u5206\nstruct Segment {\n    P\
    \ p1, p2;\n    Segment(const P& p1, const P& p2) : p1(p1), p2(p2) {}\n    double\
    \ len() const { return abs(p2 - p1); }\n    bool between(P p) const { return (p1.X\
    \ - p.X) * (p2.X - p.X) < EPS && (p1.Y - p.Y) * (p2.Y - p.Y) < EPS; }\n    Line\
    \ to_line() const {\n        P v = p2 - p1;\n        return Line(v.Y, v.X, -(v.Y\
    \ * p1.X + v.X * p1.Y));\n    }\n};\n// \u7DDA\u5206\u3068\u70B9\u306E\u8DDD\u96E2\
    \ndouble dist(const Segment& s, const P& p) {\n    if (dot(s.p2 - s.p1, p - s.p1)\
    \ < EPS) return abs(p - s.p1);\n    if (dot(s.p1 - s.p2, p - s.p2) < EPS) return\
    \ abs(p - s.p2);\n    return abs(cross(s.p2 - s.p1, p - s.p1)) / s.len();\n}\n\
    \n// \u76F4\u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u70B9\nP intersection(const Line&\
    \ l1, const Segment& s) {\n    Line l2 = s.to_line();\n    P p = intersection(l1,\
    \ l2);\n    if (!s.between(p)) return DUM;\n    return p;\n}\n\n// \u5186\nstruct\
    \ Circle {\n    P p;\n    double r;\n    Circle(const P& p, double r) : p(p),\
    \ r(r) {}\n};\n"
  code: "const double EPS = 1e-8;\nconst double INF = 1e12;\n#define X real()\n#define\
    \ Y imag()\n#define EQ(a, b) (abs((a) - (b)) < EPS)\n// \u70B9\u3001\u30D9\u30AF\
    \u30C8\u30EB\nusing P = complex<double>;\nconst P DUM = {INF + 12345, INF + 67890};\n\
    namespace std {\nbool operator<(const P& a, const P& b) { return a.X != b.X ?\
    \ a.X < b.X : a.Y < b.Y; }\n}  // namespace std\ndouble dot(const P& a, const\
    \ P& b) { return a.X * b.X + a.Y * b.Y; }\ndouble cross(const P& a, const P& b)\
    \ { return a.X * b.Y - a.Y * b.X; }\ndouble manhattan(const P& a, const P& b)\
    \ { return abs(a.X - b.X) + abs(a.Y - b.Y); }\n\n// \u76F4\u7DDA ax + by + c =\
    \ 0;\nstruct Line {\n    double a, b, c;\n    Line(double a, double b, double\
    \ c) : a(a), b(b), c(c) {}\n};\nbool parallel(const Line& l1, const Line& l2)\
    \ { return EQ(l1.a * l2.b, l1.b * l2.a); }\nP intersection(const Line& l1, const\
    \ Line& l2) {\n    if (parallel(l1, l2)) return DUM;\n    P vec = {l1.b * l2.c\
    \ - l2.b * l1.c, l2.a * l1.c - l1.a * l2.c};\n    return vec / (l1.a * l2.b -\
    \ l1.b * l2.a);\n}\n\n// \u7DDA\u5206\nstruct Segment {\n    P p1, p2;\n    Segment(const\
    \ P& p1, const P& p2) : p1(p1), p2(p2) {}\n    double len() const { return abs(p2\
    \ - p1); }\n    bool between(P p) const { return (p1.X - p.X) * (p2.X - p.X) <\
    \ EPS && (p1.Y - p.Y) * (p2.Y - p.Y) < EPS; }\n    Line to_line() const {\n  \
    \      P v = p2 - p1;\n        return Line(v.Y, v.X, -(v.Y * p1.X + v.X * p1.Y));\n\
    \    }\n};\n// \u7DDA\u5206\u3068\u70B9\u306E\u8DDD\u96E2\ndouble dist(const Segment&\
    \ s, const P& p) {\n    if (dot(s.p2 - s.p1, p - s.p1) < EPS) return abs(p - s.p1);\n\
    \    if (dot(s.p1 - s.p2, p - s.p2) < EPS) return abs(p - s.p2);\n    return abs(cross(s.p2\
    \ - s.p1, p - s.p1)) / s.len();\n}\n\n// \u76F4\u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\
    \u70B9\nP intersection(const Line& l1, const Segment& s) {\n    Line l2 = s.to_line();\n\
    \    P p = intersection(l1, l2);\n    if (!s.between(p)) return DUM;\n    return\
    \ p;\n}\n\n// \u5186\nstruct Circle {\n    P p;\n    double r;\n    Circle(const\
    \ P& p, double r) : p(p), r(r) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/old/Geometry/Geometry.hpp
  requiredBy: []
  timestamp: '2020-04-28 00:07:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/Geometry/Geometry.hpp
layout: document
redirect_from:
- /library/src/old/Geometry/Geometry.hpp
- /library/src/old/Geometry/Geometry.hpp.html
title: src/old/Geometry/Geometry.hpp
---
