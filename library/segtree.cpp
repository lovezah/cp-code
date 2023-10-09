#include <bits/stdc++.h>
using namespace std;

template<class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n;
    vector<S> v;
    segtree() : n(0) {}
    segtree(int n_, S val = e()) {
        init(n_, val);
    }
    template<class T>
    segtree(vector<T> info) {
        init(info);
    }
    void init(int n_, S val = e()) {
        init(vector<S>(n_, val));
    }
    template<class T>
    void init(vector<T> info) {
        n = info.size();
        v.assign(4 << __lg(n), e());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                v[p] = info[l]; return;
            }
            int m = (l + r) / 2;
            build(p * 2, l, m);
            build(p * 2 + 1, m + 1, r);
            pull(p);
        };
        build(1, 0, n - 1);
    }
    void pull(int p) {
        v[p] = op(v[p*2], v[p*2+1]);
    }
    void modify(int x, const S &cv, int p, int l, int r) {
        if (l == r) {
            v[p] = cv; return;
        }
        int m = (l + r) / 2;
        if (x <= m) modify(x, cv, p * 2, l, m);
        else modify(x, cv, p * 2 + 1, m + 1, r);
        pull(p);
    }
    void modify(int x, const S &cv) {
        modify(x, cv, 1, 0, n - 1);
    }
    S query(int ql, int qr, int p, int l, int r) {
        if (ql == l && r == qr) {
            return v[p];
        }
        int m = (l + r) / 2;
        if (qr <= m) return query(ql, qr, p * 2, l, m);
        else if (ql > m) return query(ql, qr, p * 2 + 1, m + 1, r);
        else return op(query(ql, m, p * 2, l, m), query(m + 1, qr, p * 2 + 1, m + 1, r));
    }
    S query(int ql, int qr) {
        return query(ql, qr, 1, 0, n - 1);
    }
    template<class F>
    int find_first(int ql, int qr, F f, int p, int l, int r) {
        if (ql > r || qr < l || !f(v[p])) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        int ret = find_first(ql, qr, f, p * 2, l, m);
        if (ret == -1) {
            ret = find_first(ql, qr, f, p * 2 + 1, m + 1, r);
        }
        return ret;
    }
    template<class F>
    int find_first(int ql, int qr, F f) {
        return find_first(ql, qr, f, 1, 0, n - 1);
    }
};
using ll = int64_t;
ll op(ll a, ll b) { return max(a, b); }
ll e() { return 0LL; }