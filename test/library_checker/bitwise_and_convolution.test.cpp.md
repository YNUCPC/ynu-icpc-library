---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  - icon: ':x:'
    path: src/math/subset_zeta.hpp
    title: src/math/subset_zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/library_checker/bitwise_and_convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #include <bits/stdc++.h>\n#line 3 \"src/math/subset_zeta.hpp\"\nusing namespace\
    \ std;\n\ntemplate <class T>\nvector<T> subset_zeta(vector<T> f, int n, bool inv\
    \ = false) {\n    for (int i = 0; i < n; i++) {\n        for (int S = 0; S < (1\
    \ << n); S++) {\n            if ((S & (1 << i)) != 0) {  // if i in S\n      \
    \          if (!inv) {\n                    f[S] += f[S ^ (1 << i)];\n       \
    \         } else {\n                    f[S] -= f[S ^ (1 << i)];\n           \
    \     }\n            }\n        }\n    }\n    return f;\n}\n\ntemplate <class\
    \ T>\nvector<T> supset_zeta(vector<T> f, int n, bool inv = false) {\n    for (int\
    \ i = 0; i < n; i++) {\n        for (int S = 0; S < (1 << n); S++) {\n       \
    \     if ((S & (1 << i)) == 0) {  // if i not in S\n                if (!inv)\
    \ {\n                    f[S] += f[S ^ (1 << i)];\n                } else {\n\
    \                    f[S] -= f[S ^ (1 << i)];\n                }\n           \
    \ }\n        }\n    }\n    return f;\n}\n#line 3 \"src/math/modint.hpp\"\nusing\
    \ namespace std;\n\ntemplate <int64_t Modulus>\nstruct Modint {\n    using mint\
    \ = Modint;\n    long long v;\n    Modint() : v(0) {}\n    Modint(long long x)\
    \ {\n        x %= Modulus;\n        if (x < 0) x += Modulus;\n        v = x;\n\
    \    }\n    const long long& val() const { return v; }\n    // \u4EE3\u5165\u6F14\
    \u7B97\u5B50\n    mint& operator+=(const mint rhs) {\n        v += rhs.v;\n  \
    \      if (v >= Modulus) v -= Modulus;\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint rhs) {\n        if (v < rhs.v) v += Modulus;\n       \
    \ v -= rhs.v;\n        return *this;\n    }\n    mint& operator*=(const mint rhs)\
    \ {\n        v = v * rhs.v % Modulus;\n        return *this;\n    }\n    mint&\
    \ operator/=(mint rhs) { return *this = *this * rhs.inv(); }\n    // \u7D2F\u4E57\
    , \u9006\u5143\n    mint pow(long long n) const {\n        mint x = *this, res\
    \ = 1;\n        while (n) {\n            if (n & 1) res *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return res;\n    }\n    mint inv()\
    \ const { return pow(Modulus - 2); }\n    // \u7B97\u8853\u6F14\u7B97\u5B50\n\
    \    mint operator+(const mint rhs) const { return mint(*this) += rhs; }\n   \
    \ mint operator-(const mint rhs) const { return mint(*this) -= rhs; }\n    mint\
    \ operator*(const mint rhs) const { return mint(*this) *= rhs; }\n    mint operator/(const\
    \ mint rhs) const { return mint(*this) /= rhs; }\n    mint operator-() const {\
    \ return mint() - *this; }  // \u5358\u9805\n    // \u5165\u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\n    friend ostream& operator<<(ostream& os, const mint& p)\
    \ { return os << p.v; }\n    friend istream& operator>>(istream& is, mint& p)\
    \ {\n        long long t;\n        is >> t;\n        p = mint(t);\n        return\
    \ (is);\n    }\n};\n#line 5 \"test/library_checker/bitwise_and_convolution.test.cpp\"\
    \nusing namespace std;\n\nusing ll = long long;\nconstexpr ll MOD = 998244353;\n\
    using mint = Modint<MOD>;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<mint> a(1 << n), b(1 << n);\n    for (int\
    \ i = 0; i < 1 << n; i++) {\n        cin >> a[i];\n    }\n    for (int i = 0;\
    \ i < 1 << n; i++) {\n        cin >> b[i];\n    }\n    // \u30BC\u30FC\u30BF\u5909\
    \u63DB\n    vector<mint> A = supset_zeta(a, n, false), B = supset_zeta(b, n, false);\n\
    \    // AND\u7573\u307F\u8FBC\u307F\n    vector<mint> C(1 << n);\n    for (int\
    \ S = 0; S < 1 << n; S++) {\n        C[S] = A[S] * B[S];\n    }\n    // \u30E1\
    \u30D3\u30A6\u30B9\u5909\u63DB\n    vector<mint> c = supset_zeta(C, n, true);\n\
    \n    for (int i = 0; i < 1 << n; i++) {\n        cout << c[i] << \" \\n\"[i ==\
    \ (1 << n) - 1];\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/math/subset_zeta.hpp\"\n#include\
    \ \"../../src/math/modint.hpp\"\nusing namespace std;\n\nusing ll = long long;\n\
    constexpr ll MOD = 998244353;\nusing mint = Modint<MOD>;\n\nint main() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    int n;\n    cin >>\
    \ n;\n    vector<mint> a(1 << n), b(1 << n);\n    for (int i = 0; i < 1 << n;\
    \ i++) {\n        cin >> a[i];\n    }\n    for (int i = 0; i < 1 << n; i++) {\n\
    \        cin >> b[i];\n    }\n    // \u30BC\u30FC\u30BF\u5909\u63DB\n    vector<mint>\
    \ A = supset_zeta(a, n, false), B = supset_zeta(b, n, false);\n    // AND\u7573\
    \u307F\u8FBC\u307F\n    vector<mint> C(1 << n);\n    for (int S = 0; S < 1 <<\
    \ n; S++) {\n        C[S] = A[S] * B[S];\n    }\n    // \u30E1\u30D3\u30A6\u30B9\
    \u5909\u63DB\n    vector<mint> c = supset_zeta(C, n, true);\n\n    for (int i\
    \ = 0; i < 1 << n; i++) {\n        cout << c[i] << \" \\n\"[i == (1 << n) - 1];\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - src/math/subset_zeta.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/bitwise_and_convolution.test.cpp
- /verify/test/library_checker/bitwise_and_convolution.test.cpp.html
title: test/library_checker/bitwise_and_convolution.test.cpp
---
