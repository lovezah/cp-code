#include <bits/stdc++.h>

using namespace std;

int solve1(vector<int> &boxs, vector<int> &specials, map<int, bool> &seen) {
    int S = specials.size();
    vector<int> suf(S+1, 0);
    for (int i = S - 1; i >= 0; i--) {
        suf[i] += suf[i+1];
        if (seen[specials[i]])
            suf[i] += 1;
    }
    int C = boxs.size();
    int ans = suf[0], ptr = 0;
    for (int i = 0; i < S; i++) {
        int cur = suf[i+1];
        while (ptr < C && boxs[ptr] <= specials[i]) {
            ptr++;
        }
        if (ptr != 0) {
            int low = 0, high = i;
            while (low < high) {
                int mid = (low + high) / 2;
                if (specials[mid] < specials[i] - ptr + 1) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            cur += i - low + 1;
        }
        ans = max(ans, cur);
    }
    return ans;
}
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N); for (auto &a : A) cin >> a;
    vector<int> B(M); for (auto &b : B) cin >> b;
    vector<int> boxs, specials;
    map<int, bool> seen;
    for (int i = 0; i < N; i++)
        if (A[i] > 0) boxs.push_back(A[i]), seen[A[i]] = true;
    for (int i = 0; i < M; i++)
        if (B[i] > 0) specials.push_back(B[i]);
    int pos = solve1(boxs, specials, seen);
    seen.clear();
    boxs.clear();
    specials.clear();
    for (int i = 0; i < N; i++)
        if (A[i] < 0) boxs.push_back(-A[i]), seen[-A[i]] = true;
    for (int i = 0; i < M; i++)
        if (B[i] < 0) specials.push_back(-B[i]);
    ranges::reverse(boxs);
    ranges::reverse(specials);
    int neg = solve1(boxs, specials, seen);
    cout << pos + neg << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
