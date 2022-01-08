#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C"
#include <bits/stdc++.h>
#include "../../src/geometry/2d_polygon.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    Polygon g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    int q;
    cin >> q;
    while (q--) {
        Line l;
        {
            Point a, b;
            cin >> a >> b;
            l = Line(a, b);
        }
        cout << fixed << setprecision(20) << area(convex_cut(g, l)) << endl;
    }
}
