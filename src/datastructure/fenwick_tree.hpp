#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T> struct FenwickTree {
    int n;
    vector<T> data;
    FenwickTree(int n_) : n(n_ + 1), data(n, 0) {}

    // a[i] += x
    void add(int i, T x) {
        for (int p = i + 1; p <= n; p += p & -p) data[p] += x;
    }

    // [0, r)
    T sum(int r) {
        T s(0);
        for (int p = r + 0; p >= 1; p -= p & -p) s += data[p];
        return s;
    }

    // [l, r)
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};