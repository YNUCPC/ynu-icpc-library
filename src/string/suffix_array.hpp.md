---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3112.test.cpp
    title: test/aoj/3112.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_D.test.cpp
    title: test/aoj/ALDS1_14_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_of_substrings.test.cpp
    title: test/library_checker/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/suffixarray.yosupo.test.cpp
    title: test/library_checker/suffixarray.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/suffix_array.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<int> suffix_array(const string& str) {\n    int\
    \ n = str.size();\n    vector<int> sa(n + 1), rank(n + 1, -1);  // sa[i] = \u8F9E\
    \u66F8\u9806\u3067i\u756A\u76EE\u3067\u3042\u308Bsuffix\u306E\u958B\u59CB\u4F4D\
    \u7F6E\n    iota(sa.begin(), sa.end(), 0);\n    for (int i = 0; i < n; i++) rank[i]\
    \ = str[i];\n    int k;\n    auto comp = [&](const int& i, const int& j) {\n \
    \       if (rank[i] != rank[j]) {\n            return rank[i] < rank[j];\n   \
    \     } else {\n            int ri = i + k <= n ? rank[i + k] : -1;\n        \
    \    int rj = j + k <= n ? rank[j + k] : -1;\n            return ri < rj;\n  \
    \      }\n    };\n    for (k = 1; k <= n; k <<= 1) {\n        sort(sa.begin(),\
    \ sa.end(), comp);\n        vector<int> tmp(n + 1, 0);\n        for (int i = 0;\
    \ i < n; i++) {\n            tmp[sa[i + 1]] = tmp[sa[i]];\n            if (comp(sa[i],\
    \ sa[i + 1])) tmp[sa[i + 1]]++;\n        }\n        rank = tmp;\n    }\n    return\
    \ sa;\n}\n\n// \u6587\u5B57\u5217s\u306B\u6587\u5B57\u5217t\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\nbool contain(const string& s,\
    \ const string& t, vector<int>& sa) {\n    int l = 0, r = int(s.size());\n   \
    \ while (r - l > 1) {\n        int mid = (l + r) / 2;\n        if (s.substr(sa[mid],\
    \ t.size()) < t) {\n            l = mid;\n        } else {\n            r = mid;\n\
    \        }\n    }\n    return s.substr(sa[r], t.size()) == t;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int>\
    \ suffix_array(const string& str) {\n    int n = str.size();\n    vector<int>\
    \ sa(n + 1), rank(n + 1, -1);  // sa[i] = \u8F9E\u66F8\u9806\u3067i\u756A\u76EE\
    \u3067\u3042\u308Bsuffix\u306E\u958B\u59CB\u4F4D\u7F6E\n    iota(sa.begin(), sa.end(),\
    \ 0);\n    for (int i = 0; i < n; i++) rank[i] = str[i];\n    int k;\n    auto\
    \ comp = [&](const int& i, const int& j) {\n        if (rank[i] != rank[j]) {\n\
    \            return rank[i] < rank[j];\n        } else {\n            int ri =\
    \ i + k <= n ? rank[i + k] : -1;\n            int rj = j + k <= n ? rank[j + k]\
    \ : -1;\n            return ri < rj;\n        }\n    };\n    for (k = 1; k <=\
    \ n; k <<= 1) {\n        sort(sa.begin(), sa.end(), comp);\n        vector<int>\
    \ tmp(n + 1, 0);\n        for (int i = 0; i < n; i++) {\n            tmp[sa[i\
    \ + 1]] = tmp[sa[i]];\n            if (comp(sa[i], sa[i + 1])) tmp[sa[i + 1]]++;\n\
    \        }\n        rank = tmp;\n    }\n    return sa;\n}\n\n// \u6587\u5B57\u5217\
    s\u306B\u6587\u5B57\u5217t\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\nbool contain(const string& s, const string& t, vector<int>&\
    \ sa) {\n    int l = 0, r = int(s.size());\n    while (r - l > 1) {\n        int\
    \ mid = (l + r) / 2;\n        if (s.substr(sa[mid], t.size()) < t) {\n       \
    \     l = mid;\n        } else {\n            r = mid;\n        }\n    }\n   \
    \ return s.substr(sa[r], t.size()) == t;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/suffix_array.hpp
  requiredBy: []
  timestamp: '2022-09-01 20:01:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3112.test.cpp
  - test/aoj/ALDS1_14_D.test.cpp
  - test/library_checker/number_of_substrings.test.cpp
  - test/library_checker/suffixarray.yosupo.test.cpp
documentation_of: src/string/suffix_array.hpp
layout: document
redirect_from:
- /library/src/string/suffix_array.hpp
- /library/src/string/suffix_array.hpp.html
title: src/string/suffix_array.hpp
---
