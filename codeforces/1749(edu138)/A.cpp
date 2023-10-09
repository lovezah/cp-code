#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    vector<int> cols(N), rows(N);
    for (int m = 0; m < M; m++) {
        int x, y; cin >> x >> y;
        x--, y--;
        rows[x]++;
        cols[y]++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rows[i] == 0 && cols[j] == 0) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
