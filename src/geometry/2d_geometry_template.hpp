#pragma once
#include <bits/stdc++.h>
using namespace std;

using Real = double;
using Point = complex<Real>;
using Polygon = vector<Point>;
const Real EPS = 1e-8, PI = acos(-1);

Point operator*(const Point& p, const Real& d) {
    return Point(p.real() * d, p.imag() * d);
}

Point operator/(const Point& p, const Real& d) {
    return Point(p.real() / d, p.imag() / d);
}

istream& operator>>(istream& is, Point& p) {
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}

ostream& operator<<(ostream& os, const Point& p) {
    return os << fixed << setprecision(20) << p.real() << " " << p.imag();
}

int sign(const Real& r) {
    if (r <= -EPS) return -1;
    if (r >= +EPS) return +1;
    return 0;
}

bool equals(const Real& a, const Real& b) {
    return sign(a - b) == 0;
}

namespace std {
bool operator<(const Point& a, const Point& b) {
    if (equals(a.real(), b.real())) return a.imag() < b.imag();
    return a.real() < b.real();
}
}

Real dot(const Point& a, const Point& b) {
    return (conj(a) * b).real();
}

Real cross(const Point& a, const Point& b) {
    return (conj(a) * b).imag();
}

struct Line {
    Point a, b;
    Line() = default;
    Line(Point a, Point b) : a(a), b(b) {}
};
using Segment = Line;
