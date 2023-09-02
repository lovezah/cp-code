#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<int> A(N); for (auto &a : A) cin >> a;
    string S; cin >> S;

    int cur = 1;
    long long ans = 0;
    priority_queue<int> PQ; PQ.push(A[0]);

    auto choose = [&]() -> long long {
        long long ret = 0;
        for (int j = 0; j < min(K, cur); j++) {
            ret += PQ.top();
            PQ.pop();
        }
        while (!PQ.empty()) PQ.pop();
        return ret;
    };

    for (int i = 1; i < N; i++) {
        if (S[i] == S[i-1]) {
            cur++;
            PQ.push(A[i]);
        } else {
            ans += choose();
            cur = 1;
            PQ.push(A[i]);
        }
    }
    if (cur > 0) ans += choose();
    cout << ans << '\n';
    return 0;
}
