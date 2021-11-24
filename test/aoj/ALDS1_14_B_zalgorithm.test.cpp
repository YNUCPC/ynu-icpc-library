#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include <bits/stdc++.h>
#include "../../src/string/z_algorithm.hpp"
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string t, p;
    cin >> t >> p;
    string s = p + t;
    int n = t.size(), m = p.size();
    vector<int> z = z_algorithm(s);
    for (int i = 0; i <= n - m; i++) {
        if (z[i + m] >= m) cout << i << "\n";
    }
    return 0;
}
