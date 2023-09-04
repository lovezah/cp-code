#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    int M; cin >> M;
    vector<int> C(M), D(M);
    for (auto &c : C) cin >> c;
    for (auto &d : D) cin >> d;

    map<int, int> freq;
    for (int i = 0; i < M; i++)
        freq[C[i]] = D[i];

    map<int, bool> found;
    for (int i = 0; i < N; i++)
        found[A[i]] = true;
    for (int i = 0; i < M; i++) {
        if (!found[C[i]]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        if (B[i] < freq[A[i]]) {
            ans = 0; break;
        }
        if (B[i] == freq[A[i]]) continue;
        ans = ans * 2 % mod;
    }
    cout << ans << '\n';
    return 0;
}
