#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    string S; cin >> S;
    if (N == 2) {
        if (S[0] >= S[1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n2\n";
            cout << S[0] << ' ' << S[1] << '\n';
        }
    } else {
        cout << "YES\n2\n";
        cout << S[0] << ' ' << S.substr(1) << '\n';
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
