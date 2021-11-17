#pragma once
#include <bits/stdc++.h>
using namespace std;

template <int64_t Modulus>
struct Modint {
    using mint = Modint;
    long long v;
    Modint() : v(0) {}
    Modint(long long x) {
        x %= Modulus;
        if (x < 0) x += Modulus;
        v = x;
    }
    const long long& val() const { return v; }
    // 代入演算子
    mint& operator+=(const mint rhs) {
        v += rhs.v;
        if (v >= Modulus) v -= Modulus;
        return *this;
    }
    mint& operator-=(const mint rhs) {
        if (v < rhs.v) v += Modulus;
        v -= rhs.v;
        return *this;
    }
    mint& operator*=(const mint rhs) {
        v = v * rhs.v % Modulus;
        return *this;
    }
    mint& operator/=(mint rhs) { return *this = *this * rhs.inv(); }
    // 累乗, 逆元
    mint pow(long long n) const {
        mint x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    mint inv() const { return pow(Modulus - 2); }
    // 算術演算子
    mint operator+(const mint rhs) const { return mint(*this) += rhs; }
    mint operator-(const mint rhs) const { return mint(*this) -= rhs; }
    mint operator*(const mint rhs) const { return mint(*this) *= rhs; }
    mint operator/(const mint rhs) const { return mint(*this) /= rhs; }
    mint operator-() const { return mint() - *this; }  // 単項
    // 入出力ストリーム
    friend ostream& operator<<(ostream& os, const mint& p) { return os << p.v; }
    friend istream& operator>>(istream& is, mint& p) {
        int64_t t;
        is >> t;
        p = mint(t);
        return (is);
    }
};
