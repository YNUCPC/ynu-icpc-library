#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
#include "src/datastructure/lazysegtree.hpp"
#include "src/template/template.hpp"

using S = pair<ll, ll>;

S op(S a, S b) { return S(a.first + b.first, a.second + b.second); }
S e() { return P(0, 0); }
S mapping(ll f, S x) { return S(x.first + f * x.second, x.second); }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<S> a(n, S(0, 1));
    LazySegmentTree<S, op, e, ll, mapping, composition, id> seg(a);
    REP(i, q) {
        int c;
        cin >> c;
        if (c == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.apply(s - 1, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.prod(s - 1, t).first << endl;
        }
    }
    return 0;
}