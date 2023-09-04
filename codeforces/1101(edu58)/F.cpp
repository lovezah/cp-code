#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<long long> A(N); for (auto &a : A) cin >> a;
    for (int i = N - 1; i >= 1; i--)
        A[i] = A[i] - A[i-1];
    for (int i = 0; i < N - 1; i++) 
        A[i] = A[i+1];
    vector<long long> S(M), F(M), C(M), R(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> F[i] >> C[i] >> R[i];
        S[i]--; F[i]--;
    }
    vector<int> ids(M);
    iota(ids.begin(), ids.end(), 0);
    random_shuffle(ids.begin(), ids.end());
    auto check = [&](long long m, int id) -> bool {
        long long fuel = m;
        int cnt = 0;
        for (int i = S[id]; i < F[id]; i++) {
            long long need = A[i] * C[id];
            if (fuel >= need) {
                fuel -= need;
            } else {
                fuel = m;
                cnt += 1;
                if (fuel < need) return false;
                fuel -= need;
            }
        }
        return cnt <= R[id];
    };
    long long ans = 0;
    for (auto i : ids) {
        if (check(ans, i)) continue;
        long long low = 1, high = (long long)1e18;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (check(mid, i))  
                high = mid;
            else 
                low = mid + 1;
        }
        ans = max(ans, low);
    }
    cout << ans << '\n';
    return 0;
}
