#pragma once

// 直線 l1 と l2 は平行か？
bool isParallel(Line3d l1, Line3d l2) {
    Vector3d A = l1.p[0], B = l1.p[1], C = l2.p[0], D = l2.p[1];
    Vector3d AB = B - A, CD = D - C;
    Vector3d n1 = AB / abs(AB), n2 = CD / abs(CD);
    double tmp = dot(n1, n2);
    tmp = 1 - tmp * tmp;
    return equals(tmp, 0.0);
}

// 直線 l1 と l2 を結ぶような線分であって最も距離が短いものを返す
// Note: l1 と l2 が平行な時には使用できないので注意
Segment3d nearest_segmentLL(Line3d l1, Line3d l2) {
    assert(!isParallel(l1, l2));  // 平行な場合は使用不可
    // l1.p[0] = A, l1.p[1] = B, l2.p[0] = C, l2.p[1] = D
    Vector3d AB = l1.p[1] - l1.p[0];
    Vector3d CD = l2.p[1] - l2.p[0];
    Vector3d AC = l2.p[0] - l1.p[0];
    Vector3d n1 = AB / abs(AB), n2 = CD / abs(CD);
    double d1 = (dot(n1, AC) - dot(n1, n2) * dot(n2, AC)) / (1.0 - pow(dot(n1, n2), 2));
    double d2 = (dot(n1, n2) * dot(n1, AC) - dot(n2, AC)) / (1.0 - pow(dot(n1, n2), 2));
    return Segment3d(l1.p[0] + n1 * d1, l2.p[0] + n2 * d2);
}

// 直線 l1 と l2 は交差するか？
bool intersectLL(Line3d l1, Line3d l2) {
    Vector3d A = l1.p[0], B = l1.p[1], C = l2.p[0], D = l2.p[1];

    // そもそもl1,l2が直線じゃない
    if (equals(abs(B - A), 0.0) || equals(abs(D - C), 0.0)) {
        // この場合は注意
        // そもそも与えられた線分が線分になっていないので、交差するかどうかは判定できない
        return false;
    }

    Vector3d AB = B - A, CD = D - C;
    Vector3d n1 = AB / abs(AB), n2 = CD / abs(CD);
    double tmp = dot(n1, n2);
    tmp = 1 - tmp * tmp;

    if (equals(tmp, 0.0)) return 0;  // 直線が平行

    Segment3d ns = nearest_segmentLL(l1, l2);
    if (ns.p[0] == ns.p[1]) return true;
    return false;
}

// 線分 seg1 と seg2 は交差しているか？
bool intersectSS(Segment3d seg1, Segment3d seg2) {
    if (isParallel(seg1, seg2)) return false;
    Segment3d seg = nearest_segmentLL(seg1, seg2);
    if (!(seg.p[0] == seg.p[1])) return false;
    Point3d cp = seg.p[1];
    return on_segment3d(seg1, cp) && on_segment3d(seg2, cp);
}
