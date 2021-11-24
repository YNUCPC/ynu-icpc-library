#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include <bits/stdc++.h>
#include "../../src/string/rolling_hash.hpp"
using namespace std;

int main() {
    string t, p;
    cin >> t >> p;
    int n = t.size(), m = p.size();
    RollingHash hash_t(t), hash_p(p);
    for (int i = 0; i < n - m + 1; i++) {
        if (match(hash_t, i, i + m, hash_p, 0, m)) {
            cout << i << "\n";
        }
    }
    return 0;
}