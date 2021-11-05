#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"
#include <bits/stdc++.h>
#include "src/string/suffix_array.hpp"
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string t;
    int q;
    cin >> t >> q;
    vector<int> sa = suffix_array(t);
    for (int i = 0; i < q; i++) {
        string p;
        cin >> p;
        cout << contain(t, p, sa) << "\n";
    }
    return 0;
}