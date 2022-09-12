#define PROBLEM "https://atcoder.jp/contests/agc047/tasks/agc047_b"
#include <bits/stdc++.h>
#include "../../src/string/trie.hpp"
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    Trie trie;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
        trie.insert(s[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt[26]{};
        for (auto c : s[i]) cnt[c - 'a']++;
        int m = s[i].size(), now = 0;
        for (int j = 0; j < m - 1; j++) {
            for (int k = 0; k < 26; k++) {
                if (cnt[k] > 0) {
                    int tmp = trie.next(now, k + 'a');
                    if (tmp != -1) {
                        ans += trie.nodes[tmp].ids.size();
                    }
                }
            }
            now = trie.next(now, s[i][j]);
            cnt[s[i][j] - 'a']--;
        }
    }
    cout << ans << endl;
    return 0;
}
