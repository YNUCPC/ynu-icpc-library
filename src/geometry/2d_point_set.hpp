#pragma once
#include "2d_geometry_template.hpp"

Real closest_pair(Polygon ps) {
    sort(ps.begin(), ps.end());
    Polygon a(ps.size());

    function<Real(int, int)> rec = [&](int left, int right) -> Real {
        if (right - left <= 1) return 1e18;
        int mid = (left + right) / 2;
        Real x = ps[mid].real();
        Real ret = min(rec(left, mid), rec(mid, right));
        inplace_merge(ps.begin() + left, ps.begin() + mid, ps.begin() + right,
                      [&](const Point& a, const Point& b) { return a.imag() < b.imag(); });
        int pos = 0;
        for (int i = left; i < right; i++) {
            if (fabs((ps[i].real()) - x) >= ret) continue;
            for (int j = 0; j < pos; j++) {
                auto tar = ps[i] - a[pos - j - 1];
                if (tar.imag() >= ret) break;
                ret = min(ret, abs(tar));
            }
            a[pos++] = ps[i];
        }
        return ret;
    };
    return rec(0, (int)ps.size());
}
