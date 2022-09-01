---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_geometry_template.hpp
    title: src/geometry/2d_geometry_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
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
    \ Line;\n#line 3 \"src/geometry/2d_point_set.hpp\"\n\nReal closest_pair(Polygon\
    \ ps) {\n    sort(ps.begin(), ps.end());\n    Polygon a(ps.size());\n\n    function<Real(int,\
    \ int)> rec = [&](int left, int right) -> Real {\n        if (right - left <=\
    \ 1) return 1e18;\n        int mid = (left + right) / 2;\n        Real x = ps[mid].real();\n\
    \        Real ret = min(rec(left, mid), rec(mid, right));\n        inplace_merge(ps.begin()\
    \ + left, ps.begin() + mid, ps.begin() + right,\n                      [&](const\
    \ Point& a, const Point& b) { return a.imag() < b.imag(); });\n        int pos\
    \ = 0;\n        for (int i = left; i < right; i++) {\n            if (fabs((ps[i].real())\
    \ - x) >= ret) continue;\n            for (int j = 0; j < pos; j++) {\n      \
    \          auto tar = ps[i] - a[pos - j - 1];\n                if (tar.imag()\
    \ >= ret) break;\n                ret = min(ret, abs(tar));\n            }\n \
    \           a[pos++] = ps[i];\n        }\n        return ret;\n    };\n    return\
    \ rec(0, (int)ps.size());\n}\n"
  code: "#pragma once\n#include \"2d_geometry_template.hpp\"\n\nReal closest_pair(Polygon\
    \ ps) {\n    sort(ps.begin(), ps.end());\n    Polygon a(ps.size());\n\n    function<Real(int,\
    \ int)> rec = [&](int left, int right) -> Real {\n        if (right - left <=\
    \ 1) return 1e18;\n        int mid = (left + right) / 2;\n        Real x = ps[mid].real();\n\
    \        Real ret = min(rec(left, mid), rec(mid, right));\n        inplace_merge(ps.begin()\
    \ + left, ps.begin() + mid, ps.begin() + right,\n                      [&](const\
    \ Point& a, const Point& b) { return a.imag() < b.imag(); });\n        int pos\
    \ = 0;\n        for (int i = left; i < right; i++) {\n            if (fabs((ps[i].real())\
    \ - x) >= ret) continue;\n            for (int j = 0; j < pos; j++) {\n      \
    \          auto tar = ps[i] - a[pos - j - 1];\n                if (tar.imag()\
    \ >= ret) break;\n                ret = min(ret, abs(tar));\n            }\n \
    \           a[pos++] = ps[i];\n        }\n        return ret;\n    };\n    return\
    \ rec(0, (int)ps.size());\n}\n"
  dependsOn:
  - src/geometry/2d_geometry_template.hpp
  isVerificationFile: false
  path: src/geometry/2d_point_set.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_5_A.test.cpp
documentation_of: src/geometry/2d_point_set.hpp
layout: document
redirect_from:
- /library/src/geometry/2d_point_set.hpp
- /library/src/geometry/2d_point_set.hpp.html
title: src/geometry/2d_point_set.hpp
---
