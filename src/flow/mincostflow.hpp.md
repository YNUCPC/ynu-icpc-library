---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/flow/mincostflow.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// \u6700\u5C0F\u8CBB\u7528\u6D41 O(FElogV)\nstruct MinCostFlow\
    \ {\n    int V;\n    vector<vector<vector<long long>>> g;  // g[from] = {{to,\
    \ \u5BB9\u91CF, \u30B3\u30B9\u30C8, \u9006\u8FBA\u306Eindex} ... }\n    vector<long\
    \ long> h, dis;             // \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB, \u6700\u77ED\
    \u8DDD\u96E2\n    vector<int> prevv, preve;             // \u76F4\u524D\u306E\u9802\
    \u70B9, \u8FBA\n\n    MinCostFlow(int v) : V(v), g(v), dis(v), prevv(v), preve(v)\
    \ {\n    }\n\n    void add_edge(int u, int v, long long c, long long d) {\n  \
    \      g[u].push_back({v, c, d, (int)g[v].size()});\n        g[v].push_back({u,\
    \ 0, -d, (int)g[u].size() - 1});\n    }\n\n    long long min_cost_flow(int s,\
    \ int t, long long f) {\n        long long res = 0;\n        h.assign(V, 0);\n\
    \        using Q = pair<long long, int>;\n        while (f > 0) {\n          \
    \  priority_queue<Q, vector<Q>, greater<Q>> que;\n            dis.assign(V, LLONG_MAX);\n\
    \            dis[s] = 0;\n            que.push({0, s});\n            while (que.size())\
    \ {\n                Q q = que.top();\n                int v = q.second;\n   \
    \             que.pop();\n                if (dis[v] < q.first) continue;\n  \
    \              for (int i = 0; i < g[v].size(); i++) {\n                    auto\
    \ edge = g[v][i];\n                    int to = edge[0];\n                   \
    \ long long cap = edge[1], cost = edge[2];\n                    if (cap > 0 and\
    \ dis[to] > dis[v] + cost + h[v] - h[to]) {\n                        dis[to] =\
    \ dis[v] + cost + h[v] - h[to];\n                        prevv[to] = v;\n    \
    \                    preve[to] = i;\n                        que.push({dis[to],\
    \ to});\n                    }\n                }\n            }\n           \
    \ if (dis[t] == LLONG_MAX) return -1;\n            for (int i = 0; i < V; i++)\
    \ h[i] += dis[i];\n            long long d = f;\n            for (int i = t; i\
    \ != s; i = prevv[i]) d = min(d, g[prevv[i]][preve[i]][1]);\n            f -=\
    \ d;\n            res += d * h[t];\n            for (int i = t; i != s; i = prevv[i])\
    \ {\n                auto& edge = g[prevv[i]][preve[i]];\n                edge[1]\
    \ -= d;\n                g[i][edge[3]][1] += d;\n            }\n        }\n  \
    \      return res;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// \u6700\
    \u5C0F\u8CBB\u7528\u6D41 O(FElogV)\nstruct MinCostFlow {\n    int V;\n    vector<vector<vector<long\
    \ long>>> g;  // g[from] = {{to, \u5BB9\u91CF, \u30B3\u30B9\u30C8, \u9006\u8FBA\
    \u306Eindex} ... }\n    vector<long long> h, dis;             // \u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB, \u6700\u77ED\u8DDD\u96E2\n    vector<int> prevv, preve;  \
    \           // \u76F4\u524D\u306E\u9802\u70B9, \u8FBA\n\n    MinCostFlow(int v)\
    \ : V(v), g(v), dis(v), prevv(v), preve(v) {\n    }\n\n    void add_edge(int u,\
    \ int v, long long c, long long d) {\n        g[u].push_back({v, c, d, (int)g[v].size()});\n\
    \        g[v].push_back({u, 0, -d, (int)g[u].size() - 1});\n    }\n\n    long\
    \ long min_cost_flow(int s, int t, long long f) {\n        long long res = 0;\n\
    \        h.assign(V, 0);\n        using Q = pair<long long, int>;\n        while\
    \ (f > 0) {\n            priority_queue<Q, vector<Q>, greater<Q>> que;\n     \
    \       dis.assign(V, LLONG_MAX);\n            dis[s] = 0;\n            que.push({0,\
    \ s});\n            while (que.size()) {\n                Q q = que.top();\n \
    \               int v = q.second;\n                que.pop();\n              \
    \  if (dis[v] < q.first) continue;\n                for (int i = 0; i < g[v].size();\
    \ i++) {\n                    auto edge = g[v][i];\n                    int to\
    \ = edge[0];\n                    long long cap = edge[1], cost = edge[2];\n \
    \                   if (cap > 0 and dis[to] > dis[v] + cost + h[v] - h[to]) {\n\
    \                        dis[to] = dis[v] + cost + h[v] - h[to];\n           \
    \             prevv[to] = v;\n                        preve[to] = i;\n       \
    \                 que.push({dis[to], to});\n                    }\n          \
    \      }\n            }\n            if (dis[t] == LLONG_MAX) return -1;\n   \
    \         for (int i = 0; i < V; i++) h[i] += dis[i];\n            long long d\
    \ = f;\n            for (int i = t; i != s; i = prevv[i]) d = min(d, g[prevv[i]][preve[i]][1]);\n\
    \            f -= d;\n            res += d * h[t];\n            for (int i = t;\
    \ i != s; i = prevv[i]) {\n                auto& edge = g[prevv[i]][preve[i]];\n\
    \                edge[1] -= d;\n                g[i][edge[3]][1] += d;\n     \
    \       }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/mincostflow.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
documentation_of: src/flow/mincostflow.hpp
layout: document
redirect_from:
- /library/src/flow/mincostflow.hpp
- /library/src/flow/mincostflow.hpp.html
title: src/flow/mincostflow.hpp
---
