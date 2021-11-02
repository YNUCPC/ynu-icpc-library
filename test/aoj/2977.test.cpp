#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2977"
#include <bits/stdc++.h>
#include "src/math/FFT.hpp"
using namespace std;

// test FFT convolution
int main() {
    int N, M, K, L;
    cin >> N >> M >> K >> L;
    vector<string> bomb(N);
    string s;
    for (int i = 0; i < N; i++) cin >> bomb[i];
    cin >> s;
    vector<long long> a((M - N + 1) * M, 0), b(N * M, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (bomb[i][j] == 'X') b[i * M + j] = 1;
        }
    }
    for (int i = 0, x = 0, y = 0; i < L; i++) {
        if (s[i] == 'U') y--;
        if (s[i] == 'D') y++;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        a[y * M + x]++;
    }
    auto c = convolution(a, b);
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i * M + j] >= K) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}