#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include <bits/stdc++.h>
#include "../../src/datastructure/fenwick_tree.hpp"
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    FenwickTree<long long> ft(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            ft.add(x - 1, y);
        } else {
            cout << ft.sum(x - 1, y) << endl;
        }
    }
    return 0;
}
