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
 
  bool operator < (const Point3d& p)const {
    if(!equals(x, p.x)) return x < p.x;
    if(!equals(y, p.y)) return y < p.y;
    if(!equals(z, p.z)) return z < p.z;
    return false;
  }
 
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
 
using Line3d = Segment3d;
using Vector3d = Point3d;
  
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

double distanceLP(Line3d line,Point3d p){
  return abs(cross(line.p[1]-line.p[0],p-line.p[0])) / abs(line.p[1]-line.p[0]);
}
 
Point3d project(Segment3d seg,Point3d p){
  Vector3d base = seg.p[1] - seg.p[0];
  double t = dot(p-seg.p[0],base) / norm(base);
  return seg.p[0] + base * t;
}
 
Point3d reflect(Segment3d seg,Point3d p){
  return p + (project(seg,p)-p) * 2.0;
}

bool on_line3d(Line3d line,Point3d p){
  return equals(abs(cross(line.p[1]-p,line.p[0]-p)),0);
}
 
bool on_segment3d(Segment3d seg,Point3d p){
  if( !on_line3d(seg,p) ) return false;
  double dist[3] = { abs(seg.p[1]-seg.p[0]), abs(p-seg.p[0]), abs(p-seg.p[1]) };  
  return on_line3d(seg,p) && equals(dist[0],dist[1]+dist[2]);
}

double distanceSP(Segment3d seg,Point3d p){
  Point3d r = project(seg,p);
  if( on_segment3d(seg,r) ) return abs(p-r);
  return min(abs(seg.p[0]-p),abs(seg.p[1]-p));
}
