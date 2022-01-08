#pragma once
#include "2d_geometry_template.hpp"
#include "2d_point_and_vector.hpp"

bool is_orthogonal(const Line& a, const Line& b) {
    return equals(dot(a.b - a.a, b.b - b.a), 0);
}

bool is_parallel(const Line& a, const Line& b) {
    return equals(cross(a.b - a.a, b.b - b.a), 0);
}

bool is_intersect_ss(const Segment& s, const Segment& t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
           ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Point cross_point_ll(const Line& l, const Line& m) {
    Real A = cross(l.b - l.a, m.b - m.a);
    Real B = cross(l.b - l.a, l.b - m.a);
    if (equals(abs(A), 0) && equals(abs(B), 0)) return m.a;
    return m.a + (m.b - m.a) * B / A;
}

Real distance_sp(const Segment& s, const Point& p) {
    Point r = projection(s, p);
    if (ccw(s.a, s.b, r) == 0) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}

Real distance_ss(const Segment& a, const Segment& b) {
    if (is_intersect_ss(a, b)) return 0;
    return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b, a.a), distance_sp(b, a.b)});
}
