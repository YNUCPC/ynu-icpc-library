#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0115"
#include "src/geometry/3d-geometry-template.hpp"
#include "src/geometry/3d-plane.hpp"
#include "src/geometry/3d-point-on-the-triangle.hpp"

const string Y="HIT", N = "MISS";
int main(){

  Point3d tri[3],S,G;
  cin >> S.x >> S.y >> S.z;
  cin >> G.x >> G.y >> G.z;
  for(int i=0;i<3;++i) cin >> tri[i].x >> tri[i].y >> tri[i].z;

  Plane3d plane(tri[0],tri[1],tri[2]);
  Segment3d seg(S,G);

  if( !plane.intersectS(seg) ){
    cout << Y << endl;
    return 0;
  }

  Point3d cp = plane.crosspointS(seg);

  cout << (point_on_the_triangle3d(tri[0],tri[1],tri[2],cp)?N:Y) << endl;
  return 0;
}
