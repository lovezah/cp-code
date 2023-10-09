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

using S = array<array<int, 2>, 9>;
const int INF = (int)1e9 + 1;
S e() {
    S ans{};
    for (int i = 0; i < 9; i++)
        ans[i] = {INF, INF};
    return ans;
}
S op(S a, S b) { 
    S cmb = e();
    for (int i = 0; i < 9; i++) {
        if (a[i][0] < b[i][0])
            cmb[i] = {a[i][0], min(a[i][1], b[i][0])};
        else 
            cmb[i] = {b[i][0], min(b[i][1], a[i][0])};
    }
    return cmb;
}
S foo(int val) {
    S c = e();
    int val_orig = val;
    for (int j = 0; j < 9 && val > 0; j++) {
        int v = val % 10;
        val /= 10;
        if (v > 0) c[j][0] = val_orig;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> A(N); for (auto &a : A) cin >> a;
    segtree<S, op, e> seg(N);
    for (int i = 0; i < N; i++) {
        seg.set(i, foo(A[i]));
    }
    while (M--) {
        int opt; cin >> opt;
        if (opt == 1) {
            int p, x; cin >> p >> x; p--;
            seg.set(p, foo(x));
            A[p] = x;
        } else {
            int l, r; cin >> l >> r; l--;
            S ret = seg.prod(l, r);
            int ans = (int)2e9 + 3;
            for (int i = 0; i < 9; i++) {
                if (ret[i][0] != INF && ret[i][1] != INF)
                    ans = min(ans, ret[i][0] + ret[i][1]);
            }
            if (ans == (int)2e9 + 3)
                ans = -1;
            cout << ans << '\n';
        }
    }
    return 0;
}