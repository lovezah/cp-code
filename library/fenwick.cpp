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
