#include <bits/stdc++.h>
using namespace std;
#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n - 1); i >= a; i--)
#define ll long long
#define vi vector<int>

const int nax = 300*1007;
const ll mod = 998244353;
int n;
ll a[nax];
ll pref[nax];
ll sum[nax];
void solve(int tc) {
    cin >> n;
    F(i, 1, n + 1) cin >> a[i];
    if (n == 1) {
        cout << a[1] % mod << '\n';
        return;
    }
    ll ans = 0;
    F(i, 0, 31) {
        
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
