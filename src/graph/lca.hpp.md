---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/lca.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct LCA {\n    vector<vector<int>> parent;\n    vector<int> depth;\n\
    \    LCA() {}\n    LCA(const vector<vector<int>>& G, int r = 0) { init(G, r);\
    \ }\n\n    void init(const vector<vector<int>>& G, int r = 0) {\n        int V\
    \ = (int)G.size();\n        int h = 1;\n        while ((1 << h) < V) ++h;\n  \
    \      parent.assign(h, vector<int>(V, -1));\n        depth.assign(V, -1);\n \
    \       dfs(G, r, -1, 0);\n        for (int i = 0; i + 1 < (int)parent.size();\
    \ ++i) {\n            for (int v = 0; v < V; ++v) {\n                if (parent[i][v]\
    \ != -1) {\n                    parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \                }\n            }\n        }\n    }\n\n    void dfs(const vector<vector<int>>&\
    \ G, int v, int p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n\
    \        for (auto e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n \
    \   }\n\n    int query(int u, int v) {\n        if (depth[u] > depth[v]) swap(u,\
    \ v);\n        for (int i = 0; i < (int)parent.size(); ++i) {\n            if\
    \ ((depth[v] - depth[u]) & (1 << i)) v = parent[i][v];\n        }\n        if\
    \ (u == v) return u;\n        for (int i = (int)parent.size() - 1; i >= 0; --i)\
    \ {\n            if (parent[i][u] != parent[i][v]) {\n                u = parent[i][u];\n\
    \                v = parent[i][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    int dist(int u, int v) {\n        return depth[u] + depth[v] - 2\
    \ * depth[query(u, v)];\n    }\n\n    bool is_on_path(int u, int v, int x) {\n\
    \        return dist(u, x) + dist(x, v) == dist(u, v);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct LCA\
    \ {\n    vector<vector<int>> parent;\n    vector<int> depth;\n    LCA() {}\n \
    \   LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }\n\n    void init(const\
    \ vector<vector<int>>& G, int r = 0) {\n        int V = (int)G.size();\n     \
    \   int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V,\
    \ -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for\
    \ (int i = 0; i + 1 < (int)parent.size(); ++i) {\n            for (int v = 0;\
    \ v < V; ++v) {\n                if (parent[i][v] != -1) {\n                 \
    \   parent[i + 1][v] = parent[i][parent[i][v]];\n                }\n         \
    \   }\n        }\n    }\n\n    void dfs(const vector<vector<int>>& G, int v, int\
    \ p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n        for (auto\
    \ e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n    }\n\n    int query(int\
    \ u, int v) {\n        if (depth[u] > depth[v]) swap(u, v);\n        for (int\
    \ i = 0; i < (int)parent.size(); ++i) {\n            if ((depth[v] - depth[u])\
    \ & (1 << i)) v = parent[i][v];\n        }\n        if (u == v) return u;\n  \
    \      for (int i = (int)parent.size() - 1; i >= 0; --i) {\n            if (parent[i][u]\
    \ != parent[i][v]) {\n                u = parent[i][u];\n                v = parent[i][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int dist(int\
    \ u, int v) {\n        return depth[u] + depth[v] - 2 * depth[query(u, v)];\n\
    \    }\n\n    bool is_on_path(int u, int v, int x) {\n        return dist(u, x)\
    \ + dist(x, v) == dist(u, v);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/lca.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_5_C.test.cpp
documentation_of: src/graph/lca.hpp
layout: document
redirect_from:
- /library/src/graph/lca.hpp
- /library/src/graph/lca.hpp.html
title: src/graph/lca.hpp
---
