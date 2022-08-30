#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Trie {
  private:
    static constexpr int C_SIZE = 26;    // C_SIZE  : 文字の種類数
    static constexpr int C_BEGIN = 'a';  // C_BEGIN : 開始文字
    int root = 0;
    struct Node {
        int child[C_SIZE];  // 子ノードの番号, 存在しなければ-1
        vector<int> ids;    // そのノードが終端である文字列のIDリスト
        Node() { fill(child, child + C_SIZE, -1); }
    };

  public:
    vector<Node> nodes;
    int cnt = 0;  // 追加した文字列の個数
    Trie() : nodes(1) {}
    // nodes[idx]から文字cで遷移したときの頂点のindex
    int next_index(int idx, char c) {
        return nodes[idx].child[c - C_BEGIN];
    }
    // 文字列の追加
    void insert(const string str) {
        int now = root;
        for (auto c : str) {
            int k = c - C_BEGIN;
            int& nxt = nodes[now].child[k];
            if (nxt == -1) {
                now = nxt = int(nodes.size());
                nodes.push_back(Node());
            } else {
                now = nxt;
            }
        }
        nodes[now].ids.push_back(cnt++);
    }
    // 文字列に対応するnodeのindexを検索, 存在しなければ-1
    int find(const string str) {
        int now = root;
        for (auto c : str) {
            int nxt = next_index(now, c);
            if (nxt == -1) return -1;
            now = nxt;
        }
        return now;
    }
};
