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
  bundledCode: "#line 2 \"src/geometry/3d_intersection_of_planes.hpp\"\n\nusing P3db\
    \ = pair<Point3d, bool>;\n\n/*\n[*] Input:\n    \uFF12\u3064\u306E\u5E73\u9762\
    \ pl1, pl2\n[*] Output:\n    \uFF12\u3064\u306E\u5E73\u9762\u304C\u4EA4\u7DDA\u3092\
    \u3082\u3064\u5834\u5408 -> first:\u4EA4\u7DDA\u4E0A\u306E\u4EFB\u610F\u306E\uFF11\
    \u70B9, second:true\n\u3000\u3000 \u3000\u3000\u3000 \u4EA4\u7DDA\u3092\u6301\u305F\
    \u306A\u3044\u5834\u5408 -> first:empty             , second:false\n*/\nP3db intersectPlPl(const\
    \ Plane3d& pl1, const Plane3d& pl2) {\n    Vector3d v = cross(pl1.normal_vector,\
    \ pl2.normal_vector);\n    if (!equals(v.x, 0.0)) {\n        Point3d p(0,\n  \
    \                (pl1.d * pl2.normal_vector.z - pl2.d * pl1.normal_vector.z) /\
    \ v.x,\n                  (pl1.d * pl2.normal_vector.y - pl2.d * pl1.normal_vector.y)\
    \ / (-v.x));\n        return P3db(p, true);\n    }\n    if (!equals(v.y, 0.0))\
    \ {\n        Point3d p((pl1.d * pl2.normal_vector.z - pl2.d * pl1.normal_vector.z)\
    \ / (-v.y),\n                  0,\n                  (pl1.d * pl2.normal_vector.x\
    \ - pl2.d * pl1.normal_vector.x) / v.y);\n        return P3db(p, true);\n    }\n\
    \    if (!equals(v.z, 0.0)) {\n        Point3d p((pl1.d * pl2.normal_vector.y\
    \ - pl2.d * pl1.normal_vector.y) / v.z,\n                  (pl1.d * pl2.normal_vector.x\
    \ - pl2.d * pl1.normal_vector.x) / (-v.z),\n                  0);\n        return\
    \ P3db(p, true);\n    }\n    return P3db(Point3d(), false);  //\u5E73\u884C\u306A\
    \u306E\u3067\u305D\u306E\u3088\u3046\u306A\u4EA4\u7DDA\u306F\u5B58\u5728\u3057\
    \u306A\u3044\n}\n\n/*\n[*] Input:\n    \uFF12\u3064\u306E\u5E73\u9762 plane, plane2\
    \ \u3068\u305D\u306E\u4EA4\u7DDA\u4E0A\u306E\u4EFB\u610F\u306E\uFF11\u70B9\n[*]\
    \ Output:\n    \uFF12\u3064\u306E\u5E73\u9762\u306E\u4EA4\u7DDA\n\n\u8AAC\u660E\
    :\n2\u3064\u306E\u5E73\u9762\u306E\u5916\u7A4D\u304B\u3089\u4EA4\u7DDA\u306E\u65B9\
    \u5411\u30D9\u30AF\u30C8\u30EB\u3092\u5F97\u308B\n\u3042\u3068\u306F\u4EFB\u610F\
    \u306E\uFF11\u70B9\u306B\u62E1\u5F35\u3057\u305F\u65B9\u5411\u30D9\u30AF\u30C8\
    \u30EB\u3092\u52A0\u3048\u3066\u30BB\u30B0\u30E1\u30F3\u30C8\u5316\u3059\u308B\
    \n\u4EA4\u7DDA\u4E0A\u306E\u4EFB\u610F\u306E\uFF11\u70B9\u306FintersectPlPl\u3067\
    \u53D6\u5F97\u3067\u304D\u308B\n\u9762\u5012\u306A\u4ED5\u69D8\u306B\u306A\u3063\
    \u3066\u3057\u307E\u3063\u305F\n*/\nLine3d intersectPlPl_converter(Plane3d plane,\
    \ Plane3d plane2, Point3d tmp) {\n    Vector3d ve = cross(plane.normal_vector,\
    \ plane2.normal_vector);\n    return Line3d(tmp, tmp + (ve * 10));  // \u4EFB\u610F\
    \u306E\u500D\u6570\u3067\u62E1\u5F35\u3001\u3053\u3053\u3067\u306F10\n}\n"
  code: "#pragma once\n\nusing P3db = pair<Point3d, bool>;\n\n/*\n[*] Input:\n   \
    \ \uFF12\u3064\u306E\u5E73\u9762 pl1, pl2\n[*] Output:\n    \uFF12\u3064\u306E\
    \u5E73\u9762\u304C\u4EA4\u7DDA\u3092\u3082\u3064\u5834\u5408 -> first:\u4EA4\u7DDA\
    \u4E0A\u306E\u4EFB\u610F\u306E\uFF11\u70B9, second:true\n\u3000\u3000 \u3000\u3000\
    \u3000 \u4EA4\u7DDA\u3092\u6301\u305F\u306A\u3044\u5834\u5408 -> first:empty \
    \            , second:false\n*/\nP3db intersectPlPl(const Plane3d& pl1, const\
    \ Plane3d& pl2) {\n    Vector3d v = cross(pl1.normal_vector, pl2.normal_vector);\n\
    \    if (!equals(v.x, 0.0)) {\n        Point3d p(0,\n                  (pl1.d\
    \ * pl2.normal_vector.z - pl2.d * pl1.normal_vector.z) / v.x,\n              \
    \    (pl1.d * pl2.normal_vector.y - pl2.d * pl1.normal_vector.y) / (-v.x));\n\
    \        return P3db(p, true);\n    }\n    if (!equals(v.y, 0.0)) {\n        Point3d\
    \ p((pl1.d * pl2.normal_vector.z - pl2.d * pl1.normal_vector.z) / (-v.y),\n  \
    \                0,\n                  (pl1.d * pl2.normal_vector.x - pl2.d *\
    \ pl1.normal_vector.x) / v.y);\n        return P3db(p, true);\n    }\n    if (!equals(v.z,\
    \ 0.0)) {\n        Point3d p((pl1.d * pl2.normal_vector.y - pl2.d * pl1.normal_vector.y)\
    \ / v.z,\n                  (pl1.d * pl2.normal_vector.x - pl2.d * pl1.normal_vector.x)\
    \ / (-v.z),\n                  0);\n        return P3db(p, true);\n    }\n   \
    \ return P3db(Point3d(), false);  //\u5E73\u884C\u306A\u306E\u3067\u305D\u306E\
    \u3088\u3046\u306A\u4EA4\u7DDA\u306F\u5B58\u5728\u3057\u306A\u3044\n}\n\n/*\n\
    [*] Input:\n    \uFF12\u3064\u306E\u5E73\u9762 plane, plane2 \u3068\u305D\u306E\
    \u4EA4\u7DDA\u4E0A\u306E\u4EFB\u610F\u306E\uFF11\u70B9\n[*] Output:\n    \uFF12\
    \u3064\u306E\u5E73\u9762\u306E\u4EA4\u7DDA\n\n\u8AAC\u660E:\n2\u3064\u306E\u5E73\
    \u9762\u306E\u5916\u7A4D\u304B\u3089\u4EA4\u7DDA\u306E\u65B9\u5411\u30D9\u30AF\
    \u30C8\u30EB\u3092\u5F97\u308B\n\u3042\u3068\u306F\u4EFB\u610F\u306E\uFF11\u70B9\
    \u306B\u62E1\u5F35\u3057\u305F\u65B9\u5411\u30D9\u30AF\u30C8\u30EB\u3092\u52A0\
    \u3048\u3066\u30BB\u30B0\u30E1\u30F3\u30C8\u5316\u3059\u308B\n\u4EA4\u7DDA\u4E0A\
    \u306E\u4EFB\u610F\u306E\uFF11\u70B9\u306FintersectPlPl\u3067\u53D6\u5F97\u3067\
    \u304D\u308B\n\u9762\u5012\u306A\u4ED5\u69D8\u306B\u306A\u3063\u3066\u3057\u307E\
    \u3063\u305F\n*/\nLine3d intersectPlPl_converter(Plane3d plane, Plane3d plane2,\
    \ Point3d tmp) {\n    Vector3d ve = cross(plane.normal_vector, plane2.normal_vector);\n\
    \    return Line3d(tmp, tmp + (ve * 10));  // \u4EFB\u610F\u306E\u500D\u6570\u3067\
    \u62E1\u5F35\u3001\u3053\u3053\u3067\u306F10\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/3d_intersection_of_planes.hpp
  requiredBy: []
  timestamp: '2021-11-06 19:25:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2562.test.cpp
documentation_of: src/geometry/3d_intersection_of_planes.hpp
layout: document
redirect_from:
- /library/src/geometry/3d_intersection_of_planes.hpp
- /library/src/geometry/3d_intersection_of_planes.hpp.html
title: src/geometry/3d_intersection_of_planes.hpp
---
