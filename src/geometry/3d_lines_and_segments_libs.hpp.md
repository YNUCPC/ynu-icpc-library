---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2081.test.cpp
    title: test/aoj/2081.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/3d_lines_and_segments_libs.hpp\"\n\n// \u76F4\
    \u7DDA l1 \u3068 l2 \u306F\u5E73\u884C\u304B\uFF1F\nbool isParallel(Line3d l1,\
    \ Line3d l2) {\n    Vector3d A = l1.p[0], B = l1.p[1], C = l2.p[0], D = l2.p[1];\n\
    \    Vector3d AB = B - A, CD = D - C;\n    Vector3d n1 = AB / abs(AB), n2 = CD\
    \ / abs(CD);\n    double tmp = dot(n1, n2);\n    tmp = 1 - tmp * tmp;\n    return\
    \ equals(tmp, 0.0);\n}\n\n// \u76F4\u7DDA l1 \u3068 l2 \u3092\u7D50\u3076\u3088\
    \u3046\u306A\u7DDA\u5206\u3067\u3042\u3063\u3066\u6700\u3082\u8DDD\u96E2\u304C\
    \u77ED\u3044\u3082\u306E\u3092\u8FD4\u3059\n// Note: l1 \u3068 l2 \u304C\u5E73\
    \u884C\u306A\u6642\u306B\u306F\u4F7F\u7528\u3067\u304D\u306A\u3044\u306E\u3067\
    \u6CE8\u610F\nSegment3d nearest_segmentLL(Line3d l1, Line3d l2) {\n    assert(!isParallel(l1,\
    \ l2));  // \u5E73\u884C\u306A\u5834\u5408\u306F\u4F7F\u7528\u4E0D\u53EF\n   \
    \ // l1.p[0] = A, l1.p[1] = B, l2.p[0] = C, l2.p[1] = D\n    Vector3d AB = l1.p[1]\
    \ - l1.p[0];\n    Vector3d CD = l2.p[1] - l2.p[0];\n    Vector3d AC = l2.p[0]\
    \ - l1.p[0];\n    Vector3d n1 = AB / abs(AB), n2 = CD / abs(CD);\n    double d1\
    \ = (dot(n1, AC) - dot(n1, n2) * dot(n2, AC)) / (1.0 - pow(dot(n1, n2), 2));\n\
    \    double d2 = (dot(n1, n2) * dot(n1, AC) - dot(n2, AC)) / (1.0 - pow(dot(n1,\
    \ n2), 2));\n    return Segment3d(l1.p[0] + n1 * d1, l2.p[0] + n2 * d2);\n}\n\n\
    // \u76F4\u7DDA l1 \u3068 l2 \u306F\u4EA4\u5DEE\u3059\u308B\u304B\uFF1F\nbool\
    \ intersectLL(Line3d l1, Line3d l2) {\n    Vector3d A = l1.p[0], B = l1.p[1],\
    \ C = l2.p[0], D = l2.p[1];\n\n    // \u305D\u3082\u305D\u3082l1,l2\u304C\u76F4\
    \u7DDA\u3058\u3083\u306A\u3044\n    if (equals(abs(B - A), 0.0) || equals(abs(D\
    \ - C), 0.0)) {\n        // \u3053\u306E\u5834\u5408\u306F\u6CE8\u610F\n     \
    \   // \u305D\u3082\u305D\u3082\u4E0E\u3048\u3089\u308C\u305F\u7DDA\u5206\u304C\
    \u7DDA\u5206\u306B\u306A\u3063\u3066\u3044\u306A\u3044\u306E\u3067\u3001\u4EA4\
    \u5DEE\u3059\u308B\u304B\u3069\u3046\u304B\u306F\u5224\u5B9A\u3067\u304D\u306A\
    \u3044\n        return false;\n    }\n\n    Vector3d AB = B - A, CD = D - C;\n\
    \    Vector3d n1 = AB / abs(AB), n2 = CD / abs(CD);\n    double tmp = dot(n1,\
    \ n2);\n    tmp = 1 - tmp * tmp;\n\n    if (equals(tmp, 0.0)) return 0;  // \u76F4\
    \u7DDA\u304C\u5E73\u884C\n\n    Segment3d ns = nearest_segmentLL(l1, l2);\n  \
    \  if (ns.p[0] == ns.p[1]) return true;\n    return false;\n}\n\n// \u7DDA\u5206\
    \ seg1 \u3068 seg2 \u306F\u4EA4\u5DEE\u3057\u3066\u3044\u308B\u304B\uFF1F\nbool\
    \ intersectSS(Segment3d seg1, Segment3d seg2) {\n    if (isParallel(seg1, seg2))\
    \ return false;\n    Segment3d seg = nearest_segmentLL(seg1, seg2);\n    if (!(seg.p[0]\
    \ == seg.p[1])) return false;\n    Point3d cp = seg.p[1];\n    return on_segment3d(seg1,\
    \ cp) && on_segment3d(seg2, cp);\n}\n"
  code: "#pragma once\n\n// \u76F4\u7DDA l1 \u3068 l2 \u306F\u5E73\u884C\u304B\uFF1F\
    \nbool isParallel(Line3d l1, Line3d l2) {\n    Vector3d A = l1.p[0], B = l1.p[1],\
    \ C = l2.p[0], D = l2.p[1];\n    Vector3d AB = B - A, CD = D - C;\n    Vector3d\
    \ n1 = AB / abs(AB), n2 = CD / abs(CD);\n    double tmp = dot(n1, n2);\n    tmp\
    \ = 1 - tmp * tmp;\n    return equals(tmp, 0.0);\n}\n\n// \u76F4\u7DDA l1 \u3068\
    \ l2 \u3092\u7D50\u3076\u3088\u3046\u306A\u7DDA\u5206\u3067\u3042\u3063\u3066\u6700\
    \u3082\u8DDD\u96E2\u304C\u77ED\u3044\u3082\u306E\u3092\u8FD4\u3059\n// Note: l1\
    \ \u3068 l2 \u304C\u5E73\u884C\u306A\u6642\u306B\u306F\u4F7F\u7528\u3067\u304D\
    \u306A\u3044\u306E\u3067\u6CE8\u610F\nSegment3d nearest_segmentLL(Line3d l1, Line3d\
    \ l2) {\n    assert(!isParallel(l1, l2));  // \u5E73\u884C\u306A\u5834\u5408\u306F\
    \u4F7F\u7528\u4E0D\u53EF\n    // l1.p[0] = A, l1.p[1] = B, l2.p[0] = C, l2.p[1]\
    \ = D\n    Vector3d AB = l1.p[1] - l1.p[0];\n    Vector3d CD = l2.p[1] - l2.p[0];\n\
    \    Vector3d AC = l2.p[0] - l1.p[0];\n    Vector3d n1 = AB / abs(AB), n2 = CD\
    \ / abs(CD);\n    double d1 = (dot(n1, AC) - dot(n1, n2) * dot(n2, AC)) / (1.0\
    \ - pow(dot(n1, n2), 2));\n    double d2 = (dot(n1, n2) * dot(n1, AC) - dot(n2,\
    \ AC)) / (1.0 - pow(dot(n1, n2), 2));\n    return Segment3d(l1.p[0] + n1 * d1,\
    \ l2.p[0] + n2 * d2);\n}\n\n// \u76F4\u7DDA l1 \u3068 l2 \u306F\u4EA4\u5DEE\u3059\
    \u308B\u304B\uFF1F\nbool intersectLL(Line3d l1, Line3d l2) {\n    Vector3d A =\
    \ l1.p[0], B = l1.p[1], C = l2.p[0], D = l2.p[1];\n\n    // \u305D\u3082\u305D\
    \u3082l1,l2\u304C\u76F4\u7DDA\u3058\u3083\u306A\u3044\n    if (equals(abs(B -\
    \ A), 0.0) || equals(abs(D - C), 0.0)) {\n        // \u3053\u306E\u5834\u5408\u306F\
    \u6CE8\u610F\n        // \u305D\u3082\u305D\u3082\u4E0E\u3048\u3089\u308C\u305F\
    \u7DDA\u5206\u304C\u7DDA\u5206\u306B\u306A\u3063\u3066\u3044\u306A\u3044\u306E\
    \u3067\u3001\u4EA4\u5DEE\u3059\u308B\u304B\u3069\u3046\u304B\u306F\u5224\u5B9A\
    \u3067\u304D\u306A\u3044\n        return false;\n    }\n\n    Vector3d AB = B\
    \ - A, CD = D - C;\n    Vector3d n1 = AB / abs(AB), n2 = CD / abs(CD);\n    double\
    \ tmp = dot(n1, n2);\n    tmp = 1 - tmp * tmp;\n\n    if (equals(tmp, 0.0)) return\
    \ 0;  // \u76F4\u7DDA\u304C\u5E73\u884C\n\n    Segment3d ns = nearest_segmentLL(l1,\
    \ l2);\n    if (ns.p[0] == ns.p[1]) return true;\n    return false;\n}\n\n// \u7DDA\
    \u5206 seg1 \u3068 seg2 \u306F\u4EA4\u5DEE\u3057\u3066\u3044\u308B\u304B\uFF1F\
    \nbool intersectSS(Segment3d seg1, Segment3d seg2) {\n    if (isParallel(seg1,\
    \ seg2)) return false;\n    Segment3d seg = nearest_segmentLL(seg1, seg2);\n \
    \   if (!(seg.p[0] == seg.p[1])) return false;\n    Point3d cp = seg.p[1];\n \
    \   return on_segment3d(seg1, cp) && on_segment3d(seg2, cp);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/3d_lines_and_segments_libs.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2081.test.cpp
documentation_of: src/geometry/3d_lines_and_segments_libs.hpp
layout: document
redirect_from:
- /library/src/geometry/3d_lines_and_segments_libs.hpp
- /library/src/geometry/3d_lines_and_segments_libs.hpp.html
title: src/geometry/3d_lines_and_segments_libs.hpp
---
