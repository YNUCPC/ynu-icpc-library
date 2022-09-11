#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    static constexpr int C_SIZE = 26;    // C_SIZE  : 文字の種類数
    static constexpr int C_BEGIN = 'a';  // C_BEGIN : 開始文字
    static constexpr int ROOT = 0;
    struct Node {
        array<int, C_SIZE> to = {};  // 子ノードの番号, 存在しなければ-1
        vector<int> ids;             // そのノードが終端である文字列のIDリスト
        Node() { to.fill(-1); }
    };
    vector<Node> nodes;
    int cnt = 0;  // 追加した文字列の個数
    Trie() : nodes(1) {}
    // nodes[idx]から文字cで遷移したときの頂点のindex
    int next(int idx, char c) { return nodes[idx].to[c - C_BEGIN]; }
    // 文字列の追加
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
        nodes[now].ids.push_back(cnt++);
        return now;
    }
    // 文字列に対応するnodeのindexを検索, 存在しなければ-1
    int find(const string& s) {
        int now = ROOT;
        for (char c : s) {
            now = next(now, c);
            if (now == -1) return -1;
        }
        return now;
    }
};
