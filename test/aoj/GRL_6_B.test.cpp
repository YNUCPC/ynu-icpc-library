#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include <bits/stdc++.h>
#include "src/flow/mincostflow.hpp"
using namespace std;

int main() {
    int V, E, u, v, c, d;
    long long F;
    cin >> V >> E >> F;
    MinCostFlow mcf(V);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> c >> d;
        mcf.add_edge(u, v, c, d);
    }
    cout << mcf.min_cost_flow(0, V - 1, F) << endl;
    return 0;
}
