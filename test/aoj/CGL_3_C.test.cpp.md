---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_geometry_template.hpp
    title: src/geometry/2d_geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_point_and_vector.hpp
    title: src/geometry/2d_point_and_vector.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/2d_polygon.hpp
    title: src/geometry/2d_polygon.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
  bundledCode: "#line 1 \"test/aoj/CGL_3_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/geometry/2d_geometry_template.hpp\"\n\
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
    \ a.a), distance_sp(b, a.b)});\n}\n#line 5 \"src/geometry/2d_polygon.hpp\"\n\n\
    Real area(const Polygon& p) {\n    Real S = 0;\n    int n = p.size();\n    for\
    \ (int i = 0; i < n; i++) {\n        S += cross(p[i], p[(i + 1) % n]);\n    }\n\
    \    return S * 0.5;\n}\n\nbool is_convex(const Polygon& p) {\n    int n = p.size();\n\
    \    for (int i = 0; i < n; i++) {\n        if (ccw(p[(i - 1 + n) % n], p[i],\
    \ p[(i + 1) % n]) == -1) return false;\n    }\n    return true;\n}\n\nint contains(const\
    \ Polygon& Q, const Point& p) {\n    int n = Q.size();\n    bool in = false;\n\
    \    for (int i = 0; i < n; i++) {\n        Point a = Q[i] - p, b = Q[(i + 1)\
    \ % n] - p;\n        if (sign(a.imag() - b.imag()) == +1) swap(a, b);\n      \
    \  if (sign(a.imag()) <= 0 && sign(b.imag()) == +1 && sign(cross(a, b)) == -1)\
    \ in = !in;\n        if (sign(cross(a, b)) == 0 && sign(dot(a, b)) <= 0) return\
    \ 1;\n    }\n    return in ? 2 : 0;\n}\n\nPolygon convex_hull(Polygon p) {\n \
    \   int n = p.size(), k = 0;\n    if (n <= 2) return p;\n    sort(p.begin(), p.end());\n\
    \    Polygon ch(2 * n);\n    for (int i = 0; i < n; ch[k++] = p[i++]) {\n    \
    \    while (k >= 2 && sign(cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])) ==\
    \ -1) --k;\n    }\n    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--])\
    \ {\n        while (k >= t && sign(cross(ch[k - 1] - ch[k - 2], p[i] - ch[k -\
    \ 1])) == -1) --k;\n    }\n    ch.resize(k - 1);\n    return ch;\n}\n\nReal convex_diameter(const\
    \ Polygon& p) {\n    int n = p.size(), is = 0, js = 0;\n    for (int i = 1; i\
    \ < n; i++) {\n        if (sign(p[i].imag() - p[is].imag()) == +1) is = i;\n \
    \       if (sign(p[i].imag() - p[js].imag()) == -1) js = i;\n    }\n    Real maxdis\
    \ = norm(p[is] - p[js]);\n    int maxi, maxj, i, j;\n    i = maxi = is;\n    j\
    \ = maxj = js;\n    do {\n        if (sign(cross(p[(i + 1) % n] - p[i], p[(j +\
    \ 1) % n] - p[j])) >= 0) {\n            j = (j + 1) % n;\n        } else {\n \
    \           i = (i + 1) % n;\n        }\n        if (norm(p[i] - p[j]) > maxdis)\
    \ {\n            maxdis = norm(p[i] - p[j]);\n            maxi = i;\n        \
    \    maxj = j;\n        }\n    } while (i != is || j != js);\n    return sqrt(maxdis);\n\
    }\n\nPolygon convex_cut(const Polygon& p, const Line& l) {\n    int n = p.size();\n\
    \    Polygon ret;\n    for (int i = 0; i < n; i++) {\n        Point now = p[i],\
    \ nxt = p[(i + 1) % n];\n        if (ccw(l.a, l.b, now) != -1) ret.push_back(now);\n\
    \        if (ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) {\n            ret.push_back(cross_point_ll(Line(now,\
    \ nxt), l));\n        }\n    }\n    return ret;\n}\n#line 4 \"test/aoj/CGL_3_C.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    Polygon\
    \ g(n);\n    for (int i = 0; i < n; i++) cin >> g[i];\n    int q;\n    cin >>\
    \ q;\n    while (q--) {\n        Point p;\n        cin >> p;\n        cout <<\
    \ contains(g, p) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/geometry/2d_polygon.hpp\"\nusing\
    \ namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    Polygon g(n);\n\
    \    for (int i = 0; i < n; i++) cin >> g[i];\n    int q;\n    cin >> q;\n   \
    \ while (q--) {\n        Point p;\n        cin >> p;\n        cout << contains(g,\
    \ p) << endl;\n    }\n}\n"
  dependsOn:
  - src/geometry/2d_polygon.hpp
  - src/geometry/2d_geometry_template.hpp
  - src/geometry/2d_point_and_vector.hpp
  - src/geometry/2d_segment_and_line.hpp
  isVerificationFile: true
  path: test/aoj/CGL_3_C.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_3_C.test.cpp
- /verify/test/aoj/CGL_3_C.test.cpp.html
title: test/aoj/CGL_3_C.test.cpp
---
