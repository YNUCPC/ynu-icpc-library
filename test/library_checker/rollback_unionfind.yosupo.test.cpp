#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include <bits/stdc++.h>
#include "../../src/datastructure/rollback_unionfind.hpp"
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> ans(Q + 1, -1);
    vector<vector<array<int, 4>>> G(Q + 1);
    for (int i = 1; i <= Q; i++) {
        int t, k, u, v;
        cin >> t >> k >> u >> v;
        k++;
        G[k].push_back({t, i, u, v});
    }

    RollbackUnionFind uf(N);
    function<void(array<int, 4>, int)> dfs = [&](array<int, 4> a, int d) -> void {
        if (d) uf.rollback(d - 1);
        auto [t, i, u, v] = a;
        if (t == 1) {
            ans[i] = uf.same(u, v);
        } else {
            uf.unite(u, v);
        }
        for (auto& a : G[i]) dfs(a, d + 1);
    };
    dfs({-1, 0, -1, 0}, 0);

    for (int a : ans)
        if (a != -1) cout << a << '\n';
}
