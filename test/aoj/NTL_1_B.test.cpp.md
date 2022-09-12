---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/math/modint.hpp\"\nusing namespace std;\n\
    \ntemplate <int64_t Modulus>\nstruct Modint {\n    using mint = Modint;\n    long\
    \ long v;\n    Modint() : v(0) {}\n    Modint(long long x) {\n        x %= Modulus;\n\
    \        if (x < 0) x += Modulus;\n        v = x;\n    }\n    const long long&\
    \ val() const { return v; }\n    // \u4EE3\u5165\u6F14\u7B97\u5B50\n    mint&\
    \ operator+=(const mint rhs) {\n        v += rhs.v;\n        if (v >= Modulus)\
    \ v -= Modulus;\n        return *this;\n    }\n    mint& operator-=(const mint\
    \ rhs) {\n        if (v < rhs.v) v += Modulus;\n        v -= rhs.v;\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint rhs) {\n        v = v * rhs.v\
    \ % Modulus;\n        return *this;\n    }\n    mint& operator/=(mint rhs) { return\
    \ *this = *this * rhs.inv(); }\n    // \u7D2F\u4E57, \u9006\u5143\n    mint pow(long\
    \ long n) const {\n        mint x = *this, res = 1;\n        while (n) {\n   \
    \         if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n  \
    \      }\n        return res;\n    }\n    mint inv() const { return pow(Modulus\
    \ - 2); }\n    // \u7B97\u8853\u6F14\u7B97\u5B50\n    mint operator+(const mint\
    \ rhs) const { return mint(*this) += rhs; }\n    mint operator-(const mint rhs)\
    \ const { return mint(*this) -= rhs; }\n    mint operator*(const mint rhs) const\
    \ { return mint(*this) *= rhs; }\n    mint operator/(const mint rhs) const { return\
    \ mint(*this) /= rhs; }\n    mint operator-() const { return mint() - *this; }\
    \  // \u5358\u9805\n    // \u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n\
    \    friend ostream& operator<<(ostream& os, const mint& p) { return os << p.v;\
    \ }\n    friend istream& operator>>(istream& is, mint& p) {\n        long long\
    \ t;\n        is >> t;\n        p = mint(t);\n        return (is);\n    }\n};\n\
    #line 4 \"test/aoj/NTL_1_B.test.cpp\"\nusing namespace std;\n\nconstexpr long\
    \ long MOD = 1000000007;\nusing mint = Modint<MOD>;\n\nint main() {\n    mint\
    \ m;\n    int n;\n    cin >> m >> n;\n    cout << m.pow(n) << endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/math/modint.hpp\"\nusing namespace\
    \ std;\n\nconstexpr long long MOD = 1000000007;\nusing mint = Modint<MOD>;\n\n\
    int main() {\n    mint m;\n    int n;\n    cin >> m >> n;\n    cout << m.pow(n)\
    \ << endl;\n    return 0;\n}\n"
  dependsOn:
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
