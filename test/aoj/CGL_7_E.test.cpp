#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR 0.000001
#include <bits/stdc++.h>
#include "../../src/geometry/2d_circle.hpp"
using namespace std;

int main() {
    Circle c1, c2;
    {
        Point p;
        Real r;
        cin >> p >> r;
        c1 = Circle(p, r);
        cin >> p >> r;
        c2 = Circle(p, r);
    }

    pair<Point, Point> res = cross_point_cc(c1, c2);
    if (res.second < res.first) swap(res.first, res.second);
    cout << res.first << " " << res.second << endl;
}
