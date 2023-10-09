#include <bits/stdc++.h>

using namespace std;

const int nax = 100*1007;
int64_t n;
int64_t a[nax];
int64_t freq[nax];
const int64_t mod = 998244353;
int64_t modpow(int64_t a, int64_t k) {
    int64_t r = 1;
    for (; k > 0; k >>= 1, a = a * a % mod) {
        if (k & 1) r = r * a % mod;
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            a[i] = max(a[i], a[j]);
        }
        freq[a[i]] += 1;
    }
    const int MAXV = 100001;
    int64_t ans = 0;
    int64_t tot = 0;
    for (int i = MAXV - 1; i >= 0; i--) {
        if (freq[i]) {
            int64_t cmin = n - tot - freq[i];
            int64_t ne = modpow(2LL, freq[i]) - 1;
            if (ne < 0) ne += mod;
            ne %= mod;
            int64_t c = ne * modpow(2LL, cmin) % mod;
            ans += c * (int64_t)(i) % mod;
            ans %= mod;
            tot += freq[i];
        }
    }
    if (ans < 0) ans += mod;
    cout << ans << '\n';
    return 0;
}
