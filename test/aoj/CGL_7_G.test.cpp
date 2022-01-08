#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"
#include <bits/stdc++.h>
#include "2d_circle.hpp"
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

    vector<Line> res = tangent_cc(c1, c2);
    vector<Point> ans;
    for (Line l : res) ans.push_back(cross_point_cl(c1, l).first);
    sort(ans.begin(), ans.end());
    for (Point p : ans) cout << p << endl;
}