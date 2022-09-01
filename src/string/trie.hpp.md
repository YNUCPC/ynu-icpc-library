---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2863.test.cpp
    title: test/aoj/2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc047_b.test.cpp
    title: test/atcoder/agc047_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/trie.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct Trie {\n  private:\n    static constexpr int C_SIZE = 26;   \
    \ // C_SIZE  : \u6587\u5B57\u306E\u7A2E\u985E\u6570\n    static constexpr int\
    \ C_BEGIN = 'a';  // C_BEGIN : \u958B\u59CB\u6587\u5B57\n    int root = 0;\n \
    \   struct Node {\n        int child[C_SIZE];  // \u5B50\u30CE\u30FC\u30C9\u306E\
    \u756A\u53F7, \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n        vector<int>\
    \ ids;    // \u305D\u306E\u30CE\u30FC\u30C9\u304C\u7D42\u7AEF\u3067\u3042\u308B\
    \u6587\u5B57\u5217\u306EID\u30EA\u30B9\u30C8\n        Node() { fill(child, child\
    \ + C_SIZE, -1); }\n    };\n\n  public:\n    vector<Node> nodes;\n    int cnt\
    \ = 0;  // \u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\u500B\u6570\n    Trie()\
    \ : nodes(1) {}\n    // nodes[idx]\u304B\u3089\u6587\u5B57c\u3067\u9077\u79FB\u3057\
    \u305F\u3068\u304D\u306E\u9802\u70B9\u306Eindex\n    int next_index(int idx, char\
    \ c) {\n        return nodes[idx].child[c - C_BEGIN];\n    }\n    // \u6587\u5B57\
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
    \   return now;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Trie\
    \ {\n  private:\n    static constexpr int C_SIZE = 26;    // C_SIZE  : \u6587\u5B57\
    \u306E\u7A2E\u985E\u6570\n    static constexpr int C_BEGIN = 'a';  // C_BEGIN\
    \ : \u958B\u59CB\u6587\u5B57\n    int root = 0;\n    struct Node {\n        int\
    \ child[C_SIZE];  // \u5B50\u30CE\u30FC\u30C9\u306E\u756A\u53F7, \u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070-1\n        vector<int> ids;    // \u305D\u306E\u30CE\u30FC\
    \u30C9\u304C\u7D42\u7AEF\u3067\u3042\u308B\u6587\u5B57\u5217\u306EID\u30EA\u30B9\
    \u30C8\n        Node() { fill(child, child + C_SIZE, -1); }\n    };\n\n  public:\n\
    \    vector<Node> nodes;\n    int cnt = 0;  // \u8FFD\u52A0\u3057\u305F\u6587\u5B57\
    \u5217\u306E\u500B\u6570\n    Trie() : nodes(1) {}\n    // nodes[idx]\u304B\u3089\
    \u6587\u5B57c\u3067\u9077\u79FB\u3057\u305F\u3068\u304D\u306E\u9802\u70B9\u306E\
    index\n    int next_index(int idx, char c) {\n        return nodes[idx].child[c\
    \ - C_BEGIN];\n    }\n    // \u6587\u5B57\u5217\u306E\u8FFD\u52A0\n    void insert(const\
    \ string str) {\n        int now = root;\n        for (auto c : str) {\n     \
    \       int k = c - C_BEGIN;\n            int& nxt = nodes[now].child[k];\n  \
    \          if (nxt == -1) {\n                now = nxt = int(nodes.size());\n\
    \                nodes.push_back(Node());\n            } else {\n            \
    \    now = nxt;\n            }\n        }\n        nodes[now].ids.push_back(cnt++);\n\
    \    }\n    // \u6587\u5B57\u5217\u306B\u5BFE\u5FDC\u3059\u308Bnode\u306Eindex\u3092\
    \u691C\u7D22, \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n    int find(const\
    \ string str) {\n        int now = root;\n        for (auto c : str) {\n     \
    \       int nxt = next_index(now, c);\n            if (nxt == -1) return -1;\n\
    \            now = nxt;\n        }\n        return now;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2863.test.cpp
  - test/atcoder/agc047_b.test.cpp
documentation_of: src/string/trie.hpp
layout: document
redirect_from:
- /library/src/string/trie.hpp
- /library/src/string/trie.hpp.html
title: src/string/trie.hpp
---
