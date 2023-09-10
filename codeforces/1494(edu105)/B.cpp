#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, U, R, D, L;
    cin >> N >> U >> R >> D >> L;
    bool ok = false;
    // 0 1
    // 2 3
    for (int mask = 0; mask < 1 << 4; mask++) {
        bool ok1 = true;
        int cntUp = (mask >> 0 & 1) + (mask >> 1 & 1);
        int cntDown = (mask >> 2 & 1) + (mask >> 3 & 1);
        int cntLeft = (mask >> 0 & 1) + (mask >> 2 & 1);
        int cntRight = (mask >> 1 & 1) + (mask >> 3 & 1);
        if (cntUp > U || cntUp + N - 2 < U) ok1 = false;
        if (cntDown > D || cntDown + N - 2 < D) ok1 = false;
        if (cntLeft > L || cntLeft + N - 2 < L) ok1 = false;
        if (cntRight > R || cntRight + N - 2 < R) ok1 = false;
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
