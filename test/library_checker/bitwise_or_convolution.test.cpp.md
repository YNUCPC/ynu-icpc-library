---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/kronecker.hpp
    title: src/math/kronecker.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/library_checker/bitwise_or_convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #include <bits/stdc++.h>\n#line 3 \"src/math/kronecker.hpp\"\nusing namespace\
    \ std;\n\nnamespace Kronecker {\n\ntemplate <class T>\nvoid mul(vector<T>& x,\
    \ T a, T b, T c, T d) {\n    int n = x.size();\n    for (int j = 1; j < n; j <<=\
    \ 1) {\n        for (int i = 0; i < n; i++) {\n            if ((i & j) == 0) {\n\
    \                T s = a * x[i] + b * x[i + j];\n                T t = c * x[i]\
    \ + d * x[i + j];\n                x[i] = s;\n                x[i + j] = t;\n\
    \            }\n        }\n    }\n}\n\ntemplate <class T>\nvoid fwht(vector<T>&\
    \ a, bool inv) {\n    mul(a, T(1), T(1), T(1), T(-1));\n    if (inv) {\n     \
    \   for (T& x : a) x /= T(a.size());\n    }\n}\n\ntemplate <class T>\nvector<T>\
    \ xor_convolution(vector<T>& a, vector<T>& b) {\n    fwht(a, false);\n    fwht(b,\
    \ false);\n    int n = a.size();\n    vector<T> c(n);\n    for (int i = 0; i <\
    \ n; i++) c[i] = a[i] * b[i];\n    fwht(c, true);\n    return c;\n}\n\ntemplate\
    \ <class T>\nvector<T> and_convolution(vector<T>& a, vector<T>& b) {\n    mul(a,\
    \ T(1), T(1), T(0), T(1));\n    mul(b, T(1), T(1), T(0), T(1));\n    int n = a.size();\n\
    \    vector<T> c(n);\n    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];\n  \
    \  mul(c, T(1), T(-1), T(0), T(1));\n    return c;\n}\n\ntemplate <class T>\n\
    vector<T> or_convolution(vector<T>& a, vector<T>& b) {\n    mul(a, T(1), T(0),\
    \ T(1), T(1));\n    mul(b, T(1), T(0), T(1), T(1));\n    int n = a.size();\n \
    \   vector<T> c(n);\n    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];\n   \
    \ mul(c, T(1), T(0), T(-1), T(1));\n    return c;\n}\n\n}  // namespace Kronecker\n\
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
    \        return (is);\n    }\n};\n#line 5 \"test/library_checker/bitwise_or_convolution.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nint main() {\n  \
    \  int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (int\
    \ i = 0; i < (1 << N); i++) cin >> a[i];\n    for (int i = 0; i < (1 << N); i++)\
    \ cin >> b[i];\n\n    // bitwise OR convolution\n    reverse(a.begin(), a.end());\n\
    \    reverse(b.begin(), b.end());\n    vector<mint> c = Kronecker::or_convolution(a,\
    \ b);\n    reverse(c.begin(), c.end());\n\n    for (int i = 0; i < (1 << N); i++)\
    \ {\n        cout << c[i] << \" \\n\"[i == (1 << N) - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/math/kronecker.hpp\"\n#include\
    \ \"../../src/math/modint.hpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 <<\
    \ N);\n    for (int i = 0; i < (1 << N); i++) cin >> a[i];\n    for (int i = 0;\
    \ i < (1 << N); i++) cin >> b[i];\n\n    // bitwise OR convolution\n    reverse(a.begin(),\
    \ a.end());\n    reverse(b.begin(), b.end());\n    vector<mint> c = Kronecker::or_convolution(a,\
    \ b);\n    reverse(c.begin(), c.end());\n\n    for (int i = 0; i < (1 << N); i++)\
    \ {\n        cout << c[i] << \" \\n\"[i == (1 << N) - 1];\n    }\n}\n"
  dependsOn:
  - src/math/kronecker.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/bitwise_or_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 22:24:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/bitwise_or_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/bitwise_or_convolution.test.cpp
- /verify/test/library_checker/bitwise_or_convolution.test.cpp.html
title: test/library_checker/bitwise_or_convolution.test.cpp
---
