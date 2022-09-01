---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/flow/dinic.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Dinic\u6CD5 O(V^2E)\nstruct Dinic {\n    int V;                 \
    \                   // \u9802\u70B9\u6570\n    vector<vector<vector<long long>>>\
    \ graph;  // \u30B0\u30E9\u30D5\n    vector<int> dis;                        \
    \  // \u59CB\u70B9\u304B\u3089\u306E\u8DDD\u96E2\n    vector<int> next;      \
    \                   // \u6B21\u306B\u51E6\u7406\u3059\u308B\u9802\u70B9\u306E\u30E1\
    \u30E2\n    Dinic(int v) : V(v) { graph.resize(V); }\n    void add_edge(int from,\
    \ int to, long long capacity) {\n        graph[from].push_back({to, capacity,\
    \ (int)graph[to].size()});\n        graph[to].push_back({from, 0, (int)graph[from].size()\
    \ - 1});\n    }\n    void bfs(int s) {\n        dis.assign(V, -1);\n        dis[s]\
    \ = 0;\n        deque<int> pos = {s};\n        while (pos.size()) {\n        \
    \    int now = pos[0];\n            pos.pop_front();\n            for (auto& to\
    \ : graph[now]) {\n                if (dis[to[0]] < 0 and to[1] > 0) {\n     \
    \               dis[to[0]] = dis[now] + 1;\n                    pos.emplace_back(to[0]);\n\
    \                }\n            }\n        }\n    }\n    long long dfs(int v,\
    \ int t, long long f) {\n        if (v == t) return f;\n        for (int& i =\
    \ next[v]; i < graph[v].size(); i++) {\n            int to = graph[v][i][0];\n\
    \            long long& cap = graph[v][i][1];\n            int rev = graph[v][i][2];\n\
    \            if (cap > 0 and dis[v] < dis[to]) {\n                long long d\
    \ = dfs(to, t, min(f, cap));\n                if (d > 0) {\n                 \
    \   cap -= d;\n                    graph[to][rev][1] += d;\n                 \
    \   return d;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n    long long max_flow(int s, int t) {\n        long long flow = 0;\n\
    \        while (1) {\n            bfs(s);\n            if (dis[t] < 0) return\
    \ flow;\n            next.assign(V, 0);\n            long long f;\n          \
    \  while ((f = dfs(s, t, LLONG_MAX)) > 0) flow += f;\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Dinic\u6CD5\
    \ O(V^2E)\nstruct Dinic {\n    int V;                                    // \u9802\
    \u70B9\u6570\n    vector<vector<vector<long long>>> graph;  // \u30B0\u30E9\u30D5\
    \n    vector<int> dis;                          // \u59CB\u70B9\u304B\u3089\u306E\
    \u8DDD\u96E2\n    vector<int> next;                         // \u6B21\u306B\u51E6\
    \u7406\u3059\u308B\u9802\u70B9\u306E\u30E1\u30E2\n    Dinic(int v) : V(v) { graph.resize(V);\
    \ }\n    void add_edge(int from, int to, long long capacity) {\n        graph[from].push_back({to,\
    \ capacity, (int)graph[to].size()});\n        graph[to].push_back({from, 0, (int)graph[from].size()\
    \ - 1});\n    }\n    void bfs(int s) {\n        dis.assign(V, -1);\n        dis[s]\
    \ = 0;\n        deque<int> pos = {s};\n        while (pos.size()) {\n        \
    \    int now = pos[0];\n            pos.pop_front();\n            for (auto& to\
    \ : graph[now]) {\n                if (dis[to[0]] < 0 and to[1] > 0) {\n     \
    \               dis[to[0]] = dis[now] + 1;\n                    pos.emplace_back(to[0]);\n\
    \                }\n            }\n        }\n    }\n    long long dfs(int v,\
    \ int t, long long f) {\n        if (v == t) return f;\n        for (int& i =\
    \ next[v]; i < graph[v].size(); i++) {\n            int to = graph[v][i][0];\n\
    \            long long& cap = graph[v][i][1];\n            int rev = graph[v][i][2];\n\
    \            if (cap > 0 and dis[v] < dis[to]) {\n                long long d\
    \ = dfs(to, t, min(f, cap));\n                if (d > 0) {\n                 \
    \   cap -= d;\n                    graph[to][rev][1] += d;\n                 \
    \   return d;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n    long long max_flow(int s, int t) {\n        long long flow = 0;\n\
    \        while (1) {\n            bfs(s);\n            if (dis[t] < 0) return\
    \ flow;\n            next.assign(V, 0);\n            long long f;\n          \
    \  while ((f = dfs(s, t, LLONG_MAX)) > 0) flow += f;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/dinic.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.test.cpp
documentation_of: src/flow/dinic.hpp
layout: document
redirect_from:
- /library/src/flow/dinic.hpp
- /library/src/flow/dinic.hpp.html
title: src/flow/dinic.hpp
---
