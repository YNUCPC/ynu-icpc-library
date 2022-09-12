---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/lazysegtree.hpp
    title: src/datastructure/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/datastructure/lazysegtree.hpp\"\nusing\
    \ namespace std;\n\ntemplate <class S,\n          S (*op)(S, S),\n          S\
    \ (*e)(),\n          class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)()>\nstruct LazySegmentTree {\n  private:\n    int _n,\
    \ size, log;\n    vector<S> dat;\n    vector<F> lz;\n    void update(int k) {\
    \ dat[k] = op(dat[2 * k], dat[2 * k + 1]); }\n    void all_apply(int k, F f) {\n\
    \        dat[k] = mapping(f, dat[k]);\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n \
    \       all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n    }\n    int lower_bits(int\
    \ x, int k) { return x & ((1 << k) - 1); }\n\n  public:\n    LazySegmentTree()\
    \ : LazySegmentTree(0) {}\n    LazySegmentTree(int n) : LazySegmentTree(vector<S>(n,\
    \ e())) {}\n    LazySegmentTree(const vector<S>& v) : _n(int(v.size())) {\n  \
    \      log = 0;\n        while ((1 << log) < _n) log++;\n        size = 1 << log;\n\
    \        dat = vector<S>(2 * size, e());\n        lz = vector<F>(size, id());\n\
    \        for (int i = 0; i < _n; i++) dat[size + i] = v[i];\n        for (int\
    \ i = size - 1; i >= 1; i--) update(i);\n    }\n    // a[p] = x\n    void set(int\
    \ p, S x) {\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        dat[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    // return a[p]\n    S get(int p) {\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return dat[p];\n\
    \    }\n    // return op(a[l], ..., a[r-1])\n    S prod(int l, int r) {\n    \
    \    if (l == r) return e();\n        l += size;\n        r += size;\n       \
    \ for (int i = log; i >= 1; i--) {\n            if (lower_bits(l, i) > 0) push(l\
    \ >> i);\n            if (lower_bits(r, i) > 0) push((r - 1) >> i);\n        }\n\
    \        S sml = e(), smr = e();\n        while (l < r) {\n            if (l &\
    \ 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr = op(dat[--r], smr);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(sml,\
    \ smr);\n    }\n    S all_prod() { return dat[1]; }\n    // a[p] = f(a[p])\n \
    \   void apply(int p, F f) {\n        p += size;\n        for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n        dat[p] = mapping(f, dat[p]);\n        for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n    }\n    // i = l...r-1 \u306B\
    \u3064\u3044\u3066 a[i] = f(a[i])\n    void apply(int l, int r, F f) {\n     \
    \   if (l == r) return;\n        l += size;\n        r += size;\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (lower_bits(l, i) > 0) push(l >> i);\n\
    \            if (lower_bits(r, i) > 0) push((r - 1) >> i);\n        }\n      \
    \  int l2 = l, r2 = r;\n        while (l < r) {\n            if (l & 1) all_apply(l++,\
    \ f);\n            if (r & 1) all_apply(--r, f);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n        l = l2;\n        r = r2;\n        for (int\
    \ i = 1; i <= log; i++) {\n            if (lower_bits(l, i) > 0) update(l >> i);\n\
    \            if (lower_bits(r, i) > 0) update((r - 1) >> i);\n        }\n    }\n\
    \    // SegmentTree\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22 (\u5FC5\u8981\u306A\u5834\
    \u5408)\n    // return r, f(op(a[l], ..., a[r-1])) == true\n    template <bool\
    \ (*g)(S)>\n    int max_right(int l) {\n        return max_right(l, [](S x) {\
    \ return g(x); });\n    }\n    template <class G>\n    int max_right(int l, G\
    \ g) {\n        assert(g(e()));\n        if (l == _n) return _n;\n        l +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm =\
    \ e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n            if\
    \ (!g(op(sm, dat[l]))) {\n                while (l < size) {\n               \
    \     push(l);\n                    l = (2 * l);\n                    if (g(op(sm,\
    \ dat[l]))) {\n                        sm = op(sm, dat[l]);\n                \
    \        l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = op(sm, dat[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return _n;\n    }\n    // return l,\
    \ f(op(a[l], ..., a[r-1])) == true\n    template <bool (*g)(S)>\n    int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return g(x); });\n    }\n    template\
    \ <class G>\n    int min_left(int r, G g) {\n        assert(g(e()));\n       \
    \ if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(dat[r],\
    \ sm))) {\n                while (r < size) {\n                    push(r);\n\
    \                    r = (2 * r + 1);\n                    if (g(op(dat[r], sm)))\
    \ {\n                        sm = op(dat[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(dat[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n#line 4 \"test/aoj/DSL_2_F.test.cpp\"\n\n\
    constexpr int E = INT32_MAX;\nconstexpr int ID = INT32_MAX;\n\nint op(int a, int\
    \ b) { return min(a, b); }\nint e() { return E; }\nint mapping(int f, int x) {\
    \ return (f == ID ? x : f); }\nint composition(int f, int g) { return (f == ID\
    \ ? g : f); }\nint id() { return ID; }\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    int n, q;\n    cin >> n >> q;\n    LazySegmentTree<int,\
    \ op, e, int, mapping, composition, id> seg(n);\n    for (int i = 0; i < q; i++)\
    \ {\n        int c;\n        cin >> c;\n        if (c == 0) {\n            int\
    \ s, t, x;\n            cin >> s >> t >> x;\n            seg.apply(s, t + 1, x);\n\
    \        } else {\n            int s, t;\n            cin >> s >> t;\n       \
    \     cout << seg.prod(s, t + 1) << endl;\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/datastructure/lazysegtree.hpp\"\
    \n\nconstexpr int E = INT32_MAX;\nconstexpr int ID = INT32_MAX;\n\nint op(int\
    \ a, int b) { return min(a, b); }\nint e() { return E; }\nint mapping(int f, int\
    \ x) { return (f == ID ? x : f); }\nint composition(int f, int g) { return (f\
    \ == ID ? g : f); }\nint id() { return ID; }\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    int n, q;\n    cin >> n >> q;\n    LazySegmentTree<int,\
    \ op, e, int, mapping, composition, id> seg(n);\n    for (int i = 0; i < q; i++)\
    \ {\n        int c;\n        cin >> c;\n        if (c == 0) {\n            int\
    \ s, t, x;\n            cin >> s >> t >> x;\n            seg.apply(s, t + 1, x);\n\
    \        } else {\n            int s, t;\n            cin >> s >> t;\n       \
    \     cout << seg.prod(s, t + 1) << endl;\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - src/datastructure/lazysegtree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 12:19:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.test.cpp
- /verify/test/aoj/DSL_2_F.test.cpp.html
title: test/aoj/DSL_2_F.test.cpp
---
