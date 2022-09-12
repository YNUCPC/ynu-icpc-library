---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/extgcd.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nT extgcd(T a, T b, T& x, T& y) {\n    if (b != 0)\
    \ {\n        T d = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n      \
    \  return d;\n    } else {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nT extgcd(T a, T b, T& x, T& y) {\n    if (b != 0) {\n        T d\
    \ = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n        return d;\n  \
    \  } else {\n        x = 1;\n        y = 0;\n        return a;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/extgcd.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_E.test.cpp
documentation_of: src/math/extgcd.hpp
layout: document
redirect_from:
- /library/src/math/extgcd.hpp
- /library/src/math/extgcd.hpp.html
title: src/math/extgcd.hpp
---
