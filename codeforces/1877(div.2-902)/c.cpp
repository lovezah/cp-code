#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M, K; cin >> N >> M >> K;
        if (K == 1) {
            cout << 1 << '\n';
        } else if (K == 2) {
            cout << min(M, N) + max(0, (M / N - 1)) << '\n';
        } else if (K == 3) {
            cout << max(0, M - N - max(0, (M / N - 1))) << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
