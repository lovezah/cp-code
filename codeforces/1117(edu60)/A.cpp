#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    int goal = *ranges::max_element(A);
    int ans = 0, cur = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == goal) {
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
