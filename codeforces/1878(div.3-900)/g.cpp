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
const int nax = 200*1007;

int n, q;
int a[nax];
vi adj[nax];

const int LOG = 19;
int vals[LOG][nax];
int go[LOG][nax];
int dep[nax];
int ans;
void dfs(int u = 0, int fa = -1) {
    dep[u] = ~fa ? dep[fa] + 1 : 1;
    trav(v, adj[u]) if (v != fa) {
        go[0][v] = u;
        vals[0][v] = a[v] | a[u];
        dfs(v, u);
    }
}
pi get(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int v = a[x];
    FF(i, 0, LOG) if (~go[i][x] && dep[go[i][x]] >= dep[y]) {
        v |= vals[i][x];
        x = go[i][x];
    }
    if (x == y) return pi(v, x);
    FF(i, 0, LOG) if (~go[i][x] && ~go[i][y] && go[i][x] != go[i][y]) {
        v |= vals[i][x] | vals[i][y];
        x = go[i][x];
        y = go[i][y];
    }
    v |= vals[0][x];
    return pi(v, go[0][x]);
}
int getNum(int x) {
    int c = 0;
    FF(i, 0, 30) if (x >> i & 1) c++;
    return c;
}
int jump(int x, int y, int k) {
    FF(i, 0, LOG) if (k >> i & 1) {
    }
}
void solve(int tc) {
    cin >> n;
    F(i, 0, n) cin >> a[i];
    F(i, 0, LOG) F(j, 0, n) go[i][j] = -1;
    F(i, 1, n) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    F(i, 1, LOG) F(j, 0, n) if (~go[i-1][j]) {
        vals[i][j] = vals[i-1][j] | vals[i-1][go[i-1][j]];
        go[i][j] = go[i-1][go[i-1][j]];
    }
    cin >> q;
    F(i, 0, q) {
        int x, y; cin >> x >> y;
        x--, y--;
        auto [mv, anc] = get(x, y);
        ans = 0;
        int cnt = getNum(mv);
        int d = dep[x] + dep[y] - 2 * dep[anc];
        {
        }
        {

        }
        cout << ans << " \n"[i+1==q];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
