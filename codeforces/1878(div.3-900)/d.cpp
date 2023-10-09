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
template<class T, class U> bool ckmin(T &a, U b) { return b < a ? a = b, 1 : 0; }
template<class T, class U> bool ckmax(T &a, U b) { return b > a ? a = b, 1 : 0; }

const char nl = '\n';
const int nax = 500*1007;

int n, k, q;
string s;
pi seg[nax];

int where(int i) {
    int lo = 0, hi = k-1;
    while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if (seg[mi].f <= i && i <= seg[mi].s) return mi;
        if (seg[mi].f > i) hi = mi - 1;
        else if (seg[mi].s < i) lo = mi + 1;
    }
    return lo;
}

int c[nax];
void solve(int tc) {
    cin >> n >> k;
    cin >> s;
    F(i, 0, k) cin >> seg[i].f, seg[i].f--;
    F(i, 0, k) cin >> seg[i].s, seg[i].s--;
    F(i, 0, n+1) c[i] = 0;
    cin >> q;
    F(i, 0, q) {
        int x; cin >> x; x--;
        int id = where(x);
        int z = seg[id].s + seg[id].f - x;
        int y = max(x, z);
        x = min(x, z);
        c[x]++, c[y+1]--;
    }
    F(i, 1, n) c[i] += c[i-1];
    F(i, 0, n) {
        if (c[i]&1^1) continue;
        int id = where(i);
        int j = seg[id].s + seg[id].f - i;
        c[j]++;
        swap(s[i], s[j]);
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
