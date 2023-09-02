#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    long long K; 
    cin >> N >> M >> K;
    vector<int> A(N); for (auto &a : A) cin >> a;
    ranges::sort(A);
    long long v1 = A[N-1], v2 = A[N-2];
    long long ans = M / (K+1) * (K*v1+v2);
    M %= K+1;
    ans += M*v1;
    cout << ans << '\n';
    return 0;
}
