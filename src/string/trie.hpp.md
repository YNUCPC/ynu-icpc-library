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
    \ std;\n\nstruct Trie {\n    static constexpr int C_SIZE = 26;    // C_SIZE  :\
    \ \u6587\u5B57\u306E\u7A2E\u985E\u6570\n    static constexpr int C_BEGIN = 'a';\
    \  // C_BEGIN : \u958B\u59CB\u6587\u5B57\n    static constexpr int ROOT = 0;\n\
    \    struct Node {\n        array<int, C_SIZE> to = {};  // \u5B50\u30CE\u30FC\
    \u30C9\u306E\u756A\u53F7, \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n     \
    \   vector<int> ids;             // \u305D\u306E\u30CE\u30FC\u30C9\u304C\u7D42\
    \u7AEF\u3067\u3042\u308B\u6587\u5B57\u5217\u306EID\u30EA\u30B9\u30C8\n       \
    \ Node() { to.fill(-1); }\n    };\n    vector<Node> nodes;\n    int cnt = 0; \
    \ // \u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\u500B\u6570\n    Trie()\
    \ : nodes(1) {}\n    // nodes[idx]\u304B\u3089\u6587\u5B57c\u3067\u9077\u79FB\u3057\
    \u305F\u3068\u304D\u306E\u9802\u70B9\u306Eindex\n    int next(int idx, char c)\
    \ { return nodes[idx].to[c - C_BEGIN]; }\n    // \u6587\u5B57\u5217\u306E\u8FFD\
    \u52A0\n    int insert(const string& s) {\n        int now = ROOT;\n        for\
    \ (char c : s) {\n            int k = c - C_BEGIN;\n            if (nodes[now].to[k]\
    \ == -1) {\n                nodes[now].to[k] = nodes.size();\n               \
    \ nodes.push_back(Node());\n            }\n            now = nodes[now].to[k];\n\
    \        }\n        nodes[now].ids.push_back(cnt++);\n        return now;\n  \
    \  }\n    // \u6587\u5B57\u5217\u306B\u5BFE\u5FDC\u3059\u308Bnode\u306Eindex\u3092\
    \u691C\u7D22, \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n    int find(const\
    \ string& s) {\n        int now = ROOT;\n        for (char c : s) {\n        \
    \    now = next(now, c);\n            if (now == -1) return -1;\n        }\n \
    \       return now;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Trie\
    \ {\n    static constexpr int C_SIZE = 26;    // C_SIZE  : \u6587\u5B57\u306E\u7A2E\
    \u985E\u6570\n    static constexpr int C_BEGIN = 'a';  // C_BEGIN : \u958B\u59CB\
    \u6587\u5B57\n    static constexpr int ROOT = 0;\n    struct Node {\n        array<int,\
    \ C_SIZE> to = {};  // \u5B50\u30CE\u30FC\u30C9\u306E\u756A\u53F7, \u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070-1\n        vector<int> ids;             // \u305D\
    \u306E\u30CE\u30FC\u30C9\u304C\u7D42\u7AEF\u3067\u3042\u308B\u6587\u5B57\u5217\
    \u306EID\u30EA\u30B9\u30C8\n        Node() { to.fill(-1); }\n    };\n    vector<Node>\
    \ nodes;\n    int cnt = 0;  // \u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\
    \u500B\u6570\n    Trie() : nodes(1) {}\n    // nodes[idx]\u304B\u3089\u6587\u5B57\
    c\u3067\u9077\u79FB\u3057\u305F\u3068\u304D\u306E\u9802\u70B9\u306Eindex\n   \
    \ int next(int idx, char c) { return nodes[idx].to[c - C_BEGIN]; }\n    // \u6587\
    \u5B57\u5217\u306E\u8FFD\u52A0\n    int insert(const string& s) {\n        int\
    \ now = ROOT;\n        for (char c : s) {\n            int k = c - C_BEGIN;\n\
    \            if (nodes[now].to[k] == -1) {\n                nodes[now].to[k] =\
    \ nodes.size();\n                nodes.push_back(Node());\n            }\n   \
    \         now = nodes[now].to[k];\n        }\n        nodes[now].ids.push_back(cnt++);\n\
    \        return now;\n    }\n    // \u6587\u5B57\u5217\u306B\u5BFE\u5FDC\u3059\
    \u308Bnode\u306Eindex\u3092\u691C\u7D22, \u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    -1\n    int find(const string& s) {\n        int now = ROOT;\n        for (char\
    \ c : s) {\n            now = next(now, c);\n            if (now == -1) return\
    \ -1;\n        }\n        return now;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy: []
  timestamp: '2022-09-11 15:44:54+09:00'
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
