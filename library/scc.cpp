#include <bits/stdc++.h>
using namespace std;

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk, instk;
    vector<int> dfn, low, bel;
    int cur, cnt;

    SCC() {}
    SCC(int n_) { init(n_); }

    void init(int m) {
        n = m;
        adj.assign(n, {});
        dfn.assign(n, 0);
        low.assign(n, 0);
        bel.assign(n, -1);
        instk.assign(n, 0);
        stk.clear();
        cur = cnt = 0;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void dfs(int u) {
        dfn[u] = low[u] = ++cur;
        stk.push_back(u);
        instk[u] = true;
        for (auto &&v : adj[u]) {
            if (!dfn[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (instk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            while (true) {
                v = stk.back(); stk.pop_back();
                instk[v] = false;
                bel[v] = cnt;
                if (v == u) break;
            }
            cnt++;
        }
    }
    vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }
        return bel;
    }
};
