#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include <bits/stdc++.h>
#include "../../src/math/kronecker.hpp"
#include "../../src/math/modint.hpp"
using namespace std;

using mint = Modint<998244353>;

int main() {
    int N;
    cin >> N;
    vector<mint> a(1 << N), b(1 << N);
    for(int i = 0; i < (1 << N); i++) cin >> a[i];
    for(int i = 0; i < (1 << N); i++) cin >> b[i];
    vector<mint> c = Kronecker::xor_convolution(a, b);
    for(int i = 0; i < (1 << N); i++) {
        cout << c[i] << " \n"[i == (1 << N) - 1];
    }
}