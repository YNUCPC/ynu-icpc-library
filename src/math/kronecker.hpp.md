---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/bitwise_and_convolution_by_kronecker.test.cpp
    title: test/library_checker/bitwise_and_convolution_by_kronecker.test.cpp
  - icon: ':x:'
    path: test/library_checker/bitwise_or_convolution.test.cpp
    title: test/library_checker/bitwise_or_convolution.test.cpp
  - icon: ':x:'
    path: test/library_checker/bitwise_xor_convolution.test.cpp
    title: test/library_checker/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/kronecker.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nnamespace Kronecker {\n\ntemplate <class T>\nvoid mul(vector<T>&\
    \ x, T a, T b, T c, T d) {\n    int n = x.size();\n    for (int j = 1; j < n;\
    \ j <<= 1) {\n        for (int i = 0; i < n; i++) {\n            if ((i & j) ==\
    \ 0) {\n                T s = a * x[i] + b * x[i + j];\n                T t =\
    \ c * x[i] + d * x[i + j];\n                x[i] = s;\n                x[i + j]\
    \ = t;\n            }\n        }\n    }\n}\n\ntemplate <class T>\nvoid fwht(vector<T>&\
    \ a, bool inv) {\n    mul(a, T(1), T(1), T(1), T(-1));\n    if (inv) {\n     \
    \   for (T& x : a) x /= T(a.size());\n    }\n}\n\ntemplate <class T>\nvector<T>\
    \ xor_convolution(vector<T>& a, vector<T>& b) {\n    fwht(a, false);\n    fwht(b,\
    \ false);\n    int n = a.size();\n    vector<T> c(n);\n    for (int i = 0; i <\
    \ n; i++) c[i] = a[i] * b[i];\n    fwht(c, true);\n    return c;\n}\n\ntemplate\
    \ <class T>\nvector<T> and_convolution(vector<T>& a, vector<T>& b) {\n    mul(a,\
    \ T(1), T(1), T(0), T(1));\n    mul(b, T(1), T(1), T(0), T(1));\n    int n = a.size();\n\
    \    vector<T> c(n);\n    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];\n  \
    \  mul(c, T(1), T(-1), T(0), T(1));\n    return c;\n}\n\ntemplate <class T>\n\
    vector<T> or_convolution(vector<T>& a, vector<T>& b) {\n    mul(a, T(1), T(0),\
    \ T(1), T(1));\n    mul(b, T(1), T(0), T(1), T(1));\n    int n = a.size();\n \
    \   vector<T> c(n);\n    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];\n   \
    \ mul(c, T(1), T(0), T(-1), T(1));\n    return c;\n}\n\n}  // namespace Kronecker\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ Kronecker {\n\ntemplate <class T>\nvoid mul(vector<T>& x, T a, T b, T c, T d)\
    \ {\n    int n = x.size();\n    for (int j = 1; j < n; j <<= 1) {\n        for\
    \ (int i = 0; i < n; i++) {\n            if ((i & j) == 0) {\n               \
    \ T s = a * x[i] + b * x[i + j];\n                T t = c * x[i] + d * x[i + j];\n\
    \                x[i] = s;\n                x[i + j] = t;\n            }\n   \
    \     }\n    }\n}\n\ntemplate <class T>\nvoid fwht(vector<T>& a, bool inv) {\n\
    \    mul(a, T(1), T(1), T(1), T(-1));\n    if (inv) {\n        for (T& x : a)\
    \ x /= T(a.size());\n    }\n}\n\ntemplate <class T>\nvector<T> xor_convolution(vector<T>&\
    \ a, vector<T>& b) {\n    fwht(a, false);\n    fwht(b, false);\n    int n = a.size();\n\
    \    vector<T> c(n);\n    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];\n  \
    \  fwht(c, true);\n    return c;\n}\n\ntemplate <class T>\nvector<T> and_convolution(vector<T>&\
    \ a, vector<T>& b) {\n    mul(a, T(1), T(1), T(0), T(1));\n    mul(b, T(1), T(1),\
    \ T(0), T(1));\n    int n = a.size();\n    vector<T> c(n);\n    for (int i = 0;\
    \ i < n; i++) c[i] = a[i] * b[i];\n    mul(c, T(1), T(-1), T(0), T(1));\n    return\
    \ c;\n}\n\ntemplate <class T>\nvector<T> or_convolution(vector<T>& a, vector<T>&\
    \ b) {\n    mul(a, T(1), T(0), T(1), T(1));\n    mul(b, T(1), T(0), T(1), T(1));\n\
    \    int n = a.size();\n    vector<T> c(n);\n    for (int i = 0; i < n; i++) c[i]\
    \ = a[i] * b[i];\n    mul(c, T(1), T(0), T(-1), T(1));\n    return c;\n}\n\n}\
    \  // namespace Kronecker\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/kronecker.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/bitwise_and_convolution_by_kronecker.test.cpp
  - test/library_checker/bitwise_or_convolution.test.cpp
  - test/library_checker/bitwise_xor_convolution.test.cpp
documentation_of: src/math/kronecker.hpp
layout: document
redirect_from:
- /library/src/math/kronecker.hpp
- /library/src/math/kronecker.hpp.html
title: src/math/kronecker.hpp
---
