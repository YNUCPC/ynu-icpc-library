#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(const string& str) {
    int n = str.size();
    vector<int> sa(n + 1), rank(n + 1, -1);  // sa[i] = 辞書順でi番目であるsuffixの開始位置
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; i++) rank[i] = str[i];
    int k;
    auto comp = [&](const int& i, const int& j) {
        if (rank[i] != rank[j]) {
            return rank[i] < rank[j];
        } else {
            int ri = i + k <= n ? rank[i + k] : -1;
            int rj = j + k <= n ? rank[j + k] : -1;
            return ri < rj;
        }
    };
    for (k = 1; k <= n; k <<= 1) {
        sort(sa.begin(), sa.end(), comp);
        vector<int> tmp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            tmp[sa[i + 1]] = tmp[sa[i]];
            if (comp(sa[i], sa[i + 1])) tmp[sa[i + 1]]++;
        }
        rank = tmp;
    }
    return sa;
}

// 文字列sに文字列tに含まれているか判定する
bool contain(const string& s, const string& t, vector<int>& sa) {
    int l = 0, r = int(s.size());
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (s.substr(sa[mid], t.size()) < t) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return s.substr(sa[r], t.size()) == t;
}