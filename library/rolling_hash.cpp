#include <bits/stdc++.h>
using namespace std;

mt19937 mrand(random_device{}());
int rng(int x) { return mrand() % x; }

typedef pair<int64_t, int64_t> hashv;
const int64_t mod1 = 1000000007;
const int64_t mod2 = 1000000009;

hashv operator + (hashv a, hashv b) {
    hashv c(0, 0);
    c.first = a.first + b.first; if (c.first >= mod1) c.first -= mod1;
    c.second = a.second + b.second; if (c.second >= mod2) c.second -= mod2;
    return c;
}
hashv operator - (hashv a, hashv b) {
    hashv c(0, 0);
    c.first = a.first - b.first; if (c.first < 0) c.first += mod1;
    c.second = a.second - b.second; if (c.second < 0) c.second += mod2;
    return c;
}
hashv operator * (hashv a, hashv b) {
    return make_pair(a.first * b.first % mod1, a.second * b.second % mod2);
}

hashv base(13331, 1331);
hashv ff[nax], hs[nax], pB[nax];
hashv get(int l, int r) { // [l, r)
    return hs[r] - (hs[l] * pB[r-l]);
}
