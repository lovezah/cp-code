#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    map<char, int> to;
    for (int i = 0; i < 10; i++)
        to[char(i+'0')] = i;
    for (int i = 10; i < 16; i++)   
        to[char('A'+i-10)] = i;
    int N; cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        A[i].reserve(N);
        string x; cin >> x;
        for (int j = 0; j < N / 4; j++) {
            for (int k = 3; k >= 0; k--) {
                A[i].push_back(to[x[j]] >> k & 1);
            }
        }
    }
    vector cum(N+1, vector<int>(N+1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cum[i+1][j+1] = cum[i][j+1] + cum[i+1][j] - cum[i][j] + A[i][j];
        }
    }
    vector<int> factor;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0 && N * N % (i * i) == 0)
            factor.push_back(i);
    }
    int ans = 1;
    for (const auto x : factor) {
        bool good = true;
        for (int i = 0; i < N && good; i += x) {
            for (int j = 0; j < N && good; j += x) {
                int cnt = cum[i+x][j+x] - cum[i+x][j] - cum[i][j+x] + cum[i][j];
                if (cnt != x * x && cnt != 0)
                    good = false;
            }
        }
        if (good)
            ans = x;
    }
    cout << ans << '\n';
    return 0;
}
