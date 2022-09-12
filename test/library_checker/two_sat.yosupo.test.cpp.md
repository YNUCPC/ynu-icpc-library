---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  - icon: ':x:'
    path: src/graph/two_sat.hpp
    title: src/graph/two_sat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/library_checker/two_sat.yosupo.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/graph/scc.hpp\"\nusing namespace std;\n\nstruct SCC {\n    int _n;\n\
    \    struct edge {\n        int to;\n    };\n    vector<pair<int, edge>> edges;\n\
    \n    template <class E>\n    struct csr {\n        vector<int> start;\n     \
    \   vector<E> elist;\n        csr(int n, const vector<pair<int, E>>& edges)\n\
    \            : start(n + 1), elist(edges.size()) {\n            for (auto e :\
    \ edges) start[e.first + 1]++;\n            for (int i = 1; i <= n; i++) start[i]\
    \ += start[i - 1];\n            auto counter = start;\n            for (auto e\
    \ : edges) elist[counter[e.first]++] = e.second;\n        }\n    };\n\n    SCC(int\
    \ n) : _n(n) {}\n    SCC() : _n(0) {}\n\n    int num_vertices() { return _n; }\n\
    \n    void add_edge(int from, int to) {\n        edges.push_back({from, {to}});\n\
    \    }\n\n    // return pair of (# of scc, scc id)\n    pair<int, vector<int>>\
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
    \     return groups;\n    }\n};\n#line 4 \"src/graph/two_sat.hpp\"\nusing namespace\
    \ std;\n\nstruct TwoSAT {\n  public:\n    TwoSAT() : _n(0), scc(0) {}\n    TwoSAT(int\
    \ n) : _n(n), _answer(n), scc(2 * n) {}\n\n    void add_clause(int i, bool f,\
    \ int j, bool g) {\n        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 :\
    \ 0));\n        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n\
    \n    bool satisfiable() {\n        auto id = scc.scc_ids().second;\n        for\
    \ (int i = 0; i < _n; i++) {\n            if (id[2 * i] == id[2 * i + 1]) return\
    \ false;\n            _answer[i] = id[2 * i] < id[2 * i + 1];\n        }\n   \
    \     return true;\n    }\n\n    vector<bool> answer() { return _answer; }\n\n\
    \  private:\n    int _n;\n    vector<bool> _answer;\n    SCC scc;  // \u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\u3092\u7528\u3044\u308B\n};\n#line 4 \"test/library_checker/two_sat.yosupo.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    string tmp;\n    int N, M;\n    cin\
    \ >> tmp >> tmp >> N >> M;\n    TwoSAT ts(N);\n    for (int i = 0; i < M; i++)\
    \ {\n        int a, b;\n        cin >> a >> b >> tmp;\n        ts.add_clause(abs(a)\
    \ - 1, (a > 0), abs(b) - 1, (b > 0));\n    }\n\n    if (!ts.satisfiable()) {\n\
    \        cout << \"s UNSATISFIABLE\" << '\\n';\n        return 0;\n    }\n\n \
    \   auto ans = ts.answer();\n    cout << \"s SATISFIABLE\\n v \";\n    for (int\
    \ i = 0; i < N; i++) {\n        int v = i + 1;\n        if (!ans[i]) v *= -1;\n\
    \        cout << v << \" \";\n    }\n    cout << \"0\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\n\
    #include \"../../src/graph/two_sat.hpp\"\nusing namespace std;\n\nint main() {\n\
    \    string tmp;\n    int N, M;\n    cin >> tmp >> tmp >> N >> M;\n    TwoSAT\
    \ ts(N);\n    for (int i = 0; i < M; i++) {\n        int a, b;\n        cin >>\
    \ a >> b >> tmp;\n        ts.add_clause(abs(a) - 1, (a > 0), abs(b) - 1, (b >\
    \ 0));\n    }\n\n    if (!ts.satisfiable()) {\n        cout << \"s UNSATISFIABLE\"\
    \ << '\\n';\n        return 0;\n    }\n\n    auto ans = ts.answer();\n    cout\
    \ << \"s SATISFIABLE\\n v \";\n    for (int i = 0; i < N; i++) {\n        int\
    \ v = i + 1;\n        if (!ans[i]) v *= -1;\n        cout << v << \" \";\n   \
    \ }\n    cout << \"0\\n\";\n}\n"
  dependsOn:
  - src/graph/two_sat.hpp
  - src/graph/scc.hpp
  isVerificationFile: true
  path: test/library_checker/two_sat.yosupo.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/two_sat.yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/two_sat.yosupo.test.cpp
- /verify/test/library_checker/two_sat.yosupo.test.cpp.html
title: test/library_checker/two_sat.yosupo.test.cpp
---
