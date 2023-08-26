#include <bits/stdc++.h>
using namespace std;

template<class T> struct Flow {
    int n;
    struct edge {
        int to;
        T cap;
        edge(int to, T cap) : to(to), cap(cap) {}
    };
    vector<edge> edges;
    vector<vector<int>> g;
    vector<int> cur, lev;
    
    Flow(int n_) : n(n_), g(n_) {}

    void addEdge(int u, int v, T c) {
        g[u].push_back((int)edges.size());
        edges.emplace_back(v, c);
        g[v].push_back((int)edges.size());
        edges.emplace_back(u, 0);
    }
    bool bfs(int s, int t) {
        lev.assign(n, -1);
        lev[s] = 0;
        queue<int> q; q.emplace(s);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (int i = 0; i < (int)g[u].size(); i++) {
                const int j = g[u][i];
                auto &&[v, c] = edges[j];
                if (c > 0 && lev[v] == -1) {
                    lev[v] = lev[u] + 1;
                    if (v == t) return true;
                    q.emplace(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, int t, T f) {
        if (u == t) return f;
        T flow = 0;
        for (int &i = cur[u]; i < (int)g[u].size(); i++) {
            int j = g[u][i];
            auto &&[v, c] = edges[j];
            if (c > 0 && lev[v] == lev[u] + 1) {
                auto a = dfs(v, t, std::min(c, f));
                edges[j].cap -= a;
                edges[j^1].cap += a;
                f -= a;
                flow += a;
                if (f == 0) break;
            }
        }
        if (flow == 0) {
            lev[u] = -1;
        }
        return flow;
    }
    T work(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            flow += dfs(s, t, std::numeric_limits<T>::max());
        }
        return flow;
    }
};
