---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3112.test.cpp
    title: test/aoj/3112.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_of_substrings.test.cpp
    title: test/library_checker/number_of_substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/lcp_array.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// lcp[i] = sa[i]\u3068sa[i+1]\u306E common prefix \u306E\u9577\
    \u3055\nvector<int> lcp_array(const string& s, const vector<int>& sa) {\n    int\
    \ n = sa.size();\n    vector<int> lcp(n), rank(n);  // rank[i] = s[i,n)\u306E\u8F9E\
    \u66F8\u9806\u4F4D\n    for (int i = 0; i < n; i++) rank[sa[i]] = i;\n    for\
    \ (int i = 0, len = 0; i < n; i++) {\n        if (len > 0) len--;\n        if\
    \ (rank[i] == n - 1) continue;\n        int j = sa[rank[i] + 1];  // s[i,n)\u3088\
    \u308A\u8F9E\u66F8\u9806\u30671\u3064\u5927\u304D\u3044suffix\u306E\u5148\u982D\
    \u4F4D\u7F6E\n        while (max(i, j) + len < int(s.size()) && s[i + len] ==\
    \ s[j + len]) len++;\n        lcp[rank[i]] = len;\n    }\n    return lcp;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// lcp[i]\
    \ = sa[i]\u3068sa[i+1]\u306E common prefix \u306E\u9577\u3055\nvector<int> lcp_array(const\
    \ string& s, const vector<int>& sa) {\n    int n = sa.size();\n    vector<int>\
    \ lcp(n), rank(n);  // rank[i] = s[i,n)\u306E\u8F9E\u66F8\u9806\u4F4D\n    for\
    \ (int i = 0; i < n; i++) rank[sa[i]] = i;\n    for (int i = 0, len = 0; i < n;\
    \ i++) {\n        if (len > 0) len--;\n        if (rank[i] == n - 1) continue;\n\
    \        int j = sa[rank[i] + 1];  // s[i,n)\u3088\u308A\u8F9E\u66F8\u9806\u3067\
    1\u3064\u5927\u304D\u3044suffix\u306E\u5148\u982D\u4F4D\u7F6E\n        while (max(i,\
    \ j) + len < int(s.size()) && s[i + len] == s[j + len]) len++;\n        lcp[rank[i]]\
    \ = len;\n    }\n    return lcp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/lcp_array.hpp
  requiredBy: []
  timestamp: '2022-09-14 02:48:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3112.test.cpp
  - test/library_checker/number_of_substrings.test.cpp
documentation_of: src/string/lcp_array.hpp
layout: document
redirect_from:
- /library/src/string/lcp_array.hpp
- /library/src/string/lcp_array.hpp.html
title: src/string/lcp_array.hpp
---
