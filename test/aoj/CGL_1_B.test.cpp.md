---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_geometry_template.hpp
    title: src/geometry/2d_geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_point_and_vector.hpp
    title: src/geometry/2d_point_and_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
  bundledCode: "#line 1 \"test/aoj/CGL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR 0.00000001\n#include <bits/stdc++.h>\n#line 3 \"src/geometry/2d_geometry_template.hpp\"\
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
    }\n#line 6 \"test/aoj/CGL_1_B.test.cpp\"\nusing namespace std;\n\nint main() {\n\
    \    Line l;\n    {\n        Point p1, p2;\n        cin >> p1 >> p2;\n       \
    \ l = Line(p1, p2);\n    }\n\n    int q;\n    cin >> q;\n    while (q--) {\n \
    \       Point p;\n        cin >> p;\n        cout << reflection(l, p) << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR 0.00000001\n#include <bits/stdc++.h>\n#include \"../../src/geometry/2d_geometry_template.hpp\"\
    \n#include \"../../src/geometry/2d_point_and_vector.hpp\"\nusing namespace std;\n\
    \nint main() {\n    Line l;\n    {\n        Point p1, p2;\n        cin >> p1 >>\
    \ p2;\n        l = Line(p1, p2);\n    }\n\n    int q;\n    cin >> q;\n    while\
    \ (q--) {\n        Point p;\n        cin >> p;\n        cout << reflection(l,\
    \ p) << endl;\n    }\n}\n"
  dependsOn:
  - src/geometry/2d_geometry_template.hpp
  - src/geometry/2d_point_and_vector.hpp
  isVerificationFile: true
  path: test/aoj/CGL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 15:18:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_B.test.cpp
- /verify/test/aoj/CGL_1_B.test.cpp.html
title: test/aoj/CGL_1_B.test.cpp
---