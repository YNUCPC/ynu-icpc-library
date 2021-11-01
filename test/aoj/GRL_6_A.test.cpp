#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include <bits/stdc++.h>
#include "src/flow/dinic.hpp"
using namespace std;

int main() {
    int V, E, u, v, c;
    cin >> V >> E;
    Dinic flow(V);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }
    cout << flow.max_flow(0, V - 1) << endl;
}
