#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"
#include <bits/stdc++.h>
#include "2d_polygon.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    Polygon g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    g = convex_hull(g);
    n = g.size();

    int id = 0;
    for (int i = 1; i < n; i++) {
        if (g[id].imag() > g[i].imag() || (g[id].imag() == g[i].imag() && g[id].real() > g[i].real())) id = i;
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        Point p = g[(id + i) % n];
        cout << (int)p.real() << " " << (int)p.imag() << endl;
    }
}