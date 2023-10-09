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
template<class T, size_t S>
using ar = array<T, S>;
typedef vt<int> vi;
typedef vt<ll> vl;
typedef vt<pi> vpi;
typedef vt<pl> vpl;

#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
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

mt19937 mrand(random_device{}());
int rng(int x) { return mrand() % x; }

const char nl = '\n';
const int nax = 1007;

void solve(int tc = 1) {
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
}
