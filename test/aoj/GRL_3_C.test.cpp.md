---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
  bundledCode: "#line 1 \"test/aoj/GRL_3_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/graph/scc.hpp\"\nusing namespace std;\n\
    \nstruct SCC {\n    int _n;\n    struct edge {\n        int to;\n    };\n    vector<pair<int,\
    \ edge>> edges;\n\n    template <class E>\n    struct csr {\n        vector<int>\
    \ start;\n        vector<E> elist;\n        csr(int n, const vector<pair<int,\
    \ E>>& edges)\n            : start(n + 1), elist(edges.size()) {\n           \
    \ for (auto e : edges) start[e.first + 1]++;\n            for (int i = 1; i <=\
    \ n; i++) start[i] += start[i - 1];\n            auto counter = start;\n     \
    \       for (auto e : edges) elist[counter[e.first]++] = e.second;\n        }\n\
    \    };\n\n    SCC(int n) : _n(n) {}\n    SCC() : _n(0) {}\n\n    int num_vertices()\
    \ { return _n; }\n\n    void add_edge(int from, int to) {\n        edges.push_back({from,\
    \ {to}});\n    }\n\n    // return pair of (# of scc, scc id)\n    pair<int, vector<int>>\
    \ scc_ids() {\n        auto g = csr<edge>(_n, edges);\n        int now_ord = 0,\
    \ group_num = 0;\n        vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n\
    \        visited.reserve(_n);\n        auto dfs = [&](auto self, int v) -> void\
    \ {\n            low[v] = ord[v] = now_ord++;\n            visited.push_back(v);\n\
    \            for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n           \
    \     auto to = g.elist[i].to;\n                if (ord[to] == -1) {\n       \
    \             self(self, to);\n                    low[v] = min(low[v], low[to]);\n\
    \                } else {\n                    low[v] = min(low[v], ord[to]);\n\
    \                }\n            }\n            if (low[v] == ord[v]) {\n     \
    \           while (true) {\n                    int u = visited.back();\n    \
    \                visited.pop_back();\n                    ord[u] = _n;\n     \
    \               ids[u] = group_num;\n                    if (u == v) break;\n\
    \                }\n                group_num++;\n            }\n        };\n\
    \        for (int i = 0; i < _n; i++)\n            if (ord[i] == -1) dfs(dfs,\
    \ i);\n        for (auto& x : ids) x = group_num - 1 - x;\n        return {group_num,\
    \ ids};\n    }\n\n    vector<vector<int>> scc() {\n        auto ids = scc_ids();\n\
    \        int group_num = ids.first;\n        vector<int> counts(group_num);\n\
    \        for (auto x : ids.second) counts[x]++;\n        vector<vector<int>> groups(ids.first);\n\
    \        for (int i = 0; i < group_num; i++) groups[i].reserve(counts[i]);\n \
    \       for (int i = 0; i < _n; i++) groups[ids.second[i]].push_back(i);\n   \
    \     return groups;\n    }\n};\n#line 4 \"test/aoj/GRL_3_C.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    SCC G(V);\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n\
    \        G.add_edge(s, t);\n    }\n\n    auto ids = G.scc_ids().second;\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << (int)(ids[u] == ids[v]) << '\\n';\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/graph/scc.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    SCC G(V);\n   \
    \ for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n \
    \       G.add_edge(s, t);\n    }\n\n    auto ids = G.scc_ids().second;\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << (int)(ids[u] == ids[v]) << '\\n';\n   \
    \ }\n}\n"
  dependsOn:
  - src/graph/scc.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2021-11-25 01:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_C.test.cpp
- /verify/test/aoj/GRL_3_C.test.cpp.html
title: test/aoj/GRL_3_C.test.cpp
---
