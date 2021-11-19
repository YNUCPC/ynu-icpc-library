#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Kronecker {
    template <class T>
    static void mul(vector<T>& x, T a, T b, T c, T d) {
        for (int j = 1; j < (int)x.size(); j <<= 1) {
            for (int i = 0; i < (int)x.size(); i++) {
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
    static void fwht(vector<T>& a, bool inv) {
        mul(a, T(1), T(1), T(1), T(-1));
        if (inv) for (T& x : a) x /= T(a.size());
    }

    template <class T>
    static vector<T> xor_convolution(vector<T>& a, vector<T>& b) {
        fwht(a, false);
        fwht(b, false);
        vector<T> c;
        for (int i = 0; i < (int)a.size(); i++) c.push_back(a[i] * b[i]);
        fwht(c, true);
        return c;
    }

    template <class T>
    static vector<T> and_convolution(vector<T>& a, vector<T>& b) {
        mul(a, T(1), T(1), T(0), T(1));
        mul(b, T(1), T(1), T(0), T(1));
        vector<T> c;
        for (int i = 0; i < (int)a.size(); i++) c.push_back(a[i] * b[i]);
        mul(c, T(1), T(-1), T(0), T(1));
        return c;
    }

    template <class T>
    static vector<T> or_convolution(vector<T>& a, vector<T>& b) {
        mul(a, T(1), T(0), T(1), T(1));
        mul(b, T(1), T(0), T(1), T(1));
        vector<T> c;
        for (int i = 0; i < (int)a.size(); i++) c.push_back(a[i] * b[i]);
        mul(c, T(1), T(0), T(-1), T(1));
        return c;
    }
};