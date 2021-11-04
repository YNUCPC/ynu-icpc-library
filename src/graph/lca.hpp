#pragma once
#include <bits/stdc++.h>
using namespace std;

struct LCA {
    vector<vector<int>> parent;
    vector<int> depth;
    LCA() {}
    LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }

    void init(const vector<vector<int>>& G, int r = 0) {
        int V = (int)G.size();
        int h = 1;
        while ((1 << h) < V) ++h;
        parent.assign(h, vector<int>(V, -1));
        depth.assign(V, -1);
        dfs(G, r, -1, 0);
        for (int i = 0; i + 1 < (int)parent.size(); ++i) {
            for (int v = 0; v < V; ++v) {
                if (parent[i][v] != -1) {
                    parent[i + 1][v] = parent[i][parent[i][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<int>>& G, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto e : G[v])
            if (e != p) dfs(G, e, v, d + 1);
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int i = 0; i < (int)parent.size(); ++i) {
            if ((depth[v] - depth[u]) & (1 << i)) v = parent[i][v];
        }
        if (u == v) return u;
        for (int i = (int)parent.size() - 1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }

    bool is_on_path(int u, int v, int x) {
        return dist(u, x) + dist(x, v) == dist(u, v);
    }
};
