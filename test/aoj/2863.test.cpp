#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2863"
#include <bits/stdc++.h>
#include "../../src/math/modint.hpp"
#include "../../src/string/rolling_hash.hpp"
#include "../../src/string/trie.hpp"
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

constexpr long long MOD = 1000000007;
using mint = Modint<MOD>;

int main() {
    int n, s_sum = 0, sq;
    cin >> n;
    vector<string> s(n);
    REP(i, n) {
        cin >> s[i];
        s_sum += s[i].size();
    }
    string t;
    cin >> t;
    Trie trie;
    vector<RollingHash> hashs;
    RollingHash hash_t(t);
    sq = sqrt(s_sum) + 1;
    REP(i, n) {
        if (s[i].size() < sq) {
            trie.insert(s[i]);
        } else {
            hashs.push_back(RollingHash(s[i]));
        }
    }
    int m = t.size();
    vector<mint> dp(m + 1);
    dp[0] = 1;
    REP(i, m) {
        if (dp[i].val() == 0) continue;
        int idx = 0, j = 0;
        while (i + j < m) {
            idx = trie.next_index(idx, t[i + j]);
            if (idx == -1) break;
            if (!trie.nodes[idx].ids.empty()) {
                dp[i + j + 1] += dp[i];
            }
            j++;
        }
        for (auto& rh : hashs) {
            int len = rh.n;
            if (i + len > m) continue;
            if (match(hash_t, i, i + len, rh, 0, len)) {
                dp[i + len] += dp[i];
            }
        }
    }
    cout << dp[m] << endl;
}