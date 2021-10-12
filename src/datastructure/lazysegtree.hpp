#pragma once
#include "src/template/template.hpp"

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct LazySegmentTree {
  private:
    int _n, size, log;
    vector<S> dat;
    vector<F> lz;
    void update(int k) { dat[k] = op(dat[2 * k], dat[2 * k + 1]); }
    void all_apply(int k, F f) {
        dat[k] = mapping(f, dat[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
    int lower_bits(int x, int k) { return x & ((1 << k) - 1); }

  public:
    LazySegmentTree() : LazySegmentTree(0) {}
    LazySegmentTree(int n) : LazySegmentTree(vector<S>(n, e())) {}
    LazySegmentTree(const vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) log++;
        size = 1 << log;
        dat = vector<S>(2 * size, e());
        lz = vector<F>(size, id());
        for (int i = 0; i < _n; i++) dat[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }
    // a[p] = x
    void set(int p, S x) {
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        dat[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    // return a[p]
    S get(int p) {
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return dat[p];
    }
    // return op(a[l], ..., a[r-1])
    S prod(int l, int r) {
        if (l == r) return e();
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (lower_bits(l, i) > 0) push(l >> i);
            if (lower_bits(r, i) > 0) push((r - 1) >> i);
        }
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, dat[l++]);
            if (r & 1) smr = op(dat[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() { return dat[1]; }
    // a[p] = f(a[p])
    void apply(int p, F f) {
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        dat[p] = mapping(f, dat[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    // i = l...r-1 について a[i] = f(a[i])
    void apply(int l, int r, F f) {
        if (l == r) return;
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (lower_bits(l, i) > 0) push(l >> i);
            if (lower_bits(r, i) > 0) push((r - 1) >> i);
        }
        int l2 = l, r2 = r;
        while (l < r) {
            if (l & 1) all_apply(l++, f);
            if (r & 1) all_apply(--r, f);
            l >>= 1;
            r >>= 1;
        }
        l = l2;
        r = r2;
        for (int i = 1; i <= log; i++) {
            if (lower_bits(l, i) > 0) update(l >> i);
            if (lower_bits(r, i) > 0) update((r - 1) >> i);
        }
    }
    // SegmentTree上の二分探索 (必要な場合)
    // return r, f(op(a[l], ..., a[r-1])) == true
    template <bool (*g)(S)>
    int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G>
    int max_right(int l, G g) {
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, dat[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, dat[l]))) {
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
    template <bool (*g)(S)>
    int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G>
    int min_left(int r, G g) {
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(dat[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(dat[r], sm))) {
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