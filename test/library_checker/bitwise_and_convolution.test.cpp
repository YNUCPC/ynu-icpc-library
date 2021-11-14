#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include <bits/stdc++.h>
#include "../../src/math/subset_zeta.hpp"
#include "../../src/math/modint.hpp"
using namespace std;

using ll = long long;
constexpr ll MOD = 998244353;
using mint = Modint<MOD>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<mint> a(1 << n), b(1 << n);
    for (int i = 0; i < 1 << n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < 1 << n; i++) {
        ll x;
        cin >> x;
        b[i] = x;
    }
    // ゼータ変換
    vector<mint> A = supset_zeta(a, n, false), B = supset_zeta(b, n, false);
    // AND畳み込み
    vector<mint> C(1 << n);
    for (int S = 0; S < 1 << n; S++) {
        C[S] = A[S] * B[S];
    }
    // メビウス変換
    vector<mint> c = supset_zeta(C, n, true);

    for (int i = 0; i < 1 << n; i++) {
        cout << c[i].val() << " \n"[i == (1 << n) - 1];
    }
    return 0;
}
