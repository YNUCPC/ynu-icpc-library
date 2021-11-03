#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"
#include <bits/stdc++.h>
#include "src/graph/scc.hpp"
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    scc_graph G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G.add_edge(s, t);
    }

    auto ids = G.scc_ids().second;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (int)(ids[u] == ids[v]) << '\n';
    }
}
