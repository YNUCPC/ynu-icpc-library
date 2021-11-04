#pragma once

class Plane3d {
  public:
    Point3d normal_vector;  // 法線ベクトル
    double d;               // 平面方程式 normal_vector = (a,b,c), a*x + b*y + c*z + d = 0

    Plane3d(Point3d normal_vector = Point3d(), double d = 0) : normal_vector(normal_vector), d(d) {}
    Plane3d(Vector3d a, Vector3d b, Vector3d c) {
        Vector3d v1 = b - a;
        Vector3d v2 = c - a;
        Vector3d tmp = cross(v1, v2);
        normal_vector = tmp / abs(tmp);
        set_d(a);
    }

    // 法線ベクトルnormal_vectorと平面上の１点からdを計算する
    void set_d(Point3d p) {
        d = dot(normal_vector, p);
    }

    // 平面と点pの距離を求める
    double distanceP(Point3d p) {
        Point3d a = normal_vector * d;  // 平面上の適当な点をつくる
        return abs(dot(p - a, normal_vector));
    }

    // 平面上でもっとも点pと近い点を求める
    Point3d nearest_point(Point3d p) {
        Point3d a = normal_vector * d;
        return p - (normal_vector * dot(p - a, normal_vector));
    }

    // 平面と線分が交差するか
    bool intersectS(Segment3d seg) {
        Point3d a = normal_vector * d;
        double res1 = dot(a - seg.p[0], normal_vector);
        double res2 = dot(a - seg.p[1], normal_vector);
        if (res1 > res2) swap(res1, res2);
        if ((equals(res1, 0.0) || res1 < 0) && (equals(res2, 0.0) || res2 > 0)) return true;
        return false;
    }

    // 平面と線分の交点を求める
    Point3d crosspointS(Segment3d seg) {
        Point3d a = normal_vector * d;
        double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));
        double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));
        if (equals(dot_p0a + dot_p1a, 0)) return seg.p[0];
        return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
    }
};
