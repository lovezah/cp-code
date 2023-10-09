#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S; cin >> S;
    int N = S.size();
    vector<int> nxt(N+1); nxt[N] = N;
    for (int i = N - 1; i >= 0; i--) 
        nxt[i] = (S[i] == '1' ? i : nxt[i+1]);
    long long ans = 0;
    for (int l = 0; l < N; l++) {
        int val = 0;
        for (int r = nxt[l]; r < N; r++) {
            val *= 2;
            if (S[r] == '1')
                val += 1;
            if (val == r - l + 1)
                ans++;
            if (val > N) break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
