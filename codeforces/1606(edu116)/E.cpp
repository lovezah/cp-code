#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;

long long pow(int a, int k) {
    long long r = 1;
    for (; k > 0; k >>= 1, a = (long long)a * a % mod) {
        if (k & 1)  
            r = r * a % mod;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, X; cin >> N >> X;
    vector C(N+1, vector<long long>(N+1));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else    
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    vector dp(N+1, vector<long long>(X+1));
    dp[N][0] = 1;
    for (int i = N; i >= 2; i--) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k <= i; k++) {
                int dam = min(X, j + i - 1);
                // j < health <= dam
                dp[k][dam] += dp[i][j] * (C[i][i-k] * pow(dam - j, i - k) % mod) % mod;
                dp[k][dam] %= mod;
            }
        }
    }
    long long ans = 0;
    for (int x = 1; x <= X; x++) {
        ans += dp[0][x];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}
