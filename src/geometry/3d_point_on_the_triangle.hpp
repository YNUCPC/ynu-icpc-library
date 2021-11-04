#pragma once

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
    // 線分上にpがあった場合、三角形内とみなす場合は以下のコメントアウトを外す
    /*
    if( on_segment3d(Segment3d(tri1,tri2),p) ) return true;
    if( on_segment3d(Segment3d(tri2,tri3),p) ) return true;
    if( on_segment3d(Segment3d(tri3,tri1),p) ) return true;
    */

    vector<Point3d> vec(3);
    vec[0] = tri1, vec[1] = tri2, vec[2] = tri3;
    double area = 0;
    {
        double a = abs(vec[0] - vec[1]), b = abs(vec[1] - vec[2]), c = abs(vec[2] - vec[0]);
        double s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double sum = 0;
    for (int i = 0; i < 3; ++i) {
        double a = abs(vec[i] - vec[(i + 1) % 3]), b = abs(vec[(i + 1) % 3] - p), c = abs(p - vec[i]);
        double s = (a + b + c) / 2;
        sum += sqrt(s * (s - a) * (s - b) * (s - c));
    }
    return equals(sum, area);
}
