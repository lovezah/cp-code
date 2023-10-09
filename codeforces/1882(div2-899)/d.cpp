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

int n;
int a[nax];
vi adj[nax];
int sz[nax];
ll dp1[nax], dp2[nax];
void dfs1(int u = 0, int fa = -1) {
    sz[u] = 1;
    dp1[u] = dp2[u] = 0;
    trav(v, adj[u]) if (v != fa) {
        dfs1(v, u);
        sz[u] += sz[v];
        dp1[u] += dp1[v] + (ll)(a[u] ^ a[v]) * sz[v];
    }
}
void dfs2(int u = 0, int fa = -1) {
    trav(v, adj[u]) if (v != fa) {
        dp2[v] = dp1[u] + dp2[u] - dp1[v] - (ll)(a[u] ^ a[v]) * sz[v];
        dp2[v] += (ll)(n - sz[v]) * (a[u] ^ a[v]);
        dfs2(v, u);
    }
}
void solve(int tc) {
    cin >> n;
    F(i, 0, n) adj[i].clear(), cin >> a[i];
    F(i, 1, n) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1();
    dfs2();
    F(i, 0, n) cout << dp1[i] + dp2[i] << " \n"[i+1==n];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
