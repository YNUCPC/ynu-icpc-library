---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/aho_corasick.hpp
    title: src/string/aho_corasick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2863
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2863
  bundledCode: "#line 1 \"test/aoj/2863_ahocorasick.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2863\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/math/modint.hpp\"\nusing namespace std;\n\ntemplate <int64_t Modulus>\n\
    struct Modint {\n    using mint = Modint;\n    long long v;\n    Modint() : v(0)\
    \ {}\n    Modint(long long x) {\n        x %= Modulus;\n        if (x < 0) x +=\
    \ Modulus;\n        v = x;\n    }\n    const long long& val() const { return v;\
    \ }\n    // \u4EE3\u5165\u6F14\u7B97\u5B50\n    mint& operator+=(const mint rhs)\
    \ {\n        v += rhs.v;\n        if (v >= Modulus) v -= Modulus;\n        return\
    \ *this;\n    }\n    mint& operator-=(const mint rhs) {\n        if (v < rhs.v)\
    \ v += Modulus;\n        v -= rhs.v;\n        return *this;\n    }\n    mint&\
    \ operator*=(const mint rhs) {\n        v = v * rhs.v % Modulus;\n        return\
    \ *this;\n    }\n    mint& operator/=(mint rhs) { return *this = *this * rhs.inv();\
    \ }\n    // \u7D2F\u4E57, \u9006\u5143\n    mint pow(long long n) const {\n  \
    \      mint x = *this, res = 1;\n        while (n) {\n            if (n & 1) res\
    \ *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n    mint inv() const { return pow(Modulus - 2); }\n    // \u7B97\
    \u8853\u6F14\u7B97\u5B50\n    mint operator+(const mint rhs) const { return mint(*this)\
    \ += rhs; }\n    mint operator-(const mint rhs) const { return mint(*this) -=\
    \ rhs; }\n    mint operator*(const mint rhs) const { return mint(*this) *= rhs;\
    \ }\n    mint operator/(const mint rhs) const { return mint(*this) /= rhs; }\n\
    \    mint operator-() const { return mint() - *this; }  // \u5358\u9805\n    //\
    \ \u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    friend ostream& operator<<(ostream&\
    \ os, const mint& p) { return os << p.v; }\n    friend istream& operator>>(istream&\
    \ is, mint& p) {\n        long long t;\n        is >> t;\n        p = mint(t);\n\
    \        return (is);\n    }\n};\n#line 3 \"src/string/aho_corasick.hpp\"\nusing\
    \ namespace std;\n\nstruct AhoCorasick {\n    static constexpr int C_SIZE = 26;\
    \    // C_SIZE  : \u6587\u5B57\u306E\u7A2E\u985E\u6570\n    static constexpr int\
    \ C_BEGIN = 'a';  // C_BEGIN : \u958B\u59CB\u6587\u5B57\n    static constexpr\
    \ int ROOT = 0;\n    struct Node {\n        array<int, C_SIZE> to = {};    //\
    \ to[c]=\u6587\u5B57c\u306B\u3088\u308B\u9077\u79FB\u5148\u30CE\u30FC\u30C9, \u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070-1\n        vector<int> ids;             \
    \  // \u305D\u306E\u30CE\u30FC\u30C9\u3067\u30DE\u30C3\u30C1\u3059\u308B\u6587\
    \u5B57\u5217\u306EID\u30EA\u30B9\u30C8\n        int fail = ROOT, drct = ROOT;\
    \  // \u5931\u6557\u6642\u306E\u9077\u79FB\u5148, suffix\u3067\u30DE\u30C3\u30C1\
    \u3059\u308B\u9077\u79FB\u5148\n        Node() { to.fill(-1); }\n    };\n    vector<Node>\
    \ nodes;\n    vector<string> patterns;\n    AhoCorasick() : nodes(1) {}\n\n  \
    \  int insert(const string& s) {\n        int now = ROOT;\n        for (char c\
    \ : s) {\n            int k = c - C_BEGIN;\n            if (nodes[now].to[k] ==\
    \ -1) {\n                nodes[now].to[k] = nodes.size();\n                nodes.push_back(Node());\n\
    \            }\n            now = nodes[now].to[k];\n        }\n        nodes[now].ids.push_back(patterns.size());\n\
    \        patterns.push_back(s);\n        return now;\n    }\n\n    void build()\
    \ {\n        queue<int> que;\n        for (int& x : nodes[ROOT].to) {\n      \
    \      if (x == -1) {\n                x = ROOT;\n            } else {\n     \
    \           que.push(x);\n            }\n        }\n        while (!que.empty())\
    \ {\n            int now = que.front();\n            que.pop();\n            int\
    \ fail = nodes[now].fail;\n            for (int k = 0; k < C_SIZE; k++) {\n  \
    \              int& nxt = nodes[now].to[k];\n                if (nxt == -1) {\n\
    \                    nxt = nodes[fail].to[k];  // failure link \u3067\u9077\u79FB\
    \u3057\u3066\u304B\u3089\u9077\u79FB\n                } else {\n             \
    \       nodes[nxt].fail = nodes[fail].to[k];  // \u9077\u79FB\u5148\u306Efailure\
    \ link\u3092\u6C42\u3081\u308B\n                    que.push(nxt);\n         \
    \       }\n            }\n            nodes[now].drct = (nodes[fail].ids.empty()\
    \ ? nodes[fail].drct : fail);\n        }\n    }\n\n    int next(int idx, char\
    \ c) { return nodes[idx].to[c - C_BEGIN]; }\n\n    bool accept(int idx) { return\
    \ nodes[idx].drct != ROOT || !nodes[idx].ids.empty(); }\n\n    vector<int> match(int\
    \ idx) {\n        vector<int> res;\n        int now = idx;\n        while (now\
    \ != ROOT) {\n            for (int id : nodes[now].ids) res.push_back(id);\n \
    \           now = nodes[now].drct;\n        }\n        return res;\n    }\n\n\
    \    vector<vector<int>> search(const string& s) {\n        vector<vector<int>>\
    \ res;\n        int now = ROOT;\n        for (char c : s) {\n            now =\
    \ next(now, c);\n            res.emplace_back(match(now));\n        }\n      \
    \  return res;\n    }\n};\n#line 5 \"test/aoj/2863_ahocorasick.test.cpp\"\nusing\
    \ namespace std;\n\nconstexpr long long MOD = 1000000007;\nusing mint = Modint<MOD>;\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    int\
    \ n;\n    cin >> n;\n    AhoCorasick ac;\n    for (int i = 0; i < n; i++) {\n\
    \        string s;\n        cin >> s;\n        ac.insert(s);\n    }\n    ac.build();\n\
    \    string t;\n    cin >> t;\n    auto match = ac.search(t);\n    int m = t.size();\n\
    \    vector<mint> dp(m + 1);\n    dp[0] = 1;\n    for (int i = 1; i <= m; i++)\
    \ {\n        for (const auto& id : match[i - 1]) {\n            int len = ac.patterns[id].size();\n\
    \            dp[i] += dp[i - len];\n        }\n    }\n    cout << dp[m] << endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2863\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/math/modint.hpp\"\n#include \"\
    ../../src/string/aho_corasick.hpp\"\nusing namespace std;\n\nconstexpr long long\
    \ MOD = 1000000007;\nusing mint = Modint<MOD>;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    int n;\n    cin >> n;\n    AhoCorasick\
    \ ac;\n    for (int i = 0; i < n; i++) {\n        string s;\n        cin >> s;\n\
    \        ac.insert(s);\n    }\n    ac.build();\n    string t;\n    cin >> t;\n\
    \    auto match = ac.search(t);\n    int m = t.size();\n    vector<mint> dp(m\
    \ + 1);\n    dp[0] = 1;\n    for (int i = 1; i <= m; i++) {\n        for (const\
    \ auto& id : match[i - 1]) {\n            int len = ac.patterns[id].size();\n\
    \            dp[i] += dp[i - len];\n        }\n    }\n    cout << dp[m] << endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - src/math/modint.hpp
  - src/string/aho_corasick.hpp
  isVerificationFile: true
  path: test/aoj/2863_ahocorasick.test.cpp
  requiredBy: []
  timestamp: '2022-09-11 15:55:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2863_ahocorasick.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2863_ahocorasick.test.cpp
- /verify/test/aoj/2863_ahocorasick.test.cpp.html
title: test/aoj/2863_ahocorasick.test.cpp
---
