#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0341"
#include <bits/stdc++.h>
#include "src/math/modint.hpp"
using namespace std;

constexpr long long MOD = 1000000007;
using mint = Modint<MOD>;

int main() {
    int n, m;
    string t, b;
    cin >> t >> b;
    n = t.size();
    m = b.size();
    vector<vector<mint> > dp(n + 1);  // dp[i][j]=tのi文字目までみてbのj文字目までつくる通り
    for (int i = 0; i <= n; i++) dp[i].resize(m + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i + 1][j] += dp[i][j];
            if (j < m && t[i] == b[j]) {
                dp[i + 1][j + 1] += dp[i][j];
            }
        }
    }
    cout << dp[n][m].val() << endl;
    return 0;
}