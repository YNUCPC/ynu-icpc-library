---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/lca.hpp
    title: src/graph/lca.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/graph/lca.hpp\"\nusing namespace std;\n\
    \nstruct LCA {\n    vector<vector<int>> parent;\n    vector<int> depth;\n    LCA()\
    \ {}\n    LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }\n\n   \
    \ void init(const vector<vector<int>>& G, int r = 0) {\n        int V = (int)G.size();\n\
    \        int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h,\
    \ vector<int>(V, -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n\
    \        for (int i = 0; i + 1 < (int)parent.size(); ++i) {\n            for (int\
    \ v = 0; v < V; ++v) {\n                if (parent[i][v] != -1) {\n          \
    \          parent[i + 1][v] = parent[i][parent[i][v]];\n                }\n  \
    \          }\n        }\n    }\n\n    void dfs(const vector<vector<int>>& G, int\
    \ v, int p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n     \
    \   for (auto e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n    }\n\
    \n    int query(int u, int v) {\n        if (depth[u] > depth[v]) swap(u, v);\n\
    \        for (int i = 0; i < (int)parent.size(); ++i) {\n            if ((depth[v]\
    \ - depth[u]) & (1 << i)) v = parent[i][v];\n        }\n        if (u == v) return\
    \ u;\n        for (int i = (int)parent.size() - 1; i >= 0; --i) {\n          \
    \  if (parent[i][u] != parent[i][v]) {\n                u = parent[i][u];\n  \
    \              v = parent[i][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    int dist(int u, int v) {\n        return depth[u] + depth[v] - 2\
    \ * depth[query(u, v)];\n    }\n\n    bool is_on_path(int u, int v, int x) {\n\
    \        return dist(u, x) + dist(x, v) == dist(u, v);\n    }\n};\n#line 4 \"\
    test/aoj/GRL_5_C.test.cpp\"\nusing namespace std;\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    vector<vector<int>> G(n);\n    for (int i = 0; i < n; i++)\
    \ {\n        int k;\n        cin >> k;\n        for (int j = 0; j < k; j++) {\n\
    \            int c;\n            cin >> c;\n            G[i].push_back(c);\n \
    \           G[c].push_back(i);\n        }\n    }\n\n    LCA lca(G, 0);\n\n   \
    \ int q;\n    cin >> q;\n    for (int i = 0; i < q; i++) {\n        int u, v;\n\
    \        cin >> u >> v;\n        cout << lca.query(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/graph/lca.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<int>> G(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; j++) {\n            int c;\n            cin >> c;\n\
    \            G[i].push_back(c);\n            G[c].push_back(i);\n        }\n \
    \   }\n\n    LCA lca(G, 0);\n\n    int q;\n    cin >> q;\n    for (int i = 0;\
    \ i < q; i++) {\n        int u, v;\n        cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << '\\n';\n    }\n}\n"
  dependsOn:
  - src/graph/lca.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
