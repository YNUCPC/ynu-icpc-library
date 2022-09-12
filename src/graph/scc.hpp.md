---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/graph/two_sat.hpp
    title: src/graph/two_sat.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':x:'
    path: test/library_checker/two_sat.yosupo.test.cpp
    title: test/library_checker/two_sat.yosupo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/scc.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct SCC {\n    int _n;\n    struct edge {\n        int to;\n    };\n\
    \    vector<pair<int, edge>> edges;\n\n    template <class E>\n    struct csr\
    \ {\n        vector<int> start;\n        vector<E> elist;\n        csr(int n,\
    \ const vector<pair<int, E>>& edges)\n            : start(n + 1), elist(edges.size())\
    \ {\n            for (auto e : edges) start[e.first + 1]++;\n            for (int\
    \ i = 1; i <= n; i++) start[i] += start[i - 1];\n            auto counter = start;\n\
    \            for (auto e : edges) elist[counter[e.first]++] = e.second;\n    \
    \    }\n    };\n\n    SCC(int n) : _n(n) {}\n    SCC() : _n(0) {}\n\n    int num_vertices()\
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
    \     return groups;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct SCC\
    \ {\n    int _n;\n    struct edge {\n        int to;\n    };\n    vector<pair<int,\
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
    \     return groups;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/scc.hpp
  requiredBy:
  - src/graph/two_sat.hpp
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/two_sat.yosupo.test.cpp
  - test/aoj/GRL_3_C.test.cpp
documentation_of: src/graph/scc.hpp
layout: document
redirect_from:
- /library/src/graph/scc.hpp
- /library/src/graph/scc.hpp.html
title: src/graph/scc.hpp
---
