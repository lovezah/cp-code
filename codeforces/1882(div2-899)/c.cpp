#include <bits/stdc++.h>
using namespace std;
#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n - 1); i >= a; i--)
#define ll long long
#define vi vector<int>

const int nax = 200*1007;
int n;
int a[nax];
int vis[nax];
ll suf[nax];
void solve(int tc) {
    cin >> n;
    F(i, 0, n) cin >> a[i];
    F(i, 0, n + 11) vis[i] = suf[i] = 0;
    int f = 0;
    F(i, 0, n) {
        if (a[i] >= 0) {
            if (!f && (i&1)) continue;
            vis[i] = 1;
            if (i&1^1) f = 1;
        }
    }
    ll ans = 0;
    vi na;
    F(i, 0, n) {
        if (vis[i]) ans += a[i];
        else na.push_back(a[i]);
    }
    if (na.size() > 0) {    
        int m = na.size();
        FF(i, 0, m) suf[i] = suf[i+1] + (na[i] > 0 ? na[i] : 0);
        ll cur = 0;
        F(i, 0, m) {
            if (i % 2 == 1) {
                cur = max(cur, suf[i+1]);
            } else {
                cur = max(cur, suf[i+1] + na[i]);
            }
        }
        ans += cur;
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
