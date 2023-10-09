#include <bits/stdc++.h>
using namespace std;
#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n - 1); i >= a; i--)
#define ll long long
#define vi vector<int>

const int nax = 111;
int n;
set<int> a[nax];
void solve(int tc) {
    cin >> n;
    F(i, 0, n) a[i].clear();
    F(i, 0, n) {
        int k; cin >> k;
        F(j, 0, k) {
            int x; cin >> x;
            a[i].insert(x);
        }
    }
    int ans = 0;
    set<int> all;
    F(i, 0, n) for (auto v : a[i]) all.insert(v);
    int tot = all.size();
    // cout << "tt : " << tot << '\n';
    F(i, 1, 51) if (all.count(i)) {
        set<int> cur;
        F(j, 0, n) {
            if (a[j].count(i)) {
                continue;
            }
            for (auto v : a[j])
                cur.insert(v);
        }
        if (cur.size() != all.size()) {
            ans = max(ans, (int)cur.size());
        }
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
