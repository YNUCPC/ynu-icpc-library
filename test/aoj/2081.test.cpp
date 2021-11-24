#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2081"
#include "../../src/geometry/3d_geometry_template.hpp"
#include "../../src/geometry/3d_lines_and_segments_libs.hpp"

using namespace std;

Line3d line[110];
Point3d source_p, sink_p;
int source, sink;
double fw[110][110];

#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)

const int IINF = INT_MAX;

int main() {
    int N;
    while (cin >> N, N) {
        cin >> source_p.x >> source_p.y >> source_p.z >> sink_p.x >> sink_p.y >> sink_p.z;

        source = sink = -1;
        rep(i, N) {
            rep(j, 2) cin >> line[i].p[j].x >> line[i].p[j].y >> line[i].p[j].z;
            if (on_line3d(line[i], source_p)) {
                assert(source == -1);
                source = i;
            }
            if (on_line3d(line[i], sink_p)) {
                assert(sink == -1);
                sink = i;
            }
        }
        assert(source != -1 && sink != -1);

        rep(i, N) rep(j, N) fw[i][j] = IINF;
        rep(i, N) REP(j, i, N) {
            if (i == j)
                fw[i][j] = 0;
            else if (isParallel(line[i], line[j])) {
                double area = abs(cross(line[i].p[1] - line[i].p[0], line[j].p[1] - line[i].p[0]));
                fw[i][j] = fw[j][i] = area / abs(line[i].p[1] - line[i].p[0]);
            } else if (!intersectLL(line[i], line[j])) {
                Segment3d seg = nearest_segmentLL(line[i], line[j]);
                fw[i][j] = fw[j][i] = abs(seg.p[1] - seg.p[0]);
            }
        }

        rep(k, N) rep(i, N) rep(j, N) if (!equals(fw[i][k], IINF) && !equals(fw[k][j], IINF)) fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
        printf("%.5f\n", fw[source][sink]);
    }
    return 0;
}
