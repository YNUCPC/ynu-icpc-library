---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/trie.hpp
    title: src/string/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/agc047/tasks/agc047_b
    links:
    - https://atcoder.jp/contests/agc047/tasks/agc047_b
  bundledCode: "#line 1 \"test/atcoder/agc047_b.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc047/tasks/agc047_b\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/string/trie.hpp\"\nusing namespace std;\n\
    \nstruct Trie {\n  private:\n    static constexpr int C_SIZE = 26;    // C_SIZE\
    \  : \u6587\u5B57\u306E\u7A2E\u985E\u6570\n    static constexpr int C_BEGIN =\
    \ 'a';  // C_BEGIN : \u958B\u59CB\u6587\u5B57\n    int root = 0;\n    struct Node\
    \ {\n        int child[C_SIZE];  // \u5B50\u30CE\u30FC\u30C9\u306E\u756A\u53F7\
    , \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n        vector<int> ids;    //\
    \ \u305D\u306E\u30CE\u30FC\u30C9\u304C\u7D42\u7AEF\u3067\u3042\u308B\u6587\u5B57\
    \u5217\u306EID\u30EA\u30B9\u30C8\n        Node() { fill(child, child + C_SIZE,\
    \ -1); }\n    };\n\n  public:\n    vector<Node> nodes;\n    int cnt = 0;  // \u8FFD\
    \u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\u500B\u6570\n    Trie() : nodes(1)\
    \ {}\n    // nodes[idx]\u304B\u3089\u6587\u5B57c\u3067\u9077\u79FB\u3057\u305F\
    \u3068\u304D\u306E\u9802\u70B9\u306Eindex\n    int next_index(int idx, char c)\
    \ {\n        return nodes[idx].child[c - C_BEGIN];\n    }\n    // \u6587\u5B57\
    \u5217\u306E\u8FFD\u52A0\n    void insert(const string str) {\n        int now\
    \ = root;\n        for (auto c : str) {\n            int k = c - C_BEGIN;\n  \
    \          int& nxt = nodes[now].child[k];\n            if (nxt == -1) {\n   \
    \             now = nxt = int(nodes.size());\n                nodes.push_back(Node());\n\
    \            } else {\n                now = nxt;\n            }\n        }\n\
    \        nodes[now].ids.push_back(cnt++);\n    }\n    // \u6587\u5B57\u5217\u306B\
    \u5BFE\u5FDC\u3059\u308Bnode\u306Eindex\u3092\u691C\u7D22, \u5B58\u5728\u3057\u306A\
    \u3051\u308C\u3070-1\n    int find(const string str) {\n        int now = root;\n\
    \        for (auto c : str) {\n            int nxt = next_index(now, c);\n   \
    \         if (nxt == -1) return -1;\n            now = nxt;\n        }\n     \
    \   return now;\n    }\n};\n#line 4 \"test/atcoder/agc047_b.test.cpp\"\nusing\
    \ namespace std;\n\nusing ll = long long;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    int n;\n    cin >> n;\n    vector<string>\
    \ s(n);\n    Trie trie;\n    for (int i = 0; i < n; i++) {\n        cin >> s[i];\n\
    \        reverse(s[i].begin(), s[i].end());\n        trie.insert(s[i]);\n    }\n\
    \    ll ans = 0;\n    for (int i = 0; i < n; i++) {\n        int cnt[26]{};\n\
    \        for (auto c : s[i]) cnt[c - 'a']++;\n        int m = s[i].size(), now\
    \ = 0;\n        for (int j = 0; j < m - 1; j++) {\n            for (int k = 0;\
    \ k < 26; k++) {\n                if (cnt[k] > 0) {\n                    int tmp\
    \ = trie.next_index(now, k + 'a');\n                    if (tmp != -1) {\n   \
    \                     ans += trie.nodes[tmp].ids.size();\n                   \
    \ }\n                }\n            }\n            now = trie.next_index(now,\
    \ s[i][j]);\n            cnt[s[i][j] - 'a']--;\n        }\n    }\n    cout <<\
    \ ans << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc047/tasks/agc047_b\"\n#include\
    \ <bits/stdc++.h>\n#include \"../../src/string/trie.hpp\"\nusing namespace std;\n\
    \nusing ll = long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<string> s(n);\n    Trie trie;\n    for\
    \ (int i = 0; i < n; i++) {\n        cin >> s[i];\n        reverse(s[i].begin(),\
    \ s[i].end());\n        trie.insert(s[i]);\n    }\n    ll ans = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        int cnt[26]{};\n        for (auto c : s[i]) cnt[c\
    \ - 'a']++;\n        int m = s[i].size(), now = 0;\n        for (int j = 0; j\
    \ < m - 1; j++) {\n            for (int k = 0; k < 26; k++) {\n              \
    \  if (cnt[k] > 0) {\n                    int tmp = trie.next_index(now, k + 'a');\n\
    \                    if (tmp != -1) {\n                        ans += trie.nodes[tmp].ids.size();\n\
    \                    }\n                }\n            }\n            now = trie.next_index(now,\
    \ s[i][j]);\n            cnt[s[i][j] - 'a']--;\n        }\n    }\n    cout <<\
    \ ans << endl;\n    return 0;\n}\n"
  dependsOn:
  - src/string/trie.hpp
  isVerificationFile: true
  path: test/atcoder/agc047_b.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/agc047_b.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/agc047_b.test.cpp
- /verify/test/atcoder/agc047_b.test.cpp.html
title: test/atcoder/agc047_b.test.cpp
---
