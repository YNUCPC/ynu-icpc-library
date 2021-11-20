#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"
#include <bits/stdc++.h>
#include "../../src/math/extgcd.hpp"
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;
    return 0;
}
