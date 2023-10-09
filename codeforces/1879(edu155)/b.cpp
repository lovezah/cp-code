#include <bits/stdc++.h>
using namespace std;
#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n - 1); i >= a; i--)
#define ll long long

const int nax = 300*1007;
int n;
ll a[nax];
ll b[nax];
void solve(int tc) {
    cin >> n;
    F(i, 0, n) cin >> a[i];
    F(i, 0, n) cin >> b[i];
    ll r = 0, c = 0;
    F(i, 0, n) r += a[i], c += b[i];
    ll ans = (ll)2e18;
    F(i, 0, n) {
        ans = min(ans, a[i] * n + c);
        ans = min(ans, b[i] * n + r);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
