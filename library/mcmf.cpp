#include <bits/stdc++.h>
using namespace std;

template<typename flow_t = int, typename cost_t = long long> 
struct mcmf {
    int n;
    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        edge(int t, flow_t f, cost_t c) : to(t), cap(f), cost(c) {}
    };
    vector<edge> edges;
    vector<vector<int>> g;
    vector<cost_t> dis, h;
    vector<int> pre;

    mcmf(int n_) : n(n_), g(n_), h(n_) {}

    void addEdge(int u, int v, flow_t f, cost_t c) {
        g[u].push_back((int)edges.size());
        edges.emplace_back(v, f, c);
        g[v].push_back((int)edges.size());
        edges.emplace_back(u, 0, -c);
    }
    bool dijkstra(int s, int t) {
        constexpr cost_t INF = numeric_limits<cost_t>::max() / 2;
        pre.assign(n, -1);
        dis.assign(n, INF);

        using T = pair<cost_t, int>;
        priority_queue<T, vector<T>, greater<T>> q;
        q.emplace(dis[s] = 0, s);
        while (!q.empty()) {
            auto [exp, u] = q.top(); q.pop();
            if (dis[u] != exp) continue;
            for (int i = 0; i < (int)g[u].size(); i++) {
                const int j = g[u][i];
                auto [v, f, c] = edges[j];
                if (f > 0 && dis[v] > dis[u] + c + h[u] - h[v]) {
                    pre[v] = j;
                    dis[v] = dis[u] + c + h[u] - h[v];
                    q.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != INF;
    }
    flow_t augment(int t) {
        for (int i = 0; i < n; i++) h[i] += dis[i];
        flow_t f = numeric_limits<flow_t>::max();
        for (int u = t; ~pre[u]; u = edges[pre[u]^1].to) {
            f = min(f, edges[pre[u]].cap);
        }
        for (int u = t; ~pre[u]; u = edges[pre[u]^1].to) {
            edges[pre[u]].cap -= f;
            edges[pre[u]^1].cap += f;
        }
        return f;
    }
    pair<flow_t, cost_t> work(int s, int t) {
        flow_t flow = 0;
        cost_t cost = 0;
        while (dijkstra(s, t)) {
            auto p = augment(t);
            flow += p;
            cost += p * (h[t] - h[s]);
        }
        return {flow, cost};
    }
};
