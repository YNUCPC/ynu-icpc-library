#pragma once
#include <bits/stdc++.h>
using namespace std;

struct AhoCorasick {
    static constexpr int C_SIZE = 26;    // C_SIZE  : 文字の種類数
    static constexpr int C_BEGIN = 'a';  // C_BEGIN : 開始文字
    static constexpr int ROOT = 0;
    struct Node {
        array<int, C_SIZE> to = {};    // to[c]=文字cによる遷移先ノード, 存在しなければ-1
        vector<int> ids;               // そのノードでマッチする文字列のIDリスト
        int fail = ROOT, drct = ROOT;  // 失敗時の遷移先, suffixでマッチする遷移先
        Node() { to.fill(-1); }
    };
    vector<Node> nodes;
    vector<string> patterns;
    AhoCorasick() : nodes(1) {}

    int insert(const string& s) {
        int now = ROOT;
        for (char c : s) {
            int k = c - C_BEGIN;
            if (nodes[now].to[k] == -1) {
                nodes[now].to[k] = nodes.size();
                nodes.push_back(Node());
            }
            now = nodes[now].to[k];
        }
        nodes[now].ids.push_back(patterns.size());
        patterns.push_back(s);
        return now;
    }

    void build() {
        queue<int> que;
        for (int& x : nodes[ROOT].to) {
            if (x == -1) {
                x = ROOT;
            } else {
                que.push(x);
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            int fail = nodes[now].fail;
            for (int k = 0; k < C_SIZE; k++) {
                int& nxt = nodes[now].to[k];
                if (nxt == -1) {
                    nxt = nodes[fail].to[k];  // failure link で遷移してから遷移
                } else {
                    nodes[nxt].fail = nodes[fail].to[k];  // 遷移先のfailure linkを求める
                    que.push(nxt);
                }
            }
            nodes[now].drct = (nodes[fail].ids.empty() ? nodes[fail].drct : fail);
        }
    }

    int next(int idx, char c) { return nodes[idx].to[c - C_BEGIN]; }

    bool accept(int idx) { return nodes[idx].drct != ROOT || !nodes[idx].ids.empty(); }

    vector<int> match(int idx) {
        vector<int> res;
        int now = idx;
        while (now != ROOT) {
            for (int id : nodes[now].ids) res.push_back(id);
            now = nodes[now].drct;
        }
        return res;
    }

    vector<vector<int>> search(const string& s) {
        vector<vector<int>> res;
        int now = ROOT;
        for (char c : s) {
            now = next(now, c);
            res.emplace_back(match(now));
        }
        return res;
    }
};
