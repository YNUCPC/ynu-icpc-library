#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#include <bits/stdc++.h>
#include "../../src/geometry/2d_geometry_template.hpp"
#include "../../src/geometry/2d_point_and_vector.hpp"
using namespace std;

int main() {
    Line l;
    {
        Point p1, p2;
        cin >> p1 >> p2;
        l = Line(p1, p2);
    }

    int q;
    cin >> q;
    while (q--) {
        Point p;
        cin >> p;
        cout << reflection(l, p) << endl;
    }
}
