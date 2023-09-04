#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int ans = 2e9;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        ans = min(ans, abs(x));
    }
    cout << ans << '\n';
    return 0;
}
