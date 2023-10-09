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
const int nax = 500*1007;

ll n, q;
ll tot = 1;
map<int, ll> freq;
void gao(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int c = 0;
            while (x % i == 0) {
                c += 1;
                x /= i;
            }
            tot /= (freq[i] + 1);
            freq[i] += c;
            tot *= (freq[i] + 1);
        }
    }
    if (x > 1) {
        tot /= (freq[x] + 1);
        freq[x]++;
        tot *= (freq[x] + 1);
    }
}

vi seq;
void init() {
    seq = vi(1, n);
    freq.clear();
    tot = 1;
    gao(n);
}
void solve(int tc) {
    cin >> n >> q;
    init();
    F(i, 0, q) {
        int k; cin >> k;
        if (k == 1) {
            ll x; cin >> x;
            seq.pb(x);
            gao(x);
            ll now = 1;
            for (auto v : seq) {
                now = now * v % tot;
            }
            cout << (now == 0 ? "YES" : "NO") << nl;
        } else {
            init();
        }
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
