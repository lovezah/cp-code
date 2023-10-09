#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

template<class T>
using vt = vector<T>;
typedef vt<int> vi;
typedef vt<ll> vl;
typedef vt<pi> vpi;
typedef vt<pl> vpl;

#define sz(a) (int)(a).size()
#define pb push_back
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ins insert
#define lb lower_bound
#define ub upper_bound

#define F(i, a, n) for (int i = a; i < n; i++)
#define FF(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define trav(a, x) for (auto &a : x)

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vt<T>, greater<T>>;
template<class T, class U> bool ckmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<class T, class U> bool ckmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

const char nl = '\n';
const int nax = 200*1007;

int n;
int a[nax];
int q;

int seg[nax*4];
void pull(int p) {
    seg[p] = seg[p*2] & seg[p*2+1];
}
void build(int p = 1, int l = 0, int r = n-1) {
    if (l == r) {
        seg[p] = a[l];
        return;
    }
    int mi = (l + r) / 2;
    build(p * 2, l, mi);
    build(p * 2 + 1, mi + 1, r);
    pull(p);
}
int query(int ql, int qr, int p = 1, int l = 0, int r = n - 1) {
    if (ql == l && qr == r) {
        return seg[p];
    }
    int mi = (l + r) / 2;
    if (qr <= mi) return query(ql, qr, p * 2, l, mi);
    else if (ql >= mi + 1) return query(ql, qr, p * 2 + 1, mi + 1, r);
    else return (query(ql, mi, p * 2, l, mi) & query(mi + 1, qr, p * 2 + 1, mi + 1, r));
}
void solve(int tc) {
    cin >> n;
    F(i, 0, n) cin >> a[i];
    build();
    cin >> q;
    F(i, 0, q) {
        int l, k; cin >> l >> k;
        l--;
        int lo = l - 1, hi = n - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (query(l, mi) >= k) lo = mi;
            else hi = mi - 1;
        }
        if (lo < l) cout << -1 << ' ';
        else cout << lo + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
