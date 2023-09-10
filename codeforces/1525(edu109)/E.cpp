#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vl = vector<ll>;

#define F(i, a, n) for(int i=a,i##end=n; i<i##end; i++)
#define FF(i, a, n) for(int i=n-1,i##end=a; i>=i##end; i--)

#define f first 
#define s second 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define pb push_back
#define mp make_pair

template<class T>
using vt = vector<T>;
template<class T, size_t S>
using ar = array<T, S>;
template<class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T>
using pq = priority_queue<T>;
template<class U, class V>
bool ckmax(U &a, V b) { return b > a ? a = b, true : false; }
template<class U, class V>
bool ckmin(U &a, V b) { return b < a ? a = b, true : false; }

#define tcT template<class T
#define EACH(x, a) for(auto &x : a)
tcT> void read(vt<T> &v);
tcT> void read(T &x) { cin >> x; }
int read() { int x; read(x); return x; }
void read(double &x) { string t; read(t); x=stod(t); }
void read(long double &x) { string t; read(t); x=stold(t); }
tcT, class U> void read(pair<T, U> &x) { T a; U b; read(a); read(b); x=make_pair(a, b); }
tcT, size_t S> void read(ar<T, S> &a) { F(i, 0, S) read(a[i]); }
tcT, class... A> void read(T &t, A&... a) { read(t); read(a...); }
tcT> void read(vt<T> &x) { EACH(a, x) read(a); }
 
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
tcT> string to_string(T v) {
    bool f=1; string res="";
    EACH(x, v) { if(!f) res+=' '; f=0; res+=to_string(x); }
    res+="";
    return res;
}
tcT> void write(T x) { cout << to_string(x); }
template<class H, class... T> void write(const H &h, const T&... t) {
    write(h); write(t...);
}
void print() { write("\n"); }
template<class H, class... T> void print(const H &h, const T&... t) {
    write(h); if(sizeof... (t)) write(' '); print(t...);
}
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h); if(sizeof... (t)) cerr << ", "; DBG(t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else 
#define dbg(...) 0
#endif

const char nl = '\n';
const int nax=50100;

const ll mod = 998244353;
ll pow(ll a, ll k) {
    ll r=1;
    for (; k; k>>=1, a=a*a%mod) {
        if (k&1) r=r*a%mod;
    }
    return r;
}
ll inv(ll a) {
    return pow(a, mod-2);
}
int n, m;
int c[nax][22];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    read(n, m);
    F(i, 0, n) F(j, 0, m) {
        c[j][read()-1]++;
    }
    ll ans = 0;
    ll ba = 1;
    F(i, 1, n+1)
        ba = ba * i % mod;
    ba=inv(ba);
    F(i, 0, m) {
        ll s = 0, v = 1;
        FF(j, 1, n+1) {
            s += c[i][j];
            s %= mod;
            v = v * s % mod;
            s--;
        }
        v = v * ba % mod;
        v = (1 - v) + mod;
        v %= mod;
        ans = (ans + v) % mod;
    }
    print(ans);
}