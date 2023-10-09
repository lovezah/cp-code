#include <bits/stdc++.h>
using namespace std;

template<class T> struct RMQ {
    int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
    int n;
    std::vector<std::vector<int>> ids;
    std::vector<T> vals;
    int comb(int a, int b) {
        // TODO: should fix this guy
        // return (vals[a] < vals[b] ? a : b);
    }
    RMQ() {}
    RMQ(const std::vector<T> &vals_) {
        init(vals_);
    }
    void init(const std::vector<T> &vals_) {
        vals = vals_;
        n = int(vals.size());
        int logn = highest_bit(n) + 1;
        ids.assign(logn, std::vector<int>(n));
        for (int i = 0; i < n; i++) ids[0][i] = i;
        for (int i = 1; i < logn; i++)
            for (int j = 0; j + (1 << i) < n; j++)
                ids[i][j] = comb(ids[i-1][j], ids[i-1][j+(1<<(i-1))]);
    }
    int query_index(int a, int b) {
        b++;
        int logn = highest_bit(b-a);
        return comb(ids[logn][a], ids[logn][b-(1<<logn)]);
    }
    T query_value(int a, int b) {
        return vals[query_index(a,b)];
    }
};