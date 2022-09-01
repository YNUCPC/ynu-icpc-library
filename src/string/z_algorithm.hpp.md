---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B_zalgorithm.test.cpp
    title: test/aoj/ALDS1_14_B_zalgorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/zalgorithm.test.cpp
    title: test/library_checker/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/z_algorithm.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<int> z_algorithm(string& s) {\n    int n = int(s.size());\n\
    \    vector<int> z(n);\n    z[0] = n;\n    for (int i = 1, l = 0, r = 0; i < n;\
    \ i++) {\n        int& k = z[i];\n        k = (r <= i ? 0 : min(r - i, z[i - l]));\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (r < i + k) l\
    \ = i, r = i + k;\n    }\n    return z;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int>\
    \ z_algorithm(string& s) {\n    int n = int(s.size());\n    vector<int> z(n);\n\
    \    z[0] = n;\n    for (int i = 1, l = 0, r = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (r <= i ? 0 : min(r - i, z[i - l]));\n        while (i\
    \ + k < n && s[k] == s[i + k]) k++;\n        if (r < i + k) l = i, r = i + k;\n\
    \    }\n    return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/zalgorithm.test.cpp
  - test/aoj/ALDS1_14_B_zalgorithm.test.cpp
documentation_of: src/string/z_algorithm.hpp
layout: document
redirect_from:
- /library/src/string/z_algorithm.hpp
- /library/src/string/z_algorithm.hpp.html
title: src/string/z_algorithm.hpp
---
