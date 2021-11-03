#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"
#include <bits/stdc++.h>
#include "src/graph/lca.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            G[i].push_back(c);
            G[c].push_back(i);
        }
    }

    LCA lca(G, 0);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << '\n';
    }
}
