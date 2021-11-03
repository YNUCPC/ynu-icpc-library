#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include <bits/stdc++.h>
#include "src/datastructure/segtree.hpp"
using namespace std;

constexpr int INF = INT32_MAX;

int op(int a, int b) { return min(a, b); }
constexpr int e() { return INF; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    SegmentTree<int, op, e> seg(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        } else {
            cout << seg.prod(x, y + 1) << endl;
        }
    }
    return 0;
}
