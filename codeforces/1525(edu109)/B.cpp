#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a, a--;
    if (is_sorted(A.begin(), A.end())) {
        cout << 0 << '\n';
    } else if (A[0] == 0 || A[N-1] == N-1) {
        cout << 1 << '\n';
    } else if (A[0] == N-1 && A[N-1] == 0) {
        cout << 3 << '\n';
    } else {
        cout << 2 << '\n';
    }
    // 3 2 1
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
