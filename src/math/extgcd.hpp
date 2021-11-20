#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
T extgcd(T a, T b, T& x, T& y) {
    if (b > 0) {
        T d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    } else {
        x = 1;
        y = 0;
        return a;
    }
}
