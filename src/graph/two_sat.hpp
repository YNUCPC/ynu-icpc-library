#pragma once
#include <bits/stdc++.h>
#include "src/graph/scc.hpp"
using namespace std;

struct TwoSAT {
  public:
    TwoSAT() : _n(0), scc(0) {}
    TwoSAT(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }

    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }

    vector<bool> answer() { return _answer; }

  private:
    int _n;
    vector<bool> _answer;
    SCC scc; // 強連結成分分解を用いる
};
