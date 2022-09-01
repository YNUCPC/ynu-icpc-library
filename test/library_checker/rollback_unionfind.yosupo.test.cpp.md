---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/rollback_unionfind.hpp
    title: src/datastructure/rollback_unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/library_checker/rollback_unionfind.yosupo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/datastructure/rollback_unionfind.hpp\"\nusing\
    \ namespace std;\n\nstruct RollbackUnionFind {\n    vector<int> data;\n    stack<pair<int,\
    \ int>> history;\n    int inner_snap = 0;\n    RollbackUnionFind(int n) { data.resize(n,\
    \ -1); }\n    int find(int x) { return data[x] < 0 ? x : find(data[x]); }\n  \
    \  bool unite(int x, int y) {\n        x = find(x), y = find(y);\n        history.push({x,\
    \ data[x]});\n        history.push({y, data[y]});\n        if (x == y) return\
    \ false;\n        if (-data[x] < -data[y]) swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n        return true;\n    }\n    int same(int x, int y)\
    \ { return find(x) == find(y); }\n    int size(int x) { return (-data[find(x)]);\
    \ }\n    void undo() {\n        data[history.top().first] = history.top().second;\n\
    \        history.pop();\n        data[history.top().first] = history.top().second;\n\
    \        history.pop();\n    }\n    int time() { return int(history.size() >>\
    \ 1); }\n    void snapshot() { inner_snap = time(); }\n    void rollback(int t\
    \ = -1) {\n        if (t == -1) t = inner_snap;\n        while (t < time()) undo();\n\
    \    }\n};\n#line 4 \"test/library_checker/rollback_unionfind.yosupo.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n  \
    \  vector<int> ans(Q + 1, -1);\n    vector<vector<array<int, 4>>> G(Q + 1);\n\
    \    for (int i = 1; i <= Q; i++) {\n        int t, k, u, v;\n        cin >> t\
    \ >> k >> u >> v;\n        k++;\n        G[k].push_back({t, i, u, v});\n    }\n\
    \n    RollbackUnionFind uf(N);\n    function<void(array<int, 4>, int)> dfs = [&](array<int,\
    \ 4> a, int d) -> void {\n        if (d) uf.rollback(d - 1);\n        auto [t,\
    \ i, u, v] = a;\n        if (t == 1) {\n            ans[i] = uf.same(u, v);\n\
    \        } else {\n            uf.unite(u, v);\n        }\n        for (auto&\
    \ a : G[i]) dfs(a, d + 1);\n    };\n    dfs({-1, 0, -1, 0}, 0);\n\n    for (int\
    \ a : ans)\n        if (a != -1) cout << a << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include <bits/stdc++.h>\n#include \"../../src/datastructure/rollback_unionfind.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n  \
    \  vector<int> ans(Q + 1, -1);\n    vector<vector<array<int, 4>>> G(Q + 1);\n\
    \    for (int i = 1; i <= Q; i++) {\n        int t, k, u, v;\n        cin >> t\
    \ >> k >> u >> v;\n        k++;\n        G[k].push_back({t, i, u, v});\n    }\n\
    \n    RollbackUnionFind uf(N);\n    function<void(array<int, 4>, int)> dfs = [&](array<int,\
    \ 4> a, int d) -> void {\n        if (d) uf.rollback(d - 1);\n        auto [t,\
    \ i, u, v] = a;\n        if (t == 1) {\n            ans[i] = uf.same(u, v);\n\
    \        } else {\n            uf.unite(u, v);\n        }\n        for (auto&\
    \ a : G[i]) dfs(a, d + 1);\n    };\n    dfs({-1, 0, -1, 0}, 0);\n\n    for (int\
    \ a : ans)\n        if (a != -1) cout << a << '\\n';\n}\n"
  dependsOn:
  - src/datastructure/rollback_unionfind.hpp
  isVerificationFile: true
  path: test/library_checker/rollback_unionfind.yosupo.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/rollback_unionfind.yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/rollback_unionfind.yosupo.test.cpp
- /verify/test/library_checker/rollback_unionfind.yosupo.test.cpp.html
title: test/library_checker/rollback_unionfind.yosupo.test.cpp
---
