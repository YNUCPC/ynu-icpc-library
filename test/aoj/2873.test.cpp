#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2873"
#include <bits/stdc++.h>
#include "../../src/string/aho_corasick.hpp"
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    int n;
    cin >> s >> n;
    AhoCorasick ac;
    for (int i = 0; i < n; i++) {
        string p;
        cin >> p;
        ac.insert(p);
    }
    ac.build();
    int ans = 0, state = AhoCorasick::ROOT;
    for (char c : s) {
        state = ac.next(state, c);
        if (ac.accept(state)) {
            ans++;
            state = AhoCorasick::ROOT;
        }
    }
    cout << ans << endl;
    return 0;
}
