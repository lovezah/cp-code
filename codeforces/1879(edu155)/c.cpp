#include <bits/stdc++.h>
using namespace std;
#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n - 1); i >= a; i--)
#define ll long long
#define vi vector<int>

const int nax = 200*1007;
const ll mod = 998244353;
string s;
int n;

ll fac[nax];

void solve(int tc) {
    cin >> s;
    n = s.size();

    vi seq;
    int opt = 0;
    F(i, 0, n) {
        int j = i;
        while (j + 1 < n && s[j+1] == s[j])
            j++;
        opt += j - i;
        if (j - i > 0) seq.push_back(j - i);
        i = j;
    }
    // cout << opt << '\n';
    cout << opt << ' ';
    ll ans = 1;
    for (auto v : seq) {
        ans = ans * (ll)(v + 1) % mod;
    }
    ans = ans * fac[opt] % mod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fac[0] = 1;
    F(i, 1, nax) fac[i] = fac[i-1] * i % mod;

    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
