#include <bits/stdc++.h>

using namespace std;

struct doubling {
    int n, z;
    vector<vector<int>> adj;
    vector<vector<int>> f;
    vector<int> dep;
    vector<int> st, en, seq;
    bool worked = false;

    doubling() {}
    doubling(int n_) { init(n_); }
    doubling(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }

    void init(int m) {
        n = m;
        z = std::__lg(n) + 1;
        adj.assign(n, {});
        f.assign(z, vector<int>(n, -1));
        dep.assign(n, 0);
        st.assign(n, 0), en.assign(n, 0);
        seq.clear();
        worked = false;
    }
    void addEdge(int a, int b, bool undirected = true) {
        adj[a].push_back(b);
        if (undirected) adj[b].push_back(a);
    }
    void dfs(int u, int fa) {
        st[u] = seq.size();
        seq.push_back(u);
        for (auto v : adj[u]) {
            if (v == fa) continue;
            f[0][v] = u;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
        en[u] = seq.size();
    }
    void work(int s = 0) {
        dfs(s, -1);
        for (int i = 1; i < z; i++) {
            for (int j = 0; j < n; j++) {
                if (~f[i-1][j])
                    f[i][j] = f[i-1][f[i-1][j]];
            }
        }
        worked = true;
    }
    pair<int, array<int, 2>> getDiameter() {
        assert(worked);
        auto bfs = [&](int s = 0) -> vector<int> {
            vector<int> d(n, -1);
            d[s] = 0;
            vector<int> que(1, s);
            for (int i = 0; i < (int)que.size(); i++) {
                int u = que[i];
                for (auto v : adj[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        que.push_back(v);
                    }
                }
            }
            return d;
        };
        auto d1 = bfs(0);
        int p1 = std::distance(d1.begin(), max_element(d1.begin(), d1.end()));
        auto d2 = bfs(p1);
        int p2 = std::distance(d2.begin(), max_element(d2.begin(), d2.end()));
        return pair<int, array<int, 2>>{getDist(p1, p2), array<int, 2>{p1, p2}};
    }
    bool isAncestor(int a, int b) {
        assert(worked);
        return st[a] <= st[b] && st[b] < en[a];
    }
    int getLca(int a, int b) {
        assert(worked);

        if (dep[a] < dep[b]) swap(a, b);
        for (int i = z - 1; i >= 0; i--) {
            if (~f[i][a] && dep[f[i][a]] >= dep[b])
                a = f[i][a];
        }
        if (a == b) return a;
        for (int i = z - 1; i >= 0; i--) {
            if (~f[i][a] && ~f[i][b] && f[i][a] ^ f[i][b])
                a = f[i][a], b = f[i][b];
        }
        return f[0][a];
    }
    int getDist(int a, int b) {
        assert(worked);
        return dep[a] + dep[b] - 2 * dep[getLca(a, b)];
    }
    int jump(int a, int k) {
        assert(worked);
        if (k < 0 || k > dep[a]) return -1;
        for (int i = 0; i < z; i++)
            if (k >> i & 1)
                a = f[i][a];
        return a;
    }
    int jump(int a, int b, int k) {
        if (k == 0) return a;
        if (a != b && isAncestor(a, b)) return jump(b, a, dep[b] - dep[a] - k);
        int anc = getLca(a, b);
        int first_half = dep[a] - dep[anc];
        int second_half = dep[b] - dep[anc];
        if (k < 0 || k > first_half + second_half) return -1;
        if (k <= first_half)
            return jump(a, k);
        else 
            return jump(b, first_half + second_half - k);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    doubling g(adj);
    g.work();
    auto diam = g.getDiameter();
    int p1 = diam.second[0], p2 = diam.second[1];
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int u, k; cin >> u >> k;
        u--;
        int ans = g.jump(u, p1, k);
        if (ans == -1) ans = g.jump(u, p2, k);
        if (~ans) ans++;
        cout << ans << '\n';
    }
    return 0;
}
