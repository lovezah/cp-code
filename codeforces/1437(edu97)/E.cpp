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
const int nax=500*1007;

int n,k;
int a[nax],b[nax];
vi seq;
int find(vi &q){
    int ret=0;
    int m=sz(q);
    vi v(m+1,2e9); v[0]=-2e9;
    F(i,0,m){
        int lo=0,hi=i;
        while(lo<hi){
            int mi=(lo+hi+1)/2;
            if(v[mi]<=q[i])lo=mi;
            else hi=mi-1;
        }
        ckmin(v[lo+1],q[i]);
        if(v[lo+1]!=2e9)ckmax(ret,lo+1);
    }
    return ret;
}
void solve(){
    read(n,k);
    F(i,1,n+1)read(a[i]);
    F(i,1,k+1)read(b[i]);
    a[0]=-2e9;
    a[n+1]=2e9;
    b[0]=0;
    b[k+1]=n+1;
    F(i,0,n+2)a[i]-=i;
    int ans=0;
    F(i,0,k+1){
        int l=b[i]+1,r=b[i+1]; // [l,r)
        // dbg(l,r);
        // F(j,l,r)dbg(a[j]);
        if(a[r]<a[l-1]){print(-1);return;}
        F(j,l,r)if(a[j]>=a[l-1]&&a[j]<=a[r])seq.pb(a[j]);
        ans+=r-l-find(seq);
        seq.clear();
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // F(sry_iamnoob,0,read())solve();
    solve();
}