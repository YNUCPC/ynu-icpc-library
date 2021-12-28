#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T> struct FenwickTree {
    int n;
    vector<T> data;
    FenwickTree() : n(0) {}
    FenwickTree(int n) : n(n), data(n, 0) {}

    // a[i] += x
    void add(int i, T x) {
        for (int p = i + 1; p <= n; p += p & -p) data[p - 1] += x;
    }
    // [0, r)
    T sum(int r) {
        T s(0);
        for (int p = r; p > 0; p -= p & -p) s += data[p - 1];
        return s;
    }
    // [l, r)
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};
