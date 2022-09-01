---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/suffix_array.hpp
    title: src/string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/string/suffix_array.hpp\"\nusing namespace\
    \ std;\n\nvector<int> suffix_array(const string& str) {\n    int n = str.size();\n\
    \    vector<int> sa(n + 1), rank(n + 1, -1);  // sa[i] = \u8F9E\u66F8\u9806\u3067\
    i\u756A\u76EE\u3067\u3042\u308Bsuffix\u306E\u958B\u59CB\u4F4D\u7F6E\n    iota(sa.begin(),\
    \ sa.end(), 0);\n    for (int i = 0; i < n; i++) rank[i] = str[i];\n    int k;\n\
    \    auto comp = [&](const int& i, const int& j) {\n        if (rank[i] != rank[j])\
    \ {\n            return rank[i] < rank[j];\n        } else {\n            int\
    \ ri = i + k <= n ? rank[i + k] : -1;\n            int rj = j + k <= n ? rank[j\
    \ + k] : -1;\n            return ri < rj;\n        }\n    };\n    for (k = 1;\
    \ k <= n; k <<= 1) {\n        sort(sa.begin(), sa.end(), comp);\n        vector<int>\
    \ tmp(n + 1, 0);\n        for (int i = 0; i < n; i++) {\n            tmp[sa[i\
    \ + 1]] = tmp[sa[i]];\n            if (comp(sa[i], sa[i + 1])) tmp[sa[i + 1]]++;\n\
    \        }\n        rank = tmp;\n    }\n    return sa;\n}\n\n// \u6587\u5B57\u5217\
    s\u306B\u6587\u5B57\u5217t\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\nbool contain(const string& s, const string& t, vector<int>&\
    \ sa) {\n    int l = 0, r = int(s.size());\n    while (r - l > 1) {\n        int\
    \ mid = (l + r) / 2;\n        if (s.substr(sa[mid], t.size()) < t) {\n       \
    \     l = mid;\n        } else {\n            r = mid;\n        }\n    }\n   \
    \ return s.substr(sa[r], t.size()) == t;\n}\n#line 4 \"test/aoj/ALDS1_14_D.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    string t;\n    int q;\n    cin >> t >> q;\n    vector<int> sa = suffix_array(t);\n\
    \    for (int i = 0; i < q; i++) {\n        string p;\n        cin >> p;\n   \
    \     cout << contain(t, p, sa) << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/string/suffix_array.hpp\"\nusing\
    \ namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    string t;\n    int q;\n    cin >> t >> q;\n    vector<int> sa = suffix_array(t);\n\
    \    for (int i = 0; i < q; i++) {\n        string p;\n        cin >> p;\n   \
    \     cout << contain(t, p, sa) << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - src/string/suffix_array.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_D.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_D.test.cpp
- /verify/test/aoj/ALDS1_14_D.test.cpp.html
title: test/aoj/ALDS1_14_D.test.cpp
---
