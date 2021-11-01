#pragma once
#include "template.hpp"

//Dinic法 O(V^2E)
struct Dinic {
    int V;                                    // 頂点数
    vector<vector<vector<long long>>> graph;  // グラフ
    vector<int> dis;                          // 始点からの距離
    vector<int> next;                         // 次に処理する頂点のメモ
    Dinic(int v) : V(v) { graph.resize(V); }
    void add_edge(int from, int to, long long capacity) {
        graph[from].push_back({to, capacity, (int)graph[to].size()});
        graph[to].push_back({from, 0, (int)graph[from].size() - 1});
    }
    void bfs(int s) {
        dis.assign(V, -1);
        dis[s] = 0;
        deque<int> pos = {s};
        while (pos.size()) {
            int now = pos[0];
            pos.pop_front();
            for (auto& to : graph[now]) {
                if (dis[to[0]] < 0 and to[1] > 0) {
                    dis[to[0]] = dis[now] + 1;
                    pos.emplace_back(to[0]);
                }
            }
        }
    }
    long long dfs(int v, int t, long long f) {
        if (v == t) return f;
        for (int& i = next[v]; i < graph[v].size(); i++) {
            int to = graph[v][i][0];
            long long& cap = graph[v][i][1];
            int rev = graph[v][i][2];
            if (cap > 0 and dis[v] < dis[to]) {
                long long d = dfs(to, t, min(f, cap));
                if (d > 0) {
                    cap -= d;
                    graph[to][rev][1] += d;
                    return d;
                }
            }
        }
        return 0;
    }
    long long max_flow(int s, int t) {
        long long flow = 0;
        while (1) {
            bfs(s);
            if (dis[t] < 0) return flow;
            next.assign(V, 0);
            long long f;
            while ((f = dfs(s, t, LLONG_MAX)) > 0) flow += f;
        }
    }
};