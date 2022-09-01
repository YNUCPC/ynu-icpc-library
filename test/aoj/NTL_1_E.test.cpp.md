---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/extgcd.hpp
    title: src/math/extgcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/aoj/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/math/extgcd.hpp\"\nusing namespace std;\n\
    \ntemplate <class T>\nT extgcd(T a, T b, T& x, T& y) {\n    if (b != 0) {\n  \
    \      T d = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n        return\
    \ d;\n    } else {\n        x = 1;\n        y = 0;\n        return a;\n    }\n\
    }\n#line 4 \"test/aoj/NTL_1_E.test.cpp\"\nusing namespace std;\n\nint main() {\n\
    \    int a, b, x, y;\n    cin >> a >> b;\n    extgcd(a, b, x, y);\n    cout <<\
    \ x << \" \" << y << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/math/extgcd.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int a, b, x, y;\n    cin >> a >> b;\n    extgcd(a,\
    \ b, x, y);\n    cout << x << \" \" << y << endl;\n    return 0;\n}\n"
  dependsOn:
  - src/math/extgcd.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_E.test.cpp
- /verify/test/aoj/NTL_1_E.test.cpp.html
title: test/aoj/NTL_1_E.test.cpp
---
