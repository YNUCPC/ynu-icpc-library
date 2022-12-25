---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_geometry_template.hpp
    title: src/geometry/2d_geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_point_set.hpp
    title: src/geometry/2d_point_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A
  bundledCode: "#line 1 \"test/aoj/CGL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A\"\
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
    \ rec(0, (int)ps.size());\n}\n#line 5 \"test/aoj/CGL_5_A.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int n;\n    cin >> n;\n    Polygon ps(n);\n    for\
    \ (int i = 0; i < n; i++) cin >> ps[i];\n    cout << fixed << setprecision(20)\
    \ << closest_pair(ps) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A\"\
    \n#define ERROR 0.000001\n#include <bits/stdc++.h>\n#include \"../../src/geometry/2d_point_set.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    Polygon\
    \ ps(n);\n    for (int i = 0; i < n; i++) cin >> ps[i];\n    cout << fixed <<\
    \ setprecision(20) << closest_pair(ps) << endl;\n}\n"
  dependsOn:
  - src/geometry/2d_point_set.hpp
  - src/geometry/2d_geometry_template.hpp
  isVerificationFile: true
  path: test/aoj/CGL_5_A.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 18:00:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_5_A.test.cpp
- /verify/test/aoj/CGL_5_A.test.cpp.html
title: test/aoj/CGL_5_A.test.cpp
---
