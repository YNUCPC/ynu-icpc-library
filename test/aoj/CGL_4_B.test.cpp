#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#define ERROR 0.000001
#include <bits/stdc++.h>
#include "../../src/geometry/2d_polygon.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    Polygon g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    cout << fixed << setprecision(20) << convex_diameter(g) << endl;
}
