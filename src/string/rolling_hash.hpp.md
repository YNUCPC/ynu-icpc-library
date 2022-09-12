---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2863.test.cpp
    title: test/aoj/2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B_rollinghash.test.cpp
    title: test/aoj/ALDS1_14_B_rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/rolling_hash.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct RollingHash {\n    static constexpr int M = 2;\n\
    \    static constexpr long long MODS[M] = {999999937, 1000000007};\n    static\
    \ constexpr long long BASE = 9973;\n    vector<long long> powb[M], hash[M];\n\
    \    int n;\n    RollingHash() {}\n    RollingHash(const string& str) { init(str);\
    \ }\n    void init(const string& str) {\n        n = str.size();\n        for\
    \ (int k = 0; k < M; k++) {\n            powb[k].resize(n + 1, 1);\n         \
    \   hash[k].resize(n + 1, 0);\n            for (int i = 0; i < n; i++) {\n   \
    \             hash[k][i + 1] = (hash[k][i] * BASE + str[i]) % MODS[k];\n     \
    \           powb[k][i + 1] = powb[k][i] * BASE % MODS[k];\n            }\n   \
    \     }\n    }\n    // get hash str[l,r)\n    long long get(int l, int r, int\
    \ k) {\n        long long res = hash[k][r] - hash[k][l] * powb[k][r - l] % MODS[k];\n\
    \        if (res < 0) res += MODS[k];\n        return res;\n    }\n};\n\nbool\
    \ match(RollingHash& rh1, int l1, int r1, RollingHash& rh2, int l2, int r2) {\n\
    \    bool res = true;\n    for (int k = 0; k < RollingHash::M; k++) {\n      \
    \  res &= rh1.get(l1, r1, k) == rh2.get(l2, r2, k);\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct RollingHash\
    \ {\n    static constexpr int M = 2;\n    static constexpr long long MODS[M] =\
    \ {999999937, 1000000007};\n    static constexpr long long BASE = 9973;\n    vector<long\
    \ long> powb[M], hash[M];\n    int n;\n    RollingHash() {}\n    RollingHash(const\
    \ string& str) { init(str); }\n    void init(const string& str) {\n        n =\
    \ str.size();\n        for (int k = 0; k < M; k++) {\n            powb[k].resize(n\
    \ + 1, 1);\n            hash[k].resize(n + 1, 0);\n            for (int i = 0;\
    \ i < n; i++) {\n                hash[k][i + 1] = (hash[k][i] * BASE + str[i])\
    \ % MODS[k];\n                powb[k][i + 1] = powb[k][i] * BASE % MODS[k];\n\
    \            }\n        }\n    }\n    // get hash str[l,r)\n    long long get(int\
    \ l, int r, int k) {\n        long long res = hash[k][r] - hash[k][l] * powb[k][r\
    \ - l] % MODS[k];\n        if (res < 0) res += MODS[k];\n        return res;\n\
    \    }\n};\n\nbool match(RollingHash& rh1, int l1, int r1, RollingHash& rh2, int\
    \ l2, int r2) {\n    bool res = true;\n    for (int k = 0; k < RollingHash::M;\
    \ k++) {\n        res &= rh1.get(l1, r1, k) == rh2.get(l2, r2, k);\n    }\n  \
    \  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B_rollinghash.test.cpp
  - test/aoj/2863.test.cpp
documentation_of: src/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash.hpp
- /library/src/string/rolling_hash.hpp.html
title: src/string/rolling_hash.hpp
---
