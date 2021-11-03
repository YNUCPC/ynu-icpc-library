#pragma once
#include <bits/stdc++.h>
using namespace std;

// 最小費用流 O(FElogV)
struct MinCostFlow {
    int V;
    vector<vector<vector<long long>>> g;  // g[from] = {{to, 容量, コスト, 逆辺のindex} ... }
    vector<long long> h, dis;             // ポテンシャル, 最短距離
    vector<int> prevv, preve;             // 直前の頂点, 辺

    MinCostFlow(int v) : V(v), g(v), dis(v), prevv(v), preve(v) {
    }

    void add_edge(int u, int v, long long c, long long d) {
        g[u].push_back({v, c, d, (int)g[v].size()});
        g[v].push_back({u, 0, -d, (int)g[u].size() - 1});
    }

    long long min_cost_flow(int s, int t, long long f) {
        long long res = 0;
        h.assign(V, 0);
        using Q = pair<long long, int>;
        while (f > 0) {
            priority_queue<Q, vector<Q>, greater<Q>> que;
            dis.assign(V, LLONG_MAX);
            dis[s] = 0;
            que.push({0, s});
            while (que.size()) {
                Q q = que.top();
                int v = q.second;
                que.pop();
                if (dis[v] < q.first) continue;
                for (int i = 0; i < g[v].size(); i++) {
                    auto now = g[v][i];
                    if (now[1] > 0 and dis[now[0]] > dis[v] + now[2] + h[v] - h[now[0]]) {
                        dis[now[0]] = dis[v] + now[2] + h[v] - h[now[0]];
                        prevv[now[0]] = v;
                        preve[now[0]] = i;
                        que.push({dis[now[0]], now[0]});
                    }
                }
            }
            if (dis[t] == LLONG_MAX) return -1;
            for (int i = 0; i < V; i++) h[i] += dis[i];
            long long d = f;
            for (int i = t; i != s; i = prevv[i]) d = min(d, g[prevv[i]][preve[i]][1]);
            f -= d;
            res += d * h[t];
            for (int i = t; i != s; i = prevv[i]) {
                auto& now = g[prevv[i]][preve[i]];
                now[1] -= d;
                g[i][now[3]][1] += d;
            }
        }
        return res;
    }
};