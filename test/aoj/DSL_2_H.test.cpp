#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"
#include "src/template/template.hpp"
#include "src/datastructure/lazysegtree.hpp"

int op(int a, int b) { return min(a, b); }
int e() { return INT32_MAX; }
int mapping(int f, int x) { return x + f; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    LazySegmentTree<int, op, e, int, mapping, composition, id> seg(a);
    REP(i, q) {
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