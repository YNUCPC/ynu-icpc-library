---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/bitwise_and_convolution.test.cpp
    title: test/library_checker/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/subset_zeta.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T>\nvector<T> subset_zeta(vector<T> f, int\
    \ n, bool inv = false) {\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ S = 0; S < (1 << n); S++) {\n            if ((S & (1 << i)) != 0) {  // if i\
    \ in S\n                if (!inv) {\n                    f[S] += f[S ^ (1 << i)];\n\
    \                } else {\n                    f[S] -= f[S ^ (1 << i)];\n    \
    \            }\n            }\n        }\n    }\n    return f;\n}\n\ntemplate\
    \ <class T>\nvector<T> supset_zeta(vector<T> f, int n, bool inv = false) {\n \
    \   for (int i = 0; i < n; i++) {\n        for (int S = 0; S < (1 << n); S++)\
    \ {\n            if ((S & (1 << i)) == 0) {  // if i not in S\n              \
    \  if (!inv) {\n                    f[S] += f[S ^ (1 << i)];\n               \
    \ } else {\n                    f[S] -= f[S ^ (1 << i)];\n                }\n\
    \            }\n        }\n    }\n    return f;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nvector<T> subset_zeta(vector<T> f, int n, bool inv = false) {\n \
    \   for (int i = 0; i < n; i++) {\n        for (int S = 0; S < (1 << n); S++)\
    \ {\n            if ((S & (1 << i)) != 0) {  // if i in S\n                if\
    \ (!inv) {\n                    f[S] += f[S ^ (1 << i)];\n                } else\
    \ {\n                    f[S] -= f[S ^ (1 << i)];\n                }\n       \
    \     }\n        }\n    }\n    return f;\n}\n\ntemplate <class T>\nvector<T> supset_zeta(vector<T>\
    \ f, int n, bool inv = false) {\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int S = 0; S < (1 << n); S++) {\n            if ((S & (1 << i)) == 0) {  //\
    \ if i not in S\n                if (!inv) {\n                    f[S] += f[S\
    \ ^ (1 << i)];\n                } else {\n                    f[S] -= f[S ^ (1\
    \ << i)];\n                }\n            }\n        }\n    }\n    return f;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/subset_zeta.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/bitwise_and_convolution.test.cpp
documentation_of: src/math/subset_zeta.hpp
layout: document
redirect_from:
- /library/src/math/subset_zeta.hpp
- /library/src/math/subset_zeta.hpp.html
title: src/math/subset_zeta.hpp
---
