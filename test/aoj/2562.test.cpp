#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2562"
#include "src/geometry/3d_geometry_template.hpp"
#include "src/geometry/3d_plane.hpp"
#include "src/geometry/3d_intersection_of_planes.hpp"

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool EGT(double x, double y) { return equals(x, y) || x > y; }
bool GT(double x, double y) { return !equals(x, y) && x > y; }
bool LT(double x, double y) { return !equals(x, y) && x < y; }
bool ELT(double x, double y) { return equals(x, y) || x < y; }

const string Y = "YES", N = "NO";

int main() {
    Point3d c[2], v[2][2];
    rep(i, 2) {
        cin >> c[i].x >> c[i].y >> c[i].z;
        rep(j, 2) cin >> v[i][j].x >> v[i][j].y >> v[i][j].z;
    }

    Plane3d plane = Plane3d(c[0], c[0] + v[0][0], c[0] + v[0][1]);
    Plane3d plane2 = Plane3d(c[1], c[1] + v[1][0], c[1] + v[1][1]);

    P3db tmp = intersectPlPl(plane, plane2);

    if (!tmp.second) {
        cout << N << endl;
        return 0;
    }

    double dist = abs(c[1] - c[0]);
    if (LT(dist, 2.0)) {
        Point3d np = plane.nearest_point(c[1]);
        dist = abs(np - c[1]);
        if (LT(dist, 1.0)) {
            Line3d line = intersectPlPl_converter(plane, plane2, tmp.first);
            Vector3d inter_vec = line.p[1] - line.p[0];
            Vector3d inter_e = inter_vec / abs(inter_vec);
            dist = distanceLP(line, c[1]);
            double len = sqrt(1.0 - dist * dist);
            Point3d mp = project(line, c[1]);
            Point3d p1 = mp + inter_e * len;
            Point3d p2 = mp + inter_e * -len;

            double dist1 = abs(c[0] - p1), dist2 = abs(c[0] - p2);
            bool res1 = LT(dist1, 1.0), res2 = LT(dist2, 1.0);
            if ((int)(res1 + res2) == 1)
                cout << Y << endl;
            else
                cout << N << endl;

        } else
            cout << N << endl;
    } else
        cout << N << endl;

    return 0;
}
