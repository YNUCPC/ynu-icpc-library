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
  bundledCode: "#line 2 \"src/geometry/3d_point_on_the_triangle.hpp\"\n\nbool point_on_the_triangle3d(Point3d\
    \ tri1, Point3d tri2, Point3d tri3, Point3d p) {\n    // \u7DDA\u5206\u4E0A\u306B\
    p\u304C\u3042\u3063\u305F\u5834\u5408\u3001\u4E09\u89D2\u5F62\u5185\u3068\u307F\
    \u306A\u3059\u5834\u5408\u306F\u4EE5\u4E0B\u306E\u30B3\u30E1\u30F3\u30C8\u30A2\
    \u30A6\u30C8\u3092\u5916\u3059\n    /*\n    if( on_segment3d(Segment3d(tri1,tri2),p)\
    \ ) return true;\n    if( on_segment3d(Segment3d(tri2,tri3),p) ) return true;\n\
    \    if( on_segment3d(Segment3d(tri3,tri1),p) ) return true;\n    */\n\n    vector<Point3d>\
    \ vec(3);\n    vec[0] = tri1, vec[1] = tri2, vec[2] = tri3;\n    double area =\
    \ 0;\n    {\n        double a = abs(vec[0] - vec[1]), b = abs(vec[1] - vec[2]),\
    \ c = abs(vec[2] - vec[0]);\n        double s = (a + b + c) / 2;\n        area\
    \ = sqrt(s * (s - a) * (s - b) * (s - c));\n    }\n    double sum = 0;\n    for\
    \ (int i = 0; i < 3; ++i) {\n        double a = abs(vec[i] - vec[(i + 1) % 3]),\
    \ b = abs(vec[(i + 1) % 3] - p), c = abs(p - vec[i]);\n        double s = (a +\
    \ b + c) / 2;\n        sum += sqrt(s * (s - a) * (s - b) * (s - c));\n    }\n\
    \    return equals(sum, area);\n}\n"
  code: "#pragma once\n\nbool point_on_the_triangle3d(Point3d tri1, Point3d tri2,\
    \ Point3d tri3, Point3d p) {\n    // \u7DDA\u5206\u4E0A\u306Bp\u304C\u3042\u3063\
    \u305F\u5834\u5408\u3001\u4E09\u89D2\u5F62\u5185\u3068\u307F\u306A\u3059\u5834\
    \u5408\u306F\u4EE5\u4E0B\u306E\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\
    \u5916\u3059\n    /*\n    if( on_segment3d(Segment3d(tri1,tri2),p) ) return true;\n\
    \    if( on_segment3d(Segment3d(tri2,tri3),p) ) return true;\n    if( on_segment3d(Segment3d(tri3,tri1),p)\
    \ ) return true;\n    */\n\n    vector<Point3d> vec(3);\n    vec[0] = tri1, vec[1]\
    \ = tri2, vec[2] = tri3;\n    double area = 0;\n    {\n        double a = abs(vec[0]\
    \ - vec[1]), b = abs(vec[1] - vec[2]), c = abs(vec[2] - vec[0]);\n        double\
    \ s = (a + b + c) / 2;\n        area = sqrt(s * (s - a) * (s - b) * (s - c));\n\
    \    }\n    double sum = 0;\n    for (int i = 0; i < 3; ++i) {\n        double\
    \ a = abs(vec[i] - vec[(i + 1) % 3]), b = abs(vec[(i + 1) % 3] - p), c = abs(p\
    \ - vec[i]);\n        double s = (a + b + c) / 2;\n        sum += sqrt(s * (s\
    \ - a) * (s - b) * (s - c));\n    }\n    return equals(sum, area);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/3d_point_on_the_triangle.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/3d_point_on_the_triangle.hpp
layout: document
redirect_from:
- /library/src/geometry/3d_point_on_the_triangle.hpp
- /library/src/geometry/3d_point_on_the_triangle.hpp.html
title: src/geometry/3d_point_on_the_triangle.hpp
---
