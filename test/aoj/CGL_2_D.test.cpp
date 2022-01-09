#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D"
#define ERROR 0.00000001
#include <bits/stdc++.h>
#include "../../src/geometry/2d_segment_and_line.hpp"
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        Segment a, b;
        {
            Point p0, p1;
            cin >> p0 >> p1;
            a = Segment(p0, p1);
            cin >> p0 >> p1;
            b = Segment(p0, p1);
        }

        cout << fixed << setprecision(20) << distance_ss(a, b) << endl;
    }
}
