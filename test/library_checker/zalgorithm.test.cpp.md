---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/z_algorithm.hpp
    title: src/string/z_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/library_checker/zalgorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/string/z_algorithm.hpp\"\nusing namespace std;\n\nvector<int> z_algorithm(string&\
    \ s) {\n    int n = int(s.size());\n    vector<int> z(n);\n    z[0] = n;\n   \
    \ for (int i = 1, l = 0, r = 0; i < n; i++) {\n        int& k = z[i];\n      \
    \  k = (r <= i ? 0 : min(r - i, z[i - l]));\n        while (i + k < n && s[k]\
    \ == s[i + k]) k++;\n        if (r < i + k) l = i, r = i + k;\n    }\n    return\
    \ z;\n}\n#line 4 \"test/library_checker/zalgorithm.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    string s;\n    cin >> s;\n    int n = s.size();\n    vector<int> z = z_algorithm(s);\n\
    \    for (int i = 0; i < n; i++) {\n        cout << z[i] << \" \\n\"[i == n -\
    \ 1];\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <bits/stdc++.h>\n#include \"../../src/string/z_algorithm.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    string s;\n    cin >> s;\n    int n = s.size();\n    vector<int> z = z_algorithm(s);\n\
    \    for (int i = 0; i < n; i++) {\n        cout << z[i] << \" \\n\"[i == n -\
    \ 1];\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/string/z_algorithm.hpp
  isVerificationFile: true
  path: test/library_checker/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/zalgorithm.test.cpp
- /verify/test/library_checker/zalgorithm.test.cpp.html
title: test/library_checker/zalgorithm.test.cpp
---
