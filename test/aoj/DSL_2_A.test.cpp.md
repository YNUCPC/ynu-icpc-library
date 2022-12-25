---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/segtree.hpp
    title: src/datastructure/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/datastructure/segtree.hpp\"\nusing namespace\
    \ std;\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct SegmentTree {\n\
    \  private:\n    int _n, size, log;\n    vector<S> dat;\n    void update(int k)\
    \ { dat[k] = op(dat[2 * k], dat[2 * k + 1]); }\n\n  public:\n    SegmentTree()\
    \ : SegmentTree(0) {}\n    SegmentTree(int n) : SegmentTree(vector<S>(n, e()))\
    \ {}\n    SegmentTree(const vector<S>& v) : _n(int(v.size())) {\n        log =\
    \ 0;\n        while ((1 << log) < _n) log++;\n        size = 1 << log;\n     \
    \   dat = vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) dat[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n    // a[p] = x\n    void set(int p, S x) {\n        p += size;\n\
    \        dat[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n    // return a[p]\n    S get(int p) const { return dat[p + size]; }\n\
    \    // return op(a[l], ..., a[r-1])\n    S prod(int l, int r) const {\n     \
    \   S sml = e(), smr = e();\n        l += size;\n        r += size;\n        while\
    \ (l < r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if (r\
    \ & 1) smr = op(dat[--r], smr);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return op(sml, smr);\n    }\n    S all_prod() const { return\
    \ dat[1]; }\n\n    // SegmentTree\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22 (\u5FC5\u8981\
    \u306A\u5834\u5408)\n    // return r, f(op(a[l], ..., a[r-1])) == true\n    template\
    \ <bool (*f)(S)>\n    int max_right(int l) const {\n        return max_right(l,\
    \ [](S x) { return f(x); });\n    }\n    template <class F>\n    int max_right(int\
    \ l, F f) const {\n        assert(f(e()));\n        if (l == _n) return _n;\n\
    \        l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, dat[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ dat[l]))) {\n                        sm = op(sm, dat[l]);\n                \
    \        l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = op(sm, dat[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return _n;\n    }\n    // return l,\
    \ f(op(a[l], ..., a[r-1])) == true\n    template <bool (*f)(S)>\n    int min_left(int\
    \ r) const {\n        return min_left(r, [](S x) { return f(x); });\n    }\n \
    \   template <class F>\n    int min_left(int r, F f) const {\n        assert(f(e()));\n\
    \        if (r == 0) return 0;\n        r += size;\n        S sm = e();\n    \
    \    do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n \
    \           if (!f(op(dat[r], sm))) {\n                while (r < size) {\n  \
    \                  r = (2 * r + 1);\n                    if (f(op(dat[r], sm)))\
    \ {\n                        sm = op(dat[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(dat[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n#line 4 \"test/aoj/DSL_2_A.test.cpp\"\nusing\
    \ namespace std;\n\nconstexpr int INF = INT32_MAX;\n\nint op(int a, int b) { return\
    \ min(a, b); }\nconstexpr int e() { return INF; }\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<int,\
    \ op, e> seg(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n\
    \        cin >> com >> x >> y;\n        if (com == 0) {\n            seg.set(x,\
    \ y);\n        } else {\n            cout << seg.prod(x, y + 1) << endl;\n   \
    \     }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n#include <bits/stdc++.h>\n#include \"../../src/datastructure/segtree.hpp\"\n\
    using namespace std;\n\nconstexpr int INF = INT32_MAX;\n\nint op(int a, int b)\
    \ { return min(a, b); }\nconstexpr int e() { return INF; }\n\nint main() {\n \
    \   cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    int n, q;\n    cin\
    \ >> n >> q;\n    SegmentTree<int, op, e> seg(n);\n    for (int i = 0; i < q;\
    \ i++) {\n        int com, x, y;\n        cin >> com >> x >> y;\n        if (com\
    \ == 0) {\n            seg.set(x, y);\n        } else {\n            cout << seg.prod(x,\
    \ y + 1) << endl;\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/datastructure/segtree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-09-17 17:42:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
