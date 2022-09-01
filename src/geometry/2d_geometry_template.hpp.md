---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_circle.hpp
    title: src/geometry/2d_circle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_point_and_vector.hpp
    title: src/geometry/2d_point_and_vector.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_point_set.hpp
    title: src/geometry/2d_point_set.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_polygon.hpp
    title: src/geometry/2d_polygon.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_segment_and_line.hpp
    title: src/geometry/2d_segment_and_line.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C.test.cpp
    title: test/aoj/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A.test.cpp
    title: test/aoj/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B.test.cpp
    title: test/aoj/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D.test.cpp
    title: test/aoj/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_C.test.cpp
    title: test/aoj/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A.test.cpp
    title: test/aoj/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D.test.cpp
    title: test/aoj/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E.test.cpp
    title: test/aoj/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_F.test.cpp
    title: test/aoj/CGL_7_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_G.test.cpp
    title: test/aoj/CGL_7_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_H.test.cpp
    title: test/aoj/CGL_7_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/2d_geometry_template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing Real = double;\nusing Point = complex<Real>;\nusing\
    \ Polygon = vector<Point>;\nconst Real EPS = 1e-8, PI = acos(-1);\n\nPoint operator*(const\
    \ Point& p, const Real& d) {\n    return Point(p.real() * d, p.imag() * d);\n\
    }\n\nPoint operator/(const Point& p, const Real& d) {\n    return Point(p.real()\
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
    \ Line;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Real\
    \ = double;\nusing Point = complex<Real>;\nusing Polygon = vector<Point>;\nconst\
    \ Real EPS = 1e-8, PI = acos(-1);\n\nPoint operator*(const Point& p, const Real&\
    \ d) {\n    return Point(p.real() * d, p.imag() * d);\n}\n\nPoint operator/(const\
    \ Point& p, const Real& d) {\n    return Point(p.real() / d, p.imag() / d);\n\
    }\n\nistream& operator>>(istream& is, Point& p) {\n    Real a, b;\n    is >> a\
    \ >> b;\n    p = Point(a, b);\n    return is;\n}\n\nostream& operator<<(ostream&\
    \ os, const Point& p) {\n    return os << fixed << setprecision(20) << p.real()\
    \ << \" \" << p.imag();\n}\n\nint sign(const Real& r) {\n    if (r <= -EPS) return\
    \ -1;\n    if (r >= +EPS) return +1;\n    return 0;\n}\n\nbool equals(const Real&\
    \ a, const Real& b) {\n    return sign(a - b) == 0;\n}\n\nnamespace std {\nbool\
    \ operator<(const Point& a, const Point& b) {\n    if (equals(a.real(), b.real()))\
    \ return a.imag() < b.imag();\n    return a.real() < b.real();\n}\n}  // namespace\
    \ std\n\nReal dot(const Point& a, const Point& b) {\n    return (conj(a) * b).real();\n\
    }\n\nReal cross(const Point& a, const Point& b) {\n    return (conj(a) * b).imag();\n\
    }\n\nstruct Line {\n    Point a, b;\n    Line() = default;\n    Line(Point a,\
    \ Point b) : a(a), b(b) {}\n};\nusing Segment = Line;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/2d_geometry_template.hpp
  requiredBy:
  - src/geometry/2d_segment_and_line.hpp
  - src/geometry/2d_polygon.hpp
  - src/geometry/2d_point_and_vector.hpp
  - src/geometry/2d_point_set.hpp
  - src/geometry/2d_circle.hpp
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_1_C.test.cpp
documentation_of: src/geometry/2d_geometry_template.hpp
layout: document
redirect_from:
- /library/src/geometry/2d_geometry_template.hpp
- /library/src/geometry/2d_geometry_template.hpp.html
title: src/geometry/2d_geometry_template.hpp
---
