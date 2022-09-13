#pragma once
#include <bits/stdc++.h>
using namespace std;

// lcp[i] = sa[i]とsa[i+1]の common prefix の長さ
vector<int> lcp_array(const string& s, const vector<int>& sa) {
    int n = sa.size();
    vector<int> lcp(n), rank(n);  // rank[i] = s[i,n)の辞書順位
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0, len = 0; i < n; i++) {
        if (len > 0) len--;
        if (rank[i] == n - 1) continue;
        int j = sa[rank[i] + 1];  // s[i,n)より辞書順で1つ大きいsuffixの先頭位置
        while (max(i, j) + len < n && s[i + len] == s[j + len]) len++;
        lcp[rank[i]] = len;
    }
    return lcp;
}
