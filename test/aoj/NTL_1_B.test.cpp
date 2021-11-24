#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"
#include <bits/stdc++.h>
#include "../../src/math/modint.hpp"
using namespace std;

constexpr long long MOD = 1000000007;
using mint = Modint<MOD>;

int main() {
    mint m;
    int n;
    cin >> m >> n;
    cout << m.pow(n) << endl;
    return 0;
}
