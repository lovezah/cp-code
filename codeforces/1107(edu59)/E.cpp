#include <bits/stdc++.h>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    vector dp(N, vector(N, vector<long long>(N+1, 0)));

    cout << std::y_combinator([&](auto solve, int st, int en, int k) -> long long {
        if (st > en) return 0;
        if (st == en) return A[k];
        long long &ans = dp[st][en][k];
        if (ans > 0) return ans;
        ans = solve(st, en - 1, 1) + A[k];
        for (int i = st; i <= en - 1; i++) {
            if (S[i] == S[en]) {
                ans = max(ans, solve(i + 1, en - 1, 1) + solve(st, i, k + 1));
            }
        }
        return ans;
    })(0, N-1, 1) << '\n';

    return 0;
}
