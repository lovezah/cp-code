#include <bits/stdc++.h>
#include <functional>
#include <utility>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 2>>> adj(N);
    for (int m = 0; m < M; m++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, m});
    }
    vector<bool> vis(N, false), act(N, false);
    vector<int> col(M, 0);
    auto dfs = std::y_combinator([&](auto self, int u) -> void {
        vis[u] = true;
        act[u] = true;
        for (auto [v, id] : adj[u]) {
            if (!vis[v]) {
                col[id] = 1;
                self(v);
            } else if (act[v]) {
                col[id] = 2;
            } else {
                col[id] = 1;
            }
        }
        act[u] = false;
    });
    for (int i = 0; i < N; i++)
        if (!vis[i])
            dfs(i);
    int K = 1;
    if (ranges::count(col, 2) > 0)
        K++;
    cout << K << '\n';
    for (int m = 0; m < M; m++)
        cout << col[m] << " \n"[m+1==M];
    return 0;
}
