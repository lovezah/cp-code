#include <bits/stdc++.h>

using namespace std;

void solve() {
    int K; cin >> K;
    if (K == 100) {
        cout << 1 << '\n';
    } else {
        int A = K, B = 100 - K;
        int g = gcd(A, B);
        A /= g; B /= g;
        cout << A + B << '\n';
    }
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
