#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    string S; cin >> S;
    int ones = 0, zeros = 0;
    for (int i = 1; i < N; i++) {
        ones += (S[i] == '1' && S[i-1] == '1');
        zeros += (S[i] == '0' && S[i-1] == '0');
    }
    cout << max(ones, zeros) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
