#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S; cin >> S;
    int N = S.size();
    int AB = 0, BA = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'a' && S[i+1] == 'b') AB++;
        if (S[i] == 'b' && S[i+1] == 'a') BA++;
    }
    if (AB == BA) cout << S << '\n';
    else {
        S[0] = 'a' ^ 'b' ^ S[0];
        cout << S << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
