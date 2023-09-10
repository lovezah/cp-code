#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S; cin >> S;
    int N = S.size();
    bool ok = false;
    for (int mask = 0; mask < 1 << 3; mask++) {
        string T(N, '?');
        for (int j = 0; j < N; j++) {
            int t = S[j] - 'A';
            if (mask >> t & 1) {
                T[j] = '(';
            } else {
                T[j] = ')';
            }
        }
        bool ok1 = true;
        int bal = 0;
        for (int j = 0; j < N; j++) {
            if (T[j] == '(') bal++;
            else bal--;
            if (bal < 0) ok1 = false;
        }
        if (bal != 0) ok1 = false;
        if (ok1) ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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
