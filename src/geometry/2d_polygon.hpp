#pragma once
#include "2d_geometry_template.hpp"
#include "2d_point_and_vector.hpp"
#include "2d_segment_and_line.hpp"

Real area(const Polygon& p) {
    Real S = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        S += cross(p[i], p[(i + 1) % n]);
    }
    return S * 0.5;
}

bool is_convex(const Polygon& p) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (ccw(p[(i - 1 + n) % n], p[i], p[(i + 1) % n]) == -1) return false;
    }
    return true;
}

int contains(const Polygon& Q, const Point& p) {
    int n = Q.size();
    bool in = false;
    for (int i = 0; i < n; i++) {
        Point a = Q[i] - p, b = Q[(i + 1) % n] - p;
        if (sign(a.imag() - b.imag()) == +1) swap(a, b);
        if (sign(a.imag()) <= 0 && sign(b.imag()) == +1 && sign(cross(a, b)) == -1) in = !in;
        if (sign(cross(a, b)) == 0 && sign(dot(a, b)) <= 0) return 1;
    }
    return in ? 2 : 0;
}

Polygon convex_hull(Polygon p) {
    int n = p.size(), k = 0;
    if (n <= 2) return p;
    sort(p.begin(), p.end());
    Polygon ch(2 * n);
    for (int i = 0; i < n; ch[k++] = p[i++]) {
        while (k >= 2 && sign(cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])) == -1) --k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
        while (k >= t && sign(cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])) == -1) --k;
    }
    ch.resize(k - 1);
    return ch;
}

Real convex_diameter(const Polygon& p) {
    int n = p.size(), is = 0, js = 0;
    for (int i = 1; i < n; i++) {
        if (sign(p[i].imag() - p[is].imag()) == +1) is = i;
        if (sign(p[i].imag() - p[js].imag()) == -1) js = i;
    }
    Real maxdis = norm(p[is] - p[js]);
    int maxi, maxj, i, j;
    i = maxi = is;
    j = maxj = js;
    do {
        if (sign(cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j])) >= 0) {
            j = (j + 1) % n;
        } else {
            i = (i + 1) % n;
        }
        if (norm(p[i] - p[j]) > maxdis) {
            maxdis = norm(p[i] - p[j]);
            maxi = i;
            maxj = j;
        }
    } while (i != is || j != js);
    return sqrt(maxdis);
}

Polygon convex_cut(const Polygon& p, const Line& l) {
    int n = p.size();
    Polygon ret;
    for (int i = 0; i < n; i++) {
        Point now = p[i], nxt = p[(i + 1) % n];
        if (ccw(l.a, l.b, now) != -1) ret.push_back(now);
        if (ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) {
            ret.push_back(cross_point_ll(Line(now, nxt), l));
        }
    }
    return ret;
}