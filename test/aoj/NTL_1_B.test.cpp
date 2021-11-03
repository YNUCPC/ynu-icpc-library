#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"
#include <bits/stdc++.h>
#include "src/math/modint.hpp"
using namespace std;

constexpr long long MOD = 1000000007;
using mint = Modint<MOD>;

int main() {
    int m, n;
    cin >> m >> n;
    mint ans = mint(m).pow(n);
    cout << ans.val() << endl;
    return 0;
}
