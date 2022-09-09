#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2863"
#include <bits/stdc++.h>
#include "../../src/math/modint.hpp"
#include "../../src/string/ahocorasick.hpp"
using namespace std;

constexpr long long MOD = 1000000007;
using mint = Modint<MOD>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    AhoCorasick ac;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ac.insert(s);
    }
    ac.build();
    string t;
    cin >> t;
    auto match = ac.search(t);
    int m = t.size();
    vector<mint> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (const auto& id : match[i - 1]) {
            int len = ac.patterns[id].size();
            dp[i] += dp[i - len];
        }
    }
    cout << dp[m] << endl;
    return 0;
}
