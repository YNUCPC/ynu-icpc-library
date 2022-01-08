#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"
#include <bits/stdc++.h>
#include "../../src/geometry/2d_geometry_template.hpp"
#include "../../src/geometry/2d_point_and_vector.hpp"
using namespace std;

int main() {
    Point p1, p2;
    cin >> p1 >> p2;
    int q;
    cin >> q;
    while (q--) {
        Point p;
        cin >> p;
        int a = ccw(p1, p2, p);
        string s = "";
        switch (a) {
            case +1:
                s = "COUNTER_CLOCKWISE";
                break;
            case -1:
                s = "CLOCKWISE";
                break;
            case +2:
                s = "ONLINE_BACK";
                break;
            case -2:
                s = "ONLINE_FRONT";
                break;
            case 0:
                s = "ON_SEGMENT";
                break;
        }
        cout << s << endl;
    }
}
