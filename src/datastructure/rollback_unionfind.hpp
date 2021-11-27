#pragma once
#include <bits/stdc++.h>
using namespace std;

struct RollbackUnionFind {
    vector<int> data;
    stack<pair<int, int>> history;
    int inner_snap = 0;
    RollbackUnionFind(int n) { data.resize(n, -1); }

int find(int x) { return data[x] < 0 ? x : find(data[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        history.push({x, data[x]});
        history.push({y, data[y]});
        if (x == y) return false;
        if (-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    int same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return (-data[find(x)]); }

    void undo() {
        data[history.top().first] = history.top().second;
        history.pop();
        data[history.top().first] = history.top().second;
        history.pop();
    }

    void snapshot() { inner_snap = state(); }

    int state() { return int(history.size() >> 1); }

    void rollback(int t = -1) {
        if (t == -1) t = inner_snap;
        while (t < state()) undo();
    }
};
