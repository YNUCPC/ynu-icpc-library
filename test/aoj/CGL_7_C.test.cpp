#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"
#define ERROR 0.000001
#include <bits/stdc++.h>
#include "../../src/geometry/2d_circle.hpp"
using namespace std;

int main() {
    Point a, b, c;
    cin >> a >> b >> c;
    Circle ans = circumscribed_circle(a, b, c);
    cout << ans.p << " " << fixed << setprecision(20) << ans.r << endl;
}
