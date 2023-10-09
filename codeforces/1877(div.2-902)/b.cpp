#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, P; cin >> N >> P;
        std::vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> A[i].second;
        }
        sort(A.begin(), A.end(), [&](auto a, auto b) {
            return a.second < b.second;
        });
        int64_t ans = 0;
        using TT = pair<int, int>;
        priority_queue<TT, vector<TT>, greater<TT>> PQ;
        PQ.push({P, N});
        for (int i = 0; i < N; i++) {
            auto [c, rem] = PQ.top(); PQ.pop();
            ans += c;
            rem -= 1;
            if (rem > 0) PQ.push({c, rem});
            if (A[i].first > 0) PQ.push({A[i].second, A[i].first});
        }
        cout << ans << '\n';
    }
    return 0;
}
