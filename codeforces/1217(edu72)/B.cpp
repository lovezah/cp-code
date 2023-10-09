#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, X; cin >> N >> X;
    vector<int> D(N), H(N);
    for (int i = 0; i < N; i++)
        cin >> D[i] >> H[i];
    int damage = -1, kill = -1;
    for (int i = 0; i < N; i++) {
        damage = max(damage, D[i] - H[i]);
        kill = max(kill, D[i]);
    }
    if (kill >= X) {
        cout << 1 << '\n';
        return;
    }
    if (damage <= 0) {
        cout << -1 << '\n';
    } else {
        cout << (X - kill + damage - 1) / damage + 1 << '\n';
    }
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
