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

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (long long i = (long long)p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    sieve(200011);
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    vector<vector<int>> adj(N);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<map<int, int>> freq(N);
    int ans = 0;
    std::y_combinator([&](auto dfs, int u, int fa) -> void {
        vector<int> fac;
        int x = A[u];
        while (x > 1) {
            int v = smallest_factor[x];
            fac.push_back(v);
            while (x % v == 0) 
                x /= v;
        }
        for (auto v : adj[u]) {
            if (v == fa)
                continue;
            dfs(v, u);
        }
        for (int f : fac) {
            array<int, 2> mx{1, 1};
            for (auto v : adj[u]) {
                if (v == fa) continue;
                if (freq[v][f] + 1 > mx[1])
                    mx[1] = freq[v][f] + 1;
                if (mx[1] > mx[0])
                    swap(mx[0], mx[1]);
            }
            freq[u][f] = mx[0];
            ans = max(ans, mx[0] + mx[1] - 1);
        }
    })(0, -1);
    cout << ans << '\n';
    return 0;
}
