#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3112"
#include <bits/stdc++.h>
#include "../../src/string/suffix_array.hpp"
#include "../../src/string/lcp_array.hpp"
using namespace std;

// 解説: https://www.slideshare.net/hcpc_hokudai/acpc-2019-day3-f

int main() {
    string s, t;
    int k;
    cin >> s >> t >> k;
    string u = s + "~" + t;
    vector<int> sa = suffix_array(u);
    vector<int> lcp = lcp_array(u, sa);
    int n = s.size();
    vector<int> len(n, 0);
    for (int i = 0, h = 0; i < int(u.size()); i++) {
        if (sa[i] < n) {
            len[sa[i]] = max(len[sa[i]], h);
            h = min(h, lcp[i]);
        } else {
            h = lcp[i];
        }
    }
    for (int i = int(u.size()) - 1, h = 0; i >= 0; i--) {
        if (sa[i] < n) {
            h = min(h, lcp[i]);
            len[sa[i]] = max(len[sa[i]], h);
        } else if (i > 0) {
            h = lcp[i - 1];
        }
    }
    vector<int> dp(n + 2, 0);
    dp[0] = 1;
    dp[1] = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > 0 && len[i] >= k) {
            dp[i + k]++;
            dp[i + len[i] + 1]--;
        }
        dp[i + 1] += dp[i];
    }
    cout << (dp[n] > 0 ? "Yes" : "No") << endl;
    return 0;
}
