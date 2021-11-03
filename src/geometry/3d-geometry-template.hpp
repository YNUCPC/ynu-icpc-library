#pragma once

#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-7)
#define equals(a,b) (fabs((a)-(b))<EPS)

class Point3d{
public:
  double x,y,z;
  
  Point3d(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
 
  Point3d operator + (const Point3d& a){
    return Point3d(x+a.x,y+a.y,z+a.z);
  }
  Point3d operator - (const Point3d& a){
    return Point3d(x-a.x,y-a.y,z-a.z);
  }
  Point3d operator * (const double& d){
    return Point3d(x*d,y*d,z*d);
  }
  Point3d operator / (const double& d){
    return Point3d(x/d,y/d,z/d);
  }
 
  bool operator < (const Point3d& p)const { return !equals(x,p.x)?x<p.x:((!equals(y,p.y))?y<p.y:(!equals(z,p.z)&&z<p.z)); }
 
  bool operator == (const Point3d& p)const{
    return equals(x,p.x) && equals(y,p.y) && equals(z,p.z);
  }
 
};
 
struct Segment3d{
  Point3d p[2];
  Segment3d(Point3d p1=Point3d(),Point3d p2=Point3d()){
    p[0] = p1, p[1] = p2;
  }
 bool operator == (const Segment3d& seg)const{
    return ( p[0] == seg.p[0] && p[1] == seg.p[1] ) || ( p[0] == seg.p[1] && p[1] == seg.p[0] );
 }
};
 
typedef Point3d Vector3d;
typedef Segment3d Line3d;
  
ostream& operator << (ostream& os,const Point3d& p){
  return os << "(" << p.x << "," << p.y << "," << p.z << ")";
}
 
ostream& operator << (ostream& os,const Segment3d& seg){
  return os << "(" << seg.p[0] << "," << seg.p[1] << ")";
}
 
double dot(const Point3d& a,const Point3d& b){
  return a.x*b.x + a.y*b.y + a.z*b.z;
}
 
Vector3d cross(const Point3d& a,const Point3d& b){
  return Vector3d(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
 
inline double norm(const Point3d &p){
  return p.x*p.x + p.y*p.y + p.z*p.z;
}
 
inline double abs(const Point3d &p){
  return sqrt(norm(p));
}
 
inline double toRad(double theta){
  return theta * M_PI / 180.0;
}
