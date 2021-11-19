#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace Kronecker {

template <class T>
void mul(vector<T>& x, T a, T b, T c, T d) {
    int n = x.size();
    for (int j = 1; j < n; j <<= 1) {
        for (int i = 0; i < n; i++) {
            if ((i & j) == 0) {
                T s = a * x[i] + b * x[i + j];
                T t = c * x[i] + d * x[i + j];
                x[i] = s;
                x[i + j] = t;
            }
        }
    }
}

template <class T>
void fwht(vector<T>& a, bool inv) {
    mul(a, T(1), T(1), T(1), T(-1));
    if (inv) {
        for (T& x : a) x /= T(a.size());
    }
}

template <class T>
vector<T> xor_convolution(vector<T>& a, vector<T>& b) {
    fwht(a, false);
    fwht(b, false);
    int n = a.size();
    vector<T> c(n);
    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
    fwht(c, true);
    return c;
}

template <class T>
vector<T> and_convolution(vector<T>& a, vector<T>& b) {
    mul(a, T(1), T(1), T(0), T(1));
    mul(b, T(1), T(1), T(0), T(1));
    int n = a.size();
    vector<T> c(n);
    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
    mul(c, T(1), T(-1), T(0), T(1));
    return c;
}

template <class T>
vector<T> or_convolution(vector<T>& a, vector<T>& b) {
    mul(a, T(1), T(0), T(1), T(1));
    mul(b, T(1), T(0), T(1), T(1));
    int n = a.size();
    vector<T> c(n);
    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
    mul(c, T(1), T(0), T(-1), T(1));
    return c;
}

}  // namespace Kronecker
