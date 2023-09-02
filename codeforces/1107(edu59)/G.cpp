#include <bits/stdc++.h>

using namespace std;

template<class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, size, log;
    vector<S> v;
    segtree(int n_) : segtree(vector<S>(n_, e())) {}
    segtree(const vector<S> &v_) : n((int)v_.size()) {
        size = 1;
        while (size < n) size *= 2;
        log = __builtin_ctz(size);
        v = vector<S>(size * 2, e());
        for (int i = 0; i < n; i++)
            v[i+size] = v_[i];
        for (int i = size - 1; i > 0; i--) {
            update(i);
        }
    }
    void update(int p) { v[p] = op(v[p*2], v[p*2+1]); }
    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += size;
        v[p] = x;
        for (int i = p / 2; i > 0; i /= 2)
            update(i);
    }
    S get(int p) const {
        assert(0 <= p && p < n);
        return v[p+size];
    }
    S prod(int l, int r) const { // [l, r)
        assert(0 <= l && l <= r && r <= n);
        S vl = e(), vr = e();
        for (l += size, r += size; l < r; l /= 2, r /= 2) {
            if (l & 1) vl = op(vl, v[l++]);
            if (r & 1) vr = op(v[--r], vr);
        }
        return op(vl, vr);
    }
    S all_prod() const { return v[1]; }
    template<bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template<class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if (l == n) return n;
        l += size;
        S val = e();
        do {
            while (l % 2 == 0) l /= 2;
            if (!f(op(val, v[l]))) {
                while (l < size) {
                    l = l * 2;
                    if (f(op(val, v[l]))) {
                        val = op(val, v[l]);
                        l++;
                    }
                }
                return l - size;
            }
            val = op(val, v[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }
    template<bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template<class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S val = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r /= 2;
            if (!f(op(v[r], val))) {
                while (r < size) {
                    r = r * 2 + 1;
                    if (f(op(v[r], val))) {
                        val = op(v[r], val);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            val = op(v[r], val);
        } while ((r & -r) != r);
        return 0;
    }
};
// max_right : the maximum r that satisfies f(op(a[l], a[l+1], ..., a[r-1])) = true.
// min_left : the minimum l that satisfies f(op(a[l], a[l+1], ..., a[r-1])) = true.
using ll = long long;
ll op1(ll a, ll b) { return max(a, b); }
ll e1() { return -(ll)2e18; }
ll op2(ll a, ll b) { return min(a, b); }
ll e2() { return (ll)2e18; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A; cin >> N >> A;
    vector<long long> D(N+1), C(N+1);
    vector<long long> cum{0};
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> D[i] >> C[i];
        C[i] = A - C[i];
        ans = max(ans, C[i]);
        cum.push_back(cum.back() + C[i]);
    }
    segtree<long long, op1, e1> seg_max(cum);
    segtree<long long, op2, e2> seg_min(cum);
    vector<pair<int, int>> d;
    for (int i = 2; i <= N; i++)
        d.push_back({D[i] - D[i-1], i});
    ranges::sort(d);
    ranges::reverse(d);
    set<pair<int, int>> ps;
    ps.insert({1, N});
    for (auto a : d) {
        auto b = *prev(ps.lower_bound({a.second, -1}));
        ps.erase(b);
        ps.insert({b.first, a.second - 1});
        ps.insert({a.second, b.second});
        // cerr << a.first << '\n';
        // cerr << a.second << '\n';
        // cerr << a.second-1 << ' ' << a.second << '\n';
        // cerr << a.second << ' ' << b.second + 1 << '\n';
        // cerr << b.first - 1 << ' ' << a.second - 1 << '\n';
        ans = max(ans, seg_max.prod(a.second, b.second + 1) - 
                        seg_min.prod(b.first - 1, a.second - 1)
                         - (long long)a.first * a.first);
        // cerr << seg_max.prod(a.second, b.second + 1) << '\n';
        // cerr << seg_min.prod(b.first - 1, a.second - 1) << '\n';
        // cerr << '\n';
    }
    cout << ans << '\n';
    return 0;
}
