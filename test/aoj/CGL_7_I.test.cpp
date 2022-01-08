#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I"
#include <bits/stdc++.h>
#include "../../src/geometry/2d_circle.hpp"
using namespace std;

int main() {
    Circle c1, c2;
    {
        Point p; Real r;
        cin >> p >> r;
        c1 = Circle(p, r);
        cin >> p >> r;
        c2 = Circle(p, r);
    }

    cout << fixed << setprecision(20) << area_cc(c1, c2) << endl;
}
