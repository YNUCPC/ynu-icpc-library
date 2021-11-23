#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
#include "../../src/string/z_algorithm.hpp"
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = z_algorithm(s);
    for (int i = 0; i < n; i++) {
        cout << z[i] << " \n"[i == n - 1];
    }
    return 0;
}
