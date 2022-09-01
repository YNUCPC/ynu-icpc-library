---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/point_add_range_sum.yosupo.test.cpp
    title: test/library_checker/point_add_range_sum.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/fenwick_tree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T> struct FenwickTree {\n    int n;\n\
    \    vector<T> data;\n    FenwickTree() : n(0) {}\n    FenwickTree(int n) : n(n),\
    \ data(n, 0) {}\n\n    // a[i] += x\n    void add(int i, T x) {\n        for (int\
    \ p = i + 1; p <= n; p += p & -p) data[p - 1] += x;\n    }\n    // [0, r)\n  \
    \  T sum(int r) {\n        T s(0);\n        for (int p = r; p > 0; p -= p & -p)\
    \ s += data[p - 1];\n        return s;\n    }\n    // [l, r)\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T> struct FenwickTree {\n    int n;\n    vector<T> data;\n    FenwickTree()\
    \ : n(0) {}\n    FenwickTree(int n) : n(n), data(n, 0) {}\n\n    // a[i] += x\n\
    \    void add(int i, T x) {\n        for (int p = i + 1; p <= n; p += p & -p)\
    \ data[p - 1] += x;\n    }\n    // [0, r)\n    T sum(int r) {\n        T s(0);\n\
    \        for (int p = r; p > 0; p -= p & -p) s += data[p - 1];\n        return\
    \ s;\n    }\n    // [l, r)\n    T sum(int l, int r) {\n        return sum(r) -\
    \ sum(l);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/point_add_range_sum.yosupo.test.cpp
  - test/aoj/DSL_2_B.test.cpp
documentation_of: src/datastructure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/src/datastructure/fenwick_tree.hpp
- /library/src/datastructure/fenwick_tree.hpp.html
title: src/datastructure/fenwick_tree.hpp
---
