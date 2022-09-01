---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/rollback_unionfind.yosupo.test.cpp
    title: test/library_checker/rollback_unionfind.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/rollback_unionfind.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct RollbackUnionFind {\n    vector<int> data;\n  \
    \  stack<pair<int, int>> history;\n    int inner_snap = 0;\n    RollbackUnionFind(int\
    \ n) { data.resize(n, -1); }\n    int find(int x) { return data[x] < 0 ? x : find(data[x]);\
    \ }\n    bool unite(int x, int y) {\n        x = find(x), y = find(y);\n     \
    \   history.push({x, data[x]});\n        history.push({y, data[y]});\n       \
    \ if (x == y) return false;\n        if (-data[x] < -data[y]) swap(x, y);\n  \
    \      data[x] += data[y];\n        data[y] = x;\n        return true;\n    }\n\
    \    int same(int x, int y) { return find(x) == find(y); }\n    int size(int x)\
    \ { return (-data[find(x)]); }\n    void undo() {\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n    }\n    int time() { return\
    \ int(history.size() >> 1); }\n    void snapshot() { inner_snap = time(); }\n\
    \    void rollback(int t = -1) {\n        if (t == -1) t = inner_snap;\n     \
    \   while (t < time()) undo();\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct RollbackUnionFind\
    \ {\n    vector<int> data;\n    stack<pair<int, int>> history;\n    int inner_snap\
    \ = 0;\n    RollbackUnionFind(int n) { data.resize(n, -1); }\n    int find(int\
    \ x) { return data[x] < 0 ? x : find(data[x]); }\n    bool unite(int x, int y)\
    \ {\n        x = find(x), y = find(y);\n        history.push({x, data[x]});\n\
    \        history.push({y, data[y]});\n        if (x == y) return false;\n    \
    \    if (-data[x] < -data[y]) swap(x, y);\n        data[x] += data[y];\n     \
    \   data[y] = x;\n        return true;\n    }\n    int same(int x, int y) { return\
    \ find(x) == find(y); }\n    int size(int x) { return (-data[find(x)]); }\n  \
    \  void undo() {\n        data[history.top().first] = history.top().second;\n\
    \        history.pop();\n        data[history.top().first] = history.top().second;\n\
    \        history.pop();\n    }\n    int time() { return int(history.size() >>\
    \ 1); }\n    void snapshot() { inner_snap = time(); }\n    void rollback(int t\
    \ = -1) {\n        if (t == -1) t = inner_snap;\n        while (t < time()) undo();\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/rollback_unionfind.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/rollback_unionfind.yosupo.test.cpp
documentation_of: src/datastructure/rollback_unionfind.hpp
layout: document
redirect_from:
- /library/src/datastructure/rollback_unionfind.hpp
- /library/src/datastructure/rollback_unionfind.hpp.html
title: src/datastructure/rollback_unionfind.hpp
---
