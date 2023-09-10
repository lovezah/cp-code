#include <bits/stdc++.h>

using namespace std;

template<class T> struct fenwick {
    int n;
    vector<T> c;

    fenwick(int n_) { init(n_); }

    void init(int m) {
        n = m;
        c.assign(n+1, T());
    }
    void update(int x, T t) {
        for (int i = x+1; i <= n; i += i & -i) {
            c[i] += t;
        }
    }
    T prefix(int x) { // return range[0, x)
        T ret = T();
        for (int i = x; i > 0; i -= i & -i) 
            ret +=  c[i];
        return ret;
    }
    T suffix(int x) { // return range[x, n)
        return prefix(n) - prefix(x);
    }
    T range(int l, int r) { // return range[l, r)
        return prefix(r) - prefix(l);
    }
};

void solve() {
    int N, M; cin >> N >> M;
    vector A(N, vector<int>(M));
    for (auto &a : A) for (auto &v : a) cin >> v;
    struct dat {
        int MAX, MIN;
        dat() : MAX(0), MIN(1000001) {}
        dat(int mx, int mi) : MAX(mx), MIN(mi) {}
    };
    vector pre(N+1, vector<dat>(M+1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pre[i][j+1].MAX=max(pre[i][j].MAX, A[i][j]);
            pre[i][j+1].MIN=min(pre[i][j].MIN, A[i][j]);
        }
    }
    vector suf(N+1, vector<dat>(M+1));
    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            suf[i][j].MAX = max(suf[i][j+1].MAX, A[i][j]);
            suf[i][j].MIN = min(suf[i][j+1].MIN, A[i][j]);
        }
    }
    struct split {
        int PRE_MAX, PRE_MIN, SUF_MAX, SUF_MIN, id;
        split() : PRE_MAX(0), PRE_MIN(1000001), SUF_MAX(0), SUF_MIN(1000001) {}
        split(int a, int b, int c, int d, int e) : PRE_MAX(a), PRE_MIN(b), SUF_MAX(c), SUF_MIN(d), id(e) {}
        bool operator < (const split &other) const {
            return this->PRE_MAX < other.PRE_MAX;
        }
    };
    fenwick<int> fen(1000001);
    for (int m = 1; m < M; m++) {
        vector<split> v;
        for (int n = 0; n < N; n++)
            v.emplace_back(pre[n][m].MAX, pre[n][m].MIN, suf[n][m].MAX, suf[n][m].MIN, n);
        sort(v.begin(), v.end());
        int S = v.size();
        for (int n = 0; n < N; n++)
            fen.update(v[n].PRE_MIN, 1);
        multiset<int> blue, red;
        for (int i = 0; i < S; i++)
            red.insert(v[i].SUF_MAX);
        for (int i = 0; i < S; i++) {
            int pre_max = v[i].PRE_MAX;
            blue.insert(v[i].SUF_MIN);
            red.extract(v[i].SUF_MAX);
            fen.update(v[i].PRE_MIN, -1);
            while (i + 1 < S && v[i+1].PRE_MAX == pre_max) {
                i++;
                blue.insert(v[i].SUF_MIN);
                red.extract(v[i].SUF_MAX);
                fen.update(v[i].PRE_MIN, -1);
            }
            // the number of blue guys is i + 1.
            int C = fen.suffix(pre_max + 1);
            if (C + i + 1 != N)
                continue;
            if ((int)blue.size() == N || C == 0) 
                continue;
            if (*blue.begin() <= *red.rbegin())
                continue;
            cout << "YES" << '\n';
            vector<char> ans(N);
            for (int id = 0; id < N; id++)
                ans[v[id].id] = (id < i + 1 ? 'B' : 'R');
            for (int id = 0; id < N; id++)
                cout << ans[id];
            cout << ' ' << m << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }    
    return 0;
}
