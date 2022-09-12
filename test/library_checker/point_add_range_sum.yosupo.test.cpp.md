---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/datastructure/fenwick_tree.hpp
    title: src/datastructure/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/point_add_range_sum.yosupo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/datastructure/fenwick_tree.hpp\"\nusing namespace\
    \ std;\n\ntemplate <class T> struct FenwickTree {\n    int n;\n    vector<T> data;\n\
    \    FenwickTree() : n(0) {}\n    FenwickTree(int n) : n(n), data(n, 0) {}\n\n\
    \    // a[i] += x\n    void add(int i, T x) {\n        for (int p = i + 1; p <=\
    \ n; p += p & -p) data[p - 1] += x;\n    }\n    // [0, r)\n    T sum(int r) {\n\
    \        T s(0);\n        for (int p = r; p > 0; p -= p & -p) s += data[p - 1];\n\
    \        return s;\n    }\n    // [l, r)\n    T sum(int l, int r) {\n        return\
    \ sum(r) - sum(l);\n    }\n};\n#line 4 \"test/library_checker/point_add_range_sum.yosupo.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTree<long long> ft(N);\n   \
    \ for (int i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n        ft.add(i,\
    \ a);\n    }\n\n    for (int i = 0; i < Q; i++) {\n        int t;\n        cin\
    \ >> t;\n        switch (t) {\n            case 0: {\n                int p, x;\n\
    \                cin >> p >> x;\n                ft.add(p, x);\n            }\
    \ break;\n\n            case 1: {\n                int l, r;\n               \
    \ cin >> l >> r;\n                cout << ft.sum(l, r) << endl;\n            }\
    \ break;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\n#include \"../../src/datastructure/fenwick_tree.hpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTree<long long> ft(N);\n   \
    \ for (int i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n        ft.add(i,\
    \ a);\n    }\n\n    for (int i = 0; i < Q; i++) {\n        int t;\n        cin\
    \ >> t;\n        switch (t) {\n            case 0: {\n                int p, x;\n\
    \                cin >> p >> x;\n                ft.add(p, x);\n            }\
    \ break;\n\n            case 1: {\n                int l, r;\n               \
    \ cin >> l >> r;\n                cout << ft.sum(l, r) << endl;\n            }\
    \ break;\n        }\n    }\n}\n"
  dependsOn:
  - src/datastructure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/library_checker/point_add_range_sum.yosupo.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/point_add_range_sum.yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/point_add_range_sum.yosupo.test.cpp
- /verify/test/library_checker/point_add_range_sum.yosupo.test.cpp.html
title: test/library_checker/point_add_range_sum.yosupo.test.cpp
---
