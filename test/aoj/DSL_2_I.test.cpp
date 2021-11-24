#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"
#include <bits/stdc++.h>
#include "../../src/datastructure/lazysegtree.hpp"

using ll = long long;
using S = pair<ll, ll>;
constexpr int ID = INT32_MAX;

S op(S a, S b) { return S(a.first + b.first, a.second + b.second); }
S e() { return S(0, 0); }
S mapping(int f, S x) { return (f == ID ? x : S(f * x.second, x.second)); }
int composition(int f, int g) { return (f == ID ? g : f); }
int id() { return ID; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<S> a(n, S(0, 1));
    LazySegmentTree<S, op, e, int, mapping, composition, id> seg(a);
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
            cout << seg.prod(s, t + 1).first << endl;
        }
    }
    return 0;
}