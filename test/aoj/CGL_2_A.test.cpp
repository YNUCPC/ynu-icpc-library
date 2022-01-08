#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"
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
        if (is_parallel(a, b)) {
            cout << 2 << endl;
        } else if (is_orthogonal(a, b)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
