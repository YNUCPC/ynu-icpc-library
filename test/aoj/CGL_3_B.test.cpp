#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B"
#include <bits/stdc++.h>
#include "../../src/geometry/2d_polygon.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    Polygon p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << is_convex(p) << endl;
}
