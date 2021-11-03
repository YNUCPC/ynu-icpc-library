#progma once
#include <bits/stdc++.h>
using namespace std;

struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

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

    struct scc_graph {
        int _n;
        struct edge {
            int to;
        };
        vector<pair<int, edge>> edges;

        template <class E>
        struct csr {
            vector<int> start;
            vector<E> elist;
            csr(int n, const vector<pair<int, E>>& edges)
                : start(n + 1), elist(edges.size()) {
                for (auto e : edges) start[e.first + 1]++;
                for (int i = 1; i <= n; i++) start[i] += start[i - 1];
                auto counter = start;
                for (auto e : edges) elist[counter[e.first]++] = e.second;
            }
        };

        scc_graph(int n) : _n(n) {}
        scc_graph() : _n(0) {}

        void add_edge(int from, int to) {
            edges.push_back({from, {to}});
        }

        pair<int, vector<int>> scc_ids() {
            auto g = csr<edge>(_n, edges);
            int now_ord = 0, group_num = 0;
            vector<int> visited, low(_n), ord(_n, -1), ids(_n);
            visited.reserve(_n);
            auto dfs = [&](auto self, int v) -> void {
                low[v] = ord[v] = now_ord++;
                visited.push_back(v);
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto to = g.elist[i].to;
                    if (ord[to] == -1) {
                        self(self, to);
                        low[v] = min(low[v], low[to]);
                    } else {
                        low[v] = min(low[v], ord[to]);
                    }
                }
                if (low[v] == ord[v]) {
                    while (true) {
                        int u = visited.back();
                        visited.pop_back();
                        ord[u] = _n;
                        ids[u] = group_num;
                        if (u == v) break;
                    }
                    group_num++;
                }
            };
            for (int i = 0; i < _n; i++)
                if (ord[i] == -1) dfs(dfs, i);
            for (auto& x : ids) x = group_num - 1 - x;
            return {group_num, ids};
        }
    }; scc_graph scc;
};