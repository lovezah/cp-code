#include <bits/stdc++.h>

using namespace std;

constexpr int M = 10;

void solve() {
    long long N, K; cin >> N >> K; K++;
    vector<long long> pw(M, 1);
    for (int i = 1; i < M; i++)
        pw[i] = pw[i-1] * 10;
    vector<int> A(N); for (auto &a : A) cin >> a;
    long long ans = 0;
    for (int i = 0; i + 1 < N; i++) {
        long long take = pw[A[i+1]-A[i]] - 1;
        take = min(K, take);
        K -= take;
        ans += take * pw[A[i]];
    }
    ans += K * pw[A[N-1]];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
