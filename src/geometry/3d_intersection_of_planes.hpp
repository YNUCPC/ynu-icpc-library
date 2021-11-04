#pragma once

using P3db = pair<Point3d, bool>;

/* 
[*] Input:
    ２つの平面 pl1, pl2
[*] Output:
    ２つの平面が交線をもつ場合 -> first:交線上の任意の１点, second:true
　　 　　　 交線を持たない場合 -> first:empty           , second:false
 */
P3db intersectPlPl(const Plane3d &pl1,const Plane3d &pl2){
  Vector3d v = cross(pl1.normal_vector,pl2.normal_vector);
  if( !equals(v.x,0.0) ){
    Point3d p(0,
              (pl1.d*pl2.normal_vector.z-pl2.d*pl1.normal_vector.z)/v.x,
              (pl1.d*pl2.normal_vector.y-pl2.d*pl1.normal_vector.y)/(-v.x));
    return P3db(p, true);
  }
  if( !equals(v.y,0.0) ){
    Point3d p((pl1.d*pl2.normal_vector.z-pl2.d*pl1.normal_vector.z)/(-v.y),
              0,
              (pl1.d*pl2.normal_vector.x-pl2.d*pl1.normal_vector.x)/v.y);
    return P3db(p,true);
  }
  if( !equals(v.z,0.0) ){
    Point3d p((pl1.d*pl2.normal_vector.y-pl2.d*pl1.normal_vector.y)/v.z,
              (pl1.d*pl2.normal_vector.x-pl2.d*pl1.normal_vector.x)/(-v.z),
              0);
    return P3db(p,true);
  }
  return P3db(Point3d(),false);//平行なのでそのような交線は存在しない
}

/* 
[*] Input:
    ２つの平面 plane, plane2 とその交線上の任意の１点
[*] Output:
    ２つの平面の交線

説明:
2つの平面の外積から交線の方向ベクトルを得る
あとは任意の１点に拡張した方向ベクトルを加えてセグメント化する
交線上の任意の１点はintersectPlPlで取得できる
面倒な仕様になってしまった
*/
Line3d intersectPlPl_converter(Plane3d plane,Plane3d plane2,Point3d tmp){
  Vector3d ve = cross(plane.normal_vector,plane2.normal_vector);
  return Line3d(tmp,tmp+(ve*10)); // 任意の倍数で拡張、ここでは10
}
