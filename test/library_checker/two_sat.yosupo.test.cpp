#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <bits/stdc++.h>
#include "src/graph/two_sat.hpp"
using namespace std;

int main() {
    string tmp;
    int N, M;
    cin >> tmp >> tmp >> N >> M;
    two_sat ts(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b >> tmp;
        ts.add_clause(abs(a) - 1, (a > 0), abs(b) - 1, (b > 0));
    }

    if (!ts.satisfiable()) {
        cout << "s UNSATISFIABLE" << '\n';
        return 0;
    }

    auto ans = ts.answer();
    cout << "s SATISFIABLE\n v ";
    for (int i = 0; i < N; i++) {
        int v = i + 1;
        if (!ans[i]) v *= -1;
        cout << v << " ";
    }
    cout << "0\n";
}
