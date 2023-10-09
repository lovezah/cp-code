#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int tot = 0;
        for (int i = 0; i < N-1; i++) {
            int x; cin >> x;
            tot += x;
        }
        cout << -tot << '\n';
    }
    return 0;
}
