#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H"
#define ERROR 0.00001
#include <bits/stdc++.h>
#include "../../src/geometry/2d_circle.hpp"
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    Polygon poly(n);
    for (int i = 0; i < n; i++) cin >> poly[i];
    Circle c(Point(0, 0), r);
    cout << fixed << setprecision(20) << area_poly_c(poly, c) << endl;
}
