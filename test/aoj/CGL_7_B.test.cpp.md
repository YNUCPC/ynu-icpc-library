---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_circle.hpp
    title: src/geometry/2d_circle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_geometry_template.hpp
    title: src/geometry/2d_geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_point_and_vector.hpp
    title: src/geometry/2d_point_and_vector.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_segment_and_line.hpp
    title: src/geometry/2d_segment_and_line.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
  bundledCode: "#line 1 \"test/aoj/CGL_7_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B\"\
    \n#define ERROR 0.000001\n#include <bits/stdc++.h>\n#line 3 \"src/geometry/2d_geometry_template.hpp\"\
    \nusing namespace std;\n\nusing Real = double;\nusing Point = complex<Real>;\n\
    using Polygon = vector<Point>;\nconst Real EPS = 1e-8, PI = acos(-1);\n\nPoint\
    \ operator*(const Point& p, const Real& d) {\n    return Point(p.real() * d, p.imag()\
    \ * d);\n}\n\nPoint operator/(const Point& p, const Real& d) {\n    return Point(p.real()\
    \ / d, p.imag() / d);\n}\n\nistream& operator>>(istream& is, Point& p) {\n   \
    \ Real a, b;\n    is >> a >> b;\n    p = Point(a, b);\n    return is;\n}\n\nostream&\
    \ operator<<(ostream& os, const Point& p) {\n    return os << fixed << setprecision(20)\
    \ << p.real() << \" \" << p.imag();\n}\n\nint sign(const Real& r) {\n    if (r\
    \ <= -EPS) return -1;\n    if (r >= +EPS) return +1;\n    return 0;\n}\n\nbool\
    \ equals(const Real& a, const Real& b) {\n    return sign(a - b) == 0;\n}\n\n\
    namespace std {\nbool operator<(const Point& a, const Point& b) {\n    if (equals(a.real(),\
    \ b.real())) return a.imag() < b.imag();\n    return a.real() < b.real();\n}\n\
    }  // namespace std\n\nReal dot(const Point& a, const Point& b) {\n    return\
    \ (conj(a) * b).real();\n}\n\nReal cross(const Point& a, const Point& b) {\n \
    \   return (conj(a) * b).imag();\n}\n\nstruct Line {\n    Point a, b;\n    Line()\
    \ = default;\n    Line(Point a, Point b) : a(a), b(b) {}\n};\nusing Segment =\
    \ Line;\n#line 3 \"src/geometry/2d_point_and_vector.hpp\"\n\nPoint projection(const\
    \ Line& l, const Point& p) {\n    return l.a + (l.a - l.b) * dot(p - l.a, l.a\
    \ - l.b) / norm(l.a - l.b);\n}\n\nPoint reflection(const Line& l, const Point&\
    \ p) {\n    return p + (projection(l, p) - p) * 2.0;\n}\n\nint ccw(const Point&\
    \ a, Point b, Point c) {\n    b -= a, c -= a;\n    if (sign(cross(b, c)) == +1)\
    \ return +1;\n    if (sign(cross(b, c)) == -1) return -1;\n    if (sign(dot(b,\
    \ c)) == -1) return +2;\n    if (norm(b) < norm(c)) return -2;\n    return 0;\n\
    }\n#line 4 \"src/geometry/2d_segment_and_line.hpp\"\n\nbool is_orthogonal(const\
    \ Line& a, const Line& b) {\n    return equals(dot(a.b - a.a, b.b - b.a), 0);\n\
    }\n\nbool is_parallel(const Line& a, const Line& b) {\n    return equals(cross(a.b\
    \ - a.a, b.b - b.a), 0);\n}\n\nbool is_intersect_ss(const Segment& s, const Segment&\
    \ t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n         \
    \  ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nPoint cross_point_ll(const\
    \ Line& l, const Line& m) {\n    Real A = cross(l.b - l.a, m.b - m.a);\n    Real\
    \ B = cross(l.b - l.a, l.b - m.a);\n    if (equals(abs(A), 0) && equals(abs(B),\
    \ 0)) return m.a;\n    return m.a + (m.b - m.a) * B / A;\n}\n\nReal distance_sp(const\
    \ Segment& s, const Point& p) {\n    Point r = projection(s, p);\n    if (ccw(s.a,\
    \ s.b, r) == 0) return abs(r - p);\n    return min(abs(s.a - p), abs(s.b - p));\n\
    }\n\nReal distance_ss(const Segment& a, const Segment& b) {\n    if (is_intersect_ss(a,\
    \ b)) return 0;\n    return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b,\
    \ a.a), distance_sp(b, a.b)});\n}\n#line 4 \"src/geometry/2d_circle.hpp\"\n\n\
    struct Circle {\n    Point p;\n    Real r;\n    Circle() = default;\n    Circle(Point\
    \ p, Real r) : p(p), r(r) {}\n};\n\nint intersection_cc(Circle c1, Circle c2)\
    \ {\n    if (c1.r < c2.r) swap(c1, c2);\n    Real d = abs(c1.p - c2.p);\n    if\
    \ (sign(c1.r + c2.r - d) == -1) return 4;\n    if (equals(c1.r + c2.r, d)) return\
    \ 3;\n    if (sign(c1.r - c2.r - d) == -1) return 2;\n    if (equals(c1.r - c2.r,\
    \ d)) return 1;\n    return 0;\n}\n\nCircle incircle(const Point& a, const Point&\
    \ b, const Point& c) {\n    Real A = abs(b - c), B = abs(c - a), C = abs(a - b);\n\
    \    Point x = Point((a * A + b * B + c * C) / (A + B + C));\n    Real r = distance_sp(Segment(a,\
    \ b), x);\n    return Circle(x, r);\n}\n\nCircle circumscribed_circle(const Point&\
    \ a, const Point& b, const Point& c) {\n    Point m1((a + b) / 2.0), m2((b + c)\
    \ / 2.0);\n    Point v((b - a).imag(), (a - b).real()), w((b - c).imag(), (c -\
    \ b).real());\n    Line s(m1, Point(m1 + v)), t(m2, Point(m2 + w));\n    Point\
    \ x = cross_point_ll(s, t);\n    return Circle(x, abs(a - x));\n}\n\npair<Point,\
    \ Point> cross_point_cl(const Circle& c, const Line& l) {\n    Point pr = projection(l,\
    \ c.p);\n    if (equals(abs(pr - c.p), c.r)) return {pr, pr};\n    Point e = (l.b\
    \ - l.a) / abs(l.b - l.a);\n    Real k = sqrt(norm(c.r) - norm(pr - c.p));\n \
    \   return {pr - e * k, pr + e * k};\n}\n\npair<Point, Point> cross_point_cc(const\
    \ Circle& c1, const Circle& c2) {\n    Real d = abs(c1.p - c2.p);\n    Real a\
    \ = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));\n    Real t =\
    \ atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());\n    Point p1 =\
    \ c1.p + Point(cos(t + a), sin(t + a)) * c1.r;\n    Point p2 = c1.p + Point(cos(t\
    \ - a), sin(t - a)) * c1.r;\n    return {p1, p2};\n}\n\npair<Point, Point> tangent_cp(const\
    \ Circle& c, const Point& p) {\n    return cross_point_cc(c, Circle(p, sqrt(norm(c.p\
    \ - p) - c.r * c.r)));\n}\n\nvector<Line> tangent_cc(Circle c1, Circle c2) {\n\
    \    vector<Line> ret;\n    if (c1.r < c2.r) swap(c1, c2);\n    Real g = norm(c1.p\
    \ - c2.p);\n    if (equals(g, 0.0)) return ret;\n    Point u = (c2.p - c1.p) /\
    \ sqrt(g);\n    Point v = u * Point(cos(PI * 0.5), sin(PI * 0.5));\n    for (int\
    \ s : {-1, 1}) {\n        Real h = (c1.r + s * c2.r) / sqrt(g);\n        if (equals(1\
    \ - h * h, 0.0)) {\n            ret.emplace_back(c1.p + u * c1.r, c1.p + (u +\
    \ v) * c1.r);\n        } else if (sign(1 - h * h) == +1) {\n            Point\
    \ uu = u * h, vv = v * sqrt(1 - h * h);\n            ret.emplace_back(c1.p + (uu\
    \ + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);\n            ret.emplace_back(c1.p\
    \ + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);\n        }\n    }\n    return\
    \ ret;\n}\n\nReal area_poly_c(const Polygon& p, const Circle& c) {\n    int n\
    \ = p.size();\n    if (n < 3) return 0.0;\n    function<Real(Circle, Point, Point)>\
    \ cross_area = [&](const Circle& c, const Point& a, const Point& b) {\n      \
    \  Point va = c.p - a, vb = c.p - b;\n        Real f = cross(va, vb), ret = 0.0;\n\
    \        if (equals(f, 0.0)) return ret;\n        if (max(abs(va), abs(vb)) <\
    \ c.r + EPS) return f;\n        if (distance_sp(Segment(a, b), c.p) > c.r - EPS)\
    \ return c.r * c.r * arg(vb * conj(va));\n        auto u = cross_point_cl(c, Segment(a,\
    \ b));\n        vector<Point> tot{a, u.first, u.second, b};\n        for (int\
    \ i = 0; i + 1 < (int)tot.size(); i++) {\n            ret += cross_area(c, tot[i],\
    \ tot[i + 1]);\n        }\n        return ret;\n    };\n    Real S = 0;\n    for\
    \ (int i = 0; i < n; i++) {\n        S += cross_area(c, p[i], p[(i + 1) % n]);\n\
    \    }\n    return S * 0.5;\n}\n\nReal area_cc(const Circle& c1, const Circle&\
    \ c2) {\n    Real d = abs(c1.p - c2.p);\n    if (c1.r + c2.r <= d + EPS) return\
    \ 0.0;\n    if (d <= fabs(c1.r - c2.r) + EPS) {\n        Real r = min(c1.r, c2.r);\n\
    \        return r * r * PI;\n    }\n    Real rc = (d * d + c1.r * c1.r - c2.r\
    \ * c2.r) / (2.0 * d);\n    Real theta = acos(rc / c1.r);\n    Real phi = acos((d\
    \ - rc) / c2.r);\n    return c1.r * c1.r * theta + c2.r * c2.r * phi - d * c1.r\
    \ * sin(theta);\n}\n#line 5 \"test/aoj/CGL_7_B.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n    Point a, b, c;\n    cin >> a >> b >> c;\n    Circle ans =\
    \ incircle(a, b, c);\n    cout << ans.p << \" \" << fixed << setprecision(20)\
    \ << ans.r << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B\"\
    \n#define ERROR 0.000001\n#include <bits/stdc++.h>\n#include \"../../src/geometry/2d_circle.hpp\"\
    \nusing namespace std;\n\nint main() {\n    Point a, b, c;\n    cin >> a >> b\
    \ >> c;\n    Circle ans = incircle(a, b, c);\n    cout << ans.p << \" \" << fixed\
    \ << setprecision(20) << ans.r << endl;\n}\n"
  dependsOn:
  - src/geometry/2d_circle.hpp
  - src/geometry/2d_geometry_template.hpp
  - src/geometry/2d_segment_and_line.hpp
  - src/geometry/2d_point_and_vector.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_B.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_B.test.cpp
- /verify/test/aoj/CGL_7_B.test.cpp.html
title: test/aoj/CGL_7_B.test.cpp
---
