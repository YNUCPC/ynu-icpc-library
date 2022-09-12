---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/flow/dinic.hpp
    title: src/flow/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/flow/dinic.hpp\"\nusing namespace std;\n\
    \n// Dinic\u6CD5 O(V^2E)\nstruct Dinic {\n    int V;                         \
    \           // \u9802\u70B9\u6570\n    vector<vector<vector<long long>>> graph;\
    \  // \u30B0\u30E9\u30D5\n    vector<int> dis;                          // \u59CB\
    \u70B9\u304B\u3089\u306E\u8DDD\u96E2\n    vector<int> next;                  \
    \       // \u6B21\u306B\u51E6\u7406\u3059\u308B\u9802\u70B9\u306E\u30E1\u30E2\n\
    \    Dinic(int v) : V(v) { graph.resize(V); }\n    void add_edge(int from, int\
    \ to, long long capacity) {\n        graph[from].push_back({to, capacity, (int)graph[to].size()});\n\
    \        graph[to].push_back({from, 0, (int)graph[from].size() - 1});\n    }\n\
    \    void bfs(int s) {\n        dis.assign(V, -1);\n        dis[s] = 0;\n    \
    \    deque<int> pos = {s};\n        while (pos.size()) {\n            int now\
    \ = pos[0];\n            pos.pop_front();\n            for (auto& to : graph[now])\
    \ {\n                if (dis[to[0]] < 0 and to[1] > 0) {\n                   \
    \ dis[to[0]] = dis[now] + 1;\n                    pos.emplace_back(to[0]);\n \
    \               }\n            }\n        }\n    }\n    long long dfs(int v, int\
    \ t, long long f) {\n        if (v == t) return f;\n        for (int& i = next[v];\
    \ i < graph[v].size(); i++) {\n            int to = graph[v][i][0];\n        \
    \    long long& cap = graph[v][i][1];\n            int rev = graph[v][i][2];\n\
    \            if (cap > 0 and dis[v] < dis[to]) {\n                long long d\
    \ = dfs(to, t, min(f, cap));\n                if (d > 0) {\n                 \
    \   cap -= d;\n                    graph[to][rev][1] += d;\n                 \
    \   return d;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n    long long max_flow(int s, int t) {\n        long long flow = 0;\n\
    \        while (1) {\n            bfs(s);\n            if (dis[t] < 0) return\
    \ flow;\n            next.assign(V, 0);\n            long long f;\n          \
    \  while ((f = dfs(s, t, LLONG_MAX)) > 0) flow += f;\n        }\n    }\n};\n#line\
    \ 4 \"test/aoj/GRL_6_A.test.cpp\"\nusing namespace std;\n\nint main() {\n    int\
    \ V, E, u, v, c;\n    cin >> V >> E;\n    Dinic flow(V);\n    for (int i = 0;\
    \ i < E; i++) {\n        cin >> u >> v >> c;\n        flow.add_edge(u, v, c);\n\
    \    }\n    cout << flow.max_flow(0, V - 1) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/flow/dinic.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int V, E, u, v, c;\n    cin >> V >> E;\n    Dinic\
    \ flow(V);\n    for (int i = 0; i < E; i++) {\n        cin >> u >> v >> c;\n \
    \       flow.add_edge(u, v, c);\n    }\n    cout << flow.max_flow(0, V - 1) <<\
    \ endl;\n}\n"
  dependsOn:
  - src/flow/dinic.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
