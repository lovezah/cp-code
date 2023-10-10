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

#define dbg(x) cout << #x << ": " << x << endl

int n;
int a[nax];
int nxt[nax][2];
void solve(int tc = 1) {
    cin >> n;
    F(i, 0, n) cin >> a[i];
    vpi stk;
    F(i, 0, n+1) nxt[i][0] = nxt[i][1] = n;
    F(i, 0, n) {
        while (sz(stk) && a[i] > stk.back().s) {
            nxt[stk.back().f][0] = i;
            stk.pop_back();
        }
        stk.pb({i, a[i]});
    }
    stk.clear();
    F(i, 0, n) {
        while (sz(stk) && a[i] < stk.back().s) {
            nxt[stk.back().f][1] = i;
            stk.pop_back();
        }
        stk.pb({i, a[i]});
    }
    map<int, set<int>> lst;
    ll bad = 0;
    int R = n;
    FF(i, 0, n) {
        if (i + 2 < n) {
            vi cand;
            cand.pb(nxt[i][0]);
            cand.pb(nxt[i][1]);
            if (sz(lst[a[i]])) cand.pb(*lst[a[i]].begin());
            for (int p : cand) {
                if (p == n) continue;
                auto it = lst[a[p]].ub(p);
                if (it != lst[a[p]].end()) ckmin(R, *it);
                if (a[p] <= a[i]) ckmin(R, nxt[p][1]);
                if (a[p] >= a[i]) ckmin(R, nxt[p][0]);
            }
        }
        lst[a[i]].ins(i);
        bad += (n - 1 - R + 1);
    }
    cout << (ll)n * (n + 1) / 2 - bad << nl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
