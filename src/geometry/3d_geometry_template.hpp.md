---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1331.test.cpp
    title: test/aoj/1331.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2081.test.cpp
    title: test/aoj/2081.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2562.test.cpp
    title: test/aoj/2562.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/3d_geometry_template.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define EPS (1e-7)\n#define equals(a, b) (fabs((a) - (b))\
    \ < EPS)\n\nclass Point3d {\n  public:\n    double x, y, z;\n\n    Point3d(double\
    \ x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}\n\n    Point3d operator+(const\
    \ Point3d& a) {\n        return Point3d(x + a.x, y + a.y, z + a.z);\n    }\n \
    \   Point3d operator-(const Point3d& a) {\n        return Point3d(x - a.x, y -\
    \ a.y, z - a.z);\n    }\n    Point3d operator*(const double& d) {\n        return\
    \ Point3d(x * d, y * d, z * d);\n    }\n    Point3d operator/(const double& d)\
    \ {\n        return Point3d(x / d, y / d, z / d);\n    }\n\n    bool operator<(const\
    \ Point3d& p) const {\n        if (!equals(x, p.x)) return x < p.x;\n        if\
    \ (!equals(y, p.y)) return y < p.y;\n        if (!equals(z, p.z)) return z < p.z;\n\
    \        return false;\n    }\n\n    bool operator==(const Point3d& p) const {\n\
    \        return equals(x, p.x) && equals(y, p.y) && equals(z, p.z);\n    }\n};\n\
    \nstruct Segment3d {\n    Point3d p[2];\n    Segment3d(Point3d p1 = Point3d(),\
    \ Point3d p2 = Point3d()) {\n        p[0] = p1, p[1] = p2;\n    }\n    bool operator==(const\
    \ Segment3d& seg) const {\n        return (p[0] == seg.p[0] && p[1] == seg.p[1])\
    \ || (p[0] == seg.p[1] && p[1] == seg.p[0]);\n    }\n};\n\nusing Line3d = Segment3d;\n\
    using Vector3d = Point3d;\n\nostream& operator<<(ostream& os, const Point3d& p)\
    \ {\n    return os << \"(\" << p.x << \",\" << p.y << \",\" << p.z << \")\";\n\
    }\n\nostream& operator<<(ostream& os, const Segment3d& seg) {\n    return os <<\
    \ \"(\" << seg.p[0] << \",\" << seg.p[1] << \")\";\n}\n\ndouble dot(const Point3d&\
    \ a, const Point3d& b) {\n    return a.x * b.x + a.y * b.y + a.z * b.z;\n}\n\n\
    Vector3d cross(const Point3d& a, const Point3d& b) {\n    return Vector3d(a.y\
    \ * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);\n}\n\ninline\
    \ double norm(const Point3d& p) {\n    return p.x * p.x + p.y * p.y + p.z * p.z;\n\
    }\n\ninline double abs(const Point3d& p) {\n    return sqrt(norm(p));\n}\n\ninline\
    \ double toRad(double theta) {\n    return theta * M_PI / 180.0;\n}\n\ndouble\
    \ distanceLP(Line3d line, Point3d p) {\n    return abs(cross(line.p[1] - line.p[0],\
    \ p - line.p[0])) / abs(line.p[1] - line.p[0]);\n}\n\nPoint3d project(Segment3d\
    \ seg, Point3d p) {\n    Vector3d base = seg.p[1] - seg.p[0];\n    double t =\
    \ dot(p - seg.p[0], base) / norm(base);\n    return seg.p[0] + base * t;\n}\n\n\
    Point3d reflect(Segment3d seg, Point3d p) {\n    return p + (project(seg, p) -\
    \ p) * 2.0;\n}\n\nbool on_line3d(Line3d line, Point3d p) {\n    return equals(abs(cross(line.p[1]\
    \ - p, line.p[0] - p)), 0);\n}\n\nbool on_segment3d(Segment3d seg, Point3d p)\
    \ {\n    if (!on_line3d(seg, p)) return false;\n    double dist[3] = {abs(seg.p[1]\
    \ - seg.p[0]), abs(p - seg.p[0]), abs(p - seg.p[1])};\n    return on_line3d(seg,\
    \ p) && equals(dist[0], dist[1] + dist[2]);\n}\n\ndouble distanceSP(Segment3d\
    \ seg, Point3d p) {\n    Point3d r = project(seg, p);\n    if (on_segment3d(seg,\
    \ r)) return abs(p - r);\n    return min(abs(seg.p[0] - p), abs(seg.p[1] - p));\n\
    }\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ EPS (1e-7)\n#define equals(a, b) (fabs((a) - (b)) < EPS)\n\nclass Point3d {\n\
    \  public:\n    double x, y, z;\n\n    Point3d(double x = 0, double y = 0, double\
    \ z = 0) : x(x), y(y), z(z) {}\n\n    Point3d operator+(const Point3d& a) {\n\
    \        return Point3d(x + a.x, y + a.y, z + a.z);\n    }\n    Point3d operator-(const\
    \ Point3d& a) {\n        return Point3d(x - a.x, y - a.y, z - a.z);\n    }\n \
    \   Point3d operator*(const double& d) {\n        return Point3d(x * d, y * d,\
    \ z * d);\n    }\n    Point3d operator/(const double& d) {\n        return Point3d(x\
    \ / d, y / d, z / d);\n    }\n\n    bool operator<(const Point3d& p) const {\n\
    \        if (!equals(x, p.x)) return x < p.x;\n        if (!equals(y, p.y)) return\
    \ y < p.y;\n        if (!equals(z, p.z)) return z < p.z;\n        return false;\n\
    \    }\n\n    bool operator==(const Point3d& p) const {\n        return equals(x,\
    \ p.x) && equals(y, p.y) && equals(z, p.z);\n    }\n};\n\nstruct Segment3d {\n\
    \    Point3d p[2];\n    Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d())\
    \ {\n        p[0] = p1, p[1] = p2;\n    }\n    bool operator==(const Segment3d&\
    \ seg) const {\n        return (p[0] == seg.p[0] && p[1] == seg.p[1]) || (p[0]\
    \ == seg.p[1] && p[1] == seg.p[0]);\n    }\n};\n\nusing Line3d = Segment3d;\n\
    using Vector3d = Point3d;\n\nostream& operator<<(ostream& os, const Point3d& p)\
    \ {\n    return os << \"(\" << p.x << \",\" << p.y << \",\" << p.z << \")\";\n\
    }\n\nostream& operator<<(ostream& os, const Segment3d& seg) {\n    return os <<\
    \ \"(\" << seg.p[0] << \",\" << seg.p[1] << \")\";\n}\n\ndouble dot(const Point3d&\
    \ a, const Point3d& b) {\n    return a.x * b.x + a.y * b.y + a.z * b.z;\n}\n\n\
    Vector3d cross(const Point3d& a, const Point3d& b) {\n    return Vector3d(a.y\
    \ * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);\n}\n\ninline\
    \ double norm(const Point3d& p) {\n    return p.x * p.x + p.y * p.y + p.z * p.z;\n\
    }\n\ninline double abs(const Point3d& p) {\n    return sqrt(norm(p));\n}\n\ninline\
    \ double toRad(double theta) {\n    return theta * M_PI / 180.0;\n}\n\ndouble\
    \ distanceLP(Line3d line, Point3d p) {\n    return abs(cross(line.p[1] - line.p[0],\
    \ p - line.p[0])) / abs(line.p[1] - line.p[0]);\n}\n\nPoint3d project(Segment3d\
    \ seg, Point3d p) {\n    Vector3d base = seg.p[1] - seg.p[0];\n    double t =\
    \ dot(p - seg.p[0], base) / norm(base);\n    return seg.p[0] + base * t;\n}\n\n\
    Point3d reflect(Segment3d seg, Point3d p) {\n    return p + (project(seg, p) -\
    \ p) * 2.0;\n}\n\nbool on_line3d(Line3d line, Point3d p) {\n    return equals(abs(cross(line.p[1]\
    \ - p, line.p[0] - p)), 0);\n}\n\nbool on_segment3d(Segment3d seg, Point3d p)\
    \ {\n    if (!on_line3d(seg, p)) return false;\n    double dist[3] = {abs(seg.p[1]\
    \ - seg.p[0]), abs(p - seg.p[0]), abs(p - seg.p[1])};\n    return on_line3d(seg,\
    \ p) && equals(dist[0], dist[1] + dist[2]);\n}\n\ndouble distanceSP(Segment3d\
    \ seg, Point3d p) {\n    Point3d r = project(seg, p);\n    if (on_segment3d(seg,\
    \ r)) return abs(p - r);\n    return min(abs(seg.p[0] - p), abs(seg.p[1] - p));\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/3d_geometry_template.hpp
  requiredBy: []
  timestamp: '2021-11-04 13:51:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2081.test.cpp
  - test/aoj/2562.test.cpp
  - test/aoj/1331.test.cpp
documentation_of: src/geometry/3d_geometry_template.hpp
layout: document
redirect_from:
- /library/src/geometry/3d_geometry_template.hpp
- /library/src/geometry/3d_geometry_template.hpp.html
title: src/geometry/3d_geometry_template.hpp
---
