---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2977.test.cpp
    title: test/aoj/2977.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/FFT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u6574\u6570\u914D\u5217\u3092\u8907\u7D20\u6570\u3078\n\nvector<complex<double>>\
    \ encode(vector<long long>& a) {\n    int N = a.size();\n    vector<complex<double>>\
    \ ret(N);\n    for (int i = 0; i < N; i++) {\n        ret[i] = complex<double>(a[i],\
    \ 0);\n    }\n    return ret;\n}\n\n// \u8907\u7D20\u6570\u914D\u5217\u3092\u6574\
    \u6570\u3078\nvector<long long> decode(vector<complex<double>>& a) {\n    int\
    \ N = a.size();\n    vector<long long> ret(N);\n    for (int i = 0; i < N; i++)\
    \ {\n        ret[i] = (long long)round(a[i].real());\n    }\n    return ret;\n\
    }\n\n// \u975E\u518D\u5E30\nvoid FFT(vector<complex<double>>& a, int reverse =\
    \ false) {\n    int n = a.size();\n    int h = 0;\n    for (int i = 0; 1 << i\
    \ < n; i++) h++;\n    for (int i = 0; i < n; i++) {\n        int j = 0;\n    \
    \    for (int k = 0; k < h; k++) j |= (i >> k & 1) << (h - 1 - k);\n        if\
    \ (i < j) swap(a[i], a[j]);\n    }\n    for (int b = 1; b < n; b *= 2) {\n   \
    \     for (int j = 0; j < b; j++) {\n            double p2 = 2 * acos(-1);\n \
    \           if (reverse) p2 *= -1;\n            complex<double> w = exp(complex<double>(0,\
    \ p2 * j / (double)(2 * b)));\n            for (int k = 0; k < n; k += b * 2)\
    \ {\n                complex<double> s = a[j + k];\n                complex<double>\
    \ t = a[j + k + b] * w;\n                a[j + k] = s + t;\n                a[j\
    \ + k + b] = s - t;\n            }\n        }\n    }\n    if (reverse)\n     \
    \   for (int i = 0; i < n; i++) a[i] /= (double)n;\n    return;\n}\n\nvector<long\
    \ long> convolution(vector<long long>& a, vector<long long>& b) {\n    vector<complex<double>>\
    \ A = encode(a), B = encode(b);\n    int s = (int)a.size() + (int)b.size() - 1;\n\
    \    int t = 1;\n    while (t < s) t *= 2;\n    A.resize(t);\n    B.resize(t);\n\
    \    FFT(A, 0);\n    FFT(B, 0);\n    for (int i = 0; i < t; i++) {\n        A[i]\
    \ *= B[i];\n    }\n    FFT(A, 1);\n    A.resize(s);\n    return decode(A);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// \u6574\
    \u6570\u914D\u5217\u3092\u8907\u7D20\u6570\u3078\n\nvector<complex<double>> encode(vector<long\
    \ long>& a) {\n    int N = a.size();\n    vector<complex<double>> ret(N);\n  \
    \  for (int i = 0; i < N; i++) {\n        ret[i] = complex<double>(a[i], 0);\n\
    \    }\n    return ret;\n}\n\n// \u8907\u7D20\u6570\u914D\u5217\u3092\u6574\u6570\
    \u3078\nvector<long long> decode(vector<complex<double>>& a) {\n    int N = a.size();\n\
    \    vector<long long> ret(N);\n    for (int i = 0; i < N; i++) {\n        ret[i]\
    \ = (long long)round(a[i].real());\n    }\n    return ret;\n}\n\n// \u975E\u518D\
    \u5E30\nvoid FFT(vector<complex<double>>& a, int reverse = false) {\n    int n\
    \ = a.size();\n    int h = 0;\n    for (int i = 0; 1 << i < n; i++) h++;\n   \
    \ for (int i = 0; i < n; i++) {\n        int j = 0;\n        for (int k = 0; k\
    \ < h; k++) j |= (i >> k & 1) << (h - 1 - k);\n        if (i < j) swap(a[i], a[j]);\n\
    \    }\n    for (int b = 1; b < n; b *= 2) {\n        for (int j = 0; j < b; j++)\
    \ {\n            double p2 = 2 * acos(-1);\n            if (reverse) p2 *= -1;\n\
    \            complex<double> w = exp(complex<double>(0, p2 * j / (double)(2 *\
    \ b)));\n            for (int k = 0; k < n; k += b * 2) {\n                complex<double>\
    \ s = a[j + k];\n                complex<double> t = a[j + k + b] * w;\n     \
    \           a[j + k] = s + t;\n                a[j + k + b] = s - t;\n       \
    \     }\n        }\n    }\n    if (reverse)\n        for (int i = 0; i < n; i++)\
    \ a[i] /= (double)n;\n    return;\n}\n\nvector<long long> convolution(vector<long\
    \ long>& a, vector<long long>& b) {\n    vector<complex<double>> A = encode(a),\
    \ B = encode(b);\n    int s = (int)a.size() + (int)b.size() - 1;\n    int t =\
    \ 1;\n    while (t < s) t *= 2;\n    A.resize(t);\n    B.resize(t);\n    FFT(A,\
    \ 0);\n    FFT(B, 0);\n    for (int i = 0; i < t; i++) {\n        A[i] *= B[i];\n\
    \    }\n    FFT(A, 1);\n    A.resize(s);\n    return decode(A);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/FFT.hpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2977.test.cpp
documentation_of: src/math/FFT.hpp
layout: document
redirect_from:
- /library/src/math/FFT.hpp
- /library/src/math/FFT.hpp.html
title: src/math/FFT.hpp
---
