#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <bits/stdc++.h>
#include "../../src/string/suffix_array.hpp"
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> sa = suffix_array(s);
    for (int i = 0; i < n; i++) {
        cout << sa[i + 1] << " \n"[i == n];
    }
    return 0;
}