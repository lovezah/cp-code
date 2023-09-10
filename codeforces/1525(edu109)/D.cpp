#include <bits/stdc++.h>

using namespace std;

void setmin(int &a, int b) { a = min(a, b); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    vector<int> x, y;
    for (int i = 0; i < N; i++) {
        if (A[i])
            x.push_back(i);
        else
            y.push_back(i);
    }
    constexpr int INF = 1 << 29;
    int c1 = x.size(), c2 = y.size();
    vector dp(c1 + 11, vector<int>(c2 + 11, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= c1; i++) {
        for (int j = 0; j < c2; j++) {
            setmin(dp[i][j+1], dp[i][j]);
            if (i < c1) setmin(dp[i+1][j+1], dp[i][j] + abs(x[i] - y[j]));
        }
    }
    cout << dp[c1][c2] << '\n';
    return 0;
}
