#include <bits/stdc++.h>
using namespace std;
#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n - 1); i >= a; i--)
#define ll long long
#define vi vector<int>

const int nax = 300*1007;
int n;
int a[nax];
int b[nax];
void solve(int tc) {
    cin >> n;
    F(i, 0, n) {
        cin >> a[i];
    }
    int lst = 0;
    F(i, 0, n) {
        b[i] = lst + 1;
        if (b[i] == a[i])
            b[i] += 1;
        lst = b[i];
    }
    cout << lst << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
