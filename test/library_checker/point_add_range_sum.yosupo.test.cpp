#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#include "../../src/string/fenwick_tree.hpp"
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    FenwickTree ft(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ft.add(i, a);
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << ft.sum(l, r) << endl;
    }

    return 0;
}
