#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"
#include <bits/stdc++.h>
#include "../../src/geometry/2d_circle.hpp"
using namespace std;

int main() {
    Circle c;
    {
        Point p;
        Real r;
        cin >> p >> r;
        c = Circle(p, r);
    }

    int q;
    cin >> q;
    while (q--) {
        Line l;
        {
            Point a, b;
            cin >> a >> b;
            l = Line(a, b);
        }
        pair<Point, Point> res = cross_point_cl(c, l);
        if (res.second < res.first) swap(res.first, res.second);
        cout << res.first << " " << res.second << endl;
    }
}
