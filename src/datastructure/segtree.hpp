#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()>
struct SegmentTree {
  private:
    int _n, size, log;
    vector<S> dat;
    void update(int k) { dat[k] = op(dat[2 * k], dat[2 * k + 1]); }

  public:
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int n) : SegmentTree(vector<S>(n, e())) {}
    SegmentTree(const vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) log++;
        size = 1 << log;
        dat = vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) dat[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
    // a[p] = x
    void set(int p, S x) {
        p += size;
        dat[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    // return a[p]
    S get(int p) const {
        return dat[p + size];
    }
    // return op(a[l], ..., a[r-1])
    S prod(int l, int r) const {
        S sml = e(), smr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, dat[l++]);
            if (r & 1) smr = op(dat[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() const { return dat[1]; }

    // SegmentTree上の二分探索 (必要な場合)
    // return r, f(op(a[l], ..., a[r-1])) == true
    template <bool (*f)(S)>
    int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F>
    int max_right(int l, F f) const {
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, dat[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, dat[l]))) {
                        sm = op(sm, dat[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, dat[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    // return l, f(op(a[l], ..., a[r-1])) == true
    template <bool (*f)(S)>
    int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F>
    int min_left(int r, F f) const {
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(dat[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(dat[r], sm))) {
                        sm = op(dat[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(dat[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};
