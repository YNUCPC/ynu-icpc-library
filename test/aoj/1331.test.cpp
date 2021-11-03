#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1331"
#include <bits/stdc++.h>
#include "src/geometry/3d-geometry-template.hpp"
using namespace std;

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)


bool LT(double x, double y){ return !equals(x,y) && x < y; }
bool LTE(double x, double y){ return equals(x,y) || x < y; }

class Point3DwithWeight {
public:
  Point3d p;
  double weight;
};

const int MAX_N = 2100;
const int MAX_M = 20;
int N,M,R;
bitset<2100> remove_cost[MAX_M];
Point3DwithWeight S[MAX_N],T[MAX_M];
Point3DwithWeight E;

int getType(double a,double b){
  if( LT(a,b) ) return -1;
  return 1;
}

void init(){
  rep(i,M) remove_cost[i] = 0; 
  rep(i,M) {
    rep(j,N){
      int type[2] = { getType(abs(E.p-S[j].p),S[j].weight), getType(abs(T[i].p-S[j].p),S[j].weight) };
      if( type[0] == type[1] && type[0] == -1 ) continue;
      double dist = distanceSP(Segment3d(E.p,T[i].p),S[j].p);
      if( LTE(dist,S[j].weight) ) remove_cost[i][j] = 1;
    }
  }
}

#define pow2(a) ((a)*(a))
void compute(){
  init();
  double maxi = 0;
  rep(bitmask,(1<<M)){
    bitset<2100> BIT(0);
    rep(i,M) if( (bitmask>>i) & 1 ) BIT |= remove_cost[i];
    if( BIT.count() <= R ) {
      double cost = 0;
      rep(i,M) if( (bitmask>>i) & 1 ) cost += T[i].weight / ( pow2(T[i].p.x-E.p.x) + pow2(T[i].p.y-E.p.y) + pow2(T[i].p.z-E.p.z) );
      maxi = max(maxi,cost);
    }
  }
  printf("%.5lf\n",maxi);
}

int main(){
  while( cin >> N >> M >> R, N|M|R ){
    assert( N <= 2000);
    rep(i,N) cin >> S[i].p.x >> S[i].p.y >> S[i].p.z >> S[i].weight;
    rep(i,M) cin >> T[i].p.x >> T[i].p.y >> T[i].p.z >> T[i].weight;
    cin >> E.p.x >> E.p.y >> E.p.z;
    compute();
  }
  return 0;
}
