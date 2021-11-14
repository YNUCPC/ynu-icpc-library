#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<T> subset_zeta(vector<T> f, int n, bool inv = false) {
    for (int i = 0; i < n; i++) {
        for (int S = 0; S < (1 << n); S++) {
            if ((S & (1 << i)) != 0) {  // if i in S
                if (!inv) {
                    f[S] += f[S ^ (1 << i)];
                } else {
                    f[S] -= f[S ^ (1 << i)];
                }
            }
        }
    }
    return f;
}

template <class T>
vector<T> supset_zeta(vector<T> f, int n, bool inv = false) {
    for (int i = 0; i < n; i++) {
        for (int S = 0; S < (1 << n); S++) {
            if ((S & (1 << i)) == 0) {  // if i not in S
                if (!inv) {
                    f[S] += f[S ^ (1 << i)];
                } else {
                    f[S] -= f[S ^ (1 << i)];
                }
            }
        }
    }
    return f;
}
