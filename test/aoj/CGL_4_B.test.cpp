#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#include <bits/stdc++.h>
#include "2d_polygon.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    Polygon g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    cout << fixed << setprecision(20) << convex_diameter(g) << endl;
}