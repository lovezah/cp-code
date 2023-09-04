#include <bits/stdc++.h>

using namespace std;

struct linear_bias {
    int n;
    vector<long long> num;
    linear_bias(int n_) : n(n_), num(n) {}
    bool insert(long long x) {
        for (int i = n - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!num[i]) {
                    num[i] = x;
                    return true;
                } else {
                    x = x ^ num[i];
                }
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    linear_bias g(40);
    for (int i = 0; i < N; i++) {
        if (i) A[i] ^= A[i-1];
        g.insert(A[i]);
    }
    if (A[N-1] == 0) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < 40; i++)
        if (g.num[i] != 0)
            ans++;
    cout << ans << '\n';
    return 0;
}
