#pragma once
#include "2d_geometry_template.hpp"
#include "2d_segment_and_line.hpp"

struct Circle {
    Point p;
    Real r;
    Circle() = default;
    Circle(Point p, Real r) : p(p), r(r) {}
};

int intersection_cc(Circle c1, Circle c2) {
    if (c1.r < c2.r) swap(c1, c2);
    Real d = abs(c1.p - c2.p);
    if (sign(c1.r + c2.r - d) == -1) return 4;
    if (equals(c1.r + c2.r, d)) return 3;
    if (sign(c1.r - c2.r - d) == -1) return 2;
    if (equals(c1.r - c2.r, d)) return 1;
    return 0;
}

Circle incircle(const Point& a, const Point& b, const Point& c) {
    Real A = abs(b - c), B = abs(c - a), C = abs(a - b);
    Point x = Point((a * A + b * B + c * C) / (A + B + C));
    Real r = distance_sp(Segment(a, b), x);
    return Circle(x, r);
}

Circle circumscribed_circle(const Point& a, const Point& b, const Point& c) {
    Point m1((a + b) / 2.0), m2((b + c) / 2.0);
    Point v((b - a).imag(), (a - b).real()), w((b - c).imag(), (c - b).real());
    Line s(m1, Point(m1 + v)), t(m2, Point(m2 + w));
    Point x = cross_point_ll(s, t);
    return Circle(x, abs(a - x));
}

pair<Point, Point> cross_point_cl(const Circle& c, const Line& l) {
    Point pr = projection(l, c.p);
    if (equals(abs(pr - c.p), c.r)) return {pr, pr};
    Point e = (l.b - l.a) / abs(l.b - l.a);
    Real k = sqrt(norm(c.r) - norm(pr - c.p));
    return {pr - e * k, pr + e * k};
}

pair<Point, Point> cross_point_cc(const Circle& c1, const Circle& c2) {
    Real d = abs(c1.p - c2.p);
    Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    Point p1 = c1.p + Point(cos(t + a), sin(t + a)) * c1.r;
    Point p2 = c1.p + Point(cos(t - a), sin(t - a)) * c1.r;
    return {p1, p2};
}

pair<Point, Point> tangent_cp(const Circle& c, const Point& p) {
    return cross_point_cc(c, Circle(p, sqrt(norm(c.p - p) - c.r * c.r)));
}

vector<Line> tangent_cc(Circle c1, Circle c2) {
    vector<Line> ret;
    if (c1.r < c2.r) swap(c1, c2);
    Real g = norm(c1.p - c2.p);
    if (equals(g, 0.0)) return ret;
    Point u = (c2.p - c1.p) / sqrt(g);
    Point v = u * Point(cos(PI * 0.5), sin(PI * 0.5));
    for (int s : {-1, 1}) {
        Real h = (c1.r + s * c2.r) / sqrt(g);
        if (equals(1 - h * h, 0.0)) {
            ret.emplace_back(c1.p + u * c1.r, c1.p + (u + v) * c1.r);
        } else if (sign(1 - h * h) == +1) {
            Point uu = u * h, vv = v * sqrt(1 - h * h);
            ret.emplace_back(c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);
            ret.emplace_back(c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);
        }
    }
    return ret;
}

Real area_poly_c(const Polygon& p, const Circle& c) {
    int n = p.size();
    if (n < 3) return 0.0;
    function<Real(Circle, Point, Point)> cross_area = [&](const Circle& c, const Point& a, const Point& b) {
        Point va = c.p - a, vb = c.p - b;
        Real f = cross(va, vb), ret = 0.0;
        if (equals(f, 0.0)) return ret;
        if (max(abs(va), abs(vb)) < c.r + EPS) return f;
        if (distance_sp(Segment(a, b), c.p) > c.r - EPS) return c.r * c.r * arg(vb * conj(va));
        auto u = cross_point_cl(c, Segment(a, b));
        vector<Point> tot{a, u.first, u.second, b};
        for (int i = 0; i + 1 < (int)tot.size(); i++) {
            ret += cross_area(c, tot[i], tot[i + 1]);
        }
        return ret;
    };
    Real S = 0;
    for (int i = 0; i < n; i++) {
        S += cross_area(c, p[i], p[(i + 1) % n]);
    }
    return S * 0.5;
}

Real area_cc(const Circle& c1, const Circle& c2) {
    Real d = abs(c1.p - c2.p);
    if (c1.r + c2.r <= d + EPS) return 0.0;
    if (d <= fabs(c1.r - c2.r) + EPS) {
        Real r = min(c1.r, c2.r);
        return r * r * PI;
    }
    Real rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
    Real theta = acos(rc / c1.r);
    Real phi = acos((d - rc) / c2.r);
    return c1.r * c1.r * theta + c2.r * c2.r * phi - d * c1.r * sin(theta);
}
