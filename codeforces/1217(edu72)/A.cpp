#include <bits/stdc++.h>

using namespace std;

void solve() {
    int S, I, E; cin >> S >> I >> E;
    int low = 0, high = E + 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (S + mid <= I + E - mid)
            low = mid + 1;
        else 
            high = mid;
    }
    cout << E - low + 1 << '\n';
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
