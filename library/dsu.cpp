#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> par;
    int n = 0, comp = 0;

    DSU(int n_) { init(n_); }

    void init(int m) {
        n = m, comp = m;
        par.assign(n, -1);
    }
    int find(int x) {
        while (par[x] >= 0) {
            if (par[par[x]] >= 0)
                par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }
    int operator[] (int x) {
        return find(x);
    }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (-par[x] < -par[y]) swap(x, y);
        par[x] += par[y]; par[y] = x; comp--;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return -par[find(x)];
    }
};
