#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR 0.00001
#include <bits/stdc++.h>
#include "../../src/geometry/2d_circle.hpp"
using namespace std;

int main() {
    Point p;
    cin >> p;
    Circle c;
    {
        Point p;
        Real r;
        cin >> p >> r;
        c = Circle(p, r);
    }

    pair<Point, Point> res = tangent_cp(c, p);
    if (res.second < res.first) swap(res.first, res.second);
    cout << res.first << endl;
    cout << res.second << endl;
}
