#pragma once
#include "template.hpp"

template <uint64_t Modulus>
struct modint {
    using u64 = uint64_t;
    u64 v;
    // コンストラクタ
    modint() : v(0) {}
    modint(long long x) {
        x %= Modulus;
        if (x < 0) x += Modulus;
        v = x;
    }
    u64& val() const { return v; }
    // 代入演算子
    modint& operator+=(const modint rhs) {
        v += rhs.v;
        if (v >= Modulus) v -= Modulus;
        return *this;
    }
    modint& operator-=(const modint rhs) {
        if (v < rhs.v) v += Modulus;
        v -= rhs.v;
        return *this;
    }
    modint& operator*=(const modint rhs) {
        v = v * rhs.v % Modulus;
        return *this;
    }
    modint& operator/=(modint rhs) { return *this = *this * rhs.inv(); }
    // 累乗, 逆元
    modint pow(long long n) const {
        modint x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    modint inv() const { return pow(Modulus - 2); }
    // 算術演算子
    modint operator+(const modint rhs) const { return modint(*this) += rhs; }
    modint operator-(const modint rhs) const { return modint(*this) -= rhs; }
    modint operator*(const modint rhs) const { return modint(*this) *= rhs; }
    modint operator/(const modint rhs) const { return modint(*this) /= rhs; }
    modint operator-() const { return modint() - *this; }  // 単項
};

using mint = modint<MOD>;

// 入出力ストリーム
istream& operator>>(istream& is, mint& x) {
    long long a;
    is >> a;
    x = a;
    return is;
}
ostream& operator<<(ostream& os, mint& x) {
    return os << x.val();
}