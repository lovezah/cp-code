#include <bits/stdc++.h>

using namespace std;

void setmax(int &a, const int b) { a = max(a, b); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, P; cin >> N >> P;
    string S; cin >> S;
    bitset<17*17> bad;
    vector<bitset<17*17>> occ(1<<17);
    int freq[26] = {};
    for (auto c : S) freq[c-'a']++;

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            int x; cin >> x;
            if (!x) bad[i*17+j] = 1;
        }
    }

    auto process = [&](char x, string t) -> void {
        int done = 0;
        for (auto ch : t) {
            occ[done][(x-'a')*17+(ch-'a')] = 1;
            done |= 1 << (ch - 'a');
        }
    };

    for (int i = 0; i < N; i++) {
        int l = i - 1, done = 0;
        string tmp;
        while (l >= 0) {
            int mask = 1 << (S[l] - 'a');
            if (!(done & mask)) {
                done |= mask;
                tmp += S[l];
            }
            if (S[l] == S[i]) break;
            l--;
        }
        process(S[i], tmp);
        int r = i + 1;
        done = 0;
        tmp = "";
        while (r < N) {
            int mask = 1 << (S[r] - 'a');
            if (!(done & mask)) {
                done |= mask;
                tmp += S[r];
            }
            if (S[r] == S[i]) break;
            r++;
        }
        process(S[i], tmp);
    }
    for (int i = 0; i < 1 << P; i++) {
        for (int j = 0; j < P; j++) {
            if (i >> j & 1)
                occ[i] |= occ[i^(1<<j)];
        }
        for (int j = 0; j < P; j++) {
            for (int k = 0; k < P; k++) {
                if ((i >> j & 1) || (i >> k & 1)) {
                    occ[i][j*17+k] = 0;
                }
            }
        }
    }
    vector<bool> fine(1 << P);
    fine[0] = true;
    int ans = 0;
    for (int i = 0; i < 1 << P; i++) {
        // i -> characters deleted
        if ((occ[i] & bad).count() == 0) {
            for (int j = 0; j < P; j++) {
                if (fine[i^(1<<j)]) fine[i] = true;
            }
        }
        if (fine[i]) {
            int del = 0;
            for (int j = 0; j < P; j++) {
                if (i >> j & 1)
                    del += freq[j];
            }
            ans = max(ans, del);
        }
    }
    cout << N-ans << '\n';
    return 0;
}
