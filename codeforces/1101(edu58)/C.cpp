#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> L(N), R(N);
    vector<array<int, 2>> seg(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        seg[i] = {L[i], R[i]};
    }
    ranges::sort(R);
    ranges::sort(L);
    for (int i = 0; i < N; i++) {
        while (i + 1 < N && R[i+1] == R[i]) {
            i++;
        }
        // i+1
        auto it = upper_bound(L.begin(), L.end(), R[i]);
        if (it == L.begin()) continue;
        it = prev(it);
        int cl = std::distance(it, L.end()) - 1;
        int cr = i + 1;
        // cerr << "dbg : " << i << ' ' << cl << ' ' << cr << '\n';
        if (cl > 0 && cr > 0 && cl + cr == N) {
            for (int j = 0; j < N; j++) {
                if (seg[j][1] <= R[i]) cout << 1 << ' ';
                else cout << 2 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
