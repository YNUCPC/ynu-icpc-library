#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include <bits/stdc++.h>
#include "src/datastructure/lazysegtree.hpp"

constexpr int E = INT32_MAX;
constexpr int ID = INT32_MAX;

int op(int a, int b) { return min(a, b); }
int e() { return E; }
int mapping(int f, int x) { return (f == ID ? x : f); }
int composition(int f, int g) { return (f == ID ? g : f); }
int id() { return ID; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    LazySegmentTree<int, op, e, int, mapping, composition, id> seg(n);
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.prod(s, t + 1) << endl;
        }
    }
    return 0;
}