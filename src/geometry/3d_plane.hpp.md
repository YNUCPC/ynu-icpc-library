---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2562.test.cpp
    title: test/aoj/2562.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/3d_plane.hpp\"\n\nclass Plane3d {\n  public:\n\
    \    Point3d normal_vector;  // \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB\n    double\
    \ d;               // \u5E73\u9762\u65B9\u7A0B\u5F0F normal_vector = (a,b,c),\
    \ a*x + b*y + c*z + d = 0\n\n    Plane3d(Point3d normal_vector = Point3d(), double\
    \ d = 0) : normal_vector(normal_vector), d(d) {}\n    Plane3d(Vector3d a, Vector3d\
    \ b, Vector3d c) {\n        Vector3d v1 = b - a;\n        Vector3d v2 = c - a;\n\
    \        Vector3d tmp = cross(v1, v2);\n        normal_vector = tmp / abs(tmp);\n\
    \        set_d(a);\n    }\n\n    // \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EBnormal_vector\u3068\
    \u5E73\u9762\u4E0A\u306E\uFF11\u70B9\u304B\u3089d\u3092\u8A08\u7B97\u3059\u308B\
    \n    void set_d(Point3d p) {\n        d = dot(normal_vector, p);\n    }\n\n \
    \   // \u5E73\u9762\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n \
    \   double distanceP(Point3d p) {\n        Point3d a = normal_vector * d;  //\
    \ \u5E73\u9762\u4E0A\u306E\u9069\u5F53\u306A\u70B9\u3092\u3064\u304F\u308B\n \
    \       return abs(dot(p - a, normal_vector));\n    }\n\n    // \u5E73\u9762\u4E0A\
    \u3067\u3082\u3063\u3068\u3082\u70B9p\u3068\u8FD1\u3044\u70B9\u3092\u6C42\u3081\
    \u308B\n    Point3d nearest_point(Point3d p) {\n        Point3d a = normal_vector\
    \ * d;\n        return p - (normal_vector * dot(p - a, normal_vector));\n    }\n\
    \n    // \u5E73\u9762\u3068\u7DDA\u5206\u304C\u4EA4\u5DEE\u3059\u308B\u304B\n\
    \    bool intersectS(Segment3d seg) {\n        Point3d a = normal_vector * d;\n\
    \        double res1 = dot(a - seg.p[0], normal_vector);\n        double res2\
    \ = dot(a - seg.p[1], normal_vector);\n        if (res1 > res2) swap(res1, res2);\n\
    \        if ((equals(res1, 0.0) || res1 < 0) && (equals(res2, 0.0) || res2 > 0))\
    \ return true;\n        return false;\n    }\n\n    // \u5E73\u9762\u3068\u7DDA\
    \u5206\u306E\u4EA4\u70B9\u3092\u6C42\u3081\u308B\n    Point3d crosspointS(Segment3d\
    \ seg) {\n        Point3d a = normal_vector * d;\n        double dot_p0a = fabs(dot(seg.p[0]\
    \ - a, normal_vector));\n        double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));\n\
    \        if (equals(dot_p0a + dot_p1a, 0)) return seg.p[0];\n        return seg.p[0]\
    \ + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));\n    }\n};\n"
  code: "#pragma once\n\nclass Plane3d {\n  public:\n    Point3d normal_vector;  //\
    \ \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB\n    double d;               // \u5E73\u9762\
    \u65B9\u7A0B\u5F0F normal_vector = (a,b,c), a*x + b*y + c*z + d = 0\n\n    Plane3d(Point3d\
    \ normal_vector = Point3d(), double d = 0) : normal_vector(normal_vector), d(d)\
    \ {}\n    Plane3d(Vector3d a, Vector3d b, Vector3d c) {\n        Vector3d v1 =\
    \ b - a;\n        Vector3d v2 = c - a;\n        Vector3d tmp = cross(v1, v2);\n\
    \        normal_vector = tmp / abs(tmp);\n        set_d(a);\n    }\n\n    // \u6CD5\
    \u7DDA\u30D9\u30AF\u30C8\u30EBnormal_vector\u3068\u5E73\u9762\u4E0A\u306E\uFF11\
    \u70B9\u304B\u3089d\u3092\u8A08\u7B97\u3059\u308B\n    void set_d(Point3d p) {\n\
    \        d = dot(normal_vector, p);\n    }\n\n    // \u5E73\u9762\u3068\u70B9\
    p\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    double distanceP(Point3d p) {\n\
    \        Point3d a = normal_vector * d;  // \u5E73\u9762\u4E0A\u306E\u9069\u5F53\
    \u306A\u70B9\u3092\u3064\u304F\u308B\n        return abs(dot(p - a, normal_vector));\n\
    \    }\n\n    // \u5E73\u9762\u4E0A\u3067\u3082\u3063\u3068\u3082\u70B9p\u3068\
    \u8FD1\u3044\u70B9\u3092\u6C42\u3081\u308B\n    Point3d nearest_point(Point3d\
    \ p) {\n        Point3d a = normal_vector * d;\n        return p - (normal_vector\
    \ * dot(p - a, normal_vector));\n    }\n\n    // \u5E73\u9762\u3068\u7DDA\u5206\
    \u304C\u4EA4\u5DEE\u3059\u308B\u304B\n    bool intersectS(Segment3d seg) {\n \
    \       Point3d a = normal_vector * d;\n        double res1 = dot(a - seg.p[0],\
    \ normal_vector);\n        double res2 = dot(a - seg.p[1], normal_vector);\n \
    \       if (res1 > res2) swap(res1, res2);\n        if ((equals(res1, 0.0) ||\
    \ res1 < 0) && (equals(res2, 0.0) || res2 > 0)) return true;\n        return false;\n\
    \    }\n\n    // \u5E73\u9762\u3068\u7DDA\u5206\u306E\u4EA4\u70B9\u3092\u6C42\u3081\
    \u308B\n    Point3d crosspointS(Segment3d seg) {\n        Point3d a = normal_vector\
    \ * d;\n        double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));\n   \
    \     double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));\n        if (equals(dot_p0a\
    \ + dot_p1a, 0)) return seg.p[0];\n        return seg.p[0] + (seg.p[1] - seg.p[0])\
    \ * (dot_p0a / (dot_p0a + dot_p1a));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/3d_plane.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2562.test.cpp
documentation_of: src/geometry/3d_plane.hpp
layout: document
redirect_from:
- /library/src/geometry/3d_plane.hpp
- /library/src/geometry/3d_plane.hpp.html
title: src/geometry/3d_plane.hpp
---
