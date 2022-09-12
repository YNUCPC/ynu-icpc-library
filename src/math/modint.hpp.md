---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0341.test.cpp
    title: test/aoj/0341.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2863.test.cpp
    title: test/aoj/2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2863_ahocorasick.test.cpp
    title: test/aoj/2863_ahocorasick.test.cpp
  - icon: ':x:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':x:'
    path: test/library_checker/bitwise_and_convolution.test.cpp
    title: test/library_checker/bitwise_and_convolution.test.cpp
  - icon: ':x:'
    path: test/library_checker/bitwise_and_convolution_by_kronecker.test.cpp
    title: test/library_checker/bitwise_and_convolution_by_kronecker.test.cpp
  - icon: ':x:'
    path: test/library_checker/bitwise_or_convolution.test.cpp
    title: test/library_checker/bitwise_or_convolution.test.cpp
  - icon: ':x:'
    path: test/library_checker/bitwise_xor_convolution.test.cpp
    title: test/library_checker/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modint.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <int64_t Modulus>\nstruct Modint {\n    using mint = Modint;\n\
    \    long long v;\n    Modint() : v(0) {}\n    Modint(long long x) {\n       \
    \ x %= Modulus;\n        if (x < 0) x += Modulus;\n        v = x;\n    }\n   \
    \ const long long& val() const { return v; }\n    // \u4EE3\u5165\u6F14\u7B97\u5B50\
    \n    mint& operator+=(const mint rhs) {\n        v += rhs.v;\n        if (v >=\
    \ Modulus) v -= Modulus;\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint rhs) {\n        if (v < rhs.v) v += Modulus;\n        v -= rhs.v;\n   \
    \     return *this;\n    }\n    mint& operator*=(const mint rhs) {\n        v\
    \ = v * rhs.v % Modulus;\n        return *this;\n    }\n    mint& operator/=(mint\
    \ rhs) { return *this = *this * rhs.inv(); }\n    // \u7D2F\u4E57, \u9006\u5143\
    \n    mint pow(long long n) const {\n        mint x = *this, res = 1;\n      \
    \  while (n) {\n            if (n & 1) res *= x;\n            x *= x;\n      \
    \      n >>= 1;\n        }\n        return res;\n    }\n    mint inv() const {\
    \ return pow(Modulus - 2); }\n    // \u7B97\u8853\u6F14\u7B97\u5B50\n    mint\
    \ operator+(const mint rhs) const { return mint(*this) += rhs; }\n    mint operator-(const\
    \ mint rhs) const { return mint(*this) -= rhs; }\n    mint operator*(const mint\
    \ rhs) const { return mint(*this) *= rhs; }\n    mint operator/(const mint rhs)\
    \ const { return mint(*this) /= rhs; }\n    mint operator-() const { return mint()\
    \ - *this; }  // \u5358\u9805\n    // \u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\n    friend ostream& operator<<(ostream& os, const mint& p) { return os\
    \ << p.v; }\n    friend istream& operator>>(istream& is, mint& p) {\n        long\
    \ long t;\n        is >> t;\n        p = mint(t);\n        return (is);\n    }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <int64_t Modulus>\nstruct Modint {\n    using mint = Modint;\n    long long\
    \ v;\n    Modint() : v(0) {}\n    Modint(long long x) {\n        x %= Modulus;\n\
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
    \ t;\n        is >> t;\n        p = mint(t);\n        return (is);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modint.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/bitwise_and_convolution.test.cpp
  - test/library_checker/bitwise_and_convolution_by_kronecker.test.cpp
  - test/library_checker/bitwise_or_convolution.test.cpp
  - test/library_checker/bitwise_xor_convolution.test.cpp
  - test/aoj/2863_ahocorasick.test.cpp
  - test/aoj/0341.test.cpp
  - test/aoj/NTL_1_B.test.cpp
  - test/aoj/2863.test.cpp
documentation_of: src/math/modint.hpp
layout: document
redirect_from:
- /library/src/math/modint.hpp
- /library/src/math/modint.hpp.html
title: src/math/modint.hpp
---
