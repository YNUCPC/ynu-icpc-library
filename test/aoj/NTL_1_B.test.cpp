#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"
#include <bits/stdc++.h>
#include "src/math/modint.hpp"
using namespace std;

using mint = Modint<1000000007>;

int main() {
    int m, n;
    cin >> m >> n;
    mint ans = mint(m).pow(n);
    cout << ans.val() << endl;
    return 0;
}
