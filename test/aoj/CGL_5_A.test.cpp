#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A"
#include <bits/stdc++.h>
#include "../../src/geometry/2d_set.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    Polygon ps(n);
    for (int i = 0; i < n; i++) cin >> ps[i];
    cout << fixed << setprecision(20) << closest_pair(ps) << endl;
}
