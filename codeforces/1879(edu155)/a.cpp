#include <bits/stdc++.h>
using namespace std;
#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n - 1); i >= a; i--)
#define ll long long

const int nax = 111;
int n;
int s[nax], e[nax];
void solve(int tc) {
    cin >> n;
    F(i, 0, n) cin >> s[i] >> e[i];
    int w = s[0], c = e[0];
    F(i, 1, n) {
        if (s[i] >= w && e[i] >= c) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << w << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
