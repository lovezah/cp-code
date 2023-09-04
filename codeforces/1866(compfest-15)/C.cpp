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

constexpr long long mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<vector<int>> L(N), W(N);
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        L[i].resize(K);
        W[i].resize(K);
        for (int j = 0; j < K; j++)
            cin >> L[i][j] >> W[i][j], L[i][j]--;
    }
    vector<bool> vis(N, false);
    vector<long long> inv(N, 0);
    vector<array<long long, 2>> freq(N);
    std::y_combinator([&](auto dfs, int u, int fa) -> void {
        vis[u] = true;
        for (int j = 0; j < (int)L[u].size(); j++) {
            int v = L[u][j];
            int w = W[u][j];
            if (!vis[v]) {
                
                dfs(v, u);
            }
        }
    })(0, -1);
    cout << inv[0] << '\n';
    return 0;
}
