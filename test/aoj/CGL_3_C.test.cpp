#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"
#include <bits/stdc++.h>
#include "2d_polygon.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    Polygon g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    int q;
    cin >> q;
    while (q--) {
        Point p;
        cin >> p;
        cout << contains(g, p) << endl;
    }
}