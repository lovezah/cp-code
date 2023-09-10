#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long N, K; cin >> N >> K;
    long long N_orig = N;
    N--;
    if (!N) {
        cout << 0 << '\n';
        return;
    }
    long long A = 1, ans = 1;
    N -= 1;
    while (A * 2 <= K && N > 0) {
        ans += 1;
        A *= 2;
        N -= A;
    }
    K = min(N_orig - N, K);
    if (N > 0) ans += (N + K - 1) / K;
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
