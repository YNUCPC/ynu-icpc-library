#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include <bits/stdc++.h>
#include "../../src/string/suffix_array.hpp"
#include "../../src/string/lcp_array.hpp"
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> sa = suffix_array(s);
    vector<int> lcp = lcp_array(s, sa);
    int64_t n = s.size(), ans;
    ans = n * (n + 1) / 2;
    for (auto len : lcp) ans -= len;
    cout << ans << endl;
}
