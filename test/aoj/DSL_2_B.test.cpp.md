---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/fenwick_tree.hpp
    title: src/datastructure/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/datastructure/fenwick_tree.hpp\"\nusing\
    \ namespace std;\n\ntemplate <class T> struct FenwickTree {\n    int n;\n    vector<T>\
    \ data;\n    FenwickTree() : n(0) {}\n    FenwickTree(int n) : n(n), data(n, 0)\
    \ {}\n\n    // a[i] += x\n    void add(int i, T x) {\n        for (int p = i +\
    \ 1; p <= n; p += p & -p) data[p - 1] += x;\n    }\n    // [0, r)\n    T sum(int\
    \ r) {\n        T s(0);\n        for (int p = r; p > 0; p -= p & -p) s += data[p\
    \ - 1];\n        return s;\n    }\n    // [l, r)\n    T sum(int l, int r) {\n\
    \        return sum(r) - sum(l);\n    }\n};\n#line 4 \"test/aoj/DSL_2_B.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    int n, q;\n    cin >> n >> q;\n    FenwickTree<long long> ft(n);\n    for\
    \ (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin >> com >> x >>\
    \ y;\n        if (com == 0) {\n            ft.add(x - 1, y);\n        } else {\n\
    \            cout << ft.sum(x - 1, y) << endl;\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/datastructure/fenwick_tree.hpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    int n, q;\n    cin >> n >> q;\n    FenwickTree<long long> ft(n);\n    for\
    \ (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin >> com >> x >>\
    \ y;\n        if (com == 0) {\n            ft.add(x - 1, y);\n        } else {\n\
    \            cout << ft.sum(x - 1, y) << endl;\n        }\n    }\n    return 0;\n\
    }\n"
  dependsOn:
  - src/datastructure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 18:54:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---
