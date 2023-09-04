#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
void setmin(int &a, int b) { a = min(a, b); }

void solve() {
    int N, M; cin >> N >> M;
    vector<int> X(N); for (auto &x : X) cin >> x;
    vector<char> dir(N); for (auto &c : dir) cin >> c;
    vector<int> ans(N, -1);

    for (int d = 0; d < 2; d++) {
        vector<int> ids;
        for (int i = 0; i < N; i++) {
            if (X[i] % 2 == d) {
                ids.push_back(i);
            }
        }
        sort(ALL(ids), [&](auto a, auto b) {
            return X[a] < X[b];
        });
        int S = (int)ids.size();
        vector<int> stk;
        for (int i = 0; i < S; i++) {
            int id = ids[i];
            if (dir[id] == 'L') {
                if (stk.size()) {
                    ans[stk.back()] = (X[id] - X[stk.back()]) / 2;
                    ans[id] = (X[id] - X[stk.back()]) / 2;
                    stk.pop_back();
                }
            } else {
                stk.push_back(id);
            }
        }
        vector<int> L;
        for (int id : ids) {
            if (dir[id] == 'L' && ans[id] == -1)
                L.push_back(id);
        }
        for (int i = 0; i + 1 < (int)L.size(); i += 2) {
            int id1 = L[i], id2 = L[i+1];
            ans[id1] = (X[id1] + X[id2]) / 2;
            ans[id2] = (X[id1] + X[id2]) / 2;
        }
        vector<int> R;
        for (int id : ids) {
            if (dir[id] == 'R' && ans[id] == -1)
                R.push_back(id);
        }
        ranges::reverse(R);
        for (int i = 0; i + 1 < (int)R.size(); i += 2) {
            int id1 = R[i], id2 = R[i+1];
            ans[id1] = (2 * M - X[id1] - X[id2]) / 2;
            ans[id2] = (2 * M - X[id1] - X[id2]) / 2;
        }
        if (((int)L.size() % 2 == 1) && ((int)R.size() % 2 == 1)) {
            int id1 = L.back(), id2 = R.back();
            ans[id1] = (X[id1] + M - X[id2] + M) / 2;
            ans[id2] = (X[id1] + M - X[id2] + M) / 2;
        }
    }
    for (auto v : ans)
        cout << v << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
